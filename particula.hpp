#include <iostream>


class particula{

public:

	particula(int item = 0){
		this->item = item;
		this->ant = NULL;
		this->prox = NULL;
	}

	void Ligar( particula* anterior, particula* atual){
		this->ant = anterior;
		anterior->prox = atual;
	}

	void setItem(int inteiro){
        this->item = inteiro;
	}

	int getItem(){
		return this->item;
	}

	particula* getAnt(){
		return this->ant;
	}

	particula* getProx(){
		return this->prox;
	}

	void revelar(){
        std::cout <<"|| " << ant << "|| "
             << item << "|| "
             << prox << "||\n";
	}

private:
	particula* ant;
	int item;
	particula* prox;
};
