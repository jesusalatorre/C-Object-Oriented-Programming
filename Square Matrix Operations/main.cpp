/*
Jesus Alatorre
*/

///Operaciones entre matrices cuadradas A y B:

///Implementar las operaciones: suma, resta, transpuesta, multiplicación

#include <iostream>
using namespace std;

const int N = 4; //Dimension de la matriz cuadrada

int A[N][N] = {{1,2,3,4},
              {1,2,3,4},
              {1,2,3,4},
              {1,2,3,4}  };

int B[N][N] = {{5,6,7,8},
               {5,6,7,8},
               {5,6,7,8},
               {5,6,7,8}  };

int C[N][N];

//Imprime matriz cuadrada
void imprimeMatriz(const int matriz[][N]) {
   for(int i=0; i<N; i++) {
   	   cout << "|  " ;
   	   for(int j=0; j<N; j++)
   	  	   cout << matriz[i][j] << "  ";
	   cout << "|" << endl;
   }
}

int main() {

    int acum;

    cout << "Suma: " << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }

    imprimeMatriz(C);

    cout << "Resta: " << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            C[i][j]=A[i][j]-B[i][j];
        }
    }

    imprimeMatriz(C);

    cout << "Transpuesta: " << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            C[i][j]=A[j][i];
        }
    }

    imprimeMatriz(C);


cout << "Multiplicacion : " << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
                acum=0;
            for (int k=0; k<N; k++){
                acum += A[i][k]* B[k][j];
            }
            C[i][j]=acum;
    }
    }

    imprimeMatriz(C);


   return 0;


}

/// Demostrar que : A(B+C) = AB + AC ;   (A+B)C = AC + BC ; (AB)t= Bt * At ; AI = IA = A
