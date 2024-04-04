#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Alumno{
    char nombre[50];
    char carrera[30];
    int  ID;
    float calificaciones[3]; //todas valen 33%
    float Final;
    int faltas;
    bool aprobado;  // calcular // 0= reprobado y 1=aprobado
};

const int limite_alumnos = 20;
int nA ;
char Nombre_Archivo[30] = "Reprobados_2022.dat"; 

void Generar_cascaron(){
    fstream archivo;
    archivo.open(Nombre_Archivo, ios::binary|ios::out|ios::trunc);
    if ( !archivo ) { // verifica la existencia del archivo 
        cerr << " No se pudo abrir el archivo " << endl; // cambiamos por cout
    }else{
        Alumno base = {"","",0,{0,0,0},0,0,true}; // registro en blanco
        for(int i = 0; i < limite_alumnos; i++){
            archivo.write( reinterpret_cast<char *> (&base),sizeof(Alumno));
        }
        archivo.close(); // cierra el archivo
    }  
}

int Cantidad_de_alumnos_capturados(){
    fstream archivo;
    int c=0;
    archivo.open(Nombre_Archivo, ios::binary|ios::in);
    if ( !archivo ) { // verifica la existencia del archivo 
        cerr << " No se pudo abrir el archivo " << endl; // cambiamos por cout
    }else{
        Alumno x;
        for(int i = 0; i < limite_alumnos; i++){
            archivo.read( reinterpret_cast<char *> (&x),sizeof(Alumno));
            if(x.ID!=0){
                c++;
            } 
        }
        archivo.close(); // cierra el archivo
    } 
    return c;
}

void Leer_archivo(){
    fstream archivo;
    cout << "Se mostrara a continuacion toda nuestra base de datos :  " << endl;
    archivo.open(Nombre_Archivo, ios::binary|ios::in);
    if ( !archivo ) { // verifica la existencia del archivo 
        cerr << " No se pudo abrir el archivo " << endl; // cambiamos por cout
    }else{
        Alumno x;
        for(int i = 0; i < limite_alumnos; i++){  
            archivo.read( reinterpret_cast<char *> (&x),sizeof(Alumno));
            cout << "-Alumno  " << i+1<<endl;
            cout << "   ID     : " << x.ID << endl;
            cout << "   nombre : " << x.nombre<< endl;
            cout << "   carrera: " << x.carrera<< endl;
            for(int k=0;k<3 ;k++){
                cout << "      Calificacion "<<k+1<<" : " << x.calificaciones[k] <<endl;
            };
            cout << "   Final  : " << x.Final << endl;
            cout << "   Faltas : " << x.faltas << endl;
            cout << "   Aprobado : " << x.aprobado << endl << endl;    
        }
        archivo.close(); // cierra el archivo
    } 
}

void Dar_de_alta(){
    int numero = Cantidad_de_alumnos_capturados();
    cout << "Actualmente tenemos " << numero << " alumnos" << endl;
    Alumno x;
    float p=0;
    cout << " Alumno  " << numero+1<<endl;
    cout << "   ID     : " ;
    cin  >> x.ID;
    cout << "   nombre : ";
    cin  >> x.nombre;
    cout << "   carrera: " ;
    cin  >> x.carrera;
    for(int k=0;k<3 ;k++){
        cout << "      Calificacion "<<k+1<<" : " ;
        cin >> x.calificaciones[k];
        p += x.calificaciones[k];
    };
    p /= 3;
    x.Final=p;
    //cout << "   Final  : ";
    //cin  >>  x.Final; // calcular **
    cout << "   Faltas : " ;
    cin  >> x.faltas;
    if(p<6 || x.faltas>10 ){
         x.aprobado=false;
    }else{
        x.aprobado=true;
    }
    //cout << "   Aprobado : ";
    //cin  >> x.aprobado;  // calcular **

    fstream archivo;
    archivo.open(Nombre_Archivo, ios::binary|ios::in|ios::out);
    archivo.seekp((numero) * sizeof(Alumno), ios::beg); // write escribe el registro una vez ya posicionado
    archivo.write(reinterpret_cast<char*>(&x),sizeof(Alumno));
    cout << "Datos grabados...\n ";
    archivo.close();
}

void exportar(){
	fstream archivo;
    archivo.open(Nombre_Archivo, ios::binary|ios::in);
    
    
}

int main(){
	int opc,opc2;
    char contrasenia[10] = "hola123", resp[10]; 
    float p;
    do{
        cout << " ------ MENU archivos binarios -------" << endl;
        cout << " - 1  - Generar cascaron             -" << endl;
        cout << " - 2  - Dar de alta usuario          -" << endl; 
        cout << " - 3  - Mostrar     		     	  -" << endl;
        cout << " - 12 - Reporte-Exportar datos(texto)-" << endl;
        cout << " -------------------------------------" << endl;
        cout << " - 0  - Salir                        -" << endl;
        cout << " -------------------------------------" << endl;
        cin >>opc;
        switch (opc){
        case 1:
                cout << "Cuidado si ya existe el archivo se borrara"<< endl;
                cout << "ingresa la constraseña para realizar esto de lo contrario no lo borrare :";
                cin >> resp;
                if(strcmp(resp,contrasenia)==0){
                    cout << "Generando desde cero nuestra base de datos ( cascaron )"<< endl;
                    Generar_cascaron();
                }else{
                    cout << "no se activo el proceso" << endl;
                }
                break;
        case 2:
                Dar_de_alta();
                break;
        case 3:
                Leer_archivo();
                break;
        case 12:
                exportar();
                break;
        default:
            break;
        }
        system("pause");
        system("cls");    // limpiar consola
    }while(opc!=0);

    return 0 ;
}

