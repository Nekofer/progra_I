//Realizado por Fernando Toledo y Paris Hernandez

#include <iostream>
#include <stdlib.h>

using namespace std;

int op;
int r;
int s, a, p;
int pG[10];
int pr=0;
int *v;
int **m;

int menu(){
    cout << "1) Mostrar todo"<<endl;
    cout << "2) Editar una calificacion"<<endl;
    cout << "3) Editar el tamaño de un grupo"<<endl;
    cout << "4) Promedio de los grupos"<<endl;
    cout << "5) Promedio de total"<<endl;
    cout << "6) Salir"<<endl;
    cout << "--> "; cin >> op;
    return op;
}

void cap(){
	cout<< "Cantidad de salones: "; cin >> s;
	cout<< "Ingrese el numero de alumnos en cada salon: "<< endl;
	v = (int *) malloc(s*sizeof(int));
	for(int x=0;x<s;x++){
        cin >> v[x];
    }	
    m = (int **)malloc(s*sizeof(int *));
    for (int y=0; y<s ; y++){
        m[y] = (int *)malloc(v[y]*sizeof(int));
    }
    for (int z=0;z<s;z++){
   	cout<< "Salon: "<< z+1 <<endl;
		for (int w=0; w<v[z]; w++){
			cout<<"Ingresa el promedio del alumno: "<< w+1 <<endl;
			cin>>m[z][w];
		}
	}
	for (int i=0;i<s;i++){
		pG[i]=0;
   		for (int j=0;j<v[i];j++){
   			pG[i]+=m[i][j];
		}
		pG[i] = pG[i]/v[i];
		pr = pr + pG[i];
	}
    pr = pr / s;
    cout << "Promedio de cada salon: " << endl;
    for (int a=0;a<s;a++){
   		cout <<	pG[a]<<endl;
	}
	cout<<"Promedio total"<<endl;
	cout<<pr<<endl;
}

int main(){
	cap();
	r=menu();
    switch(r){
    	
   	case 1:
	   	for (int i=0;i<s;i++){
		   	cout<<" "<<endl;
		   	for (int j=0;j<v[i];j++){
		   		cout<<" "<<m[i][j];
			}
		}
	break;
	
	case 2:
	
	break;
	
	case 3:
		
	break;
	
	case 4:
		
	break;
	
	case 5:
		
	break;
	
	case 6:
		exit(1);
	break;
	
   }
   return 0;
}
