#include "PVC.hpp"

MatrixXf PVC::getMatriz(float cce, float ccd, float deltaR, int N){
    
    MatrixXf matriz(N-1,N-1);
    
    //Zerando a matriz
    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<N-2; j++){
            matriz(i,j) = 0;
        }
    }

    //Montando a matriz usando as derivadas centrais
    int equacao = 0;
    for(float passo=cce+deltaR; passo<ccd; passo+=deltaR){
        if(equacao==0){
            matriz(equacao,equacao) = -2/(deltaR*deltaR);
            matriz(equacao,equacao+1) = (1/(deltaR*deltaR)) + (1/(2*passo*deltaR));
        }else
        if(equacao==N-2){
            matriz(equacao,equacao) = -2/(deltaR*deltaR); 
            matriz(equacao,equacao-1) = (1/(deltaR*deltaR)) - (1/(2*passo*deltaR));
        }else{
            matriz(equacao,equacao) = -2/(deltaR*deltaR);
            matriz(equacao,equacao-1) = (1/(deltaR*deltaR)) - (1/(2*passo*deltaR));
            matriz(equacao,equacao+1) = (1/(deltaR*deltaR)) + (1/(2*passo*deltaR));

        }

        equacao++;
    }

    return matriz;
}