//
// Created by Rodrigo on 30/10/2025.
//

#ifndef TRABALHOPRATICO_COMANDOAVANCA_H
#define TRABALHOPRATICO_COMANDOAVANCA_H

#include <string>
#include "../Jardim/jardim.h"
#include "comando.h"
class Comandoavanca : public Comando {

private:
    std::string nomeComando;

public:
    Comandoavanca(const std::string& nome) : nomeComando(nome) {}

    std::string getNome() const override { return nomeComando; }
    bool executar(Jardim*& jardim, std::stringstream& parametros) override;


};


#endif //TRABALHOPRATICO_COMANDOAVANCA_H
