#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void funcion1();
void funcion2(int x, int y);
int funcion3();
int funcion4(int x, int y, int z);

int main(int argc, char** argv) {
	system("color f9");
	int opc;
	int op;
	int x,y,z,r;
	int *p;
	do{
	cout << "1. Funcion matriz \n";
	cout << "2. Funcion base de un triangulo \n";
	cout << "3. Funcion suma \n";
	cout << "4. Funcion numero menor \n";
	cout << "Ingresa una opcion: "; cin >> opc;
	switch (opc){
		case 1:
			funcion1();
		break;	
		case 2:
			cout<< "Dame la base: "; cin >> x;
			cout<< "Dame la altura: "; cin >> y;
			funcion2(x,y);
		break;
		case 3:
			z = funcion3();
			cout << "El resultado de la suma es: " << z;
			cout << endl;
			p = &z;
			cout << "La direccion de la variable es: " << p;
		break;
		case 4:
			int x1,x2,x3,resul;
			cout<<"Dame el primer numero ";
			cin>>x1;
			cout<<"Dame el segundo numero ";
			cin>>x2;
			cout<<"Dame el tercer numero ";
			cin>>x3;
			resul= funcion4(x1,x2,x3);
			cout<<"El numero menor es : "<<resul<<endl;
		break;
	}
	cout << "Quiere elegir otra opcion? [Si=1 // No=2]: "; cin >> op;	
	system("cls");
	}while(op!=2);
	return 0;
}

void funcion1(){
	int mat[3][3];
	int r;
	srand(time(NULL));
	for (int x=0; x<=2; x++){
		for (int y=0; y<=2; y++){
			mat[x][y] = 1+rand()%(10-1);
		}
	}
	for (int x=0; x<=2; x++){
		for (int y=0; y<=2; y++){
			cout << " " <<mat[x][y];
		}
		cout << endl;
	}
}

void funcion2(int x, int y){
	int z;
	z = (x*y)/2;
	cout << "La base del triangulo es: " << z;
}

int funcion3(){
	int x, y, z;
	cout << "Ingrese el primer valor: "; cin >> x;
	cout << "Ingrese el segundo valor: "; cin >> y;
	z = x + y;
	return z;
}

int funcion4(int x, int y, int z){
	int r;
	if(x<y && x<z){
		r=x;
	}else if(y<z){
		r=y;
	}else{
     	r=z;
 	}
	return r;
}
