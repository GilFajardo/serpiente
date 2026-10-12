void gotoxyS(int x, int y) 
{ 
	HANDLE hCon; 
	COORD dwPos; 
	 
	dwPos.X = x; 
	dwPos.Y = y; 
	hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition(hCon,dwPos); 
}
void OcultaCursor() {
	 
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void pintar(){ 
 	for(int i=2; i < 78; i++){
 		gotoxyS (i, 3); printf ("*");
 		gotoxyS (i, 23); printf ("*"); 
 	}
 	
 	for(int v=4; v < 23; v++){
 		gotoxyS (2,v); printf ("*");
 		gotoxyS (77,v); printf ("*"); 
 	}
 	
	gotoxyS (2,3); printf ("*");
 	gotoxyS (2,23); printf ("%c");
 	gotoxyS (77,3); printf ("%c");
 	gotoxyS (77,23); printf ("%c"); 
}
 
void guardar_posicion(int cuerpoS[][2], int &nS, int xS, int yS, int tamS){
 	cuerpoS[nS][0] = xS;
 	cuerpoS[nS][1] = yS;
	nS++;
 	if(nS == tamS) nS = 1;
}

void dibujar_cuerpo(int cuerpoS[][2], int tamS){
	
 	for(int i = 1; i < tamS; i++){
 		gotoxyS(cuerpoS[i][0] , cuerpoS[i][1]); printf("*");
 	}
}

void borrar_cuerpo(int cuerpoS[][2], int nS){
	
 	gotoxyS(cuerpoS[nS][0] , cuerpoS[nS][1]); printf(" ");
}

void teclear(char teclaS, int &dirS){
	fflush(stdin);
 	if(kbhit()){
 		fflush(stdin);
 		teclaS = getch();
 		fflush(stdin);
	 	switch(teclaS){
	 		case ARRIBA : if(dirS != 2) dirS = 1; break;
	 		case ABAJO : if(dirS != 1) dirS = 2; break;
	 		case DERECHA : if(dirS != 4) dirS = 3; break;
	 		case IZQUIERDA : if(dirS != 3) dirS = 4; break;
	 		}
 	}
}

void comidaDificil(int &score, int xS, int yS, int &xc, int &yc, int &tamS, int &velocidad){
	
 	if(xS == xc && yS == yc){
		xc = (rand() % 73) + 4;
 		yc = (rand() % 19) + 4;
 		tamS++;
 		gotoxyS(xc, yc); printf("%c", 4);
 		score = score+10;
 		velocidad = velocidad - 30;
 	}
}

void comidaFacil(int &score, int xS, int yS, int &xc, int &yc, int &tamS, int &velocidad){
	
 	if(xS == xc && yS == yc){
		xc = (rand() % 73) + 4;
 		yc = (rand() % 19) + 4;
 		tamS++;
 		gotoxyS(xc, yc); printf("%c", 4);
 		score = score+10;
 		velocidad = velocidad - 10;
 	}
}

bool JuegoTerminado(int yS, int xS, int tamS, int cuerpoS[][2]){
 	if(yS == 3 || yS == 23 || xS == 2 || xS == 77) return false;
	 	for(int j = tamS - 1; j > 0; j--){
	 	if(cuerpoS[j][0] == xS && cuerpoS[j][1] == yS)
	 	return false;
 	}
 	return true;
}

int PreguntaAleatoria(){
	int DiosRandom1 = 0, DiosRandom2 = 0, DiosRandom3 = 0, PreguntaRandom = 0;
	int cont = 0;;
	char Respuesta[50] = "";
	char Respuesta1[50] = "";
	char Respuesta2[50] = "";
	char Pregunta[300] = "";
	struct Dioses *auxiliar = primeroDioses;
	struct Pregunta *auxiliarPregunta = primeroPregunta;
	
	DiosRandom1 = rand() % 20 + 1;
	
	while(cont != DiosRandom1){
		strcpy(Respuesta, auxiliar->Nombre);
		if(cont+1 != DiosRandom1) auxiliar = auxiliar->sig;
		cont++;
	}
	
	struct Dioses *pregunta = auxiliar;
	
	PreguntaRandom = rand() %3+1;
	//cout<<"Numero de pregunta: "<<PreguntaRandom<<endl;
	
	if(PreguntaRandom == 1){
		strcpy(Pregunta, pregunta->preguntas->Pregunta);
	}else{
		while(PreguntaRandom != pregunta->preguntas->NumPregunta){
			strcpy(Pregunta, pregunta->preguntas->Pregunta);
			pregunta->preguntas = pregunta->preguntas->sig;
		}	
	}
	
	cont = 0;
	do{
		DiosRandom2 = rand() %20 + 1;
	}while(DiosRandom2 == DiosRandom1);
	
	auxiliar = primeroDioses;
	
	while(cont != DiosRandom2){
		strcpy(Respuesta1, auxiliar->Nombre);
		auxiliar = auxiliar->sig;
		cont++;
	}	
	
	cont = 0;
	do{
		DiosRandom3 = rand() %20 + 1;
	}while(DiosRandom3 == DiosRandom2 || DiosRandom3 == DiosRandom1);
	auxiliar = primeroDioses;
	
	while(cont != DiosRandom3){
		strcpy(Respuesta2, auxiliar->Nombre);
		auxiliar= auxiliar->sig;
		cont++;
	}	
	
	auxiliar = primeroDioses;
	
	/*
	cout<<PreguntaRandom<<".- "<<Pregunta<<endl;
	cout<<"1.- "<<Respuesta<<endl;
	cout<<"2.- "<<Respuesta1<<endl;
	cout<<"3.- "<<Respuesta2<<endl;
	getch();
	*/
	
	int RespuestaImprime1 = 0, RespuestaImprime2 = 0, RespuestaImprime3 = 0;
	
	RespuestaImprime1 = rand() % 3 + 1;
	
	do{
		RespuestaImprime2 = rand() % 3 + 1;	
	}while(RespuestaImprime2 == RespuestaImprime1);
	
	do{
		RespuestaImprime3 = rand() % 3 + 1;	
	}while(RespuestaImprime3 == RespuestaImprime2 || RespuestaImprime3 == RespuestaImprime1);
	
	int RespuestaDef = 0, RespuestaUsuario = 0;
	
	x=25;
	y=5;
	system("cls");
	gotoxy(x,y);
	cout<<Pregunta<<endl;
	gotoxy(x,++y);
	switch(RespuestaImprime1){
		case 1:
			cout<<"1.-"<<Respuesta;
			RespuestaDef = 1;
			break;
		case 2:
			cout<<"1.-"<<Respuesta1;
			break;
		case 3:
			cout<<"1.-"<<Respuesta2;
			break;
	}
	gotoxy(x,++y);
	switch(RespuestaImprime2){
		case 1:
			cout<<"2.-"<<Respuesta;
			RespuestaDef = 2;
			break;
		case 2:
			cout<<"2.-"<<Respuesta1;
			break;
		case 3:
			cout<<"2.-"<<Respuesta2;
			break;
	}
	gotoxy(x,++y);
	switch(RespuestaImprime3){
		case 1:
			cout<<"3.-"<<Respuesta;
			RespuestaDef = 3;
			break;
		case 2:
			cout<<"3.-"<<Respuesta1;
			break;
		case 3:
			cout<<"3.-"<<Respuesta2;
			break;
	}
	gotoxy(x,++y);
	RespuestaUsuario = validaEntero("Respuesta: ");
	
	int vidas = 0;
	
	system("cls");
	if(RespuestaUsuario == RespuestaDef){
		gotoxy(25,5);
		cout<<"CORRECTA";
		vidas = 1;
		Sleep(3000);
	}else{
		gotoxy(25,5);
		cout<<"INCORRECTA :(";
		vidas = 0;
		Sleep(3000);
	}
	
	return vidas;
}

void VideoJuegoInicioSesion(int dificultad){
	
	int rep = 0;
	
	do{
		struct Jugador *auxiliar = primero;
		system("cls");
		rep = 0;
		gotoxy(25,5);
		cout<<"Username: ";
		fflush(stdin);
		scanf("%s", InicioSesion);
		fflush(stdin);
		gotoxy(25,6);
		cout<<"Password: ";
		fflush(stdin);
		scanf("%s", Password);
		fflush(stdin);
		
		while(auxiliar!=NULL){
				if(strcmp(InicioSesion, auxiliar->Username) == 0){
					if(strcmp(Password, auxiliar->password) == 0){
						rep++;
						//cout<<"Si la encontro pa: ";
						//Sleep(3000);
						strcpy(InicioSesion, auxiliar->Username);
					}
				}
				auxiliar = auxiliar->sig;
		}
		
	}while(rep == 0);	
 
 	int vidas = 3;
 	int score = 0;
 	
 	while(vidas != 0){
 		
 		system("cls");
	
		fflush(stdin);
		
		int cuerpoS[200][2];
		int nS = 1, tamS = 5, dirS = 3;
		int xS = 10, yS = 12;
		int xc = 30, yc = 15;
		int velocidad = 140;
		int Sobrevive = 0;
		//score = 0;
		fflush(stdin);
		char teclaS;
			
		OcultaCursor();
	 
	 	pintar();
	 	gotoxyS(xc, yc); printf("%c", 4);
 		
 		
 		while(JuegoTerminado(yS, xS, tamS, cuerpoS)){
			borrar_cuerpo(cuerpoS, nS);
			guardar_posicion(cuerpoS, nS, xS, yS, tamS);
			dibujar_cuerpo(cuerpoS, tamS);
			if(dificultad == 1){
				comidaFacil(score, xS, yS, xc, yc, tamS, velocidad);	
			}else{
				comidaDificil(score, xS, yS, xc, yc, tamS, velocidad);
			}
			fflush(stdin);
			teclear(teclaS, dirS);
			fflush(stdin);
			teclear(teclaS, dirS);
			fflush(stdin);
			
			gotoxyS(1,1); printf("puntaje: %d", score);
			
			fflush(stdin);
			if(dirS == 1) yS--;
			if(dirS == 2) yS++;
			if(dirS == 3) xS++;
			if(dirS == 4) xS--;
			
			if(velocidad == 20){
				velocidad = 140;
			}
			
			Sleep(velocidad);
			
			gotoxyS(67, 1);
			printf("vidas: ");
			
			int gotoxyvidas = 75;
			
		    for (int i = 0; i < vidas; ++i) {
		    	gotoxyS(gotoxyvidas++, 1);
		        printf("%c ", 3);  // Código ASCII para el corazón
		    }	
		}
		system("cls");
		Sobrevive = PreguntaAleatoria();	
		if(Sobrevive == 0){
			vidas--;	
		}
		
		pintar();
	}
 	
 	struct Jugador *auxiliar = primero;
 	
 	while(auxiliar!=NULL){
 		
		if(strcmp(InicioSesion, auxiliar->Username)== 0){
			auxiliar->score = score;
			break;	
		}
		
		auxiliar = auxiliar->sig;
	}
}

Jugador *VideoJuego(Jugador *auxiliar, int dificultad){
	Jugador *EnJuego = auxiliar; 
 
 	int vidas = 3;
 	int score = 0;
 
 	while(vidas != 0){
 		
 		system("cls");
	
		fflush(stdin);
		
		int cuerpoS[200][2];
		int nS = 1, tamS = 5, dirS = 3;
		int xS = 10, yS = 12;
		int xc = 30, yc = 15;
		int velocidad = 140;
		int Sobrevive = 0;
		//score = 0;
		fflush(stdin);
		char teclaS;
			
		OcultaCursor();
	 
	 	pintar();
	 	gotoxyS(xc, yc); printf("%c", 4);
 		
 		
 		while(JuegoTerminado(yS, xS, tamS, cuerpoS)){
			borrar_cuerpo(cuerpoS, nS);
			guardar_posicion(cuerpoS, nS, xS, yS, tamS);
			dibujar_cuerpo(cuerpoS, tamS);
			if(dificultad == 1){
				comidaFacil(score, xS, yS, xc, yc, tamS, velocidad);	
			}else{
				comidaDificil(score, xS, yS, xc, yc, tamS, velocidad);
			}
			fflush(stdin);
			teclear(teclaS, dirS);
			fflush(stdin);
			teclear(teclaS, dirS);
			fflush(stdin);
			
			gotoxyS(1,1); printf("puntaje: %d", score);
			
			fflush(stdin);
			if(dirS == 1) yS--;
			if(dirS == 2) yS++;
			if(dirS == 3) xS++;
			if(dirS == 4) xS--;
			
			if(velocidad == 20){
				velocidad = 140;
			}
			
			Sleep(velocidad);
			
			gotoxyS(67, 1);
			printf("vidas: ");
			
			int gotoxyvidas = 75;
			
		    for (int i = 0; i < vidas; ++i) {
		    	gotoxyS(gotoxyvidas++, 1);
		        printf("%c ", 3);  // Código ASCII para el corazón
		    }	
		}
		
		system("cls");
		Sobrevive = PreguntaAleatoria();	
		if(Sobrevive == 0){
			vidas--;	
		}
		
		pintar();
	}
 	
 	EnJuego->score = score;
 	
 	return EnJuego;
}

void IniciaVideoJuegoInicioSesion(int opc){
	int dificultad = 0;
	dificultad = opc;
	system("cls");
	//VideoJuegoInicioSesion(dificultad)
	VideoJuegoInicioSesion(dificultad);
}

void IniciaVideoJuego(int opc){
	int dificultad = 0;
	dificultad = opc;
	Jugador *nuevo = registro();
	system("cls");
	Jugador *NodoNuevo = VideoJuego(nuevo, dificultad);
	agregarFinalSerpiente(NodoNuevo);
	nuevo = NULL;
	NodoNuevo = NULL;
}
