//
// Created by Rodrigo on 29/10/2025.
//

#include "comandoplantas.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;

bool ComandoPlanta::executar(Jardim*& jardim, std::stringstream& parametros)  {
    // esperar: "<linha> <coluna> <tipoChar>"
    cout << "DEBUG: Executando comando '" << nomeComando << "'" << endl;
    if(nomeComando == "planta") {
        std::string posStr;
        cout << "DEBUG: Executando comando '" << nomeComando << "'" << endl;

        char tipoChar;


        if (!(parametros >> posStr >> tipoChar)) {
            cout << "Parametros invalidos. Uso: <linha> <coluna> <tipo>\n";
            return false;
        }

        Posicao p = Posicao::deString(posStr);
        Solo *solo = jardim->getSolo(p.getLinha(), p.getColuna());
        if (!solo) {
            cout << "Posicao fora do jardim." << endl;
            return false;
        }

        if (!solo->estaVazio()) {
            cout << "Posicao ja esta ocupada." << endl;
            return false;
        }

        Plantas *novaPlanta = nullptr;
        string nome;

        tipoChar = static_cast<char>(tolower(static_cast<unsigned char>(tipoChar)));

        switch (tipoChar) {
            case 'c':
                novaPlanta = new Cacto();
                nome = "cacto";
                break;
            case 'r':
                novaPlanta = new Roseira();
                nome = "roseira";
                break;
            case 'e':
                novaPlanta = new Erva();
                nome = "erva daninha";
                break;
                //case x
            default:
                cout << "Tipo de planta invalido." << endl;
                return false;
        }

        // AGORA USA O OBJETO JÁ CRIADO PARA OBTER O SÍMBOLO
        char tipo = novaPlanta->getTipo();
        solo->setPlanta(novaPlanta);

        cout << "Plantou " << nome << " (" << tipo << ") na posicao ("
             << p.getLinha() << "," << p.getColuna() << ")" << endl;
        return true;
    }
    else if(nomeComando == "lplantas") {
        cout << "=== Plantas no Jardim ===" << endl;
        bool encontrouPlantas = false;
        for (int l=0 ; l < jardim -> getLinhas(); l++) {
            for(int c=0; c< jardim-> getColunas(); c++) {
                Solo* solo = jardim->getSolo(l,c);
                if(solo && !solo -> estaVazio()) {
                    encontrouPlantas = true;
                    Plantas* planta = solo->getPlanta();
                    string nomePlanta;
                    switch(planta->getTipo()) {
                        case 'c': nomePlanta = "Cacto"; break;
                        case 'r': nomePlanta = "Roseira"; break;
                        case 'e': nomePlanta = "Erva Daninha"; break;
                        default: nomePlanta = "Desconhecida"; break;
                    }
                    string posStr;
                    posStr += static_cast<char>('a' + l);
                    posStr += static_cast<char>('a' + c);
                    cout << nomePlanta << " na posicao " << posStr << endl;
                }
            }
        }
        if(!encontrouPlantas) {
            cout << "Nenhuma planta no jardim." << endl;
        }
        return true;
    }
    return false;
}