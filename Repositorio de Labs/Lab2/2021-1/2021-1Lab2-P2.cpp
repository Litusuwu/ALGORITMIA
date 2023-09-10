#include <iostream>
using namespace std;
/*
si 0 b+1 y descendente
si 1 b-1 y ascendente
*/

void ordenarAscendente(int matrizValor[][7],char matrizLetra[][7],int T,int diaActual){
	for (int i = 0; i < T - 1; i++) {
        for (int j = 0; j < T - i - 1; j++) {
            if (matrizValor[diaActual][j] > matrizValor[diaActual][j + 1]) {
                int temp = matrizValor[diaActual][j];
                char temp2= matrizLetra[diaActual][j];
                matrizValor[diaActual][j] = matrizValor[diaActual][j + 1];
                matrizValor[diaActual][j + 1] = temp;

                matrizLetra[diaActual][j] = matrizLetra[diaActual][j + 1];
                matrizLetra[diaActual][j + 1] = temp2;
            }
        }
    }
}
void ordenarDescendente(int matrizValor[][7],char matrizLetra[][7],int T,int diaActual){
	for (int i = 0; i < T - 1; i++) {
        for (int j = 0; j < T - i - 1; j++) {
            if (matrizValor[diaActual][j] < matrizValor[diaActual][j + 1]) {
                int temp = matrizValor[diaActual][j];
                char temp2= matrizLetra[diaActual][j];
                matrizValor[diaActual][j] = matrizValor[diaActual][j + 1];
                matrizValor[diaActual][j + 1] = temp;

                matrizLetra[diaActual][j] = matrizLetra[diaActual][j + 1];
                matrizLetra[diaActual][j + 1] = temp2;
            }
        }
    }
}
void recursion(int Presupuesto,int &P,int C,int T,int B, int diaActual,int compras,
			   int matrizValor[][7],char matrizLetra[][7],int tendencia[],
			   int tipoCambio, bool &flag){
	if(flag){
		cout<<"Solo se ha podido comprar acciones hasta el dia "<<diaActual-1<<
			" , tiene "<<Presupuesto-P<<" dolares en acciones y le ha quedado "
			<<P<<" dolar(es) de presupuesto. "<<endl;
		return;
	}
	int contadorCompras=0;
	int sum = (tipoCambio? B+1 : B-1);
	cout << "Dia "<<diaActual+1<<" :   "<<"Presupuesto: "<<P<<" "<<"Acciones Compradas: ";
	if(tipoCambio==1)ordenarDescendente(matrizValor, matrizLetra, C, diaActual);
	else ordenarAscendente(matrizValor, matrizLetra, C, diaActual);

	for(int i = 0 ; i < C ; i ++){
		if(P>=matrizValor[diaActual][i]){
			cout<<"("<<matrizLetra[diaActual][i]<<") "<<matrizValor[diaActual][i]<<" ";
			P-=matrizValor[diaActual][i];
			contadorCompras++;
		}
		if(contadorCompras==compras)break;
	}
	cout<<endl;
	if(contadorCompras==0)flag=true;
	recursion(Presupuesto, P, C, T, B, diaActual+1, sum,matrizValor, matrizLetra,tendencia,
			  tendencia[diaActual+1], flag);
}
int main(){
	int P=36, C=7, T=6, B=2;
	bool flag=false;
	int matrizValor[][7]{{3, 4, 5, 6, 7, 1, 2},
						 {3, 4, 5, 7, 1, 2, 6},
						 {3, 4, 5, 2, 1, 6, 8},
						 {3, 4, 5, 6, 2, 1, 9},
						 {3, 4, 5, 7, 8, 9, 2},
						 {3, 4, 5, 8, 9, 7, 6}};
	char matrizLetra[][7]{{'A', 'B', 'C', 'D', 'E', 'F', 'G'},
						  {'A', 'B', 'C', 'D', 'E', 'F', 'G'},
						  {'A', 'B', 'C', 'D', 'E', 'F', 'G'},
						  {'A', 'B', 'C', 'D', 'E', 'F', 'G'},
						  {'A', 'B', 'C', 'D', 'E', 'F', 'G'},
						  {'A', 'B', 'C', 'D', 'E', 'F', 'G'}};
	int tendencia[6]{1, 1, 0, 0, 1, 1};
	recursion(P,P, C, T, B, 0, B,matrizValor, matrizLetra,tendencia, tendencia[0], flag);
}
