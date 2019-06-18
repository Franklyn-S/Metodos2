#ifndef HOUSEHOLDER_H
#define HOUSEHOLDER_H

Eigen::VectorXd zeros(int size);
Eigen::MatrixXd mountHouseHolder(Eigen::Ref<Eigen::MatrixXd> A, int c);
tuple<Eigen::MatrixXd, Eigen::MatrixXd> HouseHolder(Eigen::Ref<Eigen::MatrixXd> A);


#endif