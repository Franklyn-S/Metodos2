#include "householder.h"

// Creates a vector of zeros
VectorXd zeros(int size){
	VectorXd v(size);
	for (int i = 0; i < size; i++)
	{
		v(i) = 0;
	}
	return v;
}

MatrixXd mountHouseHolder(Ref<MatrixXd> A, int c){
	
	//vetor v <- 0
	int rows = A.rows();
	int cols = A.cols();

	VectorXd v(rows);
	v = zeros(rows);

	//v(c+1:n) <- A(c+1:N,c)
	for (int i = c+1; i < rows; i++)
	{
		v(i) = A(i,c);
	}
	//l_v <- ||v||
	double l_v = v.norm();
	// Verifica se o elemento abaixo de c é positivo,
	// se for, muda o sinal da norma de v
	if (v(c+1) > 0) l_v = -1*l_v;

	//vetor v' <- 0
	VectorXd vLine(rows);
	vLine = zeros(rows);

	//v'(c+1) <- l_v
	vLine(c+1) = l_v;

	VectorXd N(rows);
	N = v - vLine;

	//n <- N/||N||
  	VectorXd n(rows);
  	n = N/N.norm();


  	// Construindo Matriz Identidade
	MatrixXd I(rows, cols);
	I = MatrixXd::Identity(rows, cols);

	// Construindo Matriz H
	MatrixXd H(rows, cols);
	H = I - 2*n*n.transpose();

	return H;
};

//retorna uma matriz tridiagonal e uma matriz acumulada das operações
tuple<MatrixXd, MatrixXd> HouseHolder(Ref<MatrixXd> A){
	
	int rows = A.rows();
	int cols = A.cols();
	//A' <- A
	MatrixXd ALine(rows, cols);
	ALine = A;
	//H' = I
	MatrixXd H(rows, cols);
	H = MatrixXd::Identity(rows, cols);

	MatrixXd Hc(rows, cols);
	for (int c = 0; c < rows-2; c++)
	{	
		Hc = mountHouseHolder(ALine, c);
		ALine = Hc * ALine * Hc;
		//cout << "Matriz " + c << endl << ALine << endl;
		H = H * Hc; 
	}

	return make_tuple(ALine, H);
}

