#include "roseira.h"
#include "../Solo.h"
#include "../Settings.h"
#include <iostream>
using namespace std;

Roseira::Roseira() {
    agua = Settings::Roseira::inicial_agua;
    nutrientes = Settings::Roseira::inicial_nutrientes;
    simbolo = 'r';
}
void Roseira::simular(Solo& solo) {
    this->agua -= Settings::Roseira::perda_agua;
    this->nutrientes -= Settings::Roseira::perda_nutrientes;

    // 2. Absorção do Solo (Tentar beber/comer)
    // Retira do solo
    solo.retirarAgua(Settings::Roseira::absorcao_agua);
    solo.retirarNutrientes(Settings::Roseira::absorcao_nutrientes);

    // Guarda na planta
    this->agua += Settings::Roseira::absorcao_agua;
    this->nutrientes += Settings::Roseira::absorcao_nutrientes;
}