#include "biblioteca.h"


// Creates a vector of zeros
VectorXd zeros(int size){
	VectorXd v(size);
	for (int i = 0; i < size; i++)
	{
		v(i) = 0;
	}
	return v;
}

double error(Ref<MatrixXd> A){
	double soma = 0;
	for (int i = 0; i < A.rows(); ++i)
		for (int j = 0; j < A.cols(); ++j)
			if(i!=j) soma += pow(A(i,j),2);
	return sqrt(soma);
}





MatrixXd montar_Pij(Ref<MatrixXd> A, int i, int j){
  	// Construindo Matriz Identidade
  	int rows  = A.rows();
  	int cols  = A.cols();
	MatrixXd Pij(rows, cols);
	Pij = MatrixXd::Identity(rows, cols);

	double t_aux = atan(A(i,j)/A(j,j));
	double teta = (A(j,j) == 0) ? (M_PI/4) : t_aux;
	
	Pij(i,i) = cos(teta);
	Pij(j,j) = cos(teta);
	Pij(i,j) = sin(teta);
	Pij(j,i) = -sin(teta);
	
	return Pij;
}


MatrixXd calcular_Pij(Ref<MatrixXd> A, int i, int j){
  	// Construindo Matriz Identidade
  	int rows  = A.rows();
  	int cols  = A.cols();
	MatrixXd Pij(rows, cols);
	Pij = MatrixXd::Identity(rows, cols);

	double t_aux = (0.5*atan( 2*A(i,j) / (A(j,j)-A(i,i)) ));
	double teta = (A(i,i) == A(j,j)) ? (M_PI/4) : t_aux;
	
	Pij(i,i) = cos(teta);
	Pij(j,j) = cos(teta);
	Pij(i,j) = sin(teta);
	Pij(j,i) = -sin(teta);
	
	return Pij;



	
}

MatrixXd ordenar_autovetores(Ref<MatrixXd> Matriz_Valor, Ref<MatrixXd> Matriz_Vetor){

	int rows = Matriz_Valor.rows();
	int cols = Matriz_Valor.cols();

	VectorXd vetor_diagonal(rows);
	VectorXd vetor_indice(rows);
	MatrixXd Matriz_Ordenada(rows,cols);


	for (int i = 0; i < rows; ++i){
		vetor_diagonal(i) = Matriz_Valor(i,i);
		vetor_indice(i) = i;
	}

	for (int i = 1; i < rows; i++) {
    	for (int j = 0; j < i; j++) {
	        if (vetor_diagonal(i) > vetor_diagonal(j)) {
	            double temp = vetor_diagonal(i);
	            vetor_diagonal(i) = vetor_diagonal(j);
	            vetor_diagonal(j) = temp;

	            int temp2 = vetor_indice(i);
	            vetor_indice(i) = vetor_indice(j);
	            vetor_indice(j) = temp2;

	        }
	    }
	}

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
		
			Matriz_Ordenada(i,j) =	Matriz_Vetor(i, vetor_indice(j));

		}	
	}

	return(Matriz_Ordenada);

}