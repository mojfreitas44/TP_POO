#ifndef COMANDOSOLO_H
#define COMANDOSOLO_H
#include "comando.h"

class ComandoSolo : public Comando {
public:
    std::string getNome() const override { return "lsolo"; } // ou 'lsolo' conforme enunciado
    bool executar(Jardim*& jardim, std::stringstream& parametros) override;
};
#endif