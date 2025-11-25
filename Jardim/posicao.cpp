#include "posicao.h"
#include "../Settings.h"
#include <stdexcept>
#include <cctype>
using namespace std;

Posicao::Posicao(int l, int c) : linha(l), coluna(c) {}

// Converte "aa" para (0,0), "ab" para (0,1), etc.
Posicao Posicao::deString(const string& str) {
    if (str.length() != 2) {
        throw invalid_argument("Posição deve ter 2 caracteres");
    }

    char letra1 = tolower(str[0]);
    char letra2 = tolower(str[1]);

    if (letra1 < 'a' || letra1 > 'z' || letra2 < 'a' || letra2 > 'z') {
        throw invalid_argument("Posição deve conter apenas letras");
    }

    int l = letra1 - 'a';  // 'a' -> 0, 'b' -> 1, etc.
    int c = letra2 - 'a';

    return Posicao(l, c);
}

// Converte (0,0) para "aa", (0,1) para "ab", etc.
string Posicao::paraString() const {
    string result;
    result += static_cast<char>('a' + linha);
    result += static_cast<char>('a' + coluna);
    return result;
}

bool Posicao::ehValida(int maxLinhas, int maxColunas) const {
    return linha >= 0 && linha < maxLinhas &&
           coluna >= 0 && coluna < maxColunas;
}

