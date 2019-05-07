#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "libmatriz.h"

#define NUM_ELEMENTS(X) (sizeof(X) / sizeof(X[0]))
using namespace std;


int main(void){
    //Dados vetores
    float vetor1[] = {2,2,2};
    float vetor2[] = {2,2,4};
    int tam = NUM_ELEMENTS(vetor1);

    float produto = prod_escalar(vetor1,vetor2,tam);
    float norma = norma_euclidiana(vetor1,tam);
    cout << "Produto escalar: " << produto << endl;
    cout << "Norma euclidiana: " << norma << endl;

    //Dados matrizes (Valores de linha e coluna lidos pelo usuário)
    int linha = 3;
    int coluna = 3;
    float matriz[linha][3] = {{1,2,3},{1,2,3},{1,2,3}};
    float matrizB[linha][3] = {{1,2,3},{1,2,3},{1,2,3}};
    float vetor_result[] = {0,0,0};
    float **result = (float**)malloc(linha*sizeof(float));
    for (int temp = 0; temp < 4; temp++ ) 
        *(result + temp) = (float*)malloc(coluna*sizeof(float));


    mult_matriz_vetor(vetor_result,vetor1,matriz,tam,linha,coluna);
    for(int i = 0; i<3; i++){
        cout << vetor_result[i] << " " << endl;
    }

    cout << "#### Multi Matriz ####" << endl;
    result = mult_matriz_matriz(matriz, matrizB, linha, coluna, 3);
    for(int i = 0; i<linha; i++){
        for(int j = 0; j<coluna; j++){   
           cout << result[i][j] << " ";
        }
        cout << "" << endl;
    }

}

