#include "PotenciaRegular.hpp"
using namespace std;

PotenciaRegular::PotenciaRegular(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro){  
     this->executar(matriz_inicial,vetor_inicial,tamanho,erro);
}

VectorXf PotenciaRegular::getAutoVetor(){
    return this->autovetor;
}

float PotenciaRegular::getAutoValor(){
    return this->autovalor;
}

void PotenciaRegular::executar(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro){
     /*Inicialização Método da Potência Regular */

        VectorXf vetor_normalizado(tamanho);
        VectorXf vetor2(tamanho);
        float lambda;
        float lambdai;

    /* Metodo da Potência Regular */

        vetor_normalizado = vetor_inicial.normalized();
        vetor2 = matriz_inicial*vetor_normalizado;
        lambda = vetor_normalizado.transpose()*vetor2;

        do{      
            lambdai = lambda;
            vetor_normalizado = vetor2.normalized();
            vetor2 = matriz_inicial*vetor_normalizado;
            lambda = vetor_normalizado.transpose()*vetor2;
        }while(fabs((lambda - lambdai)/lambda)>erro);

        //cout << "Auto vetor: " << endl << vetor2 << endl;
        //cout << "Auto valor: " << endl << lambda << endl;
        this->autovalor = lambda;
        this->autovetor = vetor2;
}