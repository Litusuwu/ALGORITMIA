#include <iostream>
using namespace std;
void solve(){
    int N, P;
    cin>>N>>P;
    int costo[N], ganancia[N], predecesores[N][3]{}, predecesor, maxGanancia=0 , answers[N]{};
    bool tiene[N]{};
//  lectura de datos
    for(int i = 0 ; i < N ; i ++){
        cin >> costo[i] >> ganancia [i];
        if(cin.get()!=' ') continue;
        else {
            tiene[i]=true;
            for(int j = 0 ; j < 3 ; j ++ ){
                cin>>predecesores[i][j];
                if(cin.peek()=='\n')break;
            }
        }
    }
    //usamos un cromosoma ( es lo equivalente a 1<<N por secuencia de bits, segun el profe se puede usar en el lab)
    for(long long mask = 0 ; mask < (1<<N); mask++){
    //declaras variables que se reinician por cada combinacion
        int ans[N]{}, gananciaTotal=0, costoTotal=0;
        bool flag = true, estaono[N]{};
    //si hay un 1 en la combinacion, actualizas las siguientes variables
        for(int bit = 0 ; bit < N ; bit ++){
            if((1<<bit)&mask){
                ans[bit]        =  bit+1;
                gananciaTotal  += ganancia[bit];  
                costoTotal     += costo[bit];
                estaono[bit]    = true;
            }
            for(int i = 0 ; i < N ; i++){ //comprobar predecesores
                if(ans[i]==0){  
                    continue;
                }
                else{
                    if(tiene[i] and ans[i]!=0){
                        //evaluar si tiene o no 
                        for(int d = 0 ; d < 3 ; d++){
                            predecesor=predecesores[i][d];
                            if(predecesor!=0){
                                if(!estaono[predecesor-1]){
                                    flag=false;
                                }
                            }
                        }
                    }
                }
            }
            
            if((costoTotal<=P) and flag and (gananciaTotal>=maxGanancia)){
                for(int i = 0 ; i < N ; i ++){
                    answers[i]=ans[i];
                }
                maxGanancia=gananciaTotal;
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        if(answers[i]==0)continue;
        cout<<answers[i]<<" ";
        
    }
    cout<<endl<<"Con ganancia total de : "<<maxGanancia;
}
int main(){
    solve();
    
    return 0;
}
