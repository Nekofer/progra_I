#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;

string map1[3][3]={{"#","#","#"},
				   {"#","#","#"},
				   {"#","#","#"}};

int main(){
	char nombre[40];
	int score;
	int vidas, muertes;
	int opc,op,i=0;
	char c, cadena[80];
	fstream archivo;
	cout<<"1.- Agregar"<<endl;
	cout<<"2.- Datos existentes"<<endl;
	cout<<"3.- Datos existentes (leido caracter por caracter)"<<endl;
	cout<<"4.- Datos existente (leido linea por linea)"<<endl;
	cout<<"--> "; cin>>op;
	switch(op){
	   case 1: 
	   		archivo.open("Archivo.txt",ios::out|ios::app);
	    	archivo << map1;
	    	archivo.close();
	    break;
		case 2:
	    	archivo.open("Archivo.txt",ios::in);
		    while(archivo >> nombre >> score >> vidas >> muertes){
		    cout << "Nombre: " <<  nombre << "\nPuntuacion: "<< score << "\nVidas: "<< vidas << "\nMuertes: " << muertes <<"\n"<<endl; 
			};
		    archivo.close(); 
	    break;
	    case 3:
	    	archivo.open("Archivo.txt",ios::in);
	    	c = archivo.get();
			while ( ! archivo.eof() ){
			cout<< c << endl;
			archivo.get( c );
		}
		archivo.close();
	    break;
	    case 4:
	    	archivo.open("Archivo.txt",ios::in);
			archivo.getline( cadena, 80 ); 
			while ( ! archivo.eof() ){
			cout<< cadena<<endl; 
			archivo.getline( cadena, 80 );
			}
		archivo.close();
		break;
	}
	return 0;
}
