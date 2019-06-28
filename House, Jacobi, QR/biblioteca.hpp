#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include "../eigenLib/Eigen/Dense"
#include <cmath>
#include <tuple>
using namespace Eigen;
using namespace std;

//Biblioteca.cpp (Funções Auxiliares)

double around(double num);
VectorXd zeros(int size);
double error(Ref<MatrixXd> A); 													
MatrixXd montar_Pij(Ref<MatrixXd> A, int i, int j);
MatrixXd calcular_Pij(Ref<MatrixXd> A, int i, int j);
tuple<MatrixXd, MatrixXd> ordenar_autovetores(Ref<MatrixXd> Matriz_Valor, Ref<MatrixXd> Matriz_Vetor);


//HolseHolder
MatrixXd mountHouseHolder(Ref<MatrixXd> A, int c);
tuple<MatrixXd, MatrixXd> HouseHolder(Ref<MatrixXd> A);

//QR
tuple<MatrixXd, MatrixXd> Decomp_QR(Ref<MatrixXd> A);
tuple<MatrixXd, MatrixXd> QR(Ref<MatrixXd> A, double E, Ref<MatrixXd> H);

//Jacobi
tuple<MatrixXd, MatrixXd> jacobi(Ref<MatrixXd> A, double E, Ref<MatrixXd> H);	

#endif

