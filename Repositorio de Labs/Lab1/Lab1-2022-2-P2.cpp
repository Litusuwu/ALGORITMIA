#include <iostream>
using namespace std;
#include <cstring>


void solve(){
    string humildad, palabra;
    cin>>humildad>>palabra;
    
    bool flag=true;
    //cout<<palabra.size();
    for(long long mask = 0 ; mask < (1<<10) ; mask ++){
        int ans[palabra.size()]{}, contador=0;
        flag=true;
        for(int bit = 0; bit < 10 ; bit ++){
            if((1<<bit)&mask){
                for(int i = 0 ; i < palabra.size() ; i++){
                    if(humildad[bit]==palabra[i]){
                        ans[i]=bit+1;
                    }
                }
                contador++;
            }
        }
        for(int i = 0 ; i < palabra.size() ; i++){
            if(ans[i]==0){
                flag=false;
                break;
            }
        }
        if(flag and contador==palabra.size()){
            for(int i = 0 ; i < palabra.size() ; i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }  
    }
}

int main(){
    solve();
    return 0;
}
