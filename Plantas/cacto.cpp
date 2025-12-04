#include "cacto.h"
#include "../Jardim/jardim.h"
#include "../Solo.h"
#include "../Settings.h"
#include "../Jardim/posicao.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

Cacto::Cacto() : diasComAguaAMais(0), diasSemNutrientes(0) {
    agua = 20;
    nutrientes = 20;
    simbolo = 'c';
}
void Cacto::simular(Jardim& jardim, int l, int c) {

    Solo* solo = jardim.getSolo(l, c);

    // --- 1. Absorção ---

    // Água: "Absorve 25% das unidades de água existentes no solo"
    int aguaNoSolo = solo->getAgua();
    int aguaParaBeber = aguaNoSolo * Settings::Cacto::absorcao_agua_percentagem / 100;

    solo->retirarAgua(aguaParaBeber);
    this->agua += aguaParaBeber;

    // Nutrientes: "Absorve 5 unidades de nutrientes do solo"
    int nutDesejados = Settings::Cacto::absorcao_nutrientes;
    int nutDisponiveis = solo->getNutrientes();
    int nutParaComer = std::min(nutDesejados, nutDisponiveis);

    solo->retirarNutrientes(nutParaComer);
    this->nutrientes += nutParaComer;

    // --- 2. ATUALIZAR CONTADORES DE MORTE ---

    // Regra: Água no solo > 100
    if (solo->getAgua() > Settings::Cacto::morre_agua_solo_maior) {
        diasComAguaAMais++;
    } else {
        diasComAguaAMais = 0; // Se a água baixar, o contador reseta
    }
    // Regra: Nutrientes no solo == 0
    // (O settings define um limiar "menor que 1", ou seja, 0)
    if (solo->getNutrientes() <= 0) {
        diasSemNutrientes++;
    } else {
        diasSemNutrientes = 0;
    }
    // --- 3. VERIFICAR MORTE ---
    // Enunciado: "3 instantes seguidos" para água, "mais do que 3" para nutrientes
    bool mortePorAgua = (diasComAguaAMais >= Settings::Cacto::morre_agua_solo_instantes);
    bool mortePorFome = (diasSemNutrientes > Settings::Cacto::morre_nutrientes_solo_instantes);

    if (mortePorAgua || mortePorFome) {
        char lChar = (char)('a' + l);
        char cChar = (char)('a' + c);

        cout << "Cacto morreu em " << lChar << cChar;
        if(mortePorAgua) cout << " (Excesso de Agua no Solo por 3 instantes seguidos: " << solo->getAgua() << " unidades de agua no instante atual)";
        if(mortePorFome) cout << " (Solo sem Nutrientes ha " << diasSemNutrientes << " dias)";
        cout << endl;

        // Regra: "Ao morrer deixa no solo todos os nutrientes que absorveu (a água não)"
        if (this->nutrientes > 0) {
            solo->adicionarNutrientes(this->nutrientes);
        }

        solo->setPlanta(nullptr);
        return; // Fim da planta
    }
    // --- 4. REPRODUÇÃO ---
    // Regra: Nutrientes acumulados > 100 e Água acumulada > 50
    if (this->nutrientes > Settings::Cacto::multiplica_nutrientes_maior &&
        this->agua > Settings::Cacto::multiplica_agua_maior) {

        // 1. Procurar vizinhos livres
        vector<Posicao> vizinhosLivres;
        for (int dl = -1; dl <= 1; dl++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dl == 0 && dc == 0) continue;
                Solo* viz = jardim.getSolo(l + dl, c + dc);
                if (viz != nullptr && viz->estaVazio()) {
                    vizinhosLivres.push_back(Posicao(l + dl, c + dc));
                }
            }
        }
        // 2. Criar filho se houver espaço
        if (!vizinhosLivres.empty()) {
            int idx = rand() % vizinhosLivres.size();
            Posicao p = vizinhosLivres[idx];

            Cacto* filho = new Cacto();

            // Regra: "água e nutrientes... divididos em iguais partes pelo cacto inicial e pelo novo"
            int metadeNut = this->nutrientes / 2;
            int metadeAgua = this->agua / 2;

            // Atualiza Mãe
            this->nutrientes = metadeNut;
            this->agua = metadeAgua;

            // Atualiza Filho
            filho->setNutrientes(metadeNut);
            filho->setAgua(metadeAgua);

            jardim.getSolo(p.getLinha(), p.getColuna())->setPlanta(filho);
        }
    }
}