#include <iostream>
#include "pilha.hpp"

void particaoQNR(int esq, int dir, int* vetor, int *i, int *j, int *n_comp, int *n_mov){
    *i = esq; *j = dir;
    int pivo = vetor[(*i + *j)/2]; 
    int aux;
    
    do{
        while (pivo > vetor[*i]){//identifica o indice do primeiro elemento do lado esquerdo que é maior do que o pivo (elemento A)
            (*n_comp)++;
            (*i)++; 
        } 
        
        while (pivo < vetor[*j]){//identifica o indice do primeiro elemento do lado direito que é menor do que o pivo (elemento B)
            (*n_comp)++; 
            (*j)--;
        } 
        
        (*n_comp)++; 
        if (*i <= *j){//se os indices i e j não se cruzaram, então troca-se os elementos A e B
            if(*i < *j)(*n_mov)++; // não aumentamos o número de movimentações quando i == j, pois significa que a troca é com o próprio elemento 
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;

            (*i)++; (*j)--;
        }
    
    } while (*i <= *j);// fazemos as trocas enquanto os indices i e j não se cruzam
}

void QNR(int esq, int dir, int *vetor, int *n_comp, int *n_mov){ 
    Pilha pilha;
    int i, j;

    struct Item item;
    struct Item auxItem;
    item.dir = dir;
    item.esq = esq;
    
    pilha.empilha(item);
    
    do{
        if(dir > esq){ //verifica-se se o subvetor é válido (possui elementos)
            particaoQNR(esq, dir, vetor, &i, &j, n_comp, n_mov); //particionamos esse vetor e ordenamos essa parte
            if ((j-esq) > (dir - i)){ //verificamos qual das particoes é maior 
                item.dir = j;
                item.esq = esq;
                pilha.empilha(item); //empilhamos essa particao
                esq = i;
            }
            else{
                item.dir = dir;
                item.esq = i;
                pilha.empilha(item);
                dir = j;
            }
        }
        else{
            pilha.desempilha(&auxItem); //após ordenar o subvetor, desempilhamos o que não está ordenado
            esq = auxItem.esq;
            dir = auxItem.dir;
        }

    }while(!pilha.isVazia()); //enquanto há elementos na pilha, existem subvetores desordenados

} 
