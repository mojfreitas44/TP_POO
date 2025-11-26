//
// Created by Rodrigo on 29/10/2025.
//

#ifndef TRABALHOPRATICO_CACTO_H
#define TRABALHOPRATICO_CACTO_H
#include "plantas.h"

class Cacto : public Plantas {
public:
    Cacto();
    void simular(Jardim& jardim, int l, int c) override;
    char getTipo() const override { return 'c'; }

};


#endif //TRABALHOPRATICO_CACTO_H
