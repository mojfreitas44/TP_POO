//
// Created by Rodrigo on 16/11/2025.
//

#ifndef TRABALHOPRATICO_ADUBO_H
#define TRABALHOPRATICO_ADUBO_H
#include "ferramentas.h"

class Adubo :public Ferramentas{
public:
    Adubo(){}
    char getTipo() const override { return 'a'; }

};


#endif //TRABALHOPRATICO_ADUBO_H
