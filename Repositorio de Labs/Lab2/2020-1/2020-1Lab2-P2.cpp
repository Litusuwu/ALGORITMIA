#include <iostream>
using namespace std;

void imprimirMatriz(int matriz[][5]){
    for(int i = 0 ; i<6;i++){
        for(int j=0; j<5; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}

void recursion(int matriz[][5], int n, int m, int max, int min, int &productos, int rowI, int rowF,
               int &productosColoc){
    int contador=0;
    if(max<min or rowI>rowF or rowF==rowI){
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(matriz[rowI][i]==0){
            matriz[rowI][i]=5;
            contador++;
            productos--;
            productosColoc++;
        }
        if(matriz[rowI][i]==1)contador++;
        if(contador==max)break;
    }

    recursion(matriz, n, m, max-1, min, productos, rowI+1, rowF-1, productosColoc);
    contador=0;
    for(int i = 0 ; i < n ; i++){
        if(matriz[rowF][i]==0){
            matriz[rowF][i]=5;
            contador++;
            productos--;
            productosColoc++;
        }
        else if(matriz[rowF][i]==1)contador++;
        if(contador==max)break;
    }
}

int main(){
    
    int matriz[][5]{{0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0}};
    int n=6, m=5, max=5, min=3, productos=20, productosColoc=0;
    int rowI=0, rowF=n-1;
    //imprimirMatriz(matriz);
    recursion(matriz, n, m, max, min, productos, rowI, rowF, productosColoc);
    imprimirMatriz(matriz);
    cout<<endl<<"Se pueden ubicar los productos : "<<(productos==0? "1":"0")<<endl<<
    "Ubicaciones : "<<productosColoc;
}
