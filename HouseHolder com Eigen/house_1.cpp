#include <iostream>
#include "eigen/Eigen/Dense"
using namespace Eigen;
using namespace std;

//g++ -I eigen nomedoarquivo.cpp -o nomepcompilar

class HouseHolder
{
	private size;
}


int main(){

	const int size = 3;
  	

	Vector3d N(0,1,0);


	/* Construindo vetor n */
  	VectorXd n(size);
  	n = N/N.norm();
  	cout << "Vetor n =" << endl << n << endl;

  	/* Construindo Matriz Identidade */
	MatrixXd I(size, size);
	I = MatrixXd::Identity(size, size);
	cout << "Identidade =" << endl << I << endl;

	/* Construindo Matriz H */
	MatrixXd H(size, size);
	H = I - 2*n*n.transpose();
	cout << "Matriz H" << endl << H << endl;	
}
