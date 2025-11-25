//
// Created by Rodrigo on 29/10/2025.
//

#ifndef TRABALHOPRATICO_ERVA_H
#define TRABALHOPRATICO_ERVA_H
#include "plantas.h"

class Erva : public Plantas {
public:
    Erva();
    void simular(Solo& solo) override;
    char getTipo() const override { return 'e'; }
};


#endif //TRABALHOPRATICO_ERVA_H
