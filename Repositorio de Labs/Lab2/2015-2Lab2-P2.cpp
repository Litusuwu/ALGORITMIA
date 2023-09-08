#include <iostream>
#include <iomanip>
using namespace std;

void patron(int n, int y){
    if(n==2){
        for(int i=0 ; i < y ; i++)cout<<" ";
        cout<<"*"<<endl;
        for(int i=0 ; i < y ; i++)cout<<" ";
        cout<<"**"<<endl;
        for(int i=0 ; i < y+1 ; i++)cout<<" ";
        cout<<"*"<<endl;
        return;
    }
    
    patron(n/2, y);
    
    for(int i = 0 ; i < y ; i++)cout<<" ";
    for(int i = 0 ; i < n ; i++)cout<<"*";
    cout<<endl;

    patron(n/2, y+n/2);

}
int main(){
    patron(8,0);
    return 0;
}
