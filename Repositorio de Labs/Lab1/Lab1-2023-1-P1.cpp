#include <iostream>
#include <cmath>
using namespace std;

void cargarBase(int n, int *arr, int b, int a){
    int re, j=0;
    for(int i=0;i<b; i++)arr[i]=0;

    while(n>0){
        re=n%a;
        n/=a;
        arr[j]=re;
        j++;
    }

}

void solve(){
    int N, M, value,dif, minDif=99999999, comp, contador=1;
    bool flag=true;
    cin>>M>>N;
    //por combinatoria, si tenemos N paquetes que TODOS deben estar en al menos
    // 1 camion, entonces el numero de combinaciones es N a la M camiones
    value=pow(N, M);
    //los datos estan para el primer caso del pdf
    int mascara[N], paquetes[N]{50 , 20 , 30, 50},
         camiones[M]{100, 100, 100},  ansDefini[N]{};

    for(int mask = 0 ; mask < value ; mask++){
        flag = true;
        //transformamos la base a base M, puesto que para cada paquete puede haber M estados porque puede estar en 1 - M camiones
        int  ans[N]{},cam[M]{}, max = 0 , min = 99999999;
        cargarBase(mask, mascara, N , M);
        //el arreglo ans tiene N paquetes y vamos acomodando segun la mascara los camiones(por el numero), ubicando en que tipo
        // de camion está cada paquete
        /* por ejemplo, M = 3, N = 4
            si la mascara en base M (3) es asi:
                1 2 0 1
                Entonces:
                El paquete 1 va al carro 2 (1 +1 por index)
                El paquete 2 va al carro 3 (2 +1 por index)
                El paquete 3 va al carro 1 (0 +1 por index)
                El paquete 4 va al carro 2 (1 +1 por index)
        (Esta es la parte mas dificil de comprender pero recuerda lo que se hacia en el ejemplo de las mochilas, el index es +1 porque
            en el arreglo, el arr[0] en realidad es la posicion 0+1)
        */
        for(int bit = 0 ; bit < N ; bit++){
            ans[bit]= mascara[bit];
        }
        //llenamos los camiones con el valor de los paquetes
        for(int it=0 ; it < N ; it++){
            cam[ans[it]]+=paquetes[it];
        }
        //evaluamos si ningun camion excede su carga y tenemos una bandera para verificar
        for(int j = 0 ; j < M ; j++){
            if(cam[j]>camiones[j]){
                flag=false;
            }
        }
        //si los camiones almacenan correctamente segun su capacidad realizar lo siguiente:
        if(flag == true){
            //encontramos la diferencia entre los camiones llenados y los que no, y analizamos la diferencia minima y maxima
            for( int k = 0 ; k < M ; k++){
                dif= camiones[k] - cam[k];
                if(dif<min){
                    min=dif;
                }
                if(dif>max){
                    max=dif;
                }
            }
            //le damos a COMP el valor de la diferencia entre el minimo y maximo espacio usado
            comp=max-min;
            if(comp<=minDif){
                minDif=comp;
            //guardamos el arreglo de respuestas
                for(int i=0; i<N; i++){
                    ansDefini[i]=ans[i];
                }
            }
            //activar este comment si quieres ver todas las soluciones
            /*if(comp == minDif){
                cout<<"Caso Dif=0 #"<<contador<<" : "<<endl;
                for(int i = 0 ; i < N ; i++){
                    cout<<"Paquete "<<(i+1)<<" : "<<ansDefini[i]+1<<endl;
                }
                cout<<"Dif maxima: "<<minDif<<endl<<endl;
                contador++;
            }*/
        }
        
    }
    //Aqui imprimimos la solucion optima, o la ultima que todas las combinaciones halló, aunque salga una "distinta" a la del pdf,
    // realmente cumple con TODAS Las condiciones, asi que funciona.
    for(int i = 0 ; i < N ; i++){
        cout<<"Paquete "<<(i+1)<<" : "<<ansDefini[i]+1<<endl;
    }
    cout<<"Dif : "<<minDif<<endl<<endl;    
    
}
int main(){
    solve();
    return 0;
}
