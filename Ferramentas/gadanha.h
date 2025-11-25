//
// Created by Rodrigo on 16/11/2025.
//

#ifndef TRABALHOPRATICO_GADANHA_H
#define TRABALHOPRATICO_GADANHA_H
#include "ferramentas.h"

class Gadanha : public Ferramentas{
public:
    Gadanha(){}
    char getTipo() const override { return 'z'; }
};


#endif //TRABALHOPRATICO_GADANHA_H
