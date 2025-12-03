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
    std::string getDetalhes() const override {return "Indestrutivel";}

    bool gastou() const override { return false; }
    void simular(Solo* solo) override;
};


#endif //TRABALHOPRATICO_GADANHA_H
