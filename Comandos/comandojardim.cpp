//
// Created by Rodrigo on 29/10/2025.
//

#include "comandojardim.h"
#include "../Jardim/jardim.h"
#include <iostream>
#include <sstream>

using namespace std;
ComandoJardim::ComandoJardim(){}

bool ComandoJardim::executar(Jardim*& jardim, std::stringstream& parametros){
    cout << "entrou no comando jardim" << endl;

    int l,c;
    if(parametros >> l && parametros >> c){
        if(l<1 || l>26 || c<1 || c>26){
            std::cout << "Dimensoes invalidas. Linhas e colunas devem estar entre 1 e 26." << std::endl;
            return false;
        }
        delete jardim; // eliminar jardim anterior, se existir
        jardim = new Jardim(l,c);
        std::cout << "Jardim criado com " << l << " linhas e " << c << " colunas." << std::endl;
        return true;
    }
    std::cout << "Parametros insuficientes para comando 'jardim' <linhas> <colunas>." << std::endl;
    return false;
}
