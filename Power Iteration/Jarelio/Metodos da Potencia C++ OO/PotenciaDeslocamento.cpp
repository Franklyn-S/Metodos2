#include "PotenciaDeslocamento.hpp"
using namespace std;

PotenciaDeslocamento::PotenciaDeslocamento(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro, float chute){  
     this->executar(matriz_inicial,vetor_inicial,tamanho,erro,chute);
}

VectorXf PotenciaDeslocamento::getAutoVetor(){
    return this->autovetor;
}

float PotenciaDeslocamento::getAutoValor(){
    return this->autovalor;
}

void PotenciaDeslocamento::executar(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro, float chute){
    /*Inicialização Método da Potência com Deslocamento */

    MatrixXf matrizbarra(tamanho,tamanho);
    MatrixXf I(tamanho,tamanho);
    VectorXf xn(tamanho);
    VectorXf xi(tamanho);
    I = MatrixXf::Identity(tamanho,tamanho);
    float lambdan;
    float lambdai;

    /* Metodo da Potência com Deslocamento */

    matrizbarra = matriz_inicial - (chute*I);
    PotenciaInversa pid(matrizbarra,vetor_inicial,tamanho,erro);
    lambdan = pid.getAutoValor();
    xn = pid.getAutoVetor();
    lambdai = lambdan + chute;
    xi = xn;
    //cout << "Auto vetor: " << endl << xi << endl;
    //cout << "Auto valor: " << endl << lambdai << endl;
    this->autovalor = lambdai;
    this->autovetor = xi;
}