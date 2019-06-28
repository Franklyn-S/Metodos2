#include "biblioteca.hpp"

//g++ -c *.cpp -I eigen -std=c++11 && g++ -o main *.o && ./main

int main(){

	MatrixXd A(5, 5);
	A <<
	 40, 3, 9, 7, 8,
	 3, 23, 4, 7, 12,
	 9, 4, 65, 16, 15,
	 7, 7, 16, 37, 12,
	 8, 12, 15, 12, 51;

	//Erro
	double E = 0.01;

	int rows = A.rows();
	int cols = A.cols();
	
	MatrixXd H(rows, cols);
	MatrixXd It(rows, cols);
	MatrixXd AL(rows, cols);
	MatrixXd AT(rows, cols);

	//Formato do Print de Matriz (Eigen)
	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");

	int op; 
	cout << "1 - Metodo de Jacobi" << endl << "2 - Metodo QR" << endl; 
	cin >> op;

	//HouseHolder
	tie(It,H) = HouseHolder(A);
	//arredonda os zeros para 0
	around(It);
	around(H);

	//printa matrizes tridiagonal e acumulada do House Holder
	cout << "Matriz Tridiagonal" << endl << It.format(CleanFmt) << endl << endl;
	cout << "Matriz Acumulada" << endl << H.format(CleanFmt) << endl << endl;

	//Jacobi
	if (op == 1) 
		tie(AL, AT) = jacobi(A, E, H);

	//QR
	else if(op == 2) 
		tie(AL, AT) = QR(A, E, H);
		
	else 
		cout << "Opção Invalida" << endl;

	tie(AL,AT) = ordenar(AL, AT);
	
	//Arredonda os Valores das Matrizes

	around(AL);
	around(AT);


	cout << "Matriz de Autovalores: "<< endl << AL.format(CleanFmt) << endl << endl;
	cout << "Matriz de Autovetores: " << endl << AT.format(CleanFmt) << endl;

	return 0;
}