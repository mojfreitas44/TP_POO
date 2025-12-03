#include "regador.h"
#include "../Solo.h"
#include <iostream>


using namespace std;

void Regador::simular(Solo *solo) {
    if (quantidade > 0) {

        solo->adicionarAgua(Settings::Regador::dose);
        quantidade -= Settings::Regador::dose;
    }
    cout << "Regador aplicado! Restam " << quantidade << " unidades de agua." << endl;
}
