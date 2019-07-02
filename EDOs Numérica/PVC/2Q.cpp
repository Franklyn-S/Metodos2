#include "2Q.hpp"
#include <iostream>

using namespace std;

int main(void){
    
    VectorXf matricula(6);
    matricula << 3,9,7,8,4,7;
    int A=matricula[0],B=matricula[1],C=matricula[2],D=matricula[3],E=matricula[4],F=matricula[5];
    
    //Numero de Particoes
    int N = 4 + (A + B + C + D + E + F) % 4;
    //Tensao
    int T = (A + B + C);
    //Pressao
    int P = (D + E + F);

    // CCE = Condicão de Contorno Esquerda
    // CCD = Condição de Contorno Direita
    float cce = 0.2, ccd = 0.5;

    //Passo que vai ser dado do comeco da esquerda ate a direita [0,2 ate 0,5 incrementando o deltaR]
    float deltaR = (ccd - cce)/N;

    //Matriz do sistema
    MatrixXf matriz(N-1,N-1);
    matriz = PVC::getMatriz(cce,ccd,deltaR,N);

    //Vetor Y Solução
    VectorXf vetorY(N-1);

    //Vetor P
    VectorXf vetorP(N-1);
    for(int i = 0; i<N-1; i++){
        vetorP[i] = -P/T; 
    }

    cout << "----- Dados da Questão -----" << endl << endl;
    cout << "Número de Partições (N): " << N << endl;
    cout << "Tensão (T): " << T << endl;
    cout << "Pressão Constante (P): " <<  P << endl << endl;
    cout << "Valores de Contorno: " << endl;
        cout << "\tEsquerda: " << cce << endl;
        cout << "\tDireita: " << ccd << endl;
        cout << "\tDelta r: " << deltaR << endl << endl;

    cout << "----- Função Utilizada -----" << endl << endl;
    cout << "T * y''(r) + T/r * y'(r) = -P " << endl;
    cout << "y''(r) + 1/r * y'(r) = -P/T" << endl << endl;

    cout << "----- Sistema Aplicado  (A * y = -P/T) -----" << endl;
    cout << "Matriz: " << endl << endl <<  matriz << endl << endl;
    cout << "Vetor y: " << endl;for(int i = 0; i<N-1; i++){cout << "y"+to_string(i+1) << endl;};cout << endl << endl;
    cout << "Vetor P: " << endl << vetorP << endl << endl;

    //Resolução do Sistema
    
    vetorY = LU::solve(matriz,vetorP,N-1);
    int posicao = 0;

    cout << "----- Solução (Vetor Y) -----" << endl << endl;

    cout << "y(" << cce << ") = y0 = 0" << endl; 

    for(float passo=cce+deltaR; passo<ccd; passo+=deltaR){
        cout << "y(" << passo << ") = y"<< posicao+1 << " = "<< vetorY[posicao] << endl; 
        posicao++;
    }

    cout << "y(" << ccd << ") = y" << N <<" = 0" << endl << endl;
    
    return 0;
}