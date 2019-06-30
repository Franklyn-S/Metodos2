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
	MatrixXd A_J(rows, cols);
	MatrixXd H_J(rows, cols);
	MatrixXd It_J(rows, cols);
	MatrixXd valueJ(rows, cols);
	MatrixXd vectorJ(rows, cols);

	A_J = A*A.transpose();
	tie(It_J,H_J) = HouseHolder(A_J);
	tie(valueJ, vectorJ) = QR(It_J, E, H_J);
	bool jacobiA_J = false;

	around(It_J, false);
	around(H_J, false);
	around(valueJ, false);
	around(vectorJ, false);

	ordenar(valueJ, vectorJ);


	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");
	cout << "\n" <<"---------------------------  Metodo de Jacobi --------------------------- " << "\n" << endl;
	cout << "Matriz A*A_transposta" << endl << A_J.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Tridiagonal" << endl << It_J.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Acumulada" << endl << H_J.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovalores: "<< endl << valueJ.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovetores: " << endl << vectorJ.format(CleanFmt) << "\n" << endl;

	

	//---------------------------------------- Metodo QR ------------------------------------
	MatrixXd A_QR(rows, cols);
	MatrixXd H_QR(rows, cols);
	MatrixXd It_QR(rows, cols);
	MatrixXd valueQR(rows, cols);
	MatrixXd vectorQR(rows, cols);
	
	A_QR = A.transpose()*A;
	tie(It_QR,H_QR) = HouseHolder(A_QR);
	tie(valueQR, vectorQR) = QR(It_QR, E, H_QR);
	bool jacobiA_QR = false;

	around(It_QR, false);
	around(H_QR, false);
	around(valueQR, false);
	around(vectorQR, false);

	ordenar(valueQR, vectorQR);


	cout << "\n" <<"---------------------------------- Metodo QR ---------------------------------- " << "\n" << endl;
	cout << "Matriz A_transposta*A" << endl << A_J.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Tridiagonal" << endl << It_QR.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Acumulada" << endl << H_QR.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovalores: "<< endl << valueQR.format(CleanFmt) << "\n" << endl;
	cout << "Matriz de Autovetores: " << endl << vectorQR.format(CleanFmt) << "\n" << endl;


	//---------------------------------------- RESULTADO ------------------------------------
	
	MatrixXd Sigma(3, 5);
	MatrixXd aux(rows, cols);

	Sigma <<
	73.085,  	0,  	0,  	0,  	0,
        0,   	37.541, 0,      0,     	0,
        0 ,       0 ,  24.542 , 0,     	0;

	//Sigma = valueQR;
	//sqrt_diagonal(Sigma);

    if (jacobiA_J) inverteSinal(vectorJ, 1);
	else inverteSinal(vectorJ, 0);

    if (jacobiA_QR) inverteSinal(vectorQR, 1);
    else inverteSinal(vectorQR, 0);
    inverteSinal(vectorQR, 2);

	aux = vectorJ*Sigma*vectorQR.transpose();
	around(aux, true);

	cout << "\n" <<"---------------------------------- RESULTADO ---------------------------------- " << "\n" << endl;
	
	cout << "Matriz U: " << endl << vectorJ.format(CleanFmt) << "\n" << endl;
	cout << "Matriz Σ: " << endl << Sigma.format(CleanFmt) << "\n" << endl;
	cout << "Matriz V: " << endl << vectorQR.format(CleanFmt) << "\n" << endl;
	cout << "Matriz A: " << endl << A.format(CleanFmt) << "\n" << endl;
	cout << "Matriz U*Σ*(V^t): " << endl << aux.format(CleanFmt) << "\n" << endl;


	return 0;
}

