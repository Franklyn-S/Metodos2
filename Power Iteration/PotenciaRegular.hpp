#ifndef POTENCIAREGULAR_H
#define POTENCIAREGULAR_H
#include "../eigenLib/Eigen/Core"
using namespace Eigen;

class PotenciaRegular{
    
    public:
        PotenciaRegular(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro);
        VectorXf getAutoVetor();
        float getAutoValor();
    
    private:
        VectorXf autovetor;
        float autovalor;

        void executar(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro);
};

#endif //POTENCIAREGULAR_H