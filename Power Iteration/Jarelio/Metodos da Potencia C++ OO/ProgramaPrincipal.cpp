#include "ProgramaPrincipal.hpp"
#include <iostream>
using namespace std;

int main(void){

    /*Inicialização */

    int tamanho = 5;

    VectorXf vetor_inicial(tamanho);
    vetor_inicial << 1,1,1,1,1;
    cout << "Vetor inicial" << endl << vetor_inicial << endl;

    MatrixXf matriz_inicial(tamanho,tamanho);
    matriz_inicial <<   40,3,9,7,8,
                        3,23,4,7,12,
                        9,4,65,16,15,
                        7,7,16,37,12,
                        8,12,15,12,51;
    cout << "Matriz inicial" << endl << matriz_inicial << endl;
    
    float erro = 0.0000000001;
    
    
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
    float chute = ((pr.getAutoValor()+pi.getAutoValor())/2)+1; //proximo ao valor do autovalor central
    /*Execução do Método da Potência com Deslocamento*/
    PotenciaDeslocamento pd(matriz_inicial,vetor_inicial,tamanho,erro,chute);
    cout << endl << "Auto valor: " << pd.getAutoValor() << endl;
    cout << "Auto vetor: " << endl << pd.getAutoVetor() << endl; 
    
    /*Mais autovalores
    for(float contador = pi.getAutoValor()+1; contador<=pr.getAutoValor(); contador = contador + 10){
        PotenciaDeslocamento pd(matriz_inicial,vetor_inicial,tamanho,erro,contador);
        cout <<"Chute: "<< contador << " - Auto valor: " << pd.getAutoValor() << endl;
    }
    */
//--------------------------------------------------------------------------------------
    return 0;
}

    