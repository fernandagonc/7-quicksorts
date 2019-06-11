#include <iostream>
#include <cstdlib>

#define MAX 500000
//https://www.geeksforgeeks.org/stack-data-structure-introduction-program/

struct Item{
    int esq;
    int dir;
};

class Pilha{
	int top;

    public:
        Pilha();
		Item vetor[MAX];

        void empilha(struct Item item);
        void desempilha(struct Item *item);
        int getTamanho();
        bool isVazia();
};

Pilha::Pilha(){top = -1;}

int Pilha::getTamanho(){
	return top + 1;
}

bool Pilha::isVazia(){
	return top < 0;
}

void Pilha::empilha(struct Item x){
	top += 1;
	vetor[top].dir = x.dir;
	vetor[top].esq = x.esq;
}

void Pilha::desempilha(struct Item *item){
	if(this->isVazia())
		return;

	*item = vetor[top--];
	
}

