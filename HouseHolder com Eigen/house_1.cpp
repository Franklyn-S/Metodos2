#include <iostream>
#include <tuple>
#include "../eigenLib/Eigen/Dense"
using namespace Eigen;
using namespace std;

//g++ -I eigen house_1.cpp -o house -std=c++11

// Creates a vector of zeros
Eigen::VectorXd zeros(int size){
	VectorXd v(size);
	for (int i = 0; i < size; i++)
	{
		v(i) = 0;
	}
	return v;
}



Eigen::MatrixXd mountHouseHolder(Eigen::Ref<Eigen::MatrixXd> A, int c, int size){
	
	//vetor v <- 0
	VectorXd v(size);
	v = zeros(size);

	//v(c+1:n) <- A(c+1:N,c)
	for (int i = c+1; i < size; i++)
	{
		v(i) = A(i,c);
	}
	//l_v <- ||v||
	int l_v = v.norm();
	// Verifica se o elemento abaixo de c é positivo,
	// se for, muda o sinal da norma de v
	if (v(c+1) > 0)
	{
		l_v = -l_v;
	}
	//vetor v' <- 0
	VectorXd vLine(size);
	vLine = zeros(size);

	//v'(c+1) <- l_v
	vLine(c+1) = l_v;

	VectorXd N(size);
	N = v - vLine;

	//n <- N/||N||
  	VectorXd n(size);
  	n = N/N.norm();


  	// Construindo Matriz Identidade
	MatrixXd I(size, size);
	I = MatrixXd::Identity(size, size);

	// Construindo Matriz H
	MatrixXd H(size, size);
	H = I - 2*n*n.transpose();

	return H;
};


//retorna uma matriz tridiagonal e uma matriz acumulada das operações
tuple<Eigen::MatrixXd, Eigen::MatrixXd> HouseHolder(Eigen::Ref<Eigen::MatrixXd> A, int size){
	//A' <- A
	MatrixXd ALine(size, size);
	ALine = A;
	//H' = I
	MatrixXd H(size, size);
	H = MatrixXd::Identity(size, size);

	MatrixXd Hc(size, size);
	for (int c = 0; c < size-2; c++)
	{	
		Hc = mountHouseHolder(ALine, c, size);
		ALine = Hc * ALine * Hc;
		//cout << "Matriz " + c << endl << ALine << endl;
		H = H * Hc; 
	}

	return std::make_tuple(ALine, H);
}

int main(){

	const int size = 4;
	MatrixXd A(size, size);
	A <<
	 4, 1, -2, -2,
     1, 2, 0, 1,
     -2, 0, 3, -2,
	 2, 1, -2, -1;

    MatrixXd It(size, size);
  	MatrixXd H(size, size);
	tie(It,H) = HouseHolder(A, size);

	cout << "Matriz Tridiagonal" << endl << It << endl;
	cout << "Matriz Acumulada" << endl << H << endl;

	return 0;
}

