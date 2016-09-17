#include <iostream>
#include "particula.hpp"
#include "quick.hpp"

using namespace std;

class lista{

public:

    void mostrar(){
    particula* modulo = alfa;
        do{
            cout<< modulo<<"||";
            modulo->revelar();
            modulo = modulo->getProx();
        }while(modulo != gama);
        cout<< gama<<"||"; gama->revelar();
    }

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
        quick(alfa, tam, gama);
    }

private:
    int tam;
    particula* alfa;
    particula* gama;
    bool ordenada;
};
