#include <iostream>
using namespace std;

void solve(){
    long long N, C, M, sum=0, cant=0, cmask, caso=1;
    cin>>N>>M>>C;
    int time=3*N;
    int arr[3][N];
    for(int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    for(long long mask=0 ; mask<(1<<(time)) ; mask++){
        cmask=mask;
        for(int timer=0 ; timer<3; timer++){
            for(int bit=0 ; bit<N ; bit++){
                if((1<<bit) & mask){
                    sum+=arr[timer][bit];
                    cant++;
                }
            }
            mask>>=N;
        }
        if(sum==C and cant==M){
            cout<<"Caso #"<<caso<<":"<<endl;
            mask=cmask;
            for(int timer=0; timer<3; timer++){
                cout<<"Bahia "<<(timer+1)<<": ";
                for(int bit=0; bit<N ; bit++){
                    if(1<<bit & mask){
                        cout<<arr[timer][bit]<<" ";
                    }
                }
                cout<<endl;
                mask>>=N;
            }
            cout<<endl;
            caso++;
        }
        sum=0;
        cant=0;
        mask=cmask;
    }
}
int main(){
    solve();    
    return 0;
}
