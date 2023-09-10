#include <iostream>
using namespace std;
void recursion2(int matrizP[][9], int indexDia, int index, int limite, int &indexAns,int &valAns){
    if(index==limite)return;
    if(matrizP[indexDia][index]>valAns){
        indexAns=index;
        valAns=matrizP[indexDia][index];
    }
    recursion2(matrizP, indexDia, index+1, limite, indexAns, valAns);
}
void recursion3(int matrizP[][9],int diaActual, int i, int p, int times){
    if(times>i)return;
    int indexAns=0, valAns=0;
    recursion2(matrizP, diaActual, 0, p, indexAns, valAns);
    matrizP[diaActual][indexAns]=-1;
    cout<<valAns<<" ";
    recursion3(matrizP, diaActual, i, p,times+1);
}
void recursion(int m,int i,int n,int d,int p,int &ans,int matrizP[][9], int diaActual,
               bool &flag){
    if(i<n){
        cout<<endl<<"La respuesta es : "<<ans;
        return;
    }
    //condicion de parada
    if(flag){
        cout<<"Dia "<<diaActual+1<<": ";
        recursion3(matrizP, diaActual, i, p, 1);
        cout<<endl;
        ans++;
        recursion(m, i-1, n, d, p , ans,matrizP, diaActual+1, flag);
    }
    else{
        cout<<"Dia "<<diaActual+1<<": ";
        recursion3(matrizP, diaActual, i, p, 1);
        cout<<endl;
        ans++;
        if(i==m ){
            flag=true;
            recursion(m, i, n, d, p , ans,matrizP, diaActual+1, flag);
        }
        else{
            recursion(m, i+1, n, d, p , ans,matrizP, diaActual+1, flag);
        }
    }
}
int main(){
    int m=8, i=6, n=4,d=10,p=9, ans=0, limite=8;
    bool flag=false, flag2=false;
    int matrizP[][9]{{1, 2, 3, 4, 5, 6, 7, 8, 0},
                     {1, 2, 3, 4, 5, 6, 7, 8, 1},
                     {1, 2, 3, 4, 5, 6, 7, 8, 2},
                     {1, 2, 3, 4, 5, 6, 7, 8, 3},
                     {1, 2, 3, 4, 5, 6, 7, 8, 4},
                     {1, 2, 3, 4, 5, 6, 7, 8, 5},
                     {1, 2, 3, 4, 5, 6, 7, 8, 6},
                     {1, 2, 3, 4, 5, 6, 7, 8, 7},
                     {1, 2, 3, 4, 5, 6, 7, 8, 8},
                     {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    recursion(m, i, n, d, p, ans, matrizP, 0, flag);
}
