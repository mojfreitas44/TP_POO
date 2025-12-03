//
// Created by Rodrigo on 16/11/2025.
//

#ifndef TRABALHOPRATICO_COMANDOFERRAMENTAS_H
#define TRABALHOPRATICO_COMANDOFERRAMENTAS_H
#include "../Ferramentas/adubo.h"
#include "../Ferramentas/ferramentas.h"
#include "../Ferramentas/regador.h"
#include "../Ferramentas/ferramentaZ.h"
#include "../Ferramentas/tesoura.h"
#include "comando.h"
#include "../Solo.h"
#include "../Jardim/jardim.h"
#include "../Jardim/posicao.h"
#include <string>

class ComandoFerramentas : public Comando {
private:
    std::string nomeComando;
public:
    ComandoFerramentas(const std::string& nome) : nomeComando(nome){}
    std::string getNome() const override { return nomeComando; }
    bool executar(Jardim*& jardim, std::stringstream& parametros) override;

};


#endif //TRABALHOPRATICO_COMANDOFERRAMENTAS_H
