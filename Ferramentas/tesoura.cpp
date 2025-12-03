#include "tesoura.h"
#include "../Solo.h"
#include "../Plantas/plantas.h"
#include <iostream>

using namespace std;

void Tesoura::simular(Solo* solo) {
    Plantas* p = solo->getPlanta();
    if(p != nullptr && p->getTipo() == 'e'){
        cout << "A tesoure cortou uma erva daninha!" << endl;
        solo->setPlanta(nullptr); // remove a planta
    }
}