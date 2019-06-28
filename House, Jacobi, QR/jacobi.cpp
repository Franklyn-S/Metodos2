#include "biblioteca.h"

tuple<MatrixXd, MatrixXd> jacobi(Ref<MatrixXd> A, double E, Ref<MatrixXd> H){

	MatrixXd Pij(A.rows(), A.rows());
	MatrixXd J(A.rows(), A.cols());
	MatrixXd P(A.rows(), A.rows());
	P = MatrixXd::Identity(A.rows(), A.rows());
	J = H;


	int MAX_INTERATION = 2000;
	int i = 0;
	while(error(A) > E && i < MAX_INTERATION){
		for (int j = 0; j < A.rows()-1; ++j){
			for (int i = j+1; i < A.cols(); ++i){
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