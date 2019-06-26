#include "biblioteca.h"

tuple<MatrixXd, MatrixXd> Decomp_QR(Ref<MatrixXd> A){
	int size = A.rows();
	MatrixXd Pt(size, size);
	MatrixXd Qt(size, size);
	Qt = MatrixXd::Identity(size, size);
	for (int j = 0; j < size-2; j++){
		for (int i = (j+1); i < size-1; i++){
			Pt = montar_Pij(A, i, j).transpose();
			A = Pt*A;
			Qt = Pt*Qt;
		}
	}

	return make_tuple(Qt.transpose(), A);
}


tuple<MatrixXd, MatrixXd> QR(Ref<MatrixXd> A, double E, Ref<MatrixXd> H){
	
	int size = A.rows();
	MatrixXd Q(size, size);
	MatrixXd R(size, size);
	MatrixXd P(size, size);
	P = H;
	int i = 0;
	while (error(A) > E and i < 50){
		tie(Q,R) = Decomp_QR(A);
		A = R*Q;
		P = P*Q;
		i++;

	}

	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");
	cout << "Matriz Q" << endl << Q.format(CleanFmt) << endl << endl;
	cout << "Matriz R" << endl << R.format(CleanFmt) << endl << endl;

	return make_tuple(A,P);
}
