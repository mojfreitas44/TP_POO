//
// Created by Rodrigo on 29/10/2025.
//

#ifndef TRABALHOPRATICO_COMANDOJARDIM_H
#define TRABALHOPRATICO_COMANDOJARDIM_H
#include <sstream>
#include "comando.h"
#include "../Jardim/jardim.h"




class ComandoJardim : public Comando {

public:
    std::string getNome() const override { return "jardim"; }
    bool executar(Jardim*& jardim, std::stringstream& parametros);

    ComandoJardim();
};



#endif //TRABALHOPRATICO_COMANDOJARDIM_H
