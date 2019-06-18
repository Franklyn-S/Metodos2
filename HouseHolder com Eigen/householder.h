#ifndef HOUSEHOLDER_H
#define HOUSEHOLDER_H
#include <iostream>
#include <tuple>
#include "../eigenLib/Eigen/Dense"
using namespace Eigen;
using namespace std;

VectorXd zeros(int size);
MatrixXd mountHouseHolder(Ref<MatrixXd> A, int c);
tuple<MatrixXd, MatrixXd> HouseHolder(Ref<MatrixXd> A);

#endif