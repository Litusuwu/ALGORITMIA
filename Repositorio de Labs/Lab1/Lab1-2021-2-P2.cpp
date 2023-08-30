#include <iostream>
using namespace std;

void solve(){
    int T, P, N;
    cin>>T>>P>>N;
    // S*i  0< i < N y 0<N<=16
    double acciones[N][4], ganMax=0, accionesAns;
    long long ans;

    for(int i = 0 ; i < N ; i ++ ){
        cin>>acciones[i][0]>>acciones[i][1]>>acciones[i][2];
        acciones[i][3]= P*acciones[i][1]*acciones[i][2];
    }

    for(long long mask = 0 ; mask < (1<<N) ; mask++){

        double ganancia=0, accionesXD=0;

        for(int bit = 0 ; bit < N ; bit ++){
            if((1<<bit) & mask ){
                ganancia += acciones[bit][3];
                accionesXD += acciones[bit][1];
            }
        }
        if(ganancia>=ganMax and accionesXD<=T){
            ans=mask;
            ganMax=ganancia;
            accionesAns=accionesXD;
        }
    }
    cout<<"Para este conjunto de datos, una solucion con la maxima ganancia debido a las comisiones seria de "
        <<ganMax<<" dolares por un total de "<<accionesAns<<" acciones."<<endl;
    for(int i = 0 ; i < N ; i ++ ){
        if((1<<i) & ans){
            cout<<"El cliente "<<acciones[i][0]<<
            " otorga una ganancia de "<<acciones[i][3]<<
            " dolares por comprar "<<acciones[i][1]<<" acciones."<<endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
