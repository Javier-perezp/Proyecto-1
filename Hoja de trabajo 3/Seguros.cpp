#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

struct empleado{
	string nombre;
	string apellido;
	int codemp;
	float salario;
};

void mp();
void registro();
void lectura();
	
int main(){
	mp();
	system("pause");
	exit(1);
}

void mp(){//Menu principal
	int resp;
	
	do {
		system("cls");
		cout<<" --------------------------"<<"\n";
		cout<<"       Menu Principal"<<"\n";
		cout<<" --------------------------"<<"\n";
		cout<<" 1 - Ingresar un nuevo seguro "<<"\n";
		cout<<" 2 - Mostrar seguros guardados "<<"\n";
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
	string nombre, modelo, color;
	int edad;
	float precio, incremento, aux;
	fflush(stdin);
	cout<<"Ingrese Nombre: ";
	getline(cin,nombre);
	cout<<"Ingrese su Edad: ";
	cin>>edad;
	fflush(stdin);
	cout<<"Ingrese modelo: ";
	getline(cin,modelo);

	if(modelo=="A"){
		
		cout<<"Ingrese el color del vehiculo A: ";
		getline(cin,color);
		
		if (color=="Blanco"){
			precio=240.50;
			
		}
		else if(color=="Metalizado"){
			precio=330.00;
		}
		else{
			precio=270.50;
		}
	}
	else if(modelo=="B"){
		
		cout<<"Ingrese el color del vehiculo B: ";
		getline(cin,color);
		
		if (color=="Blanco"){
			precio=300.00;
		}
		else if(color=="Metalizado"){
			precio=360.50;
		}
		else{
			precio=330.00;
		}
	}
	else{
		system("cls");
		cout<<"Ingrese A o B\n";
		system("Pause");
	}
	
	if(edad<=31){
		aux=precio*0.25;
		incremento=aux+precio;
	}		
	else if(edad>31&edad<=65){
		incremento=0;
	}
	else if(edad>65){
		aux=precio*0.30;
		incremento=aux+precio;
	}
		
	fflush(stdin);
	
	ofstream archivo; //leer archivo 
	archivo.open("Seguros.txt",ios::app);
		
	archivo<<nombre<<"\t"<<edad<<"\t"<<modelo<<"\t"<<color<<"\t"<<precio<<"\t"<<incremento<<endl;
	archivo.close();
		
}


void lectura(){
	ifstream archivo;
	string texto;
	
	archivo.open("Seguros.txt",ios::in);//in: abrir archivo modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cout<<"Nombre"<<"\t"<<"Edad"<<"\t"<<"Modelo"<<"\t"<<"Color"<<"\t"<<"Precio"<<"\t"<<"Incremento"<<endl;
	while(!archivo.eof()){//mientras no sea el final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}

	archivo.close();
}

