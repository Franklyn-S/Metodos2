#include "biblioteca.hpp"

tuple<MatrixXd, MatrixXd> jacobi(Ref<MatrixXd> A, double E, Ref<MatrixXd> H){

	int rows = A.rows();
	int cols = A.cols();

	MatrixXd Pij(rows, cols);
	MatrixXd J(rows, cols);
	MatrixXd P(rows, cols);
	J = H;


	int MAX_INTERATION = 2000;
	int i = 0;
	while(error(A) > E && i < MAX_INTERATION){
		P = MatrixXd::Identity(rows, cols);
		for (int j = 0; j < rows-1; ++j){
			for (int i = j+1; i < cols; ++i){
				Pij = calcular_Pij(A,i,j);
				A = Pij.transpose()*A*Pij;
				P = P*Pij;
			}
		}

		J = J*P;
		i++;

	}

	return make_tuple(A, J);

}