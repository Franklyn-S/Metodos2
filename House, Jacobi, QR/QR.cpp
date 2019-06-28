#include "biblioteca.hpp"

tuple<MatrixXd, MatrixXd> Decomp_QR(Ref<MatrixXd> A){

	int rows = A.rows();
	int cols = A.cols();
	MatrixXd Pt(rows, cols);
	MatrixXd Qt(rows, cols);
	Qt = MatrixXd::Identity(rows, cols);

	for (int j = 0; j < cols-1; j++){
		for (int i = (j+1); i < rows; i++){
			
			Pt = montar_Pij(A, i, j);
			A = Pt*A;
			Qt = Pt*Qt;
		}
	}

	return make_tuple(Qt.transpose(), A);
}


tuple<MatrixXd, MatrixXd> QR(Ref<MatrixXd> A, double E, Ref<MatrixXd> H){
	

	int rows = A.rows();
	int cols = A.cols();
	MatrixXd Q(rows, cols);
	MatrixXd R(rows, cols);
	MatrixXd P(rows, cols);

	P = H;
	int MAX_INTERATION = 2000;
	int i = 0;
	while (error(A) > E and i < MAX_INTERATION){
		tie(Q,R) = Decomp_QR(A);
		A = R*Q;
		P = P*Q;
		i++;
	}

	return make_tuple(A,P);
}
