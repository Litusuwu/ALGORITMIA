#include <iostream>
using namespace std;

void recursion(int matriz[][6], int n,int  m,int x,int y,int &ans, int xm, int ym){
    if(x >5 or y>5 or y<0 or x<0)return;

    for(int i = y ; i < m ; i++ ){
        if(matriz[x][i]==1){
            ans++;
            matriz[x][i]=0;
        }
    }
    for(int i = y ; i >= 0  ; i-- ){
        if(matriz[x][i]==1){
            ans++;
            matriz[x][i]=0;
        }
    }
    for(int i = x ; i < m ; i++ ){
        if(matriz[i][y]==1){
            ans++;
            matriz[i][y]=0;
        }
    }
    for(int i = x ; i >=0 ; i-- ){
        if(matriz[i][y]==1){
            ans++;
            matriz[i][y]=0;
        }
    }
    recursion(matriz, n, m, x+xm, y+ym, ans, xm, ym);
}

int main(){
    string movimiento;
    int n=6, m=6, x=3, y=2, ans=0, xm, ym;
    int matriz[][6]{{0,0,0,1,0,1},
                    {0,0,1,0,0,0},
                    {0,1,0,0,0,1},
                    {1,0,0,0,0,0},
                    {0,1,0,0,0,0},
                    {0,0,0,0,1,0}};
    cin>>movimiento;
    
    if(movimiento=="derecha"){
        xm=0;
        ym=1;
    }   
    else if(movimiento=="izquierda"){
        xm=0;
        ym=-1;
    } 
    else if(movimiento=="arriba"){
        xm=1;
        ym=0;
    }  
    else if(movimiento=="abajo"){
        xm=-1;
        ym=0;
    } 
    else{
        exit(1);
    }
            
            
    
    recursion(matriz, n, m, x, y, ans, xm, ym);
    cout<<ans;

}
