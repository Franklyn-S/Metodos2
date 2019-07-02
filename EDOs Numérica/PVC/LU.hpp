#ifndef LU_H
#define LU_H
#include "../../eigenLib/Eigen/Core"
using namespace Eigen;

class LU{
    public:
        LU();
        static VectorXf solve(MatrixXf U, VectorXf b, int n);

};

#endif //LU_H