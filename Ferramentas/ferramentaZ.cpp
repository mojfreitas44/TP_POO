#include "ferramentaZ.h"
#include "../Solo.h"
#include "../Plantas/plantas.h"
#include <iostream>

using namespace std;
// ---------------------------------------------- //
// ----------- VITAMINA DE USO ÚNICO  ----------- //
// ------- DUPLICA OS STATS DE UMA PLANTA ------- //
// ---------------------------------------------- //
void FerramentaZ::simular(Solo* solo) {
    if (usou) return;
    Plantas* p = solo->getPlanta();
    if(p != nullptr){
        int newAgua = p->getAgua() * 2;
        int newNutrientes = p->getNutrientes() * 2;

        p->setAgua(newAgua);
        p->setNutrientes(newNutrientes);

        cout << "A ferramentaZ (Vitamina) foi aplicada!" << endl;
        cout << "A planta ficou com o DOBRO dos recursos: Agua=" << newAgua
             << " Nut=" << newNutrientes << endl;
    usou = true;
    }
}