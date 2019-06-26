#include "biblioteca.h"


// Creates a vector of zeros
VectorXd zeros(int size){
	VectorXd v(size);
	for (int i = 0; i < size; i++)
	{
		v(i) = 0;
	}
	return v;
}

double error(Ref<MatrixXd> A){
	double soma = 0;
	for (int i = 0; i < A.rows(); ++i)
		for (int j = 0; j < A.cols(); ++j)
			if(i!=j) soma += pow(A(i,j),2);
	return sqrt(soma);
}

MatrixXd montar_Pij(Ref<MatrixXd> A, int i, int j){
  	// Construindo Matriz Identidade
  	int size  = A.rows();
	MatrixXd Pij(size, size);
	Pij = MatrixXd::Identity(size, size);

	double t_aux = atan(A(i,j)/A(j,j));
	double teta = (A(i,i) == A(j,j)) ? (M_PI/4) : t_aux;
	
	Pij(i,i) = cos(teta);
	Pij(j,j) = cos(teta);
	Pij(i,j) = sin(teta);
	Pij(j,i) = -sin(teta);
	
	return Pij;
}

MatrixXd calcular_Pij(Ref<MatrixXd> A, int i, int j){
  	// Construindo Matriz Identidade
  	int size  = A.rows();
	MatrixXd Pij(size, size);
	Pij = MatrixXd::Identity(size, size);

	double t_aux = (0.5*atan( 2*A(i,j) / (A(j,j)-A(i,i)) ));
	double teta = (A(i,i) == A(j,j)) ? (M_PI/4) : t_aux;
	
	Pij(i,i) = cos(teta);
	Pij(j,j) = cos(teta);
	Pij(i,j) = sin(teta);
	Pij(j,i) = -sin(teta);
	
	return Pij;
}