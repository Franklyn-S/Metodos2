#include <stdlib.h>
#include <iostream>
#include <cmath>
#define NUM_ELEMENTS(X) (sizeof(X) / sizeof(X[0]))
using namespace std;

float prod_escalar(float *vetor1, float *vetor2, int tamanho);
float norma_euclidiana(float *vetor, int tamanho);
void mult_matriz_vetor(float* vetor_result, float *vetor, float matriz[][3], int tamanho, int linha, int coluna);
float** mult_matriz_matriz(float A[][3], float B[][3],  int linhaA, int colunaA, int colunaB);

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
