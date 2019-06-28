#ifndef POTENCIADESLOCAMENTO_H
#define POTENCIADESLOCAMENTO_H
#include "eigen/Eigen/Core"
#include "PotenciaInversa.hpp"
using namespace Eigen;

class PotenciaDeslocamento{
    
    public:
        PotenciaDeslocamento(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro, float chute);
        VectorXf getAutoVetor();
        float getAutoValor();
    
    private:
        VectorXf autovetor;
        float autovalor;

        void executar(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro, float chute);
};

#endif //POTENCIADESLOCAMENTO_H