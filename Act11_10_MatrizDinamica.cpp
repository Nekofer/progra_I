#include <iostream>
#include <stdlib.h>
using namespace std;



int main(){
	system("color f9");
	int c1, c2, c3;
	int **m;

    cout<<"Columnas(1):"; cin>>c1;
    cout<<"Columnas(2):"; cin>>c2;
    cout<<"Columnas(3):"; cin>>c3;
	
	m=(int **)malloc(3*sizeof(int *));
	for (int x=0;x<3;x++){
        m[x]=(int *)malloc(c1*sizeof(int *));
    }
	
	cout << "Ingresar datos:" << endl;
    for(int z=0;z<c1;z++){
    	cout << "dato[" << 1 <<"][" << z <<"] : ";
        cin >> m[0][z];
    }
    
    for(int z=0;z<c2;z++){
    	cout << "dato[" << 2 <<"][" << z <<"] : ";
        cin >> m[1][z];
    }
    
    for(int z=0;z<c3;z++){
    	cout << "dato[" << 3 <<"][" << z <<"] : ";
        cin >> m[2][z];
    }
    
    
    cout << "Mostrar datos de la matriz:" << endl;
  
        for(int j=0;j<c1;j++){
         cout << m[0][j] << " ";
        }
        cout << endl;
        
        for(int j=0;j<c2;j++){
         cout << m[1][j] << " ";
        }
        cout << endl;
        
        for(int j=0;j<c3;j++){
         cout << m[2][j] << " ";
        }
        cout << endl;
	
	
	return 0;
}
