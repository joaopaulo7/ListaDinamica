//============================================================================
// Name        : Lista.cpp
// Author      : João Paulo Paiva Lima
// Version     :
// Copyright   : This file belongs to João Paulo Paiva Lima
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "lista.hpp"

using namespace std;

int main() {
    lista listenha;
    listenha.inserirfim(11000);
    listenha.inserirfim(21);
    listenha.inserirfim(100);
    listenha.listarCome();
    listenha.ordenarDesc();
    listenha.listarFim();
}
