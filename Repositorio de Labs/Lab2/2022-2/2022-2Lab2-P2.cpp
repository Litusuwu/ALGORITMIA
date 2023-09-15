#include <iostream>
using namespace std;

void imprimirMatriz(int matriz[][5]){
    for(int i = 0 ; i<9;i++){
        for(int j=0; j<5; j++){
            cout<<(matriz[i][j]==0? "o": "*")<<" ";
        }
        cout<<endl;
    }
}

int recursion(int x, int y, int f, int c, int matriz[][5],int ans, int matriz2[][5]){
    if(x==f-1 and y==c-1)return ans;
    if(x>=f or y>=c or x<0 or y <0)return 100000;
    int a, b, d, k;

    if(matriz[x][y]==0){
        a=recursion(x, y+1, f, c, matriz, ans+1, matriz2);    
        b=recursion(x+1, y, f, c, matriz, ans+1, matriz2);    
        d=recursion(x+1, y+1, f, c, matriz, ans+1, matriz2);    
        if(a <= b and a<=d)k=a;
        else if(b<=a and b<=d)k=b;
        else k=d;
        return k;
    }
    else{
        matriz2[x][y]=1;
        //flojera xd
        return 100000;
    } 
    
}


int main(){
    int n=9, m=5, ans=0, def;
    int matriz[][5]{{0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 1, 1, 0, 1},
                    {0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 0, 0, 0, 0}};
    int matriz2[][5]{{0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}};
    imprimirMatriz(matriz);
    def=recursion(0, 0, n, m, matriz, ans, matriz2);    
    cout<<endl<<def<<endl;
    imprimirMatriz(matriz2);            
    return 0;
}
