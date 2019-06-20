#include <iostream>
#include "../eigenLib/Eigen/Dense"
#include <cmath>
#include <tuple>

using namespace Eigen;
using namespace std;


double error(Ref<MatrixXd> A){
	double soma = 0;
	for (int i = 0; i < A.rows(); ++i)
		for (int j = 0; j < A.cols(); ++j)
			if(i!=j) soma += pow(A(i,j),2);

	return sqrt(soma);
}

MatrixXd calcular_Pij(Ref<MatrixXd> A, int i, int j){
  	// Construindo Matriz Identidade
  	int size  = A.rows();
	MatrixXd Pij(size, size);
	Pij = MatrixXd::Identity(size, size);

	double t_aux = (0.5*atan( 2*A(i,j) / (A(j,j)-A(i,i)) ));
	double teta = (A(i,i) == A(j,j)) ? (M_PI/4) : t_aux;
	


	Pij(j,j) = cos(teta);
	Pij(i,i) = cos(teta);
	Pij(i,j) = sin(teta);
	Pij(j,i) = -sin(teta);
	
	return Pij;

}


tuple<MatrixXd, MatrixXd> jacobi(Ref<MatrixXd> A, double E, Ref<MatrixXd> H){

	MatrixXd Pij(A.rows(), A.cols());
	MatrixXd J(A.rows(), A.cols());
	MatrixXd P(A.rows(), A.cols());
	P = MatrixXd::Identity(A.rows(), A.cols());
	J = H;
	int i = 0;
	while(error(A) > E and i < 20)
	{
		for (int j = 0; j < A.rows()-1; ++j)
		{
			for (int i = j+1; i < A.cols(); ++i)
			{
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



int main(){

	const int size = 3;

	MatrixXd A(size, size);
	A = MatrixXd::Identity(size, size);
	A <<
	 4, 2, -4,
     2, 10, 4,
     -4, 4, 9;
	
	MatrixXd H(size, size);
	H = MatrixXd::Identity(size, size);

  	MatrixXd AL(size, size);
	MatrixXd AT(size, size);
    tie(AL, AT) = jacobi(A, 0.01, H);
	cout << "Matriz de autovalores: "<< endl << AL << endl << endl;
	cout << "Matriz de autovetores: " << endl << AT << endl;
	return 0;

}