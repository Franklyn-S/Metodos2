#include "biblioteca.h"

<<<<<<< HEAD

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
=======
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
>>>>>>> f8efb4354de2655a5191aadd35e53fcc4890b79c

	double E = 0.01;

	int rows = A.rows();
	int cols = A.cols();
<<<<<<< HEAD
	IOFormat CleanFmt(5, 0, ", ", "\n", "│", "│");
=======
	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");
>>>>>>> f8efb4354de2655a5191aadd35e53fcc4890b79c
	
	MatrixXd H(rows, cols);
	MatrixXd It(rows, cols);
	MatrixXd AL(rows, cols);
	MatrixXd AT(rows, cols);

<<<<<<< HEAD
	int op; 
	cout << "1 - Metodo de Jacobi" << endl << "2 - Metodo QR" << endl; 
	cin >> op;
=======
	int op; cout << "1 - Metodo de Jacobi" << endl << "2 - Metodo QR" << endl; cin >> op;
>>>>>>> f8efb4354de2655a5191aadd35e53fcc4890b79c

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