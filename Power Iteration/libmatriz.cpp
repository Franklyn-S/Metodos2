#include <stdlib.h>
#include <cmath>
#include "libmatriz.h"

/*Percorre os vetores multiplicando os elementos e somando em produto, no caso seria um vetor linha
e um vetor coluna, então na hora de implementar é só transformar a matriz no vetor correspondente*/
float prod_escalar(float *vetor1, float *vetor2, int tamanho){
    float produto = 0;
    for(int i = 0; i<tamanho; i++){
        produto+= vetor1[i]*vetor2[i];
    }
    return produto;
}

/*Norma euclidiana é a raiz do somatório dos módulos ao quadrado dos elementos do vetor
    ||x||2 = sqrt(somatorio(|xi|^2)) */
float norma_euclidiana(float *vetor, int tamanho){
    float norma = 0;
    for(int i = 0; i<tamanho; i++){
        norma += pow(abs(vetor[i]),2);
    }
    norma = sqrt(norma);
    return norma;
}

void mult_matriz_vetor(float *vetor_result, float *vetor, float matriz[][3], int tamanho, int linha, int coluna){
    for(int i = 0; i<linha; i++){
        for(int j = 0; j<coluna; j++){
            vetor_result[i] += matriz[i][j]*vetor[j];
        }
    }
}
//colunaA == linhaB
float** mult_matriz_matriz(float A[][3], float B[][3],  int linhaA, int colunaA, int colunaB){
    float soma = 0.0;
    
    float **result = (float**)malloc(linhaA*sizeof(float));
    for (int temp = 0; temp < 4; temp++ ) 
        *(result + temp) = (float*)malloc(colunaB*sizeof(float));

    for (int i = 0; i<linhaA; i++){
        for (int j = 0; j<colunaB; j++){
            soma = 0.0;
            for (int k = 0; k<colunaA; k++){
                soma += A[i][k] * B[k][j];
            }
            result[i][j] = soma;
        }
    }
    return result;
}
