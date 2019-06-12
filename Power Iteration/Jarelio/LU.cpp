#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <limits>
using namespace std;



class LU
{
public:
	float * calculate(float ** U, float * b, int n);

};

float * LU::calculate(float ** U, float * b, int n)
{
	int linha = 3;
    int coluna = 3;
	float ** L = (float**)malloc(linha * sizeof(float));
    for (int i = 0; i < linha; i++ ){
        L[i] = (float*) malloc(coluna * sizeof(float));
    }

    L[0][0] = 1;
    L[0][1] = 0;
    L[0][2] = 0;
    L[1][0] = 0;
    L[1][1] = 1;
    L[1][2] = 0;
    L[2][0] = 0;
    L[2][1] = 0;
    L[2][2] = 1;


	float *y = (float*)malloc(n * sizeof(float)); //vetor auxiliar y
	float *x = (float*)malloc(n * sizeof(float)); //vetor resposta x
	double m, s, maior, aux; //auxiliares


	

	//Eliminação
	for (int k = 0; k < n-1; k++){//percorre as colunas
		maior = -numeric_limits<double>::max();//-infinito
		//falta o pivotamento nas iterações
		for (int i = k+1; i < n; i++){ //percorre as linhas
			m = U[i][k]/U[k][k];
			U[i][k] = 0;
			L[i][k] = m;
			for (int j = k+1; j < n; j++){//percorre as linhas calculando seus novos valores
				U[i][j] = U[i][j] - m*U[k][j];
			}
			b[i] = b[i] - m*b[k];
		}
	}


	//resolução do sistema Ly = b	

	y[0] = b[0]/L[0][0];


	for (int k = 1; k < n; k++){//substituição
		s = 0;
		for (int j = k+1; j < n; j++){
			s = s + L[k][j]*y[j];
		}
		y[k] = (b[k]-s)/L[k][k];
	}



	//resolução do sistema Ux = y
	x[n-1] = y[n-1]/U[n-1][n-1];
	
	for (int k = n-2; k >= 0; k--){//substituição retroativa
		s = 0;
		for (int j = k+1; j < n; j++){
			s = s + U[k][j]*x[j];
		}
		x[k] = (y[k]-s)/U[k][k];
	}

	return x;

}

int main(int argc, char const *argv[]){
	int tamanho = 3;

    int linha = 3;
    int coluna = 3;

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
    //float erro = 0.000001;
	
	LU lu;

	float *x = lu.calculate(matriz, vetor, tamanho);
	

	//imprimir x
	cout << "Vetor resposta:" << endl;
	for (int i = 0; i < 3; i++){
		cout << x[i] << endl;
	}
	return 0;
}