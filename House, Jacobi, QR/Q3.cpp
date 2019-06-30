#include "biblioteca.hpp"

//g++ -c *.cpp -I eigen -std=c++11 && g++ -o q2 *.o && ./q2

int main(){

	MatrixXd A(3, 5);
	A <<
	 		40, 3, 9, 7, 8,
		 	3, 23, 4, 7, 12,
		 	9, 4, 65, 16, 15;


	//Erro
	double E = 0.0001;

	int rows = A.rows();
	int cols = A.cols();
	
	//---------------------------------- Metodo de Jacobi ------------------------------------
	MatrixXd A_U(rows, cols);
	MatrixXd H_U(rows, cols);
	MatrixXd It_U(rows, cols);
	MatrixXd valueU(rows, cols);
	MatrixXd vectorU(rows, cols);

	A_U = A*A.transpose();
	tie(It_U,H_U) = HouseHolder(A_U);

	// QR = 0 | Jacobi = 1
	bool metodoU = 1;
	tie(valueU, vectorU) = jacobi(It_U, E, H_U);

	around(It_U);
	around(H_U);
	around(valueU);
	around(vectorU);

	ordenar(valueU, vectorU);


	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");
	cout << "\n" <<"---------------------------  Metodo de Jacobi --------------------------- " << "\n" << endl;
	cout << "Matriz A*A_transposta" << endl << A_U.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Tridiagonal" << endl << It_U.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Acumulada" << endl << H_U.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovalores: "<< endl << valueU.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovetores: " << endl << vectorU.format(CleanFmt) << "\n" << endl;

	

	//---------------------------------------- Metodo QR ------------------------------------
	MatrixXd A_V(rows, cols);
	MatrixXd H_V(rows, cols);
	MatrixXd It_V(rows, cols);
	MatrixXd valueV(rows, cols);
	MatrixXd vectorV(rows, cols);
	
	A_V = A.transpose()*A;
	tie(It_V,H_V) = HouseHolder(A_V);

	// QR = 0 | Jacobi = 1
	bool metodoV = 0;
	tie(valueV, vectorV) = QR(It_V, E, H_V);
	
	

	around(It_V);
	around(H_V);
	around(valueV);
	around(vectorV);

	ordenar(valueV, vectorV);


	cout << "\n" <<"---------------------------------- Metodo QR ---------------------------------- " << "\n" << endl;
	cout << "Matriz A_transposta*A" << endl << A_U.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Tridiagonal" << endl << It_V.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Acumulada" << endl << H_V.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovalores: "<< endl << valueV.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovetores: " << endl << vectorV.format(CleanFmt) << "\n" << endl;


	//---------------------------------------- RESULTADO ------------------------------------
	
	MatrixXd Sigma(3, 5);
	MatrixXd aux(rows, cols);
	
	Sigma = MatrixXd::Zero(3,5);

	for (int i = 0; i < 3; i++) 
		Sigma(i,i) = valueU(i,i);

	sqrt_diagonal(Sigma);

    inverteSinal(vectorU,vectorV,metodoU,metodoV);

	aux = vectorU*Sigma*vectorV.transpose();


	cout << "\n" <<"---------------------------------- RESULTADO ---------------------------------- " << "\n" << endl;
	
	cout << "Matriz U: " << endl << vectorU.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Σ: " << endl << Sigma.format(CleanFmt) << "\n" << endl;
	cout << "Matriz V: " << endl << vectorV.format(CleanFmt) << "\n" << endl;
	cout << "Matriz A: " << endl << A.format(CleanFmt) << "\n" << endl;
	cout << "Matriz U*Σ*(V^t): " << endl << aux.format(CleanFmt) << "\n" << endl;


	return 0;
}
