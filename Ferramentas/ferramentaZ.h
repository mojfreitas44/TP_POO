#ifndef TRABALHOPRATICO_FERRAMENTAZ_H
#define TRABALHOPRATICO_FERRAMENTAZ_H
#include "ferramentas.h"
// ---------------------------------------------- //
// ----------- VITAMINA DE USO ÚNICO  ----------- //
// ------- DUPLICA OS STATS DE UMA PLANTA ------- //
// ---------------------------------------------- //
class FerramentaZ : public Ferramentas{
bool usou;
public:
    FerramentaZ() : usou (false){}
    char getTipo() const override { return 'z'; }
    std::string getDetalhes() const override {return "Vitamina (Stats x2)";}

    bool gastou() const override { return usou; }
    void simular(Solo* solo) override;
};


#endif //TRABALHOPRATICO_FERRAMENTAZ_H
