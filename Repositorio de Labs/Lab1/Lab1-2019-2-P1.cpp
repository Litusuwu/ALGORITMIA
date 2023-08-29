#include <iostream>
using namespace std;

void solve(){
    int N, P;
    
    cin>>N>>P;

    int costo[N], ganancia[N], predecesores[N][3]{}, predecesor, maxGanancia=0 , answers[N]{};
    bool tiene[N]{};
/////
//    int gananciaTotal=0;

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

    //cout<<P<<endl;
    for(long long mask = 0 ; mask < (1<<N); mask++){

        int ans[N]{}, gananciaTotal=0, costoTotal=0;
        bool flag = true, estaono[N]{}, flagCosto=false;

        for(int bit = 0 ; bit < N ; bit ++){
            if((1<<bit)&mask){
                ans[bit]        =  bit+1;
                gananciaTotal  += ganancia[bit];  
                costoTotal     += costo[bit];
                estaono[bit]    = true;
            }

            if(costoTotal <= P){
                flagCosto=true;
            }
            /////
            for(int i = 0 ; i < N ; i++){ //comprobar predecesores
                if(ans[i]==0){  
                    continue;
                }
                else{
                    if(tiene[i] and ans[i]!=0){
                        //evaluar si tiene o no 
                        //cout<<"a";
                        for(int d = 0 ; d < 3 ; d++){
                            predecesor=predecesores[i][d];
                            //cout<<predecesor;
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
                //cout<<costoTotal<<endl;
                //cout<<"a";
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
