#ifndef EXOTICA_H
#define EXOTICA_H

#include "plantas.h"

class Exotica : public Plantas {
public:
    Exotica();
    void simular(Jardim& jardim, int l, int c) override;
    char getTipo() const override { return 'x'; } // Requisito do enunciado

};

#endif //EXOTICA_H
