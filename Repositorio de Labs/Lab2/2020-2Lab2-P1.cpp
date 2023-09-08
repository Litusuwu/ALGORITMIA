#include <iostream>
using namespace std;

bool arreglo[26]{};

void funcion(int matriz[][4], int x, int y, int n, int m, int &k){
    int h=x, v=y;
    if(k<=0)return;
    if(x==n-1 and y==m-1){
        cout<<matriz[x][y]<<" ";
        return;
    }
    for( v=y; v < m-1 ; v++){
        
        cout<<matriz[h][v]<<" ";
        k-=matriz[h][v];
        
        if(k<=0)return;
    }
    for(h = x ; h < n-1; h++){
    
        cout<<matriz[h][v]<<" ";
        
        k-=matriz[h][v];
        if(k<=0)return;
    }
    
    
    for( v=m-1; v >y ; v--){
        
        cout<<matriz[h][v]<<" ";
        
        k-=matriz[h][v];
        if(k<=0)return;
    }
    for(h = n-1 ; h > x; h--){
        
        cout<<matriz[h][v]<<" ";
//        cout<<h<<"and"<<v;
        k-=matriz[h][v];
        if(k<=0)return;
    }
    
    //return;
    funcion(matriz, h+1, v+1, n-1, m-1, k);
}

int main(){
    
    /*int k=((25*26)/2);
    int n=5, m=5, x=0, y=0;
    int matriz[][5]{{1, 2, 3, 4, 5},
                    {6, 7, 8, 9 ,10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20},
                    {21, 22, 23, 24, 25}};*/
    /*int k=((9*10)/2);
    int n=3, m=3, x=0, y=0;
    int matriz[][3]{{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};*/
    int k=((12*13)/2);
    int n=3, m=4, x=0, y=0;
    int matriz[][4]{{1, 2, 3, 4},
                    {5, 6, 7, 8 },
                    {9, 10, 11, 12}};
    funcion(matriz, x, y, n, m,k);


    return 0;
}
