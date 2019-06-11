#include <iostream>
/*O processo de partição é interrompido quando o subvetor tiver menos
de k = 1% chaves. A partição então deve ser ordenada usando uma implementação especial
do algoritmo de ordenação por inserção, preparada para ordenar um subvetor. Seleção de pivô
usando a “mediana de três” elementos, descrita acima.*/

void insercao(int *v, int tamanho, int *n_comp, int *n_mov) {
    int i,j;
    int aux[tamanho];
    for (i = 1; i < tamanho; i++) {
        aux[i] = v[i]; // elemento a ser colocado na posição certa
        j = i - 1; // recebe o número de elementos à esquerda do elemento aux[i] 
        while (( j >= 0 ) && (aux[i] < v[j])) {  // enquanto houverem posições à esquerda e aux[i] for menor que os elementos à esquerda dele 
            (*n_comp)++;                            
            (*n_mov)++;                            
            v[j + 1] = v[j];                     //movimentamos o elemento imediatamente à esquerda de aux[i] para direita
            j--;                                    
            v[j + 1] = aux[i];                    //colocamos aux[i] uma posição mais à esquerda
        }
    }
}

void particaoQI(int esq, int dir, int *i, int *j, int vetor[], int *n_comp, int *n_mov){
    *i = esq; *j = dir;
    int aux;
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
    
    int pivo = vetor[medianaIndice];
    
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

void QI(int esq, int dir, int vetor[], int tamanho, float porcentagem, int *n_comp, int *n_mov){ 
    int i, j;
    int tamanhoPart = (dir-esq) + 1;
    static int tamanhoInicial; 
    
    if (tamanhoPart == tamanho){ //inicializa o tamanho inicial do vetor apenas na primeira chamada recursiva 
        tamanhoInicial = tamanho; // ou seja, quando a particao é o proprio vetor
    }

    if(tamanhoPart > porcentagem * tamanhoInicial){
        particaoQI(esq, dir, &i, &j, vetor, n_comp, n_mov);
    
        if(esq < j)
            QI(esq, j, vetor,tamanho, porcentagem, n_comp, n_mov);
        if(i < dir)
            QI(i, dir, vetor, tamanho, porcentagem, n_comp, n_mov);
    } 
    else {
        insercao(&vetor[esq], tamanhoPart, n_comp, n_mov);
    }
    
} 