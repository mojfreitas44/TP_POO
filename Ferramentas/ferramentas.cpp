//
// Created by Rodrigo on 16/11/2025.
//
#include "ferramentas.h"

int Ferramentas::proximoID = 1;

Ferramentas::Ferramentas() {
    id = proximoID;
    proximoID++;
}
