#include <iostream>
using namespace std;

void p(int *q, double *r, char *s){
	cout << "el entero es " << *q << endl;
    cout << "el double es " << *r << endl;
    cout << "el caracter es " << *s << endl;
}

int main(){

	//Parte 1
	
	float a;
	float *b;
	cout << "Ingresa un valor con decimales: "; cin >> a;
	b=&a;
	cout << "Valor: " << *b << endl;
	cout << "Direccion: " << &b << endl;
	*b=*b*2;
	cout << "El resultado de la operacion es: " << *b;
	
	//Parte 2
	
	int c, d, r;
	int *e, *f, *g;
	cout << "Ingrese el primer valor: "; cin >> c;
	cout << "Ingrese el segundo valor: "; cin >> d;
	e=&c; f=&d, g=&r;
	*g=*e+*f;
	cout << "La direccion del resultado es: " << g << endl;
	cout << "El resultado de la operacion es: " << *g;
	
	//Parte 3
	
	int h[10];
	int *i;
	i = h;
	for(int x=1; x<=10; x++){
		cout << "Ingresa el " << x << " numero: "; cin >> h[x];
	}
	for(int y=0; y<=9; y++){
		i++;
		cout << *i << endl;
	}
	for(int z=10; z>=1; z--){
		cout << *i << endl;
		i--;
	}
	
	//Parte 4
	
	int j[5];
	int k[5];
	int l[5];
	int *m, *n, *o;
	m = j;  n = k; o = l;
	for(int x=1; x<=5; x++){
		cout << "Ingresa el " << x << " numero: "; cin >> j[x];
	}
	for(int y=1; y<=5; y++){
		cout << "Ingresa el " << y << " numero: "; cin >> k[y];
	}
	for(int z=1; z<=5; z++){
		m++;
		n++;
		o++;
		*o=*m+*n;
		cout << *o << endl;
	}

	//Parte 5
	
	int t;
	double u;
	char v;
	cout << "Ingrese un numero: "; cin >> t;
	cout << "Ingrese un numero flotante"; cin >> u;
	cout << "Ingrese una letra: "; cin >> v;
	p(&t,&u,&v);
	
	return 0;
}
