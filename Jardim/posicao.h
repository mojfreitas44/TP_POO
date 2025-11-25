#ifndef TRABALHOPRATICO_POSICAO_H
#define TRABALHOPRATICO_POSICAO_H
#include <string>
using namespace std;

class Posicao {

private:
    int linha;
    int coluna;

public:
    Posicao(int l, int c);

    // Converte de "aa" para linha=0, coluna=0
    static Posicao deString(const string& str);

    // Converte para string "aa", "ab", etc.
    string paraString() const;

    // Getters
    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }

    // Setters
    void setLinha(int l) { linha = l; }
    void setColuna(int c) { coluna = c; }

    // Verifica se é posição válida para um jardim de tamanho LxC
    bool ehValida(int maxLinhas, int maxColunas) const;
};
#endif //TRABALHOPRATICO_POSICAO_H
