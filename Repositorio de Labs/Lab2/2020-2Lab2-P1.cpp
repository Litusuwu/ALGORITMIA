#include <iostream>
using namespace std;

void recursion(int matriz[][3], int n, int i1, int i2, int i3, int index, int &ans){
    if(i1>2 or i2>2 or i3>2) return;
    if(index==n and i1!=i2 and i2!=i3){
        ans=(ans<(matriz[0][i1]+matriz[1][i2]+matriz[2][i3])? (matriz[0][i1]+matriz[1][i2]+matriz[2][i3]) : ans);
        return;
    }
    recursion(matriz, n, i1+1, i2, i3, index+1, ans);
    recursion(matriz, n, i1, i2+1, i3, index+1, ans);
    recursion(matriz, n, i1, i2, i3+1, index+1, ans);
}

int main(){
    int n=3, ans=0;
    int matriz[][3]{{100, 150, 200},
                    {100, 100, 100},
                    {100, 200, 150}};
    recursion(matriz, n, 0, 0, 0, 0, ans);
    cout<<ans;
    return 0;
}
