#include "adubo.h"
#include "../Solo.h"
#include <iostream>

using namespace std;

void Adubo::simular(Solo* solo) {
    // Só atua se ainda tiver carga
    if (quantidade > 0) {
        solo->adicionarNutrientes(Settings::Adubo::dose); // Adiciona 10
        quantidade -= Settings::Adubo::dose; // Gasta 10

         cout << "Adubo aplicado! Restam " << quantidade << " doses." << endl;
    } else {
        // cout << "O adubo acabou." << endl;
    }
}