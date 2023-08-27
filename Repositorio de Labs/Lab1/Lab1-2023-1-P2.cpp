#include <iostream>
#include <cmath>
using namespace std;

int maximo(int a, int b){
    return (a<b)? b:a;
}

void solve(){
    //declaracion inicial de variables
    int cantNiveles, cantRobots, pesosVidrios, pesosRobots,
        pesoMin=0, contador=1;
    cin>>cantNiveles>>cantRobots;
    //declaracion de arreglos
    int pisos[cantNiveles][2], robots[cantRobots], ans[cantNiveles][2];
    bool flag=true;


    for(int i=0 ; i < cantNiveles ; i++){
        cin>>pisos[i][0]>>pisos[i][1];
    }
    for(int i = 0 ; i < cantRobots ; i++){ 
        cin>>robots[i];
        pesoMin=maximo(robots[i], pesoMin);
    }
    //cout<<pesoMin;
    for( int mask = 0 ; mask < (1<<cantNiveles) ; mask++){
        for(int bit = 0 ; bit < cantNiveles ; bit++ ){
            if((1<<bit) & mask){ //1 = DERECHA Y 0 = IZQUIERDA
                ans[bit][0] = pisos[bit][0];
                ans[bit][1] = 0;
            }
            else{
                ans[bit][0] = pisos[bit][1];
                ans[bit][1] = 1;
            }
            if(ans[bit][0]<pesoMin)flag=false;
        }
        if(flag){
            cout<<"Solucion #"<<contador<<" : "<<endl;
            for(int i = 0 ; i < cantNiveles ; i++){

                cout<<"Piso #"<<i<<": "<<(ans[i][1] == 1? "Derecha" : "Izquierda")<<endl;
            }
            contador++;
        }
        flag=true;
    }
}


int main(){
    solve();
    return 0;
}
