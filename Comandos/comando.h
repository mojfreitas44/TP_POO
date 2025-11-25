//
// Created by Rodrigo on 29/10/2025.
//

#ifndef TRABALHOPRATICO_COMANDO_H
#define TRABALHOPRATICO_COMANDO_H

#include <string>
#include <sstream>
#include "../Jardim/jardim.h"



class Comando {
private:
    std::string nomeComando;
public:
    virtual ~Comando(){}
    virtual std::string getNome() const = 0;

    virtual bool executar(Jardim*& jardim, std::stringstream& parametros) = 0;
};


#endif //TRABALHOPRATICO_COMANDO_H


