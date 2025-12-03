#include "jardineiro.h"
#include "Ferramentas/ferramentas.h"
#include "Settings.h"
#include <algorithm>
#include <iostream>

using namespace std;

Jardineiro::Jardineiro()
        : dentroDoJardim(false), linha(0), coluna(0),
          ferramentaNaMao(nullptr), movimentosFeitos(0), plantasPlantadas(0), plantasColhidas(0) {}

Jardineiro::~Jardineiro() {
    delete ferramentaNaMao; // Apaga a da mão se existir
    for (Ferramentas* f : mochila) {
        delete f;
    }
    mochila.clear();
}

void Jardineiro::entrar(int l, int c) {
    dentroDoJardim = true;
    linha = l;
    coluna = c;
}

void Jardineiro::sair() {
    dentroDoJardim = false;
}

void Jardineiro::setPosicao(int l, int c) {
    linha = l;
    coluna = c;
}

// --- GESTÃO DE FERRAMENTAS ---

void Jardineiro::apanharFerramenta(Ferramentas* f) {
    if (f != nullptr) {
        mochila.push_back(f);
    }
}

bool Jardineiro::equiparFerramenta(int id) {
    // 1. Procurar a ferramenta na mochila
    for (auto it = mochila.begin(); it != mochila.end(); ++it) {
        if ((*it)->getID() == id) {

            // Encontrou!
            Ferramentas* novaFerramenta = *it;

            // 2. Se já tiver algo na mão, devolve à mochila
            if (ferramentaNaMao != nullptr) {
                mochila.push_back(ferramentaNaMao);
                cout << "Guardou a ferramenta " << ferramentaNaMao->getTipo() << " na mochila." << endl;
            }

            // 3. Põe a nova na mão
            ferramentaNaMao = novaFerramenta;

            // 4. Remove a nova da mochila (agora só está na mão)
            mochila.erase(it);

            return true;
        }
    }
    return false; // Não encontrou esse ID na mochila
}

void Jardineiro::largarFerramenta() {
    // Largar = Guardar na mochila
    if (ferramentaNaMao != nullptr) {
        mochila.push_back(ferramentaNaMao);
        ferramentaNaMao = nullptr;
    }
}

void Jardineiro::verificarFerramentaNaMao() {
    // Como a ferramenta na mão JÁ NÃO ESTÁ na mochila, basta apagar a da mão.
    if (ferramentaNaMao != nullptr && ferramentaNaMao->gastou()) {
        cout << "A ferramenta " << ferramentaNaMao->getTipo()
             << " (ID: " << ferramentaNaMao->getID() << ") acabou e foi deitada fora!" << endl;

        delete ferramentaNaMao; // Apaga da memória
        ferramentaNaMao = nullptr; // Esvazia a mão
    }
}

// --- Gestão de Ações ---

void Jardineiro::resetarAcoes() {
    movimentosFeitos = 0;
    plantasPlantadas = 0;
    plantasColhidas = 0;
}

bool Jardineiro::podeMover() const {
    return movimentosFeitos < Settings::Jardineiro::max_movimentos;
}

bool Jardineiro::podeColher() const {
    return plantasColhidas < Settings::Jardineiro::max_colheitas;
}

void Jardineiro::registarColheita() {
    plantasColhidas++;
}

void Jardineiro::registarMovimento() {
    movimentosFeitos++;
}