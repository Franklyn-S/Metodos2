#include "ProgramaPrincipal.hpp"
#include <iostream>
using namespace std;

int main(void){

    /*Inicialização */

    int tamanho = 3;

    Vector3f vetor_inicial(1,1,1);
    cout << "Vetor inicial" << endl << vetor_inicial << endl;

    MatrixXf matriz_inicial(tamanho,tamanho);
    matriz_inicial << (Matrix3f() << 3,0,0,0,3,2,0,-1,0).finished();
    cout << "Matriz inicial" << endl << matriz_inicial << endl;
    
    float erro = 0.0000000001;
    float chute = 2.1;
    
//--------------------------------------------------------------------------------------

    cout << endl << "Método da Potência Regular: " << endl;

    /*Execução do Método de Potência Regular*/
    PotenciaRegular pr(matriz_inicial,vetor_inicial,tamanho,erro);
    cout << endl << "Auto valor: " << pr.getAutoValor() << endl;
    cout << "Auto vetor: " << endl << pr.getAutoVetor() << endl;

//--------------------------------------------------------------------------------------

    cout << endl << "Método da Potência Inversa: " << endl;

    /*Execução do Método da Potência Inversa*/
    PotenciaInversa pi(matriz_inicial,vetor_inicial,tamanho,erro);
    cout << endl << "Auto valor: " << pi.getAutoValor() << endl;
    cout << "Auto vetor: " << endl << pi.getAutoVetor() << endl;   

//--------------------------------------------------------------------------------------
    cout << endl << "Método da Potência com Deslocamento: " << endl;

    /*Execução do Método da Potência com Deslocamento*/
    PotenciaDeslocamento pd(matriz_inicial,vetor_inicial,tamanho,erro,chute);
    cout << endl << "Auto valor: " << pd.getAutoValor() << endl;
    cout << "Auto vetor: " << endl << pd.getAutoVetor() << endl; 

//--------------------------------------------------------------------------------------
    return 0;
}

    