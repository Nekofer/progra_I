/*

Realizado por:
Fernando Toledo Pacciotta
Angel Santiago Urzua Castañeda
Paris Ahmed Hernandez Perez
Jorge Ernesto Montes Lopez

*/

#include<iostream>
using namespace std;

//variables

int x1,y1,x2,y2,x3,y3,r1,r2,r3;

//funciones

int mult(int a, int b){
	if(a==0 || b==0){
		return 0;
	}
	else{
		return mult(a,b-1)+a;
	}
}

int div(int c, int d){
	if(c<d){
		return 0;
	}
 	else{
 		return div(c-d,d)+1;
	}
}

int res(int e, int f){
	int g;
	if(e<f){
		return e;
	}
 	else{
 		return res(e-f,f);
	}
}

int main(){
	int op,op1;
	system("color f9");
	do{
		cout << "1. Multiplicacion\n";
		cout << "2. Division\n";
		cout << "3. Residuo\n";
		cout << "Que operacion quiere realizar? "; cin >> op1;
		switch(op1){
			case 1:
				cout << "Ingrese el primer numero: "; cin >> x1;
				cout << "Ingrese el segundo numero: "; cin >> y1;
				r1 = mult(x1,y1);
				cout << "El resultado es: " << r1 << endl;
			break;
			case 2:
				cout << "Ingrese el dividendo: "; cin >> x2;
				cout << "Ingrese el divisor: "; cin >> y2;
				if(y2!=0){
					r2=div(x2,y2);
					cout << "El resultado es: " << r2 << endl;
				}
				else{
					cout << "El divisor no puede ser 0 " << endl;
				}
			break;
			case 3:
				cout << "Ingrese el dividendo: "; cin >> x3;
				cout << "Ingrese el divisor: "; cin >> y3;
				if(y3!=0){
					r3=res(x3,y3);
					cout << "El resultado es: " << r3 << endl;
				}
				else{
					cout << "El divisor no puede ser 0 " << endl;
				}
			break;
		}
		cout << "Quiere realizar otra operacion?[Si=1 // No=2]: "; cin >> op;
	}while(op!=2);
	return 0;
}
