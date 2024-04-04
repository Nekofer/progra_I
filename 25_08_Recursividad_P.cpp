#include<iostream>
using namespace std;

int primo(int n, int n1);

int main(){
	int n, r;
	cout << "Ingresa un numero: "; cin >> n;
	r = primo(n,n-1);
	cout << "r: " << r << endl;
	if(r==0){
		cout << "No es primo " << endl;
	}
	else if(r==1){
		cout << "Si es primo " << endl;
	}
}

int primo(int n, int n1){
	int residuo = n % n1;
	cout << n << " - " << n1 << " : " << residuo << endl;
	if (residuo==0){
		if(n1==1){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return primo(n,n1-1);
	}
}
