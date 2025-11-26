//
// Created by Rodrigo on 29/10/2025.
//

#ifndef TRABALHOPRATICO_PLANTAS_H
#define TRABALHOPRATICO_PLANTAS_H

class Solo;
class Jardim;

class Plantas {
protected:
    int agua;
    int nutrientes;
    char simbolo;
    char tipo;
public:
    virtual ~Plantas() {}
    virtual void simular(Jardim& jardim, int l, int c) = 0;
    virtual char getTipo() const = 0;

    int getAgua() const { return agua; }
    int getNutrientes() const { return nutrientes; }

    void setAgua(int a) { agua = a; }
    void setNutrientes(int n) { nutrientes = n; }
};


#endif //TRABALHOPRATICO_PLANTAS_H
