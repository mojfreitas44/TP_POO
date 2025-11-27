

#ifndef TRABALHOPRATICO_ADUBO_H
#define TRABALHOPRATICO_ADUBO_H
#include "ferramentas.h"
#include "../Settings.h"

class Adubo :public Ferramentas{
    int quantidade;
public:
    Adubo() : quantidade(Settings::Adubo::capacidade) {} // Começa com 100

    char getTipo() const override { return 'a'; }

    // Método que aplica o efeito
    void simular(Solo* solo) override;

    // Getter para veres quanto resta (útil para debug)
    int getQuantidade() const { return quantidade; }

    bool gastou() const override { return quantidade <= 0; }
};


#endif //TRABALHOPRATICO_ADUBO_H
