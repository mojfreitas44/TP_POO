//
// Created by Rodrigo on 16/11/2025.
//

#ifndef TRABALHOPRATICO_FERRAMENTAS_H
#define TRABALHOPRATICO_FERRAMENTAS_H


class Solo;
class Ferramentas{
protected:
    int id;
    static int proximoID;
public:
    Ferramentas();
    virtual ~Ferramentas(){}
    virtual  char getTipo() const = 0;
    virtual void simular (Solo *solo) {}
    int getID () const {return id;}

};


#endif //TRABALHOPRATICO_FERRAMENTAS_H
