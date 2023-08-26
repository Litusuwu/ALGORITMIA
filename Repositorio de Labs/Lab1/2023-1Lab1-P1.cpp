#include <iostream>
using namespace std;
/* M camiones para repartir N paquetes, c/camion tiene ccarga determinada y c/paquete peso determinado
    puede pasar que paquete peso > ccarga; PERO SIEMPRE hay un camion que puede llevar ese paquete
    optima -> dif espacio no utilizado de camion max y min es elm enor posible*/
struct Camion{
    int carga;
    int cargaRestante;
};
struct Paquete{
    int peso;
    int numeroCamion;
    bool empleado;
};
void solve(){
    int N, M, cmask, suma=0, min=99999999, max=0, dif, dif2=99999999;
    bool corresponde=false;
    cin>>M>>N;
    
    Paquete paquetes[N], ansPack[N];
    Camion camiones[M];
    int respuesta[N]{}, definitiva[N]{};

    //lectura de datos
    for(int i=0; i<M; i++){
        cin>>camiones[i].carga;
        camiones[i].cargaRestante=0;
    }
    for(int i=0; i<N; i++){
        cin>>paquetes[i].peso;
        paquetes[i].numeroCamion=0;
        paquetes[i].empleado=false;
        ansPack[i].empleado=false;
        ansPack[i].numeroCamion=0;
        ansPack[i].peso=paquetes[i].peso;
    }

    for(int mask = 0 ; mask< (1<<(N*M)) ; mask++){
        cmask = mask;
        for(int index= 1 ; index <= M ; index++ ){
            for(int bit = 0 ; bit < N ; bit++ ){
                if(((1<<bit) & mask) and !(ansPack[bit].empleado)){
                    ansPack[bit].empleado=true;
                    respuesta[index-1]=index;
                    suma+=ansPack[bit].peso;
                }
            }
            if(suma<=camiones[index-1].carga){
                corresponde=true;
                dif=(camiones[index-1].carga-suma);
                if(dif<=min)min=dif;
                if(max<=dif)max=dif;
            }
            else{
                corresponde=false;
            }
            mask>>=N;
            suma=0;
        }
        dif=max-min;
        for(int i=0; i<N; i++){
            if(ansPack[i].empleado==false)corresponde=false;
            
        }
        
        if(corresponde and dif2>dif){
            for(int i=0; i<N; i++){
                definitiva[i]=respuesta[i];
            }
            dif2=dif;
        }


        mask=cmask;
        max=0;
        min=99999999;
        corresponde=false;
        for(int i=0; i<N; i++){
            respuesta[i]=0;
            ansPack[i].empleado=false;
        }
    }

    for(int i=0; i<N; i++){
        cout<<(definitiva[i])<<" ";
    }

}

int main(){
    solve();
    return 0;
}