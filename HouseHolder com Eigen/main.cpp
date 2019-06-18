#include "householder.h"

//g++ -I eigen -c main.cpp -o main -std=c++11 && g++ -I eigen -c householder.cpp -o house -std=c++11 
//g++ main house && ./teste

int main(){

	MatrixXd A(4, 4);
	A <<
	 4, 1, -2, 2,
     1, 2, 0, 1,
     -2, 0, 3, -2,
	 2, 1, -2, -1;

	int rows = A.rows();
	int cols = A.cols();

    MatrixXd It(rows, cols);
  	MatrixXd H(rows, cols);
	tie(It,H) = HouseHolder(A);

	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");
	cout << "Matriz Tridiagonal" << endl << It.format(CleanFmt) << endl << endl;
	cout << "Matriz Acumulada" << endl << H.format(CleanFmt) << endl << endl;

	return 0;
}