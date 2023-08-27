#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int maximo(int a, int b){
    return (a<b)? b:a;
}

void solve(){
    int cantHerramientas, M, P, maxCant=0 /**/,ansCant=0,
         ansPrecio=0, cantH=0, defCant, defPrecio;
    //bool flag = false;
    cin>>cantHerramientas>>M>>P;
    int arr[cantHerramientas][2], ans[cantHerramientas]{};
    //lectura
    for(int i = 0 ; i < cantHerramientas ; i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    //humilde
    for(ll mask = 0 ; mask < (1<<cantHerramientas) ; mask++){
        
        ll maybeAns[cantHerramientas]{};

        for(ll bit = 0 ; bit < cantHerramientas ; bit++){
            if((1<<bit)&mask){
                ansPrecio+=(arr[bit][1] * arr[bit][0]);
                ansCant+=arr[bit][1];  
                maybeAns[bit]=(bit+1);
                cantH++;
            }
        }

        if(cantH<=M and ansPrecio<=P and ansCant>=maxCant){
            //cout<<'a';
            for(int i = 0 ; i < cantHerramientas ; i++){
                ans[i]=maybeAns[i];
            }
            defCant=ansCant;
            defPrecio=ansPrecio;
            //cout<<defCant<<endl;
            maxCant=maximo(ansCant, maxCant);
        }
        ansCant=0;
        ansPrecio=0;
        cantH=0;

    }
    cout<<"Monto Total : "<<defPrecio<<endl;
    cout<<"Cantidad de Herramientas: "<<defCant<<endl;
    for(int i = 0 ; i < cantHerramientas ; i++){
        
        if(ans[i]!=0)cout<<ans[i]<<" ";
    }
}
int main(){
    solve();
    return 0;
}
