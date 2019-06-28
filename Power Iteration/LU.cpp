#include "LU.hpp"
using namespace std;

VectorXf LU::solve(MatrixXf U, VectorXf b, int n){
    int linha = n;
    int coluna = n;
    MatrixXf L(n,n);
    
    L = MatrixXf::Identity(n,n);

    VectorXf y(n);
    VectorXf x(n);
    double m, s, maior, aux; //auxiliares

    //Eliminação
    for (int k = 0; k < n-1; k++){//percorre as colunas
        maior = -numeric_limits<double>::max();//-infinito
        //falta o pivotamento nas iterações
        for (int i = k+1; i < n; i++){ //percorre as linhas
            m = U(i,k)/U(k,k);
            U(i,k) = 0;
            L(i,k) = m;
            for (int j = k+1; j < n; j++){//percorre as linhas calculando seus novos valores
                U(i,j) = U(i,j) - m*U(k,j);
            }
            b[i] = b[i] - m*b[k];
        }
    }

    //resolução do sistema Ly = b	

    y[0] = b[0]/L(0,0);

    for (int k = 1; k < n; k++){//substituição
        s = 0;
        for (int j = k+1; j < n; j++){
            s = s + L(k,j)*y[j];
        }
        y[k] = (b[k]-s)/L(k,k);
    }

    //resolução do sistema Ux = y
    x[n-1] = y[n-1]/U(n-1,n-1);
    
    for (int k = n-2; k >= 0; k--){//substituição retroativa
        s = 0;
        for (int j = k+1; j < n; j++){
            s = s + U(k,j)*x[j];
        }
        x[k] = (y[k]-s)/U(k,k);
    }

    return x;

}