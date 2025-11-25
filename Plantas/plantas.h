//
// Created by Rodrigo on 29/10/2025.
//

#ifndef TRABALHOPRATICO_PLANTAS_H
#define TRABALHOPRATICO_PLANTAS_H

class Solo;
class Plantas {
protected:
    int agua;
    int nutrientes;
    char simbolo;
    char tipo;
public:
    virtual ~Plantas() {}
    virtual void simular(Solo& solo) = 0;
    virtual char getTipo() const = 0;

};


#endif //TRABALHOPRATICO_PLANTAS_H
