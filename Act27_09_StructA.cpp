#include <iostream>
#include <string>
using namespace std;

int op, opc, opd;

struct pkf{
    int dd,mm,aa;
};

struct pkt{
    string nombres, apellido;
};

struct atk{
    string atk_n;
	string type;
};

struct pkmn{
    struct pkf fecha;
    struct pkt trainer;
    struct atk attk[4];
    string cap;
    bool act = false;
};

int main(){
    struct pkmn data[10];
    int x;
    do{	
        cout << " -------------- MENU -------------- " << endl;
        cout << " - 1 - Capturar datos          - " << endl;
        cout << " - 2 - Mostrar un dato           - " << endl;
        cout << " - 3 - Mostrar todo              - " << endl;
        cout << " ---------------------------------- " << endl;
        cout << " - 4 - Salir                      - " << endl;
        cout << " ---------------------------------- " << endl;
        cin  >> op;
        switch (op){
        	
        case 1:
            do{
			    cout << "Cual de los 10 datos capturar: "; cin  >> x;
			}while( x>10 || x<=0  ); x--;
			cout << " -> capturar datos de una casa " << x + 1 << endl;
			cout << "Ingresa la fecha de la captura[dia/mes/año]: ";
			cin  >> data[x].fecha.dd;
			cin  >> data[x].fecha.mm;
			cin  >> data[x].fecha.aa;
			fflush(stdin); 
			cout << "Ingresa el nombre del entrenador:"; getline(cin,data[x].trainer.nombres); 
			cout << "Ingresa el apellido del entrenador:"; getline(cin,data[x].trainer.apellido); 
			for(int y=0; y<3 ; y++){
			    cout << "Movimientos del pokemon" << y+1 << ": "<< endl;
			    cout << "Cuantos movimientos tiene: "; cin  >> data[x].attk[y].atk_n;
			    cout << "Tipos de los ataques: "; cin  >> data[x].attk[y].type;
			}
			fflush(stdin); 
			cout << "Ingrese el lugar de captura: "; getline(cin,data[x].cap); 
			data[x].act=true;
        break;
        
        case 2:
            do{
		        cout << "Cual dato desea revisar?[1 - 10]: "; cin  >> opd;
		    }while( opd>10 || opd <=0  ); opd--;
		    if( data[opd].act == false ){
		        cout << "Captura sin datos................ " << endl;
		    }else{
		    cout << "Datos de la captura: " << endl;
		    cout << "Fecha de captura: " << data[opd].fecha.dd << " / " << data[opd].fecha.mm << " / " << data[opd].fecha.aa << endl;
		    cout << "Nombre del entrenador: " <<  data[opd].trainer.nombres << " " << data[opd].trainer.apellido << endl;
		    for(int z=0; z<3 ; z++){
		    	cout << "Datos del pokemon" << z+1 << ": "<< endl;
		        cout << "Numero de movimientos: " <<  data[opd].attk[z].atk_n << endl;
		        cout << "Tipo de movimientos : " << data[opd].attk[z].type << endl;
		    }
		    cout << "Lugar de la captura: " << data[opd].cap << endl;
		    }
        break;
        
        case 3:
            for(opd=0; opd<10 ; opd++){   
	        if( data[x].act==true ){ 
	            cout << "Datos de la captura: " << opd + 1 << endl;
	            cout << "Fecha de captura: " << data[opd].fecha.dd << " / " << data[opd].fecha.mm << " / " << data[opd].fecha.aa << endl;
	            cout << "Nombre del entrenador: " <<  data[opd].trainer.nombres << " " << data[opd].trainer.apellido << endl;
	            for(int w=0; w<4 ; w++){
	                cout << "Datos del pokemon" << w+1 << ": "<< endl;
	                cout << "Numero de movimientos: " <<  data[opd].attk[w].atk_n << endl;
	                cout << "Tipo de movimientos : " << data[opd].attk[w].type << endl;
	            	}
	            cout << "Lugar de la captura: " << data[opd].cap << endl;
	        	}
	  		}
        break;
        
        case 4:
            exit(1);
        break;
    }
	cout << "Quiere re ingresar datos[Si=1 // No=2]: "; cin >> opc;
	}while(opc!=2);
    return 0;
}
