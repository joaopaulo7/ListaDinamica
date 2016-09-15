#include <iostream>
#include "particula.hpp"
#include "quick.hpp"

using namespace std;

class lista{

public:

    void inserirfim(int item){
        this->ordenada = false;
        particula* inseri;
        inseri = new particula(item);
        if(tam==0)
        {
            this->alfa = inseri;
            this->gama = inseri;
            this->tam++;
        }else{
            inseri->Ligar(gama, inseri);
            this->gama = inseri;
            this->tam++;
        }
    }


    friend ostream& operator<<(std::ostream& saida, lista& entrada){ return saida; }


    void const listarCome(){
        particula* modulo = alfa;
        cout<<"[ ";
        do{
            cout << modulo->getItem() << ", ";
            modulo = modulo->getProx();
        }while(modulo != gama);
        cout << modulo->getItem()<<"]\n";
    }


    void const listarFim(){
        particula* modulo = gama;
        cout<<"[ ";
        do{
            cout << modulo->getItem() << ", ";
            modulo = modulo->getAnt();
        }while(modulo != alfa);
        cout << modulo->getItem()<<"]\n";
    }


    void ordenarAsc(){
        int* vetor, i=0;
        vetor = new int[tam];
        particula* modulo = alfa;
        do{
            vetor[i] = modulo->getItem();
            modulo = modulo->getProx();
            i++;
        }while(modulo != gama);
        vetor[i] = modulo->getItem();
        quick(vetor, tam);
        modulo = gama;
        do{
            modulo->setItem(vetor[i]);
            modulo = modulo->getAnt();
            i--;
        }while(modulo != alfa);
        modulo->setItem(vetor[i]);
    }


    void ordenarDesc(){
        int* vetor, i=0;
        vetor = new int[tam];
        particula* modulo = alfa;
        do{
            vetor[i] = modulo->getItem();
            modulo = modulo->getProx();
            i++;
        }while(modulo != gama);
        vetor[i] = modulo->getItem();
        quick(vetor, tam);
        modulo = gama;
        i=0;
        do{
            modulo->setItem(vetor[i]);
            modulo = modulo->getAnt();
            i++;
        }while(modulo != alfa);
        modulo->setItem(vetor[i]);
    }

private:
    int tam;
    particula* alfa;
    particula* gama;
    bool ordenada;
};
