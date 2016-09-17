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
    for(int i = 101; i > 0; i--)
        listenha.inserirfim(i*i);
    listenha.listarCome();
    listenha.ordenarAsc();
    listenha.listarCome();
}
