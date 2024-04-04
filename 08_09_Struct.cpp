#include<iostream>
using namespace std;

struct ff{
	int d, m, a;
}fecha;

bool a=false;
bool b=false;
bool c=false;

void cap(struct ff &fecha){
	system("cls");
	do{
		cout << "Ingrese el dia: "; cin >> fecha.d;
		if(fecha.d >= 1 && fecha.d <= 31){
			cout << "Dato guardado correctamente \n";
			a=true;
		}
		else{
			cout << "Dato no guardado  \n";
		}
		cout << "Ingrese el mes: "; cin >> fecha.m;
		if(fecha.m >=1 && fecha.m <=12){
			cout << "Dato guardado correctamente \n";
			b=true;
		}
		else{
			cout << "Dato no guardado \n";
		}
		cout << "Ingrese el año: "; cin >> fecha.a;
		if(fecha.a <= 2022){
			cout << "Dato guardado correctamente \n";
			c=true;
		}
		else{
			cout << "Dato no guardado \n";
		}
	}while(a==false && b==false && c==false);
}

void mos(struct ff &fecha){
	system("cls");
	cout << "Dia: " << fecha.d << endl;
	cout << "Mes: " << fecha.m << endl;
	cout << "Año: " << fecha.a << endl << endl;
	system("pause");
}

int main(){
	system("color f9");
	struct ff fecha;
	int op;
	do{
		cout << "1. Capturar datos" << endl;
		cout << "2. Mostrar datos" << endl;
		cout << "3. Editar datos" << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese la opcion: "; cin >> op;
		switch(op){
			case 1:	
				cap(fecha);
				system("pause");
				system("cls");
			break;
			
			case 2:
				mos(fecha);
				system("pause");
				system("cls");
			break;
			
			case 3:
				mos(fecha);
				cap(fecha);
				system("pause");
				system("cls");
			break;
			
			case 4:
				exit(1);
			break;		
		}
	}while(op!=4);
	return 0;
}