#include "comandosolo.h"
#include "../Jardim/posicao.h"
#include "../Solo.h"
#include <iostream>

using namespace std;

bool ComandoSolo::executar(Jardim*& jardim, stringstream& parametros) {
    string posStr;
    if (parametros >> posStr) {
        try {
            Posicao p = Posicao::deString(posStr);

            if (p.getLinha() < 0 || p.getLinha() >= jardim->getLinhas() ||
                p.getColuna() < 0 || p.getColuna() >= jardim->getColunas()) {
                cout << "Posicao fora do jardim." << endl;
                return false;
                }

            Solo* solo = jardim->getSolo(p.getLinha(), p.getColuna());

            cout << "--- Analise do Solo em " << posStr << " ---" << endl;
            cout << "Agua: " << solo->getAgua() << endl;
            cout << "Nutrientes: " << solo->getNutrientes() << endl;

            if (solo->getPlanta() != nullptr) {
                cout << "Planta: " << solo->getPlanta()->getTipo() << endl;
            } else {
                cout << "Planta: Nenhuma" << endl;
            }

            if (solo->getFerramenta() != nullptr) {
                cout << "Ferramenta: " << solo->getFerramenta()->getTipo() << endl;
            }

            return true;

        } catch (...) {
            cout << "Posicao invalida." << endl;
            return false;
        }
    }
    cout << "Parametros invalidos. Uso: lsolo <posicao>" << endl;
    return false;
}