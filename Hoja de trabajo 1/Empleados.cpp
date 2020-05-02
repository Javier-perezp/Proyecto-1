/*Descripción de problema:
Escribir una función Salario que calcule los salarios de un trabajador para un número dado de horas trabajadas y un salario hora.
Las horas que superen las 40 horas semanales se pagarán como extras con un salario hora 1,5 veces el salario ordinario.
Así mismo se deberá calcular el monto a pagar de IGSS por cada trabajador.
El programa deberá mostrar un menú para:
1) Invocar dicha función y grabar datos a un archivo
2) Adicionalmente deberá tener una opción para leer el archivo y grabar los datos en memoria
3) Una opción para mostrar cuanto se paga de total de planilla e IGSS.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct empleado{
	string nombre;
	string apellido;
	int codemp;
	float salarioo;
	float salariop;
	float costoh;
	float costohe;
	float igss;	
	int horast;
	int horase;		
};

void insertar_datos_archivo();
void read_file();
void salario(empleado& ingreso);
void mp();//menu principal

int main(){
	
	mp();
}

void salario(empleado& ingreso){
	
	ofstream archivo;
	string nombreArchivo;
	fflush(stdin); 
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombreArchivo);

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	system("CLS");
	
	float salarioo,igss,salariop,costoho,costohe;	
	string nombre,apellido;
	int horast,horase,codemp;
	
	cout<<"Ingrese Codigo de Empleado: "<<endl;
	cin>>codemp; //ingreso.codemp;
	fflush(stdin);
	cout<<"Ingrese Nombre de Empleado: "<<endl;
	getline(cin,nombre,'\n');//,ingreso.nombre);
	cout<<"Ingrese Apellido de Empleado: "<<endl;
	getline(cin,apellido,'\n');//,ingreso.nombre);
	cout<<"Ingrese Salario Ordinario: "<<endl;
	cin>>salarioo;
	cout<<"Ingrese Horas Trabajadas: "<<endl;
	cin>>horast;
	
	costoho = salarioo/30/8;
	if (horast>40)
		horase= horast-40;
	igss = ((horast-horase)*costoho) * 0.0483;
	costohe = (horase *costoho)*1.5;
	salariop = ((horast-horase)*costoho + costohe)-igss;
	
	archivo.open(nombreArchivo.c_str(),ios::app);
	archivo<<nombre<<"\t"<<apellido<<"\t"<<codemp<<"\t"<<salarioo<<"\t"<<salariop<<"\t"<<costoho<<"\t"<<costohe<<"\t"<<igss<<"\t"<<horast<<"\t"<<horase<<endl;
	
	archivo.close();
} 

void mp(){
	int i;
	empleado datos;
	
	do {
		system("CLS");
		cout<<"----------------------"<<"\n";
		cout<<"    Menu Principal"<<"\n";
		cout<<"----------------------"<<"\n";
		cout<<"1 - Ingresar Empleado "<<"\n";
		cout<<"2 - Leer archivo"<<"\n";
		cout<<"3 - Reporte"<<"\n";
		cout<<"4 - Salir"<<"\n";
		cout<<"----------------------\n";
		cout<<"Seleccione su opcion: ";
		cin>>i;
		if (i==1)
			salario(datos);
		else if (i==2)
			read_file();			
		else if (i==3) 	
			read_file();
		else if (i==4)
			break;
		else 
			break;
		
	} while(i!=4);	
}


void read_file(){
	ifstream archivo;
	string nombreArchivo;
	int lineas,i=0;
	string s,linea;
	float sumatotal=0;
	
	system("CLS");
	fflush(stdin);
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}
	
	while (getline(archivo, s))
        lineas++;
        
    archivo.close();
    system("CLS");
	empleado recordset_r[lineas];
		
	archivo.open(nombreArchivo.c_str(),ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }

        archivo>>recordset_r[i].nombre>>recordset_r[i].apellido>>recordset_r[i].codemp>> recordset_r[i].salarioo >> recordset_r[i].salariop >> recordset_r[i].costoh
		 >> recordset_r[i].costohe >>  recordset_r[i].igss >> recordset_r[i].horast >>  recordset_r[i].horase; 

    }
    archivo.close();    
    
    for (int i = 0; i < lineas; i++)
    {
    	cout<<"Registro: "<<i<<endl; 
    	cout<<"Codigo"<<setw(8)<<"Nombre"<<setw(10)<<"Apellido "<<setw(10)<<"Salario O"<<setw(10)<<"Salario P"<<setw(10)<<"Costo HO "<<"Costo HE "<<"IGSS "<<"Horas T "<<"Horas E"<<endl;
    	cout<<recordset_r[i].codemp<<"\t"<<recordset_r[i].nombre<<setw(10)<<recordset_r[i].apellido<<setw(10)<<recordset_r[i].salarioo<<setw(10)<<recordset_r[i].salariop<<setw(10)<<recordset_r[i].costoh<<setw(6)<<recordset_r[i].costohe<<setw(10)<<recordset_r[i].igss<<setw(6)<<recordset_r[i].horast<<setw(6)<<recordset_r[i].horase<<setw(6)<<endl;
		sumatotal = sumatotal + recordset_r[i].salariop;
	}
	cout<<"Total a pagar: "<<sumatotal<<endl;
	system("Pause");
	
}

void insertar_datos_archivo(){
	cout<<"Insertando datos\n\n";
	system("PAUSE");
	system("CLS");
}
