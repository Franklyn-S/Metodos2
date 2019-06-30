#include "biblioteca.hpp"

//g++ -c *.cpp -I eigen -std=c++11 && g++ -o main *.o && ./main

int main(){

	/*
	// Matriz da Questão 2	
	MatrixXd A(5, 5);
	A <<
	 		40, 3, 9, 7, 8,
		 	3, 23, 4, 7, 12,
		 	9, 4, 65, 16, 15,
		 	7, 7, 16, 37, 12,
			8, 12, 15, 12, 51;
	
	*/

	// Matriz da Questão 3	
	MatrixXd A(3, 5);
	A <<
	 		40, 3, 9, 7, 8,
		 	3, 23, 4, 7, 12,
		 	9, 4, 65, 16, 15;
	


	//Erro
	double E = 0.0001;

	int rows = 5;
	int cols = 5;
	
	//--------------------------- Achar Matriz U pelo Metodo de Jacobi ------------------------------------
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

	

	//------------------------------- Achar Matriz V pelo Metodo QR ------------------------------------
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


	//---------------------------------------- SIGMA QUESTÃO 2 ------------------------------------
	
	/*
	MatrixXd Sigma(rows, cols);
	Sigma = valueU;
	
	igualarSinal(vectorU, vectorV);
	*/

	//---------------------------------------- SIGMA QUESTÃO 3------------------------------------
	

	MatrixXd Sigma(3, 5);
	Sigma = MatrixXd::Zero(3,5);
	for (int i = 0; i < 3; i++) 
		Sigma(i,i) = valueU(i,i);

    inverteSinal(vectorU,vectorV,metodoU,metodoV);


	//---------------------------------------- RESULTADO ------------------------------------s

    sqrt_diagonal(Sigma);
    MatrixXd aux(rows, cols);
    aux = vectorU*Sigma*vectorV.transpose();

	cout << "\n" <<"---------------------------------- RESULTADO ---------------------------------- " << "\n" << endl;
	
	cout << "Matriz U: " << endl << vectorU.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Σ: " << endl << Sigma.format(CleanFmt) << "\n" << endl;
	cout << "Matriz V: " << endl << vectorV.format(CleanFmt) << "\n" << endl;
	cout << "Matriz A: " << endl << A.format(CleanFmt) << "\n" << endl;
	cout << "Matriz U*Σ*(V^t): " << endl << aux.format(CleanFmt) << "\n" << endl;


	return 0;
}
