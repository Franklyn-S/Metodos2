#include "biblioteca.hpp"

//g++ -c *.cpp -I eigen -std=c++11 && g++ -o q2 *.o && ./q2

int main(){

	MatrixXd A(5, 5);
	A <<
	 		40, 3, 9, 7, 8,
		 	3, 23, 4, 7, 12,
		 	9, 4, 65, 16, 15,
		 	7, 7, 16, 37, 12,
			8, 12, 15, 12, 51;


	//Erro
	double E = 0.0001;

	int rows = A.rows();
	int cols = A.cols();
	
	//---------------------------------- Metodo de Jacobi ------------------------------------
	MatrixXd A_J(rows, cols);
	MatrixXd H_J(rows, cols);
	MatrixXd It_J(rows, cols);
	MatrixXd valueJ(rows, cols);
	MatrixXd vectorJ(rows, cols);

	A_J = A*A.transpose();
	tie(It_J,H_J) = HouseHolder(A_J);
	tie(valueJ, vectorJ) = jacobi(It_J, E, H_J);

	around(It_J);
	around(H_J);
	around(valueJ);
	around(vectorJ);

	ordenar(valueJ, vectorJ);


	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");
	cout << "------------------- Metodo de Jacobi -------------------" << endl << endl;
	cout << "Matriz Tridiagonal" << endl << It_J.format(CleanFmt) << endl << endl;
	cout << "Matriz Acumulada" << endl << H_J.format(CleanFmt) << endl << endl;
	cout << "Matriz de Autovalores: "<< endl << valueJ.format(CleanFmt) << endl << endl;
	cout << "Matriz de Autovetores: " << endl << vectorJ.format(CleanFmt) << endl;


	//---------------------------------------- Metodo QR ------------------------------------
	MatrixXd A_QR(rows, cols);
	MatrixXd H_QR(rows, cols);
	MatrixXd It_QR(rows, cols);
	MatrixXd valueQR(rows, cols);
	MatrixXd vectorQR(rows, cols);
	
	A_QR = A.transpose()*A;
	tie(It_QR,H_QR) = HouseHolder(A_QR);
	tie(valueQR, vectorQR) = QR(It_QR, E, H_QR);

	around(It_QR);
	around(H_QR);
	around(valueQR);
	around(vectorQR);

	ordenar(valueQR, vectorQR);


	cout << "------------------- Metodo QR -------------------" << endl << endl;
	cout << "Matriz Tridiagonal" << endl << It_QR.format(CleanFmt) << endl << endl;
	cout << "Matriz Acumulada" << endl << H_QR.format(CleanFmt) << endl << endl;
	cout << "Matriz de Autovalores: "<< endl << valueQR.format(CleanFmt) << endl << endl;
	cout << "Matriz de Autovetores: " << endl << vectorQR.format(CleanFmt) << endl;



	// Resultados
	MatrixXd Sigma(rows, cols);
	MatrixXd aux(rows, cols);

	Sigma = valueJ; //mudar para valueJ
	
	sqrt_diagonal(Sigma);
	cout << "Sigma: " << endl << Sigma.format(CleanFmt) << endl;
	cout << "A: " << endl << A.format(CleanFmt) << endl;
	aux = vectorJ*Sigma*vectorJ.transpose();
	cout << "Matriz UΣ(V^t): " << endl << aux.format(CleanFmt) << endl;
	return 0;
}