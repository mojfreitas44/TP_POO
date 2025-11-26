//
// Created by Rodrigo on 29/10/2025.
//

#ifndef TRABALHOPRATICO_COMANDOPLANTAS_H
#define TRABALHOPRATICO_COMANDOPLANTAS_H
#include "../Plantas/cacto.h"
#include "../Plantas/erva.h"
#include "../Plantas/roseira.h"
#include "../Plantas/exotica.h"
#include "../Jardim/jardim.h"
#include "../Jardim/posicao.h"
#include "../Plantas/plantas.h"
#include "../Solo.h"
#include "comando.h"
#include <string>



class ComandoPlanta : public Comando {
private:
    std::string nomeComando;
public:

    ComandoPlanta(const std::string& nome) : nomeComando(nome){}
    std::string getNome() const override { return nomeComando; }
    bool executar(Jardim*& jardim, std::stringstream& parametros) override;

};




#endif //TRABALHOPRATICO_COMANDOPLANTAS_H
