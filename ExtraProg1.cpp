#include<iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int menu(){
	int r;
	cout << endl << endl;
	cout << "1. Factorial \n";
	cout << "2. Obtencion de Iva \n";
	cout << "3. Promedio \n";
	cout << "4. Salir \n";
	cout << "Ingrese su opcion: "; cin >> r;
	return r;
}

int factorial(double n){
    if(n==1){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

void iva(){
	float m, r;
	cout << "Ingrese el monto: "; cin >> m;
	r = m * 0.16;
	cout << "El monto final es de: " << r;
}

void promedio(){
	string al[3];
	int materias[12];
	int prom[3];
	cout << "Ingrese el nombre del alumno (1): "; cin >> al[0];
	cout << "Ingrese el nombre del alumno (2): "; cin >> al[1];
	cout << "Ingrese el nombre del alumno (3): "; cin >> al[2];
	for(int i=0; i<=12; i++){
		cout << "Ingrese la calificacion n." << i << ": "; cin >> materias[i];
	}
	prom[0]=(materias[0]+materias[1]+materias[2]+materias[3])/4;
	prom[1]=(materias[4]+materias[5]+materias[6]+materias[7])/4;
	prom[2]=(materias[8]+materias[9]+materias[10]+materias[11])/4;
	cout << "El promedio del alumno: " << al[0] << "es: " << prom[0];
	cout << "El promedio del alumno: " << al[1] << "es: " << prom[1];
	cout << "El promedio del alumno: " << al[3] << "es: " << prom[2];
}

int main() {
	system("color f9");
	int opc;
	int r, n;
	do{
		r=menu();
		switch (r){
			case 1:
				cout << "Ingresa el numero: "; cin >> n;
				factorial(n);
			break;	
			case 2:
				iva();
			break;
			case 3:
				promedio();
			break;
			case 4:
				exit(1);
			break;
		}
		cout << "Quiere elegir otra opcion? [Si=1 // No=2]: "; cin >> opc;	
		system("cls");	
	}while(opc!=2);
	return 0;
}







