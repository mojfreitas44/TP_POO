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
    std::string getDetalhes() const override {
        return "Indestrutivel";
    }
    bool gastou() const override { return false; }
    void simular(Solo* solo) override;
};


#endif //TRABALHOPRATICO_TESOURA_H
