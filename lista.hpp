#include <iostream>
#include <sstream>
#include "particula.hpp"
#include "quick.hpp"

using namespace std;

class lista{

public:

    void const mostrar(){
    particula* modulo = alfa;
        do
        {
            cout<< modulo << "||";
            modulo->revelar();
            modulo = modulo->getProx();
        }while(modulo != gama);
        cout<< gama <<"||"; gama->revelar();
    }

    void inserirfim(int item){
        this->ordenada = false;
        particula* inseri;
        inseri = new particula(item);
        if(tam == 0)
        {
            this->alfa = inseri;
            this->gama = inseri;
            this->tam++;
        }else
        {
            inseri->Ligar(gama, inseri);
            this->gama = inseri;
            this->tam++;
        }
    }

    string const listarFim(){
        stringstream saida;
        particula* modulo = gama;
        saida << "[ ";
        do
        {
            saida << modulo->getItem() << ", ";
            modulo = modulo->getAnt();
        }while(modulo != alfa);
        saida << modulo->getItem() << "] ";
        return saida.str();
    }


    friend ostream& operator<<(std::ostream& saida, lista& entrada){
        saida << entrada.listarCome();
        return saida;
    }



    void ordenarAsc(){
        quick(alfa, tam, gama);
    }
private:
    int tam;
    particula* alfa;
    particula* gama;
    bool ordenada;

    string const listarCome(){
        stringstream saida;
        particula* modulo = alfa;
        saida << "[ ";
        do
        {
            saida << modulo->getItem() << ", ";
            modulo = modulo->getProx();
        }while(modulo != gama);
        saida << modulo->getItem() << "] ";
        return saida.str();
    }



};
