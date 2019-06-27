#include "biblioteca.h"

tuple<MatrixXd, MatrixXd> Decomp_QR(Ref<MatrixXd> A){
	int rows = A.rows();
	int cols = A.cols();
	MatrixXd Pt(rows, cols);
	MatrixXd Qt(rows, cols);
	Qt = MatrixXd::Identity(rows, cols);



	
	for (int j = 0; j < cols-2; j++){
		for (int i = (j+1); i < rows-1; i++){
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
	P = MatrixXd::Identity(rows, cols);
	//P = H;
	int MAX_INTERATION = 100;
	int i = 0;
	while (error(A) > E and i < MAX_INTERATION){
		tie(Q,R) = Decomp_QR(A);
		A = R*Q;
		P = P*Q;
		i++;
	}

	if (i == MAX_INTERATION) cout << "PAROU PELO I!!!!" << endl;

	IOFormat CleanFmt(4, 0, ", ", "\n", "│", "│");
	cout << "Matriz Q" << endl << Q.format(CleanFmt) << endl << endl;
	cout << "Matriz R" << endl << R.format(CleanFmt) << endl << endl;

	return make_tuple(A,P);
}
