using namespace std;
#include <stdlib.h>
#include <iostream>
#include <cmath>

class MetodoPotencia{

    public:

        MetodoPotencia(float ** matriz, float * vetor, float erro, int linha, int coluna){
            vetor_pot = vetor;
            matriz_pot = matriz;
            linha_pot = linha;
            coluna_pot = coluna;
        }

    private:
        float * vetor_pot;
        float ** matriz_pot;
        int linha_pot;
        int coluna_pot;

        float * normalize(float * vetor, int coluna){
            float norma = 0;
            for(int i = 0; i<coluna; i++){
                norma += pow(abs(vetor[i]),2);
            }
            norma = sqrt(norma);
            for(int i = 0; i<coluna; i++){
                vetor[i] = vetor[i]/norma;
            }
            return vetor;
        }

        float * mult_matriz_vetor(float * vetor, float ** matriz, int linha, int coluna){
            float * vetor_result  = (float*)malloc(coluna * sizeof(float));
            for(int i = 0; i<linha; i++){
                for(int j = 0; j<coluna; j++){
                    vetor_result[i] += matriz[i][j]*vetor[j];
                }
            }
            return vetor_result;
        }

};

int main(){

    int linha;
    int coluna;
    linha = 3;
    coluna = 3;

    float ** matriz = (float**)malloc(linha * sizeof(float));
    for (int i = 0; i < linha; i++ ){
        matriz[i] = (float*) malloc(coluna * sizeof(float));
    }
    
    float * vetor = (float*)malloc(coluna * sizeof(float));

    matriz[0][0] = 1;
    matriz[0][1] = 2;
    matriz[0][2] = 3;
    matriz[1][0] = 1;
    matriz[1][1] = 2;
    matriz[1][2] = 3;
    matriz[2][0] = 1;
    matriz[2][1] = 2;
    matriz[2][2] = 3;
    vetor[0] = 0;
    vetor[1] = 0;
    vetor[2] = 0; 
    float erro = 0.001;

    MetodoPotencia instancia(matriz, vetor, erro, linha, coluna);

    return 0;
}

