#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(){

    std::fstream archivo_a_leer;
    //Leemos el archivo
    archivo_a_leer.open("archivo.dat", std::ios::in | std::ios::binary);

    archivo_a_leer.seekg(0, archivo_a_leer.end);
    int tamaño = archivo_a_leer.tellg();
    archivo_a_leer.seekg(0, archivo_a_leer.beg);

    //Para almacenar los datos
    char * datos = new char[tamaño];
	std::string cadena{ };

    //Leemos el archivo
    archivo_a_leer.read(datos, tamaño);

	cadena.assign( datos, tamaño );
	
    //Cerramos el archivo
    archivo_a_leer.close();

    
    //Una vez que hemos terminado de trabajar con los datos, liberamos memoria
    delete[] datos;
}
