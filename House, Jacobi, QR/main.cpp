#include "biblioteca.hpp"
#include <string>	

//g++ -c *.cpp -I eigen -std=c++11 && g++ -o main *.o && ./main

int main(){

	VectorXd M(6);
	M << 3,9,7,8,4,7;
	
	// Matriz Arbitrária da Questão 2
	MatrixXd A(5,5);
	A << 
		M(0)+M(5)+30	, M(0)			, M(1)			, 	M(2)		, M(3),
		M(0)			, M(1)+M(4)+10	, M(4)			, 	M(5)		, M(0)+M(1),
		M(1)			, M(4)			, M(2)+M(3)+50	, 	M(1)+M(2)	, M(2)+M(3),
		M(2)			, M(5)			, M(1)+M(2)		,  -M(0)+40		, M(3)+M(4),
		M(3)			, M(0)+M(1)		, M(2)+M(3)		, 	M(3)+M(4)	,-M(1)+60;

	
	/*
	// Matriz Arbitrária da Questão 3
	
	MatrixXd A(3,5);
	A << 
		M(0)+M(5)+30	, M(0)			, M(1)			, 	M(2)		, M(3),
		M(0)			, M(1)+M(4)+10	, M(4)			, 	M(5)		, M(0)+M(1),
		M(1)			, M(4)			, M(2)+M(3)+50	, 	M(1)+M(2)	, M(2)+M(3);

	*/

	/*

	MatrixXd A(5, 5);
	A <<
	 		40, 3, 9, 7, 8,
		 	3, 23, 4, 7, 12,
		 	9, 4, 65, 16, 15,
		 	7, 7, 16, 37, 12,
			8, 12, 15, 12, 51;

	*/


	//Erro
	double E = 0.000001;

	int rows = A.rows();
	int cols = A.cols();
	
	//--------------------------- Achar Matriz U pelo Metodo de Jacobi ------------------------------------
	MatrixXd A_U(rows, rows);
	MatrixXd H_U(rows, rows);
	MatrixXd It_U(rows, rows);
	MatrixXd valueU(rows, rows);
	MatrixXd vectorU(rows, rows);

	A_U = A*A.transpose();
	tie(It_U,H_U) = HouseHolder(A_U);
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
	MatrixXd A_V(cols, cols);
	MatrixXd H_V(cols, cols);
	MatrixXd It_V(cols, cols);
	MatrixXd valueV(cols, cols);
	MatrixXd vectorV(cols, cols);
	
	A_V = A.transpose()*A;
	tie(It_V,H_V) = HouseHolder(A_V);
	tie(valueV, vectorV) = QR(It_V, E, H_V);
	
	around(It_V);
	around(H_V);
	around(valueV);
	around(vectorV);

	ordenar(valueV, vectorV);


	cout << "\n" <<"---------------------------------- Metodo QR ---------------------------------- " << "\n" << endl;
	cout << "Matriz A_transposta*A" << endl << A_V.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Tridiagonal" << endl << It_V.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Acumulada" << endl << H_V.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovalores: "<< endl << valueV.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovetores: " << endl << vectorV.format(CleanFmt) << "\n" << endl;



	//------------------------------------------- RESULTADO ---------------------------------------
	

	// Sigma
	MatrixXd Sigma(rows, cols);
	Sigma = MatrixXd::Zero(rows,cols);
	for (int i = 0; i < rows; i++) 
		Sigma(i,i) = valueU(i,i);
    sqrt_diagonal(Sigma);

    consertaSinal(A, vectorV, vectorU, Sigma);

    // U * Σ * Vt
    MatrixXd aux(rows, cols);
    aux = vectorU*Sigma*vectorV.transpose();
    around(aux);

	cout << "\n" <<"---------------------------------- RESULTADO ---------------------------------- " << "\n" << endl;
	
	cout << "Matriz U: " << endl << vectorU.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Σ: " << endl << Sigma.format(CleanFmt) << "\n" << endl;
	cout << "Matriz V: " << endl << vectorV.format(CleanFmt) << "\n" << endl;
	cout << "Matriz A: " << endl << A.format(CleanFmt) << "\n" << endl;
	cout << "Matriz U*Σ*(V^t): " << endl << aux.format(CleanFmt) << "\n" << endl;



	//----------------------------------------- Outras Provas -----------------------------------
	//------------------------------------ A * At * U = U * Σ * Σt  -----------------------------
	//------------------------------------ At * A * V = V * Σt * Σ  -----------------------------

	/*

	MatrixXd A_At_U(rows,cols);
	MatrixXd U_S_St(rows,cols);
	MatrixXd At_A_V(rows,cols);
	MatrixXd V_St_S(rows,cols);

	A_At_U = A * A.transpose() * vectorU;
	U_S_St = vectorU * Sigma * Sigma.transpose();
	At_A_V = A.transpose() * A * vectorV;
	V_St_S = vectorV * Sigma.transpose() * Sigma;

	around(A_At_U);
	around(U_S_St);
	around(At_A_V);
	around(V_St_S);

	cout << "\n" <<"---------- A * At * U = U * Σ * Σt ---------- " << "\n" << endl;
	cout << "A * At * U " << endl <<A_At_U.format(CleanFmt) << "\n" << endl;
	cout << "U * Σ * Σt" << endl <<U_S_St.format(CleanFmt) << "\n" << endl;
	cout << "\n" <<"---------- At * A * V = V * Σt * Σ ----------" << "\n" << endl;
	cout << "At * A * V " << endl <<At_A_V.format(CleanFmt) << "\n" << endl;
	cout << "V * Σt * Σ" << endl <<V_St_S.format(CleanFmt) << "\n" << endl;

	*/
	
	return 0;
}

