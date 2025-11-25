#ifndef TRABALHOPRATICO_INTERPRETADOR_H
#define TRABALHOPRATICO_INTERPRETADOR_H
#include <string>
#include <vector>
#include "Comandos/comando.h"
#include "Jardim/jardim.h"
using namespace std;


class Interpretador {
    std::vector<Comando*> comandos;
public:
    Interpretador();
    ~Interpretador();
    bool processarComando(const std::string& linha, Jardim*& jardim);
};
#endif //TRABALHOPRATICO_INTERPRETADOR_H




