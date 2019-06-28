#include "PotenciaInversa.hpp"
using namespace std;

PotenciaInversa::PotenciaInversa(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro){  
     this->executar(matriz_inicial,vetor_inicial,tamanho,erro);
}

VectorXf PotenciaInversa::getAutoVetor(){
    return this->autovetor;
}

float PotenciaInversa::getAutoValor(){
    return this->autovalor;
}

void PotenciaInversa::executar(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro){
    /*Inicialização Método da Potência Inversa */

        VectorXf x_old(tamanho);
        VectorXf y_new(tamanho);
        VectorXf x_new(tamanho);
        float lambda_novo;
        float lambda_antigo;

    /* Metodo da Potência Inversa */

        lambda_novo = 0;
        x_old = vetor_inicial.normalized();

        do{      
            lambda_antigo = lambda_novo;
            y_new = LU::solve(matriz_inicial,x_old,tamanho);
            x_new = y_new.normalized();
            lambda_novo = x_old.transpose()*y_new;
            x_old = x_new;
        }while(fabs((lambda_novo - lambda_antigo)/lambda_novo)>erro);

        //cout << "Auto vetor: " << endl << x_new << endl;
        //cout << "Auto valor: " << endl << 1/lambda_novo << endl;
        this->autovalor = (1/lambda_novo);
        this->autovetor = x_new;
}