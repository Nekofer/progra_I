#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13

using namespace std;

// Mapas



// Variables

int x=5, y=5, nums, aux=0;
char z='@';
char m;
int opm;
int move;
const int limite = 20;
int np;
char Nombre_Archivo[30] = "DatosJugador.dat";
char Nombre_Archivo2[30] = "StatsJugador.dat";
char c, cadena[80];
int hpP=100, hpE=150;
int op; 
fstream archivo;

// Estructuras

struct player{
	int id;
	char name[50];
	int dif;
	bool gmode;
};

struct stats{
	int atk;
	int def;
	int dex;
	int agi;
	int arc;
};

struct data{
	player x;
	stats y;
};

// Funciones

void combat();
void status();
int menu(const char titulo[], const char *opciones[], int n);
void credits();
void atkk();
void dexx();
void arcc();
void damage();
void enemy();
void history();
void game();

void gotoxy(int x, int y, char z){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
    cout << z;
}

void movement(){
	do{
		m = getch();
		if(m=='w'){
			system("cls");
			gotoxy(x,y=y-2,z);
			aux++;
			cout << aux;
			combat();
		}
		else if(m=='a'){
			system("cls");
			gotoxy(x=x-2,y,z);
			aux++;
			cout << aux;
			combat();
		}
		else if(m=='s'){
			system("cls");
			gotoxy(x,y=y+2,z);
			aux++;
			cout << aux;
			combat();
		}
		else if(m=='d'){
			system("cls");
			gotoxy(x=x+2,y,z);
			aux++;
			cout << aux;
			combat();
		}else if(m=='e'){
			system("cls");
			status();
		}else if(m=='c'){
			system("cls");
			history();
		}
	}while(m!='z');
}

void show(){
	system("cls");
	cout << "Bienvendio bbto\n"; Sleep(3000);
	cout << "Para empezar a jugar, primero necesito que eligas un mapa\n\n"; Sleep(3000);
	cout << "1.Rock Palace\n"; 
	cout << "2.Rojito Mansion\n"; 
	cout << "3.Mary on a cross\n"; 
	cout << "--> "; cin >> opm;
	cout << "Cargando..........."; Sleep(2000);
	system("cls");
	srand(time(NULL));
	nums=1+rand()%(31-1);
	cout << nums;
	switch(opm){
		case 1:
			//mapa1
			cout << endl;
			gotoxy(x,y,z);
			movement();
		break;
		case 2:
			//mapa2
			cout << endl;
			gotoxy(x,y,z);
			movement();
		break;
		case 3:
			//mapa3
			cout << endl;
			gotoxy(x,y,z);
			movement();
		break;
	}
}

void gen(){
    fstream archivo;
    archivo.open(Nombre_Archivo, ios::binary|ios::out|ios::trunc);
    if(!archivo){ 
        cerr << " No se pudo abrir el archivo " << endl; 
    }
	else{
        player base = {0,"",0,false}; 
        for(int i = 0; i < limite; i++){
            archivo.write( reinterpret_cast<char *> (&base),sizeof(player));
        }
        archivo.close(); 
    }  
}  

void gen2(){
    fstream archivo;
    archivo.open(Nombre_Archivo2, ios::binary|ios::out|ios::trunc);
    if(!archivo){ 
        cerr << " No se pudo abrir el archivo " << endl; 
    }
	else{
        stats base = {0,0,0,0,0}; 
        for(int i = 0; i < limite; i++){
            archivo.write( reinterpret_cast<char *> (&base),sizeof(stats));
        }
        archivo.close(); 
    }  
}  

void read(){
    fstream archivo;
    cout << "Se mostrara a continuacion toda nuestra base de datos :  " << endl;
    archivo.open(Nombre_Archivo, ios::binary|ios::in);
    if (!archivo){ 
        cerr << " No se pudo abrir el archivo " << endl;
    }
	else{
        player x;
        for(int i=0; i<5; i++){  
            archivo.read( reinterpret_cast<char *> (&x),sizeof(player));
            cout << "Jugador  " << i+1<<endl;
            cout << "   ID         : " << x.id << endl;
            cout << "   Nombre     : " << x.name << endl;
            cout << "   Dificultad : " << x.dif << endl;
            cout << "   Modo dios  : " << x.gmode << endl << endl;    
            /*cout << "Estadisticas  " << endl;
            cout << "   Ataque     : " << z.y.atk << endl;
            cout << "   Defensa    : " << z.y.def << endl;
            cout << "   Destreza   : " << z.y.dex << endl;
            cout << "   Agilidad   : " << z.y.agi << endl;   
			cout << "   Arcana     : " << z.y.arc << endl; */   
        }
        archivo.close(); 
    } 
}

