#include "biblioteca.h"


//g++ -c *.cpp -I eigen -std=c++11 && g++ -o main *.o
//./main


int main(){

	MatrixXd A(5, 5);
	A <<
	 36, 3, 9, 7, 6,
     3, 20, 1, 3, 12,
	 9, 1, 63, 16, 13,
	 7, 3, 16, 37, 7,
	 6, 12, 13, 7, 51;

	double E = 0.01;

	int rows = A.rows();
	int cols = A.cols();
	IOFormat CleanFmt(5, 0, ", ", "\n", "│", "│");
	
	MatrixXd H(rows, cols);
	MatrixXd It(rows, cols);
	MatrixXd AL(rows, cols);
	MatrixXd AT(rows, cols);

	int op; 
	cout << "1 - Metodo de Jacobi" << endl << "2 - Metodo QR" << endl; 
	cin >> op;

	//HouseHolder
	tie(It,H) = HouseHolder(A);

	cout << "Matriz Tridiagonal" << endl << It.format(CleanFmt) << endl << endl;
	cout << "Matriz Acumulada" << endl << H.format(CleanFmt) << endl << endl;

	//Jacobi
	if (op == 1) tie(AL, AT) = jacobi(A, E, H);

	//QR
	else if(op == 2) tie(AL, AT) = QR(A, E, H);
		
	else cout << "Opção Invalida" << endl;
		
	cout << "Matriz de autovalores: "<< endl << AL.format(CleanFmt) << endl << endl;
	cout << "Matriz de autovetores: " << endl << AT.format(CleanFmt) << endl;

	return 0;
}