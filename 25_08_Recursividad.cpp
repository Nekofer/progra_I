#include<iostream>
using namespace std;

//variables
int cont;

//funciones
double fibonacci(double n, double n1, int limite, int posicion);


int main(){
	system("color f9");
	int n;
	cout << "Ingresa un numero: "; cin >> n;
	cout << "Fibonacci: " << fibonacci(0,1,n,2) << endl;
	//cout << "Usamos: " << cont << " veces" << endl;
	
	return 0;
}

/*
double recursividad(double n){
	cont++;
	if(n==1){
		return 1;
	}
	else{
		return n * recursividad(n-1);
	}
}
*/

double fibonacci(double n, double n1, int limite, int posicion){
	cout << n << " - " << n1 << " - " << limite << " - " << posicion << endl;
	if(posicion==limite){
		return n+n1;
	}
	else{
		return fibonacci(n1,double(n+n1),limite,++posicion);
	}
}
