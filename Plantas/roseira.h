//
// Created by Rodrigo on 29/10/2025.
//

#ifndef TRABALHOPRATICO_ROSEIRA_H
#define TRABALHOPRATICO_ROSEIRA_H
#include "plantas.h"

class Roseira : public Plantas {
public:
    Roseira();
    void simular(Jardim& jardim, int l, int c) override;
    char getTipo() const override { return 'r'; }
};


#endif //TRABALHOPRATICO_ROSEIRA_H