int caps(){
    fstream archivo;
    int c=0;
    archivo.open(Nombre_Archivo, ios::binary|ios::in);
    if (!archivo) { // verifica la existencia del archivo 
        cerr << " No se pudo abrir el archivo " << endl; 
    }
	else{
        player x;
        for(int i=0; i<limite; i++){
            archivo.read( reinterpret_cast<char *> (&x),sizeof(player));
            if(x.id!=0){
                c++;
            } 
        }
        archivo.close(); // cierra el archivo
    } 
    return c;
}

int caps2(){
    fstream archivo;
    int c=0;
    archivo.open(Nombre_Archivo2, ios::binary|ios::in);
    if (!archivo) { // verifica la existencia del archivo 
        cerr << " No se pudo abrir el archivo " << endl; 
    }
	else{
        stats x;
        for(int i=0; i<limite; i++){
            archivo.read( reinterpret_cast<char *> (&x),sizeof(stats));
            if(x.atk!=0){
                c++;
            } 
        }
        archivo.close(); // cierra el archivo
    } 
    return c;
}

void add(){
	int l;
    int numero = caps();
    cout << "Actualmente tenemos " << numero << " jugadores" << endl;
    player x;
    float p=0;
    cout << " Jugador  " << numero+1 << endl;
    cout << "   ID     : "; cin >> x.id;
    cout << "   nombre : "; cin >> x.name;
    cout << "   Dificultad : "; cin >> x.dif;
	cout << "   Modo dios [1=Si // 2=No] : "; cin >> l;
	if(l==1){
		x.gmode=true;
	}
	else{
		x.gmode=false;
	}
	/*do{
		cout << " Estadisticas: " << endl; 
		cout << "   Ataque     : "; cin >> z.y.atk; lim=lim+z.y.atk;
	    cout << "   Defensa : "; cin >> z.y.def; lim=lim+z.y.def;
	    cout << "   Destreza : "; cin >> z.y.dex; lim=lim+z.y.dex;
	    cout << "   Agilidad     : "; cin >> z.y.agi; lim=lim+z.y.agi;
	    cout << "   Arcana : "; cin >> z.y.arc; lim=lim+z.y.arc;	
	}while(lim<=50);*/
    fstream archivo;
    archivo.open(Nombre_Archivo, ios::binary|ios::in|ios::out);
    archivo.seekp((numero) * sizeof(player), ios::beg); // write escribe el registro una vez ya posicionado
    archivo.write(reinterpret_cast<char*>(&x),sizeof(player));
    cout << "Datos grabados...\n ";
    archivo.close();
}

void add2(){
	int lim;
    int numero = caps2();
    cout << "Actualmente tenemos " << numero << " jugadores" << endl;
    stats y;
    float p=0;
	
		cout << " Estadisticas: " << endl; 
		cout << "   Ataque     : "; cin >> y.atk; lim=lim+y.atk;
	    cout << "   Defensa : "; cin >> y.def; lim=lim+y.def;
	    cout << "   Destreza : "; cin >> y.dex; lim=lim+y.dex;
	    cout << "   Agilidad     : "; cin >> y.agi; lim=lim+y.agi;
	    cout << "   Arcana : "; cin >> y.arc; lim=lim+y.arc;	
	
    fstream archivo;
    archivo.open(Nombre_Archivo2, ios::binary|ios::in|ios::out);
    archivo.seekp((numero) * sizeof(stats), ios::beg); // write escribe el registro una vez ya posicionado
    archivo.write(reinterpret_cast<char*>(&y),sizeof(stats));
    cout << "Datos grabados...\n ";
    archivo.close();
}

