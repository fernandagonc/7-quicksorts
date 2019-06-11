#include <iostream>

void particaoQM3(int esq, int dir, int *i, int *j, int vetor[], int *n_comp, int *n_mov){
    int meio = (esq + dir) / 2;
    int a = vetor[esq], b = vetor[meio], c = vetor[dir];
    int medianaIndice; 
    //define o pivo de acordo com a especificação do trabalho para o quicksort 
    //verifica qual é o indice da mediana
    (*n_comp)++;
    if (a < b) {
        (*n_comp)++;
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            (*n_comp)++;
            if (a < c) {
                //a < c && c <= b
                medianaIndice = dir;
            } else {
                //c <= a && a < b
                medianaIndice = esq;
            }
        }
    } else {
        (*n_comp)++;
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            (*n_comp)++;
            if (c < a) {
                //b <= c && c < a
                medianaIndice = dir;
            } else {
                //b <= a && a <= c
                medianaIndice = esq;
            }
        }
    }
    int aux;
    int pivo = vetor[medianaIndice];
    *i = esq; *j = dir;

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

void QM3(int esq, int dir, int vetor[], int *n_comp, int *n_mov){ 
    int i, j;
    particaoQM3(esq, dir, &i, &j, vetor, n_comp, n_mov);

    if(esq < j)
        QM3(esq, j, vetor, n_comp, n_mov);
    if(i < dir)
        QM3(i, dir, vetor, n_comp, n_mov);

}