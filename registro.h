Jugador *registro(){
	Jugador *nuevo = new Jugador;
	
	int idJugador = 0;
	float Edad = 0;
	
	if(nuevo == NULL){
		cout<<"No hay mempria disponible"<<endl;
	}else{
		nuevo->idJugador = generaID("IDJugador: ", 25, 5);
		//fflush(stdin);
		//nuevo->idJugador = idJugador;
		//gotoxy(25,6);
		//cout<<"Nombre: ";
		fflush(stdin);
		validaCadena("nombre: ", nuevo->nombre, 25, 6);
		//getline(cin, nuevo->nombre);
		//gotoxy(25,7);
		fflush(stdin);
		valida_email("Correro electronico: ", nuevo->correo, 25, 7);
		//validaCadena("Correo electronico: ", nuevo->correo, 25, 7);
		//cout<<"Correo electronico: ";
		fflush(stdin);
		//getline(cin, nuevo->correo);
		do{
			gotoxy(25,8);
			printf("                              ");
			gotoxy(25,8);
			Edad = validaFlotante("Edad: ");
		}while(Edad <= 0);
		fflush(stdin);
		nuevo->edad = Edad;
		/*
		gotoxy(25,9);
		cout<<"Username: ";
		fflush(stdin);
		getline(cin, nuevo->Username);
		*/
		fflush(stdin);
		validaUsername("Username: ", nuevo->Username, 25, 9);
		//validaCadena("Username: ", nuevo->Username, 25, 9);
		fflush(stdin);
		//gotoxy(25,10);
		validaPassword("Password: ", nuevo->password, 25, 10);
		//validaCadena("password: ", nuevo->password, 25, 10);
		//cout<<"Password: ";
		fflush(stdin);
		//getline(cin, nuevo->password);
		nuevo->sig = NULL;
	}
	
	return nuevo;
}

void agregarFinalSerpiente(Jugador *Nodo){
	Jugador *nuevo = Nodo;
	
	if(primero == NULL){
		primero = nuevo;
		ultimo = nuevo;
	}else{
		ultimo->sig = nuevo;
		ultimo = nuevo;
	}
}

void agregarFinal(){
	Jugador *nuevo = registro();
	
	if(primero == NULL){
		primero = nuevo;
		ultimo = nuevo;
	}else{
		ultimo->sig = nuevo;
		ultimo = nuevo;
	}
}

void agregarInicio(){
	Jugador *nuevo = registro();
	
	if(primero == NULL){
		primero = nuevo;
		ultimo = nuevo;
	}else{
		nuevo->sig = primero;
		primero = nuevo;
	}
}

void mostrarDioses(){
	struct Dioses *auxiliar = primeroDioses;
	
	cout<<endl<<endl<<"~~~~~~ACERCA DE LOS DIOSES~~~~~~"<<endl;
	
	while(auxiliar!=NULL){
		//cout<<"~~~DIOS~~~"<<endl;
		cout<<auxiliar->Nombre<<"\t\t";
		cout<<auxiliar->informacion<<endl;
		cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
		auxiliar = auxiliar->sig;
	}
}

void mostrar_listaSiguiente(){
	struct Jugador *auxiliar = primero;
	
	cout<<endl<<endl<<"~~~~~~MARCADORES~~~~~~"<<endl;
	
	cout<<"ID Jugador"<<setw(15);
	cout<<"Nombre"<<setw(20);
	cout<<"Correo"<<setw(20);
	cout<<"Edad"<<setw(10);
	cout<<"Username"<<setw(25);
	cout<<"Score"<<endl<<endl;
	
	while(auxiliar != NULL){
	//while(auxiliar != 0){
		cout<<auxiliar->idJugador<<setw(20);
		cout<<auxiliar->nombre<<setw(20);
		cout<<auxiliar->correo<<setw(20);
		cout<<auxiliar->edad<<setw(20);
		cout<<auxiliar->Username<<setw(25);
		//cout<<auxiliar->password<<setw(15);
		cout<<auxiliar->score<<endl;
		//cout<<auxiliar<<endl;
		auxiliar = auxiliar->sig;
	}
	
	//cout<<endl<<"Primer nodo: "<<primero<<endl;
	//cout<<"Ultimo nodo: "<<ultimo;
}

void MostrarPreguntas(){
	struct Dioses *auxiliar = primeroDioses;
	//struct Empleado *auxiliar = primero;
	
	cout<<"Mostrando la lista completa"<<endl;
	
	while(auxiliar != NULL){
		cout<<"---Dios---"<<endl;
		cout<<auxiliar->Nombre<<"\t\t";
		cout<<auxiliar->informacion<<endl;
		cout<<"---Preguntas---"<<endl;
		while(auxiliar->preguntas != NULL){
			cout<<auxiliar->preguntas->NumPregunta<<".-"<<"\t";
			cout<<auxiliar->preguntas->Pregunta<<endl;
			//cout<<auxiliar->peliculas->sig<<"\t\t\t\t\t\t\t"<<endl;
			auxiliar->preguntas = auxiliar->preguntas->sig;
			//auxiliar->peliculas = auxiliar->peliculas->sig;
		}
		auxiliar = auxiliar->sig;
	}
}

void mostrarListaReglas(){
	struct Reglas *auxiliar = primeroReglas;
	//struct Jugador *auxiliar = primero;
	
	cout<<endl<<endl<<"~~~~~~~REGLAS~~~~~~~"<<endl;
	
	while(auxiliar != NULL){
		cout<<auxiliar->numRegla<<"._\t";
		cout<<auxiliar->Regla<<endl<<endl;
		auxiliar = auxiliar->sig;
	}
	//cout<<endl<<"Primer nodo: "<<primero<<endl;
	//cout<<"Ultimo nodo: "<<ultimo;
}
