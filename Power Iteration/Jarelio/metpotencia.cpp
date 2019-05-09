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
            erro_pot = erro;
        }

        float * getAutoVetor(){
            return vetor_pot;
        }

        float getAutoValor(){
            return lambda;
        }

        void executar(){
            executar_p();
        }

    private:
        float * vetor_pot;
        float ** matriz_pot;
        int linha_pot, coluna_pot;
        float lambda,lambdai,erro_pot;

        float * normalize(float * vetor){
            float norma = 0;
            for(int i = 0; i<coluna_pot; i++){
                norma += pow(abs(vetor[i]),2);
            }
            norma = sqrt(norma);
            for(int i = 0; i<coluna_pot; i++){
                vetor[i] = vetor[i]/norma;
            }
            return vetor;
        }

        float * mult_matriz_vetor(float ** matriz, float * vetor){
            float * vetor_result  = (float*)malloc(coluna_pot * sizeof(float));
            for(int i = 0; i<linha_pot; i++){
                for(int j = 0; j<coluna_pot; j++){
                    vetor_result[i] += matriz[i][j]*vetor[j];
                }
            }
            return vetor_result;
        }

        float prod_escalar(float *vetor1, float *vetor2){
            float produto = 0;
            for(int i = 0; i<coluna_pot; i++){
                produto+= vetor1[i]*vetor2[i];
            }
            return produto;
        }

        void executar_p(){
            float * vetor_normalizado = (float*)malloc(coluna_pot * sizeof(float));
            float * vetor2 = (float*)malloc(coluna_pot * sizeof(float));

            vetor_normalizado = normalize(vetor_pot);
            vetor2 = mult_matriz_vetor(matriz_pot,vetor_normalizado);
            lambda = prod_escalar(vetor_normalizado,vetor2);

            do{      
                lambdai = lambda;
                vetor_normalizado = normalize(vetor2);
                vetor2 = mult_matriz_vetor(matriz_pot,vetor_normalizado);
                lambda = prod_escalar(vetor_normalizado,vetor2);
            }while(fabs((lambda - lambdai)/lambda)>erro_pot);
            vetor_pot = vetor_normalizado;
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

    matriz[0][0] = 3;
    matriz[0][1] = 0;
    matriz[0][2] = 0;
    matriz[1][0] = 0;
    matriz[1][1] = 3;
    matriz[1][2] = 2;
    matriz[2][0] = 0;
    matriz[2][1] = -1;
    matriz[2][2] = 0;
    vetor[0] = 1;
    vetor[1] = 1;
    vetor[2] = 1; 
    float erro = 0.000001;

    MetodoPotencia instancia(matriz, vetor, erro, linha, coluna);
    instancia.executar();

    float auto_valor = instancia.getAutoValor();
    float * auto_vetor = instancia.getAutoVetor();

    cout << "Este é o auto valor: " << auto_valor << endl;
    cout << "Este é o auto vetor: ";
    for(int i = 0; i<coluna; i++){
        cout << auto_vetor[i] << " ";
    }
    cout << endl;

    return 0;
}

