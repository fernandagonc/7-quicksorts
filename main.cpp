#include <iostream>
#include<string>
#include <iomanip>
#include <chrono>
#include <ctime>    // time()
#include <cstdlib>  // srand() and rand()
#include "QPE.hpp"
#include "QM3.hpp"
#include "QC.hpp"
#include "QI.hpp"
#include "QNR.hpp"

int main (int argc, char **argv){

    if(argc < 4){
        std::cout << "Número de parâmetros insuficiente" << "\n";
        return -1;
    }
    

    srand(time(0));
    int i, valor;
    int n_comp = 0, n_mov = 0;
    int tamanho = std::stoi(argv[3]);
    int vetor[tamanho];
    int guardarVetor[tamanho];
    int esq = 0, dir = tamanho-1;


    if (std::string(argv[2]) == "Ale"){
        for (i=0; i < tamanho; i++){
            valor = (rand() % tamanho) + 1;
            vetor[i] = valor;
        }
    }
    else if(std::string(argv[2]) == "OrdC"){
        for (i=0; i < tamanho; i++){
            vetor[i] = i;
        }
    }
    else if(std::string(argv[2]) == "OrdD"){
        for (i = tamanho-1; i >= 0; i--){
                vetor[i] = tamanho - i;
            }        
    }
    
    if(argc == 5){
        if(std::string(argv[4]) == "-p"){
            for (i=0; i < tamanho; i++){
                 guardarVetor[i] = vetor[i];
            }
        }
    }

    auto start = std::chrono::system_clock::now();

    if (std::string(argv[1]) == "QC") QC(esq, dir, vetor, &n_comp, &n_mov);
    else if(std::string(argv[1]) == "QPE") QPE(esq, dir, vetor, &n_comp, &n_mov);
    else if(std::string(argv[1]) == "QM3") QM3(esq, dir, vetor, &n_comp, &n_mov);
    else if(std::string(argv[1]) == "QI1") QI(esq, dir, vetor, tamanho, 0.01, &n_comp, &n_mov);
    else if(std::string(argv[1]) == "QI5")  QI(esq, dir, vetor, tamanho, 0.05, &n_comp, &n_mov);
    else if(std::string(argv[1]) == "QI10") QI(esq, dir, vetor, tamanho, 0.10, &n_comp, &n_mov);
    else if(std::string(argv[1]) == "QNR") QNR(esq, dir, vetor, &n_comp, &n_mov);

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> tempo = end-start;
    double segundos = tempo.count();
    
    std::cout <<  std::string(argv[1]) << " " << std::string(argv[2]) << " " << tamanho << " " <<
        n_comp << " " << n_mov << " " << segundos * 1000000 << "\n";
    
    if(argv[4]){
        for (i=0; i < tamanho; i++){
            std::cout << guardarVetor[i] << " ";
        }
        std::cout << "\n";
    }

}