#ifndef POTENCIAINVERSA_H
#define POTENCIAINVERSA_H
#include "eigen/Eigen/Core"
#include "LU.hpp"
using namespace Eigen;

class PotenciaInversa{
    
    public:
        PotenciaInversa(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro);
        VectorXf getAutoVetor();
        float getAutoValor();
    
    private:
        VectorXf autovetor;
        float autovalor;

        void executar(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro);
};

#endif //POTENCIAINVERSA_H