#include <iostream>
#include "../eigenLib/Eigen/Dense"
using namespace Eigen;
using namespace std;

//g++ -I eigen house_1.cpp -o house


Eigen::VectorXd zero(int size){
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
	v = zero(size);

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
	vLine = zero(size);

	//v'(c+1) <- l_v
	vLine(c+1) = l_v;

	VectorXd N(size);

	N = v - vLine;

	// Construindo vetor n
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


int main(){

	const int size = 3;
	int c = 1;
	MatrixXd A(size, size);
	A <<
	 1, 2, 3,
     4, 5, 6,
     7, 8, 9; 
  	MatrixXd H(size, size);
	H = mountHouseHolder(A, c, size);

	cout << "Matriz HouseHolder" << endl << H << endl;

	return 0;
}

