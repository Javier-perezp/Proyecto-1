#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

void menu();
void registro();
void lectura();

int main(){
	menu();
	return 0;
}


void menu(){
	int resp;
	
	do {
		system("CLS");
		cout<<" --------------------------"<<"\n";
		cout<<"       Menu Principal"<<"\n";
		cout<<" --------------------------"<<"\n";
		cout<<" 1 - Ingresar"<<"\n";
		cout<<" 2 - Mostrar"<<"\n";
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
	int tipo=0;
	float total=0, hecta=0, precio=0, desc=0, descad=0, aux=0, tot=0, aux1=0, aux2=0;
	
	cout<<"Ingrese el tipo de servicio que necesita: "<<"\n";
	cout<<" ----------------------------"<<"\n";
	cout<<"   1 - Mala hierva - Q10.00"<<"\n";
	cout<<"   2 - Langostas - Q20.00"<<"\n";
	cout<<"   3 - Gusanos - Q30.00"<<"\n";
	cout<<"   4 - Todo lo anterior - Q50.00"<<"\n";
	cout<<" ----------------------------"<<"\n";
	cout<<"   Seleccione su opcion: ";
	cin>>tipo;
	
	cout<<"Ingrese el numero de hectareas a fumigar: ";
	cin>>hecta;
	
	if(tipo==1){
		tot=hecta*10.00;
		if(hecta>500){
			desc=tot*0.05;
			aux=desc;
		}
		
		if(tot>1500.00){
			aux1=tot-1500;
			aux2=aux1*0.10;
			descad=aux2;	
		}
		total=tot-aux-descad;
	}	
	
	else if(tipo==2){
		tot=hecta*20.00;
		if(hecta>500){
			desc=tot*0.05;
			aux=desc;
		}
		
		if(tot>1500.00){
			aux1=tot-1500;
			aux2=aux1*0.10;
			descad=aux2;	
		}
		total=tot-aux-descad;
	}
		
	else if(tipo==3){
		tot=hecta*30.00;
		if(hecta>500){
			desc=tot*0.05;
			aux=desc;
		}
		
		if(tot>1500.00){
			aux1=tot-1500;
			aux2=aux1*0.10;
			descad=aux2;	
		}
		total=tot-aux-descad;
	}
		
	else if(tipo==4){
		tot=hecta*50.00;
		if(hecta>500){
			desc=tot*0.05;
			aux=desc;
		}
		
		if(tot>1500.00){
			aux1=tot-1500;
			aux2=aux1*0.10;
			descad=aux2;	
		}
		total=tot-aux-descad;
	}
	
	fflush(stdin);
	
	ofstream archivo; //leer archivo 
	archivo.open("Ventas.txt",ios::app);
	
		
	archivo<<tipo<<"\t   "<<hecta<<"\t\t"<<tot<<"\t\t"<<aux<<"\t\t"<<descad<<"\t\t"<<total<<endl;
	archivo.close();
}

void lectura(){
	ifstream archivo;
	string texto;
	
	archivo.open("ventas.txt",ios::in);//in: abrir archivo modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout<<"Servicio   "<<"Hectareas"<<"\t"<<"Precio"<<"\t\t"<<"Descuento 1"<<"\t"<<"Descuento 2"<<"\t"<<"Total a pagar"<<endl;
	while(!archivo.eof()){//mientras no sea el final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}

	archivo.close();
}