void readO(){
    fstream archivo;
    char nombreB[50];
    char nombreR[50];
    bool encontrado = false;
    cout << "Que jugador (nombre) buscas: "; cin >> nombreB;
    for(int i=0; i<strlen(nombreB) ; i++){
        nombreB[i]= toupper(nombreB[i]);
    }
    archivo.open(Nombre_Archivo, ios::binary|ios::in);
    if (!archivo){ 
        cerr << " No se pudo abrir el archivo " << endl; 
    }
	else{
        player x;
        for(int j=0; j<limite; j++){
            archivo.read( reinterpret_cast<char *> (&x),sizeof(player));
            char nombreR[50];
            strcpy(nombreR,x.name);
            for(int i=0; i<strlen(nombreR) ; i++){
                nombreR[i]= toupper(nombreR[i]);
            }
            if(strcmp(nombreB,nombreR)==0){
                cout << "-Jugador  " << j+1<<endl;
                cout << "   ID     : " << x.id << endl;
                cout << "   Nombre : " << x.name << endl;
                cout << "   Dificultad : " << x.dif << endl;
                cout << "   Modo dios : " << x.gmode << endl << endl; 
                encontrado = true;
            }     
        }
        archivo.close(); // cierra el archivo
        if(encontrado == false){
            cout << "El jugador con ese nombre no esta " << endl;
        }
    } 
}

void hub(){
   bool repite = true;
   int opcion;  

   const char *titulo = "Rojito Adventure";
   const char *opciones[] = {"Jugar", "Creditos", "Salir"};
   int n = 3;  // Numero de opciones
 
   do {
      opcion = menu(titulo, opciones, n);
 
      switch (opcion) {
         case 1:
         	game();
            show();
            break;
 
         case 2:
            credits();
            break;
 
         case 3:
            cout << "\n\nQue las llamas os guien aventurero" << endl;
            repite = false;
            system("pause>nul");
            break;
      }
 
   } while(repite);
}

char getch2 (){
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
   ReadConsoleA (ih, &c, 1, &contador, NULL);
   if (c==0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }
   SetConsoleMode (ih, modo);
   return c;
}

int gotoxy2(USHORT x,USHORT y) {
   COORD cp = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

int menu(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
 
   int tecla;
 
   bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
 
   do {
      system("cls");
      system("color f9");
      gotoxy2(5, 3 + opcionSeleccionada); cout << "==>" << endl;
 
      // Imprime el tÃ­tulo del menÃº
      gotoxy2(15, 2); cout << titulo;
 
      // Imprime las opciones del menÃº
      for (int i = 0; i < n; ++i) {
         gotoxy2(10, 4 + i); cout << i + 1 << ") " << opciones[i];
      }
 
      // Solo permite que se ingrese ARRIBA, ABAJO o ENTER
 
      do {
         tecla = getch2();
         // gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
 
      switch (tecla) {
 
         case ARRIBA:   // En caso que se presione ARRIBA
 
            opcionSeleccionada--;
 
            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }
 
            break;
 
         case ABAJO:
            opcionSeleccionada++;
 
            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }
 
            break;
 
         case ENTER:
            repite = false;
            break;
      }
 
   } while (repite);
 
   return opcionSeleccionada;
}

void credits(){
	system("cls");
	cout << endl;
	cout << "\t Programa realizado por:\n";
	cout << endl;
	cout << "\t UnderStudio\n\n";
	cout << "\t\t Fernando Toledo Pacciotta\n\n";
	cout << "\t\t Paris Ahmed Hernandez Perez\n\n";
	system("pause");
}

