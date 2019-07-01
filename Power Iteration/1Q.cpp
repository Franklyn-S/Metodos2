#include "1Q.hpp"
#include <iostream>
using namespace std;

int main(void){
        /*Questão 1: O número de condicionamento de uma matriz simétrica com relação à norma euclidiana
        é a razão do maior autovalor sobre o menor autovalor da matriz, isto é, 
        
        k(A) = max|lambda| / min|lambda|
        
        Determine o número de condicionamento da matriz da Figura 1 usando o método da potência*/

        int tamanho = 5;

        VectorXd matricula(6);
        matricula << 3,9,7,8,4,7;

        // Matriz Arbitrária da Questão 2
        MatrixXf A(tamanho,tamanho);
        A << 
                30+matricula(0)+matricula(5), matricula(0), matricula(1), matricula(2), matricula(3),
                matricula(0), 10+matricula(1)+matricula(4), matricula(4), matricula(5), matricula(0)+matricula(1),
                matricula(1), matricula(4), 50+matricula(2)+matricula(3), matricula(1)+matricula(2), matricula(2)+matricula(3),
                matricula(2), matricula(5), matricula(1)+matricula(2), 40-matricula(0), matricula(3)+matricula(4),
                matricula(3), matricula(0)+matricula(1), matricula(2)+matricula(3), matricula(3)+matricula(4), 60-matricula(1);
        /*
        MatrixXf A(tamanho,tamanho);
        A <<
        40, 3, 9, 7, 8,
        3, 23, 4, 7, 12,
        9, 4, 65, 16, 15,
        7, 7, 16, 37, 12,
        8, 12, 15, 12, 51;
        */
        
        VectorXf vetor_inicial(tamanho);
        vetor_inicial << 1,1,1,1,1;

        float erro = 0.0000000001;

        PotenciaRegular pr = PotenciaRegular(A,vetor_inicial,tamanho,erro);
        PotenciaInversa pi = PotenciaInversa(A,vetor_inicial,tamanho,erro);

        float k_a = 0;

        /*Cálculo do número de condicionamento da matriz A */
        k_a = pr.getAutoValor()/pi.getAutoValor();
        
        /*Resultado*/
        cout << "Matriz A: "<< endl << A << endl;
        cout << "Maior autovalor: " << pr.getAutoValor() << endl;
        cout << "Menor autovalor: " << pi.getAutoValor() << endl;
        cout << "Número de Condicionamento: " << k_a << endl;
}
