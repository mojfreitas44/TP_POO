#include "gadanha.h"
#include "../Solo.h"
#include "../Plantas/plantas.h"
#include <iostream>

using namespace std;

void Gadanha::simular(Solo* solo) {
    // A Gadanha não quer saber do tipo. Se é planta, corta.
    if (solo->getPlanta() != nullptr) {
        cout << "A Gadanha ceifou uma planta (" << solo->getPlanta()->getTipo() << ")!" << endl;
        solo->setPlanta(nullptr);
    }
}