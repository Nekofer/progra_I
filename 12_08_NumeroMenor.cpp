#include<iostream>
using namespace std;

void menorNoNo();
void menorNoSi(int x, int y, int z);
int menorSiNo();
int menorSiSi(int x, int y, int z);

int main(){
	
	// Menor No - No
	menorNoNo();
	
	// Menor No - Si
	int x, y, z;
	cout << "Ingresa el primer numero: "; cin >> x;
	cout << "Ingresa el segundo numero: "; cin >> y;
	cout << "Ingresa el tercero numero: "; cin >> z;
	menorNoSi(x,y,z);
	
	// Menor Si - No
	int re;
	re = menorSiNo();
	cout << "El numero menor es: " << re;
	
	// Menor Si - Si
	int x1, y2, z3, rel;
	cout << "Ingresa el primer numero: "; cin >> x1;
	cout << "Ingresa el segundo numero: "; cin >> y2;
	cout << "Ingresa el tercero numero: "; cin >> z3;
	rel = menorSiSi(x1,y2,z3);
	cout << "El numero menor es: " << rel;
	
	return 0;
}

void menorNoNo(){
	int x, y, z;
	cout << "Ingresa el primer numero: "; cin >> x;
	cout << "Ingresa el segundo numero: "; cin >> y;
	cout << "Ingresa el tercero numero: "; cin >> z;
	if(x<y && x<z){
		cout << "El numero menor es: " << x << endl;
	}
	else if(y<z){
		cout << "El numero menor es: " << y << endl;
	} 
	else{
		cout << "El numero menor es: " << z << endl;
	}
}

void menorNoSi(int x, int y, int z){
	if(x<y && x<z){
		cout << "El numero menor es: " << x << endl;
	}
	else if(y<z){
		cout << "El numero menor es: " << y << endl;
	} 
	else{
		cout << "El numero menor es: " << z << endl;
	}
}

int menorSiNo(){
	int x, y, z, r;
	cout << "Ingresa el primer numero: "; cin >> x;
	cout << "Ingresa el segundo numero: "; cin >> y;
	cout << "Ingresa el tercero numero: "; cin >> z;
	if(x<y && x<z){
		r = x;
	}
	else if(y<z){
		r = y;
	} 
	else{
		r = z;
	}
	return r;
}

int menorSiSi(int x, int y, int z){
	int r;
	if(x<y && x<z){
		r = x;
	}
	else if(y<z){
		r = y;
	} 
	else{
		r = z;
	}
	return r;
}

