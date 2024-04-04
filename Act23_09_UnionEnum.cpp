#include <iostream>

using namespace std;

union A{
	char num_in[100];
	char code[100];
	char nombre[100];
	char des[100];
}a;

union nier{
	char modelo[100];
	char years[100];
	char id[100];
	char aplic[100]; 
}yorha;

enum B {sencilla=1, doble, suit, deluxe};

enum C {f=1, b, c, d, e};

void u1(union A a){
	bool f,b,c,d;
	int op,opc,opd;
	f=false;
	b=false;
	c=false;
	d=false;
	do{
		cout << "Numero interno[1]\n";
		cout << "Codigo de barras[2]\n";
		cout << "Nombre[3]\n";
		cout << "Descripcion[4]\n";
		cout << "Salir[5]\n";
		cout << "Eliga la opcion a guardar: "; cin >> op;
		switch(op){
			case 1:
				cout << "Ingrese el numero interno: "; cin >> a.num_in;
				f=true;
			break;
			
			case 2:
				cout << "Ingrese el codigo de barras: "; cin >> a.code;
				b=true;
			break;
			
			case 3:
				cout << "Ingrese el nombre: "; cin >> a.nombre;
				c=true;
			break;
			
			case 4:
				cout << "Ingrese el descripcion: "; cin >> a.des;
				d=true;
			break;
			
			case 5:
				exit(1);
			break;
		}
		cout << "Desea mostrar el valor guardado? [Si=1 // No=2]: "; cin >> opd;
		switch(opd){
			case 1:
				if(f=true){
					cout << "Numero interno: " << a.num_in << endl;
				}
				else if(b=true){
					cout << "Codigo de barras:" << a.code << endl;
				}
				else if(c=true){
					cout << "Nombre: " << a.nombre << endl;
				}
				else if(d=true){
					cout << "Descripcion: " << a.des << endl;
				}
			break;
			
			case 2:
			
			break;
		}
		cout << "Desea guardar otro dato? [Si=1 // No=2]: "; cin >> opc;
	}while(opc!=2);
}

void u2(union nier yorha){
	bool f,b,c,d;
	int op,opc,opd;
	f=false;
	b=false;
	c=false;
	d=false;
	do{
		cout << "Modelo[1]\n";
		cout << "Años[2]\n"; // la ñ se vera raro pero bueno
		cout << "Id[3]\n";
		cout << "Aplicacion[4]\n";
		cout << "Salir[5]\n";
		cout << "Eliga la opcion a guardar: "; cin >> op;
		switch(op){
			case 1:
				cout << "Ingrese el modelo: "; cin >> yorha.modelo;
				f=true;
			break;
			
			case 2:
				cout << "Ingrese el año: "; cin >> yorha.years;
				b=true;
			break;
			
			case 3:
				cout << "Ingrese el id: "; cin >> yorha.id;
				c=true;
			break;
			
			case 4:
				cout << "Ingrese su aplicacion: "; cin >> yorha.aplic;
				d=true;
			break;
			
			case 5:
				exit(1);
			break;
		}
		cout << "Desea mostrar el valor guardado? [Si=1 // No=2]: "; cin >> opd;
		switch(opd){
			case 1:
				if(f=true){
					cout << "Modelo: " << yorha.modelo << endl;
				}
				else if(b=true){
					cout << "Año:" << yorha.years << endl;
				}
				else if(c=true){
					cout << "ID: " << yorha.id << endl;
				}
				else if(d=true){
					cout << "Aplicacion: " << yorha.aplic << endl;
				}
			break;
			
			case 2:
			
			break;
		}
		cout << "Desea guardar otro dato? [Si=1 // No=2]: "; cin >> opc;
	}while(opc!=2);
}

int main(){
	union A a;
	union nier yorha;
	enum B b;
	enum C c;
	int opw, opx;
	do{
		cout << "Union - Producto[1]\n";
		cout << "Union - Automatas de combate[2]\n";
		cout << "Enumeracion - Tipos de habitacion[3]\n";
		cout << "Enumeracion - Datos[4]\n";
		cout << "Salir[5]\n";
		cout << "Eliga la opcion a guardar: "; cin >> opw;
		switch(opw){
			case 1:
				u1(a);
			break;
			
			case 2:
				u2(yorha);
			break;
			
			case 3:
				b = suit;
				cout << b;
			break;
			
			case 4:
				c = d;
				cout << c;
			break;
			
			case 5:
				exit(1);
			break;
		}
		cout << "Desea seleccionar otra opcion? [Si=1 // No=2]: "; cin >> opx;
	}while(opx!=2);
	return 0;
}
