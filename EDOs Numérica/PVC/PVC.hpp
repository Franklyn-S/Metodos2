#ifndef PVC_H
#define PVC_H
#include "../../eigenLib/Eigen/Core"
using namespace Eigen;

class PVC{
    public:
        PVC();
        static MatrixXf getMatriz(float cce, float ccd, float deltaR, int N);

};

#endif //PVC_H