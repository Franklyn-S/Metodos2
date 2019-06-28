#include "biblioteca.hpp"


// Verifica o erro
double error(Ref<MatrixXd> A){
	double soma = 0;
	for (int i = 0; i < A.rows(); ++i)
		for (int j = 0; j < A.cols(); ++j)
			if(i!=j) soma += pow(A(i,j),2);
	return sqrt(soma);
}

// Aredonda Valores de uma Matriz 
void around(Ref<MatrixXd> Matriz){

	for (int i = 0; i < Matriz.rows(); i++){
		for(int j = 0; j < Matriz.cols(); j++){
			
		if (fabs(Matriz(i,j)) < 0.01)
			Matriz(i,j) = round(Matriz(i,j));
		}
	}
}

// Cria Vetor de Zeros
VectorXd zeros(int size){
	VectorXd v(size);
	for (int i = 0; i < size; i++)
	{
		v(i) = 0;
	}
	return v;
}

// Controi a Matriz Identidade do QR
MatrixXd montar_Pij(Ref<MatrixXd> A, int i, int j){
  	int rows  = A.rows();
  	int cols  = A.cols();
	MatrixXd Pij(rows, cols);
	Pij = MatrixXd::Identity(rows, cols);

	double t_aux = atan(A(i,j)/A(j,j));
	double teta = (A(j,j) == 0) ? (M_PI/4) : t_aux;
	
	Pij(i,i) = cos(teta);
	Pij(j,j) = cos(teta);
	Pij(i,j) = -sin(teta);
	Pij(j,i) = sin(teta);
	
	return Pij;
}

// Controi Matriz Identidade do Jacobi
MatrixXd calcular_Pij(Ref<MatrixXd> A, int i, int j){
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

// Ordena os Autovetores em Relação aos Autovalores em Ordem Decrescente 
tuple<MatrixXd, MatrixXd> ordenar(Ref<MatrixXd> Matriz_Valor, Ref<MatrixXd> Matriz_Vetor){

	int rows = Matriz_Valor.rows();
	int cols = Matriz_Valor.cols();

	VectorXd vetor_diagonal(rows);
	VectorXd vetor_indice(rows);
	MatrixXd EigenVectorMatriz(rows,cols);
	MatrixXd EigenValueMatriz(rows,cols);


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
		
			EigenVectorMatriz(i,j) =	Matriz_Vetor(i, vetor_indice(j));
			EigenValueMatriz(i,j) =	Matriz_Valor(i, vetor_indice(j));

		}	
	}

	return make_tuple(EigenValueMatriz, EigenVectorMatriz);

}