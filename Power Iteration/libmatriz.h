#ifndef LIBMATRIZ_H
#define LIBMATRIZ_H

float prod_escalar(float *vetor1, float *vetor2, int tamanho);
float norma_euclidiana(float *vetor, int tamanho);
void mult_matriz_vetor(float* vetor_result, float *vetor, float matriz[][3], int tamanho, int linha, int coluna);
float** mult_matriz_matriz(float A[][3], float B[][3],  int linhaA, int colunaA, int colunaB);

#endif
