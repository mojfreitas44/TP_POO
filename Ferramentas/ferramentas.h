
#ifndef TRABALHOPRATICO_FERRAMENTAS_H
#define TRABALHOPRATICO_FERRAMENTAS_H
#include <string>

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

    virtual std::string getDetalhes() const = 0;
    int getID () const {return id;}
    virtual bool gastou() const { return false; }
};


#endif //TRABALHOPRATICO_FERRAMENTAS_H
