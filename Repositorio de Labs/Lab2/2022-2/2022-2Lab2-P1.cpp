#include <iostream>
using namespace std;
void imprimirMatriz(int matriz[][6]){
    for(int i = 0 ; i<6;i++){
        for(int j=0; j<6; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}
void recursion(int matriz[][6],int F ,int C,int &P,int count , int cant, int par){
    if(count == F){
        cout<<"No es posible ordenar el anaquel"<<endl<<endl;
        return;
    }
    int limInf, limSup;
    limInf=C/2-cant;
    limSup=C/2+cant+par;
    if(limSup>C)limSup=C;
    if(limInf<0)limInf=0;
    for(int i = limInf ; i < limSup ; i++){
        if(matriz[count][i]==0 and P!=0){
            matriz[count][i]=5;
            P--;
            if(P==0){
                cout<<"Si es posible ordenar el anaquel"<<endl<<endl;
                return;
            }
        }
    }
    recursion(matriz, F, C, P, count+1, cant+1, par);
    
}

int main(){
    int F, C, P, Print, par;
    cin>>F>>C>>P;
    int matriz[][6]{{0, 0, 0 ,0 ,0, 0},
                    {0, 0, 0 ,0 ,0, 0},
                    {0, 0, 0 ,0 ,0, 0},
                    {0, 1, 0 ,1 ,0, 0},
                    {0, 0, 0 ,0 ,0, 0},
                    {0, 0, 1 ,0 ,0, 0}};
    Print=(C%2==0? 1 : 0);
    par=(C%2==0? 0 : 1);
    imprimirMatriz(matriz);
    cout<<endl;
    recursion(matriz, F , C, P, 0 , Print, par);
    imprimirMatriz(matriz);
}
