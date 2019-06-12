#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main(){

    /*Inicialização */

    int tamanho = 3;

    Vector3f vetor_inicial(1,1,1);
    cout << "Vetor inicial" << endl << vetor_inicial << endl;

    MatrixXf matriz_inicial(tamanho,tamanho);
    matriz_inicial << (Matrix3f() << 3,0,0,0,3,2,0,-1,0).finished();
    cout << "Matriz inicial" << endl << matriz_inicial << endl;

    float erro =  0.0000000001;

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

        cout << "Auto vetor: " << endl << vetor2 << endl;
        cout << "Auto valor: " << endl << lambda << endl;

    return 0;
}