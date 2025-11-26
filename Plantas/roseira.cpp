#include "roseira.h"
#include "../Jardim/jardim.h"
#include "../Solo.h"
#include "../Settings.h"
#include "../Jardim/posicao.h"
#include <vector>
#include <cstdlib>
#include <algorithm> // Para usar std::min

using namespace std;

Roseira::Roseira() {
    // Regra: Inicialmente tem 25 nutrientes e 25 de água.
    agua = Settings::Roseira::inicial_agua;
    nutrientes = Settings::Roseira::inicial_nutrientes;
    simbolo = 'r';
}

void Roseira::simular(Jardim& jardim, int l, int c) {
    Solo* solo = jardim.getSolo(l, c);

    // --- 1. METABOLISMO (Gasta sempre) ---
    // Regra: perde 4 unidades de água e 4 de nutrientes.
    this->agua -= Settings::Roseira::perda_agua;
    this->nutrientes -= Settings::Roseira::perda_nutrientes;

    // --- 2. ABSORÇÃO (Só o que existe) ---
    // Regra: absorve 5 unidades de água do solo (se existir).
    // Correção: Verificamos quanto há no solo antes de tirar.
    int aguaDesejada = Settings::Roseira::absorcao_agua;
    int aguaDisponivel = solo->getAgua();
    int aguaParaBeber = std::min(aguaDesejada, aguaDisponivel); // Bebe o mínimo entre o que quer e o que há

    solo->retirarAgua(aguaParaBeber);
    this->agua += aguaParaBeber;

    // Regra: absorve 8 unidades de nutrientes do solo (se existir).
    int nutDesejados = Settings::Roseira::absorcao_nutrientes;
    int nutDisponiveis = solo->getNutrientes();
    int nutParaComer = std::min(nutDesejados, nutDisponiveis);

    solo->retirarNutrientes(nutParaComer);
    this->nutrientes += nutParaComer;

    // --- 3. VERIFICAR VIZINHOS ---
    // Necessário para regra de morte (cercada) e reprodução
    vector<Posicao> vizinhosLivres;

    for (int dl = -1; dl <= 1; dl++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dl == 0 && dc == 0) continue; // Ignora a própria posição

            Solo* viz = jardim.getSolo(l + dl, c + dc);
            if (viz != nullptr) {
                if (viz->estaVazio()) {
                    vizinhosLivres.push_back(Posicao(l + dl, c + dc));
                }
            }
        }
    }

    // --- 4. MORTE ---
    // Regras de morte: Agua=0, Nutrientes=0, Nutrientes>=200, ou cercada.
    bool semRecursos = (this->agua <= 0 || this->nutrientes <= 0);
    bool excessoNutrientes = (this->nutrientes >= Settings::Roseira::morre_nutrientes_maior); // 200
    bool cercada = vizinhosLivres.empty(); // Se não há livres, está cercada

    if (semRecursos || excessoNutrientes || cercada) {
        // Regra: Deixa no solo metade dos nutrientes que absorveu (neste caso, o que tem acumulado) e metade da água.
        solo->adicionarNutrientes(this->nutrientes / 2);
        solo->adicionarAgua(this->agua / 2);

        solo->setPlanta(nullptr); // Remove a planta do jogo
        return;
    }

    // --- 5. REPRODUÇÃO ---
    // Regra: Nutrientes > 100 e existe posição vizinha vazia.
    if (this->nutrientes > Settings::Roseira::multiplica_nutrientes_maior && !vizinhosLivres.empty()) {

        // Escolhe vizinho
        int idx = rand() % vizinhosLivres.size();
        Posicao p = vizinhosLivres[idx];

        // Regra: Nova planta começa com 25 nutrientes e metade da água da original.
        Roseira* novaPlanta = new Roseira();

        // A mãe divide a água atual por 2
        int aguaAtual = this->agua;
        this->agua = aguaAtual / 2; // Mãe fica com metade

        // Precisas de um 'setAgua' na classe Plantas ou Roseira, ou usar friend class.
        // Como as variaveis são protected, a Roseira consegue aceder às variaveis de outra Roseira!
        novaPlanta->agua = aguaAtual / 2; // Filha fica com metade
        novaPlanta->nutrientes = Settings::Roseira::nova_nutrientes; // 25

        jardim.getSolo(p.getLinha(), p.getColuna())->setPlanta(novaPlanta);

        // Regra: Roseira original fica com 100 nutrientes.
        this->nutrientes = Settings::Roseira::original_nutrientes;
    }
}