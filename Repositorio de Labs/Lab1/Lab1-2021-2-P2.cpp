#include <iostream>
using namespace std;

void solve(){
    int N;
    cin>>N;
    int pinga[(N*4)][4]{}, c=1, piso=1, contador=0, ganMax=23, maskAns, counter=1;
//1 num
//2 cuarto
//3 letra lado izq 1 der 0
//4 piso A B piso 1 == A Y PISO 2 ===0

    for(int i = 0 ; i < N*4 ; i++){
        cin>>pinga[i][0];
        if(i==(N*4)/2){
            c=0;
        }
        
        if(contador==N){
            if(piso==1)piso=0;
            else piso=1;

            contador=0;
        }
        pinga[i][2]=c; //izq der
        pinga[i][3]=piso; //A B
        pinga[i][1]=contador; //piso

        contador++;
    }

    for(int mask = 0 ; mask < (1<<(N*4)) ; mask++){

        int ganancia=0;

        for(int bit = 0 ; bit < N*4 ; bit++){
            if((1<<bit) & mask){
                ganancia+=pinga[bit][0];
            }
        }
        if(ganancia == ganMax){
            cout<<"Resultado "<<counter<<":";
            for(int i = 0 ; i < N*4 ; i++){
                if((1<<i) & mask){
                    cout<<pinga[i][0]<<"k ";
                }
            }
            cout<<"  Ubicaciones: ";
            for(int i = 0 ; i < N*4 ; i++){
                if((1<<i) & mask){
                    cout<<((pinga[i][2])==0? "D":"I")<<((pinga[i][3])==0? "B":"A")<<
                    ((pinga[i][1]+1))<<" ";
                }
            }
            cout<<endl<<endl;
            counter++;
        }
    }

    

}

int main(){
    solve();
    return 0;
}
