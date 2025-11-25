//
// Created by Rodrigo on 16/11/2025.
//

#ifndef TRABALHOPRATICO_REGADOR_H
#define TRABALHOPRATICO_REGADOR_H
#include "ferramentas.h"

class Regador : public Ferramentas{
public:
    Regador(){}
    char getTipo() const override { return 'g'; }

};


#endif //TRABALHOPRATICO_REGADOR_H
