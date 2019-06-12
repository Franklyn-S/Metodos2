#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

VectorXf calculate(MatrixXf U, VectorXf b, int n);
VectorXf potenciainversa(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro, float chute, int escolha);

int main(){

    /*Inicialização */

    int tamanho = 3;

    Vector3f vetor_inicial(1,1,1);
    cout << "Vetor inicial" << endl << vetor_inicial << endl;

    MatrixXf matriz_inicial(tamanho,tamanho);
    matriz_inicial << (Matrix3f() << 3,0,0,0,3,2,0,-1,0).finished();
    cout << "Matriz inicial" << endl << matriz_inicial << endl;

    float erro =  0.0000000001;
    float chute = 2;

    /*Inicialização Método da Potência com Deslocamento */

        MatrixXf matrizbarra(tamanho,tamanho);
        MatrixXf I(tamanho,tamanho);
        VectorXf xn(tamanho);
        VectorXf xi(tamanho);
        VectorXf aux(2);
        I = MatrixXf::Identity(tamanho,tamanho);
        float lambdan;
        float lambdai;

    /* Metodo da Potência com Deslocamento */

        matrizbarra = matriz_inicial - (chute*I);
        lambdan = potenciainversa(matrizbarra,vetor_inicial,tamanho,erro,chute,1)(0);
        xn = potenciainversa(matrizbarra,vetor_inicial,tamanho,erro,chute,0);
        lambdai = lambdan + chute;
        xi = xn;
        cout << "Auto vetor: " << endl << xi << endl;
        cout << "Auto valor: " << endl << lambdai << endl;

    return 0;
}


VectorXf potenciainversa(MatrixXf matriz_inicial, VectorXf vetor_inicial, int tamanho, float erro, float chute, int escolha){

    /*Inicialização Método da Potência Inversa */

        VectorXf x_old(tamanho);
        VectorXf y_new(tamanho);
        VectorXf x_new(tamanho);
        float lambda_novo;
        float lambda_antigo;

    /* Metodo da PotênciaInversa */

        lambda_novo = 0;
        x_old = vetor_inicial.normalized();
        do{      
            lambda_antigo = lambda_novo;
            y_new = calculate(matriz_inicial,x_old,tamanho);
            x_new = y_new.normalized();
            lambda_novo = x_old.transpose()*y_new;
            x_old = x_new;
        }while(fabs((lambda_novo - lambda_antigo)/lambda_novo)>erro);

//        cout << "Auto vetor: " << endl << x_new << endl;
//        cout << "Auto valor: " << endl << 1/lambda_novo << endl;

        Vector2f vetorlambda((1/lambda_novo),0);
        if(escolha == 0){
            return x_new;
        }
        return vetorlambda;
}

VectorXf calculate(MatrixXf U, VectorXf b, int n){
    int linha = n;
    int coluna = n;
    MatrixXf L(n,n);
    L << (Matrix3f() << 1,0,0,0,1,0,0,0,1).finished();

    VectorXf y(n);
    VectorXf x(n);
    double m, s, maior, aux; //auxiliares

    //Eliminação
    for (int k = 0; k < n-1; k++){//percorre as colunas
        maior = -numeric_limits<double>::max();//-infinito
        //falta o pivotamento nas iterações
        for (int i = k+1; i < n; i++){ //percorre as linhas
            m = U(i,k)/U(k,k);
            U(i,k) = 0;
            L(i,k) = m;
            for (int j = k+1; j < n; j++){//percorre as linhas calculando seus novos valores
                U(i,j) = U(i,j) - m*U(k,j);
            }
            b[i] = b[i] - m*b[k];
        }
    }

    //resolução do sistema Ly = b	

    y[0] = b[0]/L(0,0);


    for (int k = 1; k < n; k++){//substituição
        s = 0;
        for (int j = k+1; j < n; j++){
            s = s + L(k,j)*y[j];
        }
        y[k] = (b[k]-s)/L(k,k);
    }



    //resolução do sistema Ux = y
    x[n-1] = y[n-1]/U(n-1,n-1);
    
    for (int k = n-2; k >= 0; k--){//substituição retroativa
        s = 0;
        for (int j = k+1; j < n; j++){
            s = s + U(k,j)*x[j];
        }
        x[k] = (y[k]-s)/U(k,k);
    }

    return x;

}