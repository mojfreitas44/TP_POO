#include "roseira.h"
#include "../Jardim/jardim.h"
#include "../Solo.h"
#include "../Settings.h"
#include "../Jardim/posicao.h"
#include <vector>
#include <cstdlib>
#include <algorithm> // Para usar std::min
#include <iostream>  // Necessário para avisar que morreu

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
    this->agua -= Settings::Roseira::perda_agua;
    this->nutrientes -= Settings::Roseira::perda_nutrientes;

    // --- 2. ABSORÇÃO (Só o que existe) ---
    int aguaDesejada = Settings::Roseira::absorcao_agua;
    int aguaDisponivel = solo->getAgua();
    int aguaParaBeber = std::min(aguaDesejada, aguaDisponivel);

    solo->retirarAgua(aguaParaBeber);
    this->agua += aguaParaBeber;

    int nutDesejados = Settings::Roseira::absorcao_nutrientes;
    int nutDisponiveis = solo->getNutrientes();
    int nutParaComer = std::min(nutDesejados, nutDisponiveis);

    solo->retirarNutrientes(nutParaComer);
    this->nutrientes += nutParaComer;

    vector<Posicao> vizinhosLivres;
    int vizinhosComPlanta = 0;
    int totalVizinhosValidos = 0; // Contar limites do mapa

    for (int dl = -1; dl <= 1; dl++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dl == 0 && dc == 0) continue;

            Solo* viz = jardim.getSolo(l + dl, c + dc);
            if (viz != nullptr) {
                totalVizinhosValidos++;

                // Para reprodução: Espaço totalmente vazio
                if (viz->estaVazio()) {
                    vizinhosLivres.push_back(Posicao(l + dl, c + dc));
                }

                // Para morte: Contar especificamente plantas vizinhas
                if (viz->getPlanta() != nullptr) {
                    vizinhosComPlanta++;
                }
            }
        }
    }

    // --- 4. MORTE ---
    bool semRecursos = (this->agua <= 0 || this->nutrientes <= 0);
    bool excessoNutrientes = (this->nutrientes >= Settings::Roseira::morre_nutrientes_maior);

    // CORREÇÃO: Só está cercada se o nº de plantas vizinhas for igual ao nº de vizinhos
    // Se houver uma ferramenta ao lado, não é planta, logo não morre por "sufoco"
    bool sufocadaPorPlantas = (totalVizinhosValidos > 0 && vizinhosComPlanta == totalVizinhosValidos);

    if (semRecursos || excessoNutrientes || sufocadaPorPlantas) {
        // Mensagem de Morte
        char linhaChar = static_cast<char>('a' + l);
        char colChar = static_cast<char>('a' + c);
        cout << "Roseira morreu na posicao " << linhaChar << colChar << " (Nut: " << this->nutrientes << ")." << endl;

        if (this->nutrientes > 0) solo->adicionarNutrientes(this->nutrientes / 2);
        if (this->agua > 0) solo->adicionarAgua(this->agua / 2);

        solo->setPlanta(nullptr);
        return;
    }

    // --- 5. REPRODUÇÃO ---
    if (this->nutrientes > Settings::Roseira::multiplica_nutrientes_maior && !vizinhosLivres.empty()) {
        int idx = rand() % vizinhosLivres.size();
        Posicao p = vizinhosLivres[idx];

        Roseira* novaPlanta = new Roseira();

        int aguaAtual = this->agua;
        this->agua = aguaAtual / 2; // Mãe fica com metade

        // Define valores da filha
        novaPlanta->setAgua(aguaAtual / 2);
        novaPlanta->setNutrientes(Settings::Roseira::nova_nutrientes);

        jardim.getSolo(p.getLinha(), p.getColuna())->setPlanta(novaPlanta);

        // Atualiza mãe
        this->nutrientes = Settings::Roseira::original_nutrientes;
    }
}