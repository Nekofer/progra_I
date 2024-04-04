#include<iostream>
#include <windows.h>
using namespace std;

int menu(); //*
void ind(); //*
int timeM(); //*
int timeH(); //*
int cost(int &x, int &y); //*
int sell(int x); //*
void ggez();

int main(){
	system("color f9");
	int opc, minutos, horas;
	int salida=0;
	float monto;
	bool m=false;
	bool h=false;
	bool d=false;
	ggez();
	do{
		
		opc=menu();
		system("cls");
		switch(opc){
			case 1:
				ind();
			break;
			
			case 2:
				minutos = timeM();
				m=true;
			break;
			
			case 3:
				horas = timeH();
				h=true;
			break;
			
			case 4:
				if(m==true && h==true){
					monto = cost(horas, minutos);
					cout << endl << endl;
					cout << "Tiempo : " << horas << " horas y " << minutos << " minutos " << endl;
					cout << "El monto a pagar por tu boletos es $ " << monto << endl;
					system("pause");
					system("cls");
					d = true;
				}
				else{
					cout << "Faltan datos para realizar el pago \n";
				}
			break;
			
			case 5:
				if(d==true){
					sell(monto);
					salida=1;
				}
				else{
					cout << "Faltan datos para realizar la venta \n";
				}
			break;
			
			case 6:
				exit(1);
			break;
			
			default:
				cout << "No existe dicha opcion \n";
			break;
		}
		
	}while(salida!=1);
	cout << endl << endl;
	cout << "Vuelva pronto\n";
	return 0;
}

int menu(){
	int r;
	cout << endl << endl;
	cout << "1. Indicaciones \n";
	cout << "2. Validar minutos \n";
	cout << "3. Validar horas \n";
	cout << "4. Venta \n";
	cout << "5. Cobro \n";
	cout << "6. Salir \n";
	cout << "Ingrese su opcion: "; cin >> r;
	return r;
}

void ind(){
	cout << endl << endl;
	cout << "--- Indicaciones ---\n";
	cout << "Las primeras 2 horas valen $6 \n";
	cout << "Cada hora posterior cuenta $9, apartir de la segunda hora \n";
	cout << "Se tiene una tolerancia de 10 minutos \n";
	cout << "Ejemplo: \n";
	cout << "2 horas y 5 minutos = $12.00 (6+6)\n";
	cout << "1 horas y 30 minutos = $12.00 (6+6)\n";
	cout << "2 horas y 50 minutos = $21.00 (6+6+9)\n";
	cout << "10 horas y 3 minutos = $84.00 (6*2 + 9*8)\n";
	cout << "0 horas y 5 minutos = $6.00 (6)\n";
	system("pause");
	system("cls");
}

int timeM(){
	int min, w;
	int tm;
	do{
		cout << endl << endl;
		cout << "Ingrese los minutos: "; cin >> min;
		if(min<=60 && min>=0){
			tm = min;
			w = 1;
		}
		else{
			cout << endl << endl;
			cout << "El valor ingresado es erroneo, ingreselo de nuevo...";
		}
	}while(w!=1);
	system("pause");
	system("cls");
	return tm;
}

int timeH(){
	int h, q;
	int th;
	do{
		cout << endl << endl;
		cout << "Ingrese las horas: "; cin >> h;
		if(h<=23 && h>=0){
			th = h;
			q = 1;
		}
		else{
			cout << "El valor ingresado es erroneo, ingreselo de nuevo...";
		}
	}while(q!=1);
	system("pause");
	system("cls");
	return th;
}

int cost(int &x, int &y){
	int ww=0;
	if(x<2 && y>0){
		ww=(x*6)+6;
	}
	else if(x>=2){
		if(y<10){
			ww=(2*6)+((x-2)*9);
		}
		else if(y>10){
			ww=(2*6)+((x-2)*9)+9;
		}
	}
	return ww;
	
}

int sell(int x){
	int pago;
	int ex;
	int ss;
	do{
		cout << endl << endl;
		cout << "El cobro es de: " << x << endl;
		cout << "Ingrese el pago:"; cin >> pago;
		if(pago>=x){
			cout << "El pago ha sido realizado con exito\n";
			ex=pago-x;
			cout << "El vuelto es de: " << ex;
			ss=1;
		}
		else if(pago<x){
			cout << "El pago es insuficiente...";
		}	
	}while(ss!=1);
	return pago;
}

void ggez(){
	int seg=5;
	for(int x=0; x<=8; x++){
		cout << "\n";
	}
	cout << "\t\t\t\t\t\t        CARGANDO...\n";
	for(int y=0; y<=119; y++){
		cout << "_";
	} 
	for(int z=0; z<=119; z++){
		cout << char(219);
		Sleep(seg*1000/80);
	}
	system("cls");
	for(int x=0; x<=8; x++){
		cout << "\n";
	}
	cout << "\t\t\t\t\t\t        COMPLETADO\n";
	system("pause");
	system("cls");
}




