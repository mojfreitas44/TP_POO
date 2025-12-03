//
// Created by Rodrigo on 16/11/2025.
//

#ifndef TRABALHOPRATICO_REGADOR_H
#define TRABALHOPRATICO_REGADOR_H
#include "ferramentas.h"
#include "../Settings.h"

class Regador : public Ferramentas{
    int quantidade;
public:
    Regador() : quantidade(Settings::Regador::capacidade) {}
    char getTipo() const override { return 'g'; }
    std::string getDetalhes() const override {
        return "Agua: " + std::to_string(quantidade);
    }
    void simular (Solo* solo) override;
    bool gastou() const override { return quantidade <= 0; }
};


#endif //TRABALHOPRATICO_REGADOR_H
