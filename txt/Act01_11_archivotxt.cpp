#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <conio.h>
using namespace std;

int main(){
	int op, opc;
	char ruta[40];
	char linea[80];
	char archivo[50];
	char n_archivo[50];
	char nombre[20];
	int score;
	int vidas;
	int n_death;
	do{
		cout << "1. Crear archivo\n"; 
		cout << "2. Leer archivo\n";
		cout << "3. Salir\n";
		cout << "--> "; cin >> op;
		switch(op){
			case 1:
				cout << "Introduzca el nombre del archivo: "; cin >> n_archivo;
				ofstream archivo_salida(n_archivo);
				strcat(n_archivo,".txt");
				cout << "Nombre: "; cin >> nombre;
				cout << "Puntuacion: "; cin >> score;
				cout << "Numero de vidas: "; cin >> vidas;
				cout << "Numero de muertes: "; cin >> n_death;
				archivo_salida << nombre << endl << score << endl << vidas << endl << n_death;
			break;
			archivo_salida.close();
			case 2:
				cout << "Ingrese el nombre del archivo (ejem: datos.txt): "; cin >> archivo;
				cout << "Archivo Buscado... " << archivo << "\n\n"; 
				ifstream leer_arc (archivo);
				if (leer_arc)      
					cout << "Apertura con exito\n\n";  
				else      
					cout << "No se ha podido abrir el archivo\n";
				while (!leer_arc.eof()) 
				{
					leer_arc >> linea; 
					cout << linea << endl;
				};
				cout<<"\n | Fin de lectura de archivo |\n\n";
				system("pause>nul");
			break;
			leer_arc.close(); 
			case 3:
				//exit(1);
			break;
		}	
		cout << "Quiere realizar otra operacion?: "; cin >> opc;
	}while(opc!=2);
	return 0;
}
