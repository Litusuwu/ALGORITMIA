#include <iostream>
using namespace std;
#include <cstring>
void solveC(){
    int P, N;
    long long cmask;
    cin>>P>>N;
    double contenedor[N][4], maxGan=0, maxInv;
    string nombres[N];
    for(int i =0 ; i < N ; i++){
        cin>>contenedor[i][0]>>nombres[i]>>contenedor[i][1]>>
            contenedor[i][2]>>contenedor[i][3];    
    }

    for(long long mask = 0 ; mask < (1<<N); mask++){ 
        double inversion=0, ganancia=0;   
        for(int bit = 0 ; bit < N ; bit++){
            if((1<<bit) & mask){
                inversion += contenedor[bit][1];
                ganancia  += contenedor[bit][1]*contenedor[bit][2];
            }
        }
        if(ganancia>=maxGan and inversion<=P){
            cmask=mask;
            maxGan=ganancia;
            maxInv=inversion;
        }
    }
    cout<<"El maximo ingreso por ventas es de "<<maxGan<<" dolares con una inversion total en publicidad de "<<maxInv<<" dolares."<<endl<<endl;
    cout<<"Los canales de publicidad que se deben elegir para obtener el maximo ingreso total son : "<<endl;

    for(int i = 0 ; i < N ; i++){
        if((1<<i) & cmask){
            cout<<"- Canal "<<contenedor[i][0]<<" - "<<nombres[i]
            <<", ingreso - "<<(contenedor[i][1]*contenedor[i][2])<<
            " dolares con una inversion publicitaria de "<<contenedor[i][1]<<endl;
        }
    }
}
void solveD(){
    int P, N;
    long long cmask;
    cin>>P>>N;
    double contenedor[N][4], maxGan=0, maxInv, maxRec=0;
    string nombres[N];
    for(int i =0 ; i < N ; i++){
        cin>>contenedor[i][0]>>nombres[i]>>contenedor[i][1]>>
            contenedor[i][2]>>contenedor[i][3];    
    }

    for(long long mask = 0 ; mask < (1<<N); mask++){ 
        double inversion=0, ganancia=0, rec=0;   
        for(int bit = 0 ; bit < N ; bit++){
            if((1<<bit) & mask){
                inversion += contenedor[bit][1];
                ganancia  += contenedor[bit][1]*contenedor[bit][2];
                rec       += contenedor[bit][3];
            }
        }
        if(rec>=maxRec and inversion<=P){
            cmask=mask;
            maxGan=ganancia;
            maxInv=inversion;
            maxRec=rec;
        }
    }
    cout<<"El nivel maximo de recordacion de marca es de "<<maxRec<<" con un ingreso total de "
        <<maxGan<<" con una inversion total en publicidad de "<<maxInv<<" dolares."<<endl<<endl;
    cout<<"Los canales de publicidad que se deben elegir para obtener el maximo ingreso total son : "<<endl;

    for(int i = 0 ; i < N ; i++){
        if((1<<i) & cmask){
            cout<<"- Canal "<<contenedor[i][0]<<" - "<<nombres[i]<<" recordacion de marca - "<<contenedor[i][3]
            <<", ingreso - "<<(contenedor[i][1]*contenedor[i][2])<<
            " dolares con una inversion publicitaria de "<<contenedor[i][1]<<endl;
        }
    }
}
int main(){
    solveD();
    return 0;
}
