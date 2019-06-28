#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include "../eigenLib/Eigen/Dense"
#include <cmath>
#include <tuple>
using namespace Eigen;
using namespace std;

//Biblioteca.cpp (Funções Auxiliares)
double error(Ref<MatrixXd> A); 													
void around(Ref<MatrixXd> Matriz);
void ordenar(Ref<MatrixXd> Matriz_Valor, Ref<MatrixXd> Matriz_Vetor);
void sqrt_diagonal(Ref<MatrixXd> M);
VectorXd zeros(int size);
MatrixXd montar_Pij(Ref<MatrixXd> A, int i, int j);
MatrixXd calcular_Pij(Ref<MatrixXd> A, int i, int j);

//HolseHolder
MatrixXd mountHouseHolder(Ref<MatrixXd> A, int c);
tuple<MatrixXd, MatrixXd> HouseHolder(Ref<MatrixXd> A);

//QR
tuple<MatrixXd, MatrixXd> Decomp_QR(Ref<MatrixXd> A);
tuple<MatrixXd, MatrixXd> QR(Ref<MatrixXd> A, double E, Ref<MatrixXd> H);

//Jacobi
tuple<MatrixXd, MatrixXd> jacobi(Ref<MatrixXd> A, double E, Ref<MatrixXd> H);	

#endif

