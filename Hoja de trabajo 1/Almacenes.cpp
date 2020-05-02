/*Una empresa tiene diez almacenes y necesita crear un programa que lea las ventas mensuales de los diez almacenes,
calcular la media de ventas y obtener un listado de los almacenes cuyas ventas mensuales son superiores a la media. 
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct vtas{
  int almacenid;
  int mes;
  float montovendido;
};

int main() {
  int i, n=0, bandera=0;  
  float sumatotal=0,media,mayor;
  string almacenes =" ";
  cout<<"\n          Bienvenido "<<endl;
  cout<<"----------------------------------"<<endl;
  cout<<" Cuantas Ventas Desea Ingresar? ";
  cin>>n;
  
  vtas ventas[n];
  	for(i=0;i<n;i++){
  		system("CLS");
    	cout<<"\nIngrese el Codigo de Almacen:   ";
    	cin>>ventas[i].almacenid;
    	cout<<"Ingrese el Mes de la Venta:   ";
    	cin>>ventas[i].mes;
    	cout<<"Ingrese el Monto Vendido:   ";
    	cin>>ventas[i].montovendido;
    	sumatotal=sumatotal+ventas[i].montovendido;
  	}
  	
  	media= sumatotal/n;
  	mayor=media;
	system("CLS");
	cout<<"\nPromedio General:   "<<media<<endl;
		  	
	for(i=0;i<n;i++){
  		
		if(ventas[i].montovendido>mayor){
		  	cout<<"Ventas mayores al promedio:  "<<"Almacen:"<<ventas[i].almacenid<<"\t Mes:"<<ventas[i].mes<<"\tMonto:"<<ventas[i].montovendido<<endl;
		  	bandera=1;
		}
  		
	}
	if (bandera==0){
		cout<<"No hay ventas mayores al promedio"<<endl<<endl;
	}
	system("pause");
}
