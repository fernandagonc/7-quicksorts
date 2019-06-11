#include <iostream>

void particaoQPE(int esq, int dir, int *i, int *j, int vetor[], int *n_comp, int *n_mov){
    *i = esq; *j = dir;
    int pivo = vetor[esq];
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

void QPE(int esq, int dir, int vetor[], int *n_comp, int *n_mov){ 
    int i, j;
    particaoQPE(esq, dir, &i, &j, vetor, n_comp, n_mov);

    if(esq < j)
        QPE(esq, j, vetor, n_comp, n_mov);
    if(i < dir)
        QPE(i, dir, vetor, n_comp, n_mov);

} 