void battle(){
	//bool vic=false;
	int run;
	bool repite = true;
   	int opcion;   
   	const char *titulo = "Let the Battle begin";
	const char *opciones[] = {"Ataque fuerte", "Ataque rapido", "Ataque magico", "Huir"};
	int n = 4;  // Numero de opciones 
	do{
		opcion = menu(titulo, opciones, n); 
	    switch (opcion) {
	        case 1:
	        	atkk();
	        	damage();
	        	if(hpE<=0){
	        		cout << "Ganaste";
	        		system("pause");
	        		aux=0;
	        		hpP=100;
	        		hpE=150;
	        		movement();
				}
	        break;
	 
	        case 2:
	            dexx();
	            damage();
	            if(hpE<=0){
	        		cout << "Ganaste";
	        		system("pause");
	        		aux=0;
	        		hpP=100;
	        		hpE=150;
	        		movement();
				}
	        break;
	        
	        case 3:
	            arcc();
	            damage();
	            if(hpE<=0){
	        		cout << "Ganaste";
	        		system("pause");
	        		aux=0;
	        		hpP=100;
	        		hpE=150;
	        		movement();
				}
	        break;
	 
	        case 4:
	            srand(time(NULL));
				run=1+rand()%(31-1);
				if(run>=10){
					cout << "Has logrado escapar...";
					hpP=100;
	        		hpE=150;
					system("pause");
					movement();
				}else{
					cout << "No has logrado escapar...";
					system("pause");
				}
	        break;
	      }
	} while(repite);
}

void atkk(){
	int dmg;
	srand(time(NULL));
	dmg=1+rand()%(51-1);
	cout << "Haz realizado: " << dmg << "de danio";
	system("pause");
	hpE=hpE-dmg;
}

void dexx(){
	int dmg;
	srand(time(NULL));
	dmg=1+rand()%(51-1);
	cout << "Haz realizado: " << dmg << "de danio";
	system("pause");
	hpE=hpE-dmg;
}

void arcc(){
	int dmg;
	srand(time(NULL));
	dmg=1+rand()%(51-1);
	cout << "Haz realizado: " << dmg << "de danio";
	system("pause");
	hpE=hpE-dmg;
}

void damage(){
	int dmg;
	srand(time(NULL));
	dmg=1+rand()%(21-1);
	hpP=hpP-dmg;
	if(hpP<=0){
		system("cls");
		cout << "You died...";
		system("pause");
		exit(1);
	}
}

void enemy(){
	srand(time(NULL));
	nums=1+rand()%(31-1);
	archivo.open("enemy1.txt",ios::in);
	archivo.getline(cadena,80); 
	while (!archivo.eof()){
		cout<< cadena <<endl; 
		archivo.getline(cadena,80);
	}
	archivo.close();
	cout << endl << endl << "Un enemigo salvaje a aparecido...";
	Sleep(5000);
	battle();
}

void combat(){
	if(aux==nums){
		enemy();
	}
}

void status(){
	fstream archivo;
    cout << "Se mostrara a continuacion toda nuestra base de datos :  " << endl;
    archivo.open(Nombre_Archivo2, ios::binary|ios::in);
    if (!archivo){ 
        cerr << " No se pudo abrir el archivo " << endl;
    }
	else{
        stats y;
        for(int i=0; i<5; i++){  
            archivo.read( reinterpret_cast<char *> (&y),sizeof(stats));
            cout << "Estadisticas  " << endl;
            cout << "   Ataque     : " << y.atk << endl;
            cout << "   Defensa    : " << y.def << endl;
            cout << "   Destreza   : " << y.dex << endl;
            cout << "   Agilidad   : " << y.agi << endl;   
			cout << "   Arcana     : " << y.arc << endl; 
        }
        archivo.close(); 
    } 
}

void history(){
	archivo.open("lore.txt",ios::in);
	archivo.getline(cadena,80); 
	while (!archivo.eof()){
		cout<< cadena <<endl; 
		archivo.getline(cadena,80);
	}
	archivo.close();
}

void game(){
	int opc;
	do{
		system("cls");
		cout << "1. Nuevos datos\n"; 
    	cout << "2. Nueva Partida\n"; 
    	cout << "3. Cargar Partida\n"; 
    	cout << "-->"; cin >> op;
    	switch(op){
        	case 1:
         		cout << "Precaucion... si ya existe el archivo se borrara"<< endl;
	       	 	cout << "Generando desde cero nuestra base de datos ( cascaron )"<< endl;
	       	 	gen();
	       	 	gen2();
        	break;
         		
        	case 2:
         		add();
         		system("cls");
         		add2();
        	break;
         		
        	case 3:
         		readO();
        	break;
		}
		cout << "Desea elegir otra opcion?: [1=Si // 2=No] "; cin >> opc;	
	}while(opc!=2);
}

// Funcion principal

 int main(){
 	hub();
	return 0;  
}  
