#include <iostream>

using namespace std;

void quick(particula* ini, int tamanho, particula* fimu)
{
    if(tamanho % 2 != 0){
        tamanho++;
    }
    particula* ondenados= fimu;
    particula* contador = ini;
    particula* pivo= ini;
    for (int i = 0; i < tamanho/2; i++){
        pivo = pivo->getProx();
    }
    int auxiliar;
    while(contador != fimu)
    {
        if(contador->getItem() >= pivo->getItem() || contador == pivo)
        {
            ondenados = fimu;
            while(ondenados->getItem() > pivo->getItem() && ondenados != contador){
                ondenados = ondenados->getAnt();
            }
            if(ondenados == pivo &&  ondenados != contador && contador->getItem() != ondenados->getItem() ){
                auxiliar= contador->getItem();
                contador->setItem(ondenados->getItem());
                ondenados->setItem(auxiliar);
                pivo =contador;
            } else if(contador == pivo && contador->getItem() != ondenados->getItem() ){
                auxiliar= pivo->getItem();
                pivo->setItem(ondenados->getItem());
                ondenados->setItem(auxiliar);
                pivo = ondenados;
            }else if(contador->getItem() != ondenados->getItem()){
                auxiliar= contador->getItem();
                contador->setItem(ondenados->getItem());
                ondenados->setItem(auxiliar);

            }
        }
            contador = contador->getProx();

    }

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
    if(tamanho2 > 1){
        quick(ini, tamanho2, contador);
    }
    if(tamanho > 1){
        quick(contador, tamanho, fimu);
    }

}
