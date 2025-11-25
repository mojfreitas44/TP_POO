//
// Created by Rodrigo on 16/11/2025.
//

#include "comandoferramentas.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>
#include "../Ferramentas/ferramentas.h"
#include "../Ferramentas/regador.h"
#include "../Ferramentas/adubo.h"
#include "../Ferramentas/tesoura.h"
#include "../Ferramentas/gadanha.h"

using namespace std;

bool ComandoFerramentas::executar(Jardim*& jardim, std::stringstream& parametros){
    // implementar comando de ferramentas aqui
    cout << "DEBUG: Executando comando '" << nomeComando << "'" << endl;
    Jardineiro* j = jardim->getJardineiro();

    if(nomeComando == "lferr"){

        cout << "=== FERRAMENTAS DO JARDINEIRO ===" << endl;
        if(j->getFerramentaNaMao())
            cout << "Ferramenta na mao: ID " << j->getFerramentaNaMao()->getID() << " Tipo " << j->getFerramentaNaMao()->getTipo() << endl;
        else
            cout << "Nenhuma ferramenta na mao." << endl;
        const vector<Ferramentas*>& mochila = j->getMochila();
        cout <<"Mochila(" << mochila.size() << "itens):" << endl;
        for(int i=0; i<mochila.size(); i++){
            cout << "Tipo: " << mochila[i]->getTipo() << " ID: " << mochila[i]->getID() << endl;

        }
        return true;

    }
    else if (nomeComando == "larga"){
        if(j->getFerramentaNaMao()!= nullptr){
            j->largarFerramenta();
            cout << "Ferramenta largada." << endl;
        }else
            cout << "Nenhuma ferramenta na mao para largar." << endl;
        return true;

    }
    else if(nomeComando == "pega") {
        int id;
        if (parametros >> id) {
            if (j->equiparFerramenta(id)) {
                cout << "Ferramenta com ID " << id << " equipada." << endl;
            } else {
                cout << "Ferramenta com ID " << id << " nao encontrada na mochila." << endl;
            }
            return true;

        }
    }
    else if (nomeComando == "compra"){
        char tipo;
        cout << "aqui"<<endl;
        if(parametros >> tipo){
            Ferramentas* novaFerramenta = nullptr;
            switch(tolower(tipo)){
                case 'g':
                    novaFerramenta = new Regador();
                    break;
                case 'a':
                    novaFerramenta = new Adubo();
                    break;
                case 't':
                    novaFerramenta = new Tesoura();
                    break;
                case 'z':
                    novaFerramenta = new Gadanha();
                    break;
                default:
                    cout << "Tipo de ferramenta invalido: " << tipo << endl;
                    return false;
            }
            j->apanharFerramenta(novaFerramenta);
            cout << "Comprou ferramenta '" << tipo << " (ID: " << novaFerramenta->getID() << ")" << endl;
            return true;
        }else{
            cout << "Erro: não foi possível comprar ferramenta." << endl;
            return false;
        }
    }



    return false;
}
