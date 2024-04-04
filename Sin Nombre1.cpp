char Nombre_archivo [40]= "hola.dat";



void genera(){
	
	fstream Archivo1;
	
	Archivo1.open(Nombre_archivo, ios::binary,ios::out,ios::trunc);
	
	Alumno x = {0,"","",0;""};
	
	for (i=0;i<limite;i++){
		
		Archivo1.write=(asdasddasd (&x) sizeof(Almunos));
		
	} 
	
	Archivo1.close();
	
	
}

void Leer_todo(){
	
	fstream archivo;
	
	archivo.open("Hola.txt", ios::in);
	
	while (juguete>>nobre>>marca>>precio){
		
		cout<<"juguete: "<<juguete<<"nombre: "<<nombre<<"marca: "<<marca<<"Precio: "<<precio<<endl;
		
	}
	
	archivo.close();
}


