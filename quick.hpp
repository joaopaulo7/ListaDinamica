#include <iostream>

using namespace std;

void quick(particula* ini, int tamanho, particula* fimu)
{
    particula* ordenados= ini;
    particula* contador = ini;
    particula* pivo= ini;
    for (int i = 0; i < tamanho-1; i++){
        pivo = pivo->getProx();
    }
    int auxiliar;


    while(contador != fimu->getProx())
    {
        if(contador->getItem() < pivo->getItem())
        {
            auxiliar= contador->getItem();
            contador->setItem(ordenados->getItem());
            ordenados->setItem(auxiliar);
            if(contador == pivo)
            {
                pivo = ordenados;
            }
            ordenados = ordenados->getProx();
        }
        contador = contador->getProx();
    }
            auxiliar= ordenados->getItem();
            ordenados->setItem(pivo->getItem());
            pivo->setItem(auxiliar);
            pivo = ordenados;

    tamanho=0;
    int tamanho2=0;
    contador = ini;
    while(contador != pivo){
        tamanho2++;
        contador = contador->getProx();
    }
    while(pivo != fimu){
        tamanho++;
        pivo = pivo->getProx();
    }
    if(tamanho2-1 > 0){
        quick(ini, tamanho2, contador->getAnt());
    }
    if(tamanho-1 > 0){
        quick(contador->getProx(), tamanho, fimu);
    }

}

