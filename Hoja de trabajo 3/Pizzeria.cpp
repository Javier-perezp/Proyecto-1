#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

struct ventas{
	string pizza;
	int cantidad;
	float precio, preciotot, descuento;
};

void mp();
void registro();
void lectura();

int main(){
	mp();
	return 0;
}


void mp(){//Menu principal
	int resp;
	
	do {
		system("CLS");
		cout<<" --------------------------"<<"\n";
		cout<<"       Menu Principal"<<"\n";
		cout<<" --------------------------"<<"\n";
		cout<<" 1 - Ingresar venta "<<"\n";
		cout<<" 2 - Mostrar el registro de ventas "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<" --------------------------"<<"\n";
		cout<<"   Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			registro();			
		}
		else if (resp==2){		
			system("CLS");
			lectura();
			system("pause");
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}


void registro(){
	int cantidad;
	string pizza;
	float precio, preciotot, descuento, aux;
	
	system("cls");
	fflush(stdin);
	cout<<" --------------------------"<<"\n";
	cout<<"       Tipo de Pizza"<<"\n";
	cout<<" --------------------------"<<"\n";
	cout<<"         - Grande "<<"\n";
	cout<<"         - Familiar "<<"\n";
	cout<<"         - Fiesta "<<"\n";
	cout<<"  Que tipo de pizza desea?:  ";
	getline(cin,pizza);
	
	if(pizza=="Grande"){
		cout<<"   Cuantas pizzas desea?: ";
		cin>>cantidad;
		cout<<"    Ingrese el precio: ";
		cin>>precio;
		preciotot=precio*cantidad;
		aux=preciotot*0.10;
		descuento=preciotot-aux;
	
	}
	else if(pizza=="Familiar"){
		
		cout<<"   Cuantas pizzas desea?: ";
		cin>>cantidad;
		cout<<"    Ingrese el precio: ";
		cin>>precio;
		preciotot=precio*cantidad;
		aux=preciotot*0.15;
		descuento=preciotot-aux;
	}
	else if(pizza=="Fiesta"){
		
		cout<<"  Cuantas pizzas desea?: ";
		cin>>cantidad;
		cout<<"    Ingrese el precio: ";
		cin>>precio;
		preciotot=precio*cantidad;
		aux=preciotot*0.20;
		descuento=preciotot-aux;
	}
	else{
		system("cls");
		cout<<"Error";
		system("Pause");
		
	}	
	
	
	fflush(stdin);
	
	ofstream archivo; //leer archivo 
	archivo.open("Ventas.txt",ios::app);
	
		
	archivo<<pizza<<"\t"<<cantidad<<"\t"<<precio<<"\t"<<preciotot<<"\t"<<descuento<<endl;
	archivo.close();
	
}


void lectura(){
	
	ifstream archivo; //leer archivo 
	archivo.open("Ventas.txt",ios::in); // leer archivo
	int lineas,i=0;
	string s,linea;	
	float tota=0, totdes=0, menos;
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	ventas recordset[lineas];
	
	archivo.open("ventas.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr<< "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].pizza>>recordset[i].cantidad>>recordset[i].precio>>recordset[i].preciotot>>recordset[i].descuento;
    }
    archivo.close(); 
    cout<<"Pizza   \tCantidad\tPrecio\tPrecio Total\tDescuento\n";
    for(int i = 0; i <lineas; i++){
    	cout<<recordset[i].pizza<<"   \t"<<recordset[i].cantidad<<"       \t"<<recordset[i].precio<<"\t"<<recordset[i].preciotot<<"       \t"<<recordset[i].descuento<<endl;
		tota=recordset[i].preciotot+tota;
		totdes=recordset[i].descuento+totdes;
	}
	cout<<"\nPrecio total global: ";
	cout<<tota<<endl;
	cout<<"Precio total con descuento: ";
	cout<<totdes<<endl;
	menos=tota-totdes;
	cout<<"Descuento total: "<<menos<<endl<<endl;
	archivo.close();	
	
}








