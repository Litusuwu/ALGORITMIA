#include <iostream>
using namespace std;

void solve(){
	int M, D, P, cc[4], kmgal[4], k5m[4], t4,var1, respuesta[4], ans=(~(1 << (sizeof(int) * 8 - 1)));
	int cantCondicion2 , cantCondicion3;
	bool condicion1, condicion2, condicion3, condicion4;
	cin>>M>>D>>P;
	for(int i=0 ; i<4 ; i++){
//		cout<<"Ingrese los datos de capacidad de carga "<<i<<": ";
		cin>>cc[i];
	}
	for(int i=0 ; i<4 ; i++){
	//	cout<<"Ingrese los datos de rendimiento en kms/galon del tipo "<<i<<": ";
		cin>>kmgal[i];
	}
	for(int i=0 ; i<4 ; i++){
		//cout<<"Ingrese los datos de costo en soles por servicio c/5000km del tipo "<<i<<": ";
		cin>>k5m[i];
	}
	
	for(int t1= 0 ; (t1 < 32) ; t1++){
		
		for(int t2 = 0 ; (t2 < 32) ; t2++){
			for(int t3 = 0 ; t3 < (32); t3++){
				t4 = 32 - t1 - t2 - t3;
				var1=(t1*cc[0] + t2*cc[1] + t3*cc[2] + t4*cc[3]);
				
				if(var1==M){
					cantCondicion2= (((t1*(k5m[0]*D))/5000)+((t2*(k5m[1]*D)/5000))+
									((t3*(k5m[2]*D)/5000))+ ((t4*(k5m[3]*D)/5000)));

					cantCondicion3= (t1*P*(D/kmgal[0]))+(t2*P*(D/kmgal[1]))+(t3*P*(D/kmgal[2]))
									+(t4*P*(D/kmgal[3]));
					cout<<cantCondicion3+cantCondicion2<<"xdxdxd"<<endl;
					if((cantCondicion2+cantCondicion3) < ans){
						respuesta[0]=t1;
						respuesta[1]=t2;
						respuesta[2]=t3;
						respuesta[3]=t4;
						ans=(cantCondicion2+cantCondicion3);
					}
				}
			}
		}
	}

	cout<<respuesta[0]<<" "<<respuesta[1]<<" "<<respuesta[2]<<" "<<respuesta[3]<<" xd";

}

int main(){

	solve();
	return 0;
}