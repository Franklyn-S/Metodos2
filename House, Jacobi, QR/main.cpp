#include "biblioteca.h"

//g++ -I eigen -c main.cpp -o main -std=c++11 
//g++ -I eigen -c biblioteca.cpp -o biblioteca -std=c++11 
//g++ -I eigen -c householder.cpp -o house -std=c++11 
//g++ -I eigen -c jacobi.cpp -o jacobi -std=c++11 
//g++ -I eigen -c QR.cpp -o QR -std=c++11 
//g++ main biblioteca house jacobi QR -o teste && ./teste

int main(){

	MatrixXd A(3, 3);
	A <<
	 12, 51, 4,
     6, 167, -68,
	-4, 24, -41;

	double E = 0.01;

	int rows = A.rows();
	int cols = A.cols();
	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");
	
	MatrixXd H(rows, cols);
	MatrixXd It(rows, cols);
	MatrixXd AL(rows, cols);
	MatrixXd AT(rows, cols);

	int op; cout << "1 - Metodo de Jacobi" << endl << "2 - Metodo QR" << endl; cin >> op;

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