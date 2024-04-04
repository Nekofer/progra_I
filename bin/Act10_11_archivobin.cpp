// Fernando Toledo Pacciotta - 335097

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct an{
	int id;
	char name[40];
	char breed[40];
	char birth[40]; //place
	char diet[40];
	char clas[40]; 
};

int c=0;
const int lim = 20; 
char arc[20] = "ArchivoAnimales.dat";

void gen(){
	fstream archivo;
    archivo.open(arc, ios::binary|ios::out|ios::trunc);
    if (!archivo) { 
        cerr << " ------ No se pudo abrir el archivo ------ " << endl;
    }else{
        an base = {000,"","","","",""}; //blank
        for(int i=0; i<lim; i++){
            archivo.write( reinterpret_cast<char *> (&base),sizeof(an));
    	}
        archivo.close(); // cierra el archivo
    }  
}

int count(){
    fstream archivo;
    archivo.open(arc, ios::binary|ios::in);
    if (!archivo) {  
        cerr << "No se pudo abrir el archivo" << endl; 
    }else{
        an y;
        for(int i=0; i<lim; i++){
            archivo.read( reinterpret_cast<char *> (&y),sizeof(an));
            if(y.id!=0){
                c++;
            } 
        }
        archivo.close(); // cierra el archivo
    } 
    return c;
}

void nd(){
	int num = count();
    cout << "Actualmente tenemos " << num << " animales" << endl;
    an z;
    cout << " Animales  " << num+1<<endl;
    cout << "   ID: " ;
    cin  >> z.id;
    cout << "   Nombre: ";
    cin  >> z.name;
    cout << "   Raza: " ;
    cin  >> z.breed;
    cout << "   Lugar de nacimiento: ";
    cin  >>  z.birth;
    cout << "   Dieta: " ;
    cin  >> z.diet;
    cout << "   Clasificacion: ";
    cin  >> z.clas;  

    fstream archivo;
    archivo.open(arc, ios::binary|ios::in|ios::out);
    archivo.seekp((num) * sizeof(an), ios::beg); 
    archivo.write(reinterpret_cast<char*>(&z),sizeof(an));
    cout << "Datos grabados...\n ";
    archivo.close();
}

void read(){
	fstream archivo;
    cout << "Base de datos: " << endl;
    archivo.open(arc, ios::binary|ios::in);
    if (!archivo) {  
        cerr << "No se pudo abrir el archivo" << endl; 
    }else{
        an x;
        for(int i=0; i<lim; i++){
            archivo.read( reinterpret_cast<char *> (&x),sizeof(an));
            cout << "-Animal  " << i+1<<endl;
            cout << "   ID     : " << x.id << endl;
            cout << "   Nombre : " << x.name<< endl;
            cout << "   Raza: " << x.breed<< endl;
            cout << "   Lugar de nacimiento  : " << x.birth << endl;
            cout << "   Dieta : " << x.diet << endl;
            cout << "   Clasificacion : " << x.clas << endl << endl;    
        }
        archivo.close(); 
    } 
}

int main(){
	system("color f9");
	int op, opc;
	do{
		cout << "1. Generacion de texto vacio\n";
		cout << "2. Agregar animal\n";
		cout << "3. Mostrar animales\n";
		cout << "4. Mostrar total de datos\n";
		cout << "5. Salir\n";
		cout << "--> "; cin >> op;
		switch(op){
			case 1:
				cout << "Precaucion... si ya existe el archivo se borrara"<< endl;
                cout << "Generando desde cero nuestra base de datos ( cascaron )"<< endl;
                gen();
			break;
			
			case 2:
				nd();
			break;
			
			case 3:
				read();
			break;
			
			case 4:
				count();
				cout << "Tenemos: " << c+1 << endl;
			break;
			
			case 5:
				exit(1);
			break;
		}
		system("pause");
		system("cls");
		cout << "Desea realizar otra operacion: "; cin >> opc;
	}while(opc!=2);
	return 0;
}
