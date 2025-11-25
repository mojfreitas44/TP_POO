//
// Created by Rodrigo on 16/11/2025.
//

#ifndef TRABALHOPRATICO_TESOURA_H
#define TRABALHOPRATICO_TESOURA_H
#include "ferramentas.h"

class Tesoura : public Ferramentas {
public:
    Tesoura(){}
    char getTipo() const override { return 't'; }

};


#endif //TRABALHOPRATICO_TESOURA_H
