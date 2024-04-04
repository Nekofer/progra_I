#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <cstdio>
using namespace std;

//Variables

int x1,x2,x3,x4,r1,r2,r3;
string qq;
char x5[99]={0};
int len;
int aux=0;
int *vec;
int res=0;
int tam=0;

//Funciones

int exp(int a, int b){
	if(a==0 || b==0){
		return 1;
	}
	else{
		return a*exp(a,b-1);
	}
}

int mcd(int c, int d){
	if(d==0){
		return c;
	}
 	else{
 		return mcd(d,c%d);
	}
}

int inv(int e){
	int f1=0;
	int f2;
	if(e>10){
		f1=e/10;
		f2=e%10;
		cout << f2;
		return inv(f1);	
	}
	else{
		cout << e;
	}
}

int sum(int g[], int h){
	if(h==1){
		return g[0];
	}
	else{
		return g[h-1]+sum(g,h-1);
	}
}

int pal(char *f, int ini, int fin){
	if(ini>=fin){
		return 1;
	}
	if(f[ini]==f[fin]){
		return pal(f, ini+1, fin-1);
	}
	else{
		return 0;
	}
}

int main() {
	
	char ww[50];
	int llen=strlen(ww);
	int re=pal(ww,0,llen-1);
	vec=new int[tam];
	
	cout << "Ingrese el primer numero: "; cin >> x1;
	cout << "Ingrese el segundo numero: "; cin >> x2;
	r1=exp(x1, x2);
	cout << "El resultado es: " << r1 << endl;
	
	cout << "Ingresa el primer numero: "; cin >> x2;
	cout << "Ingresa el primer numero: "; cin >> x3;
	r2=mcd(x2, x3);
	cout << "El mcd es: " << r2 << endl;
	
	cout << "Ingrese el numero: "; cin >> x4;
	inv(x3);

	cout << "Ingrese el tamaño del arreglo: "; cin >> tam;
	for(int i=0; i<tam; i++){
		cout << "Ingrese los numeros a sumar: "; cin >> vec[i];
	}
	res=sum(vec,tam);
	cout << "El resultado es: " << res;
	
	cout << "Introduce un palindromo: "; cin.getline(ww,50,'n');
	if(re){
		cout << "Es palindromo";
	}
	else{
		cout << "No es palindromo";
	}
	return 0;
}
