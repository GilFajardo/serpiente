void menu(int, int, int, int);
void gotoxy(int, int);

using namespace std;

HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
DWORD originalMode;

void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X	= x;
	dWPos.Y = y;
	SetConsoleCursorPosition(hcon, dWPos);
}

void menuDificultadIniciarSesion(){
	setlocale(LC_CTYPE, "Spanish");
	
	opc = 0;
	
	while (opc != 3){
		system("color 02");
		x=25;
		y=5;
		system("cls");
		gotoxy(x,y);
		printf("1.- Modo facil");
		gotoxy(x,++y);
		printf("2.- Modo dificil\n");
		gotoxy(x,++y);
		printf("3.- Regresar\n");
		gotoxy(x,++y);
		menu(22,5,1,3);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case 1:
				IniciaVideoJuegoInicioSesion(opc);
				break;
			case 2:
				IniciaVideoJuegoInicioSesion(opc);
				break;
			case 3:
				menuEmpezar();
				break;
				//Salir del videojuego
		}
	}
}

void menuDificultadNuevoJugador(){
	setlocale(LC_CTYPE, "Spanish");
	
	opc = 0;
	
	while (opc != 3){
		system("color 02");
		x=25;
		y=5;
		system("cls");
		gotoxy(x,y);
		printf("1.- Modo facil");
		gotoxy(x,++y);
		printf("2.- Modo dificil\n");
		gotoxy(x,++y);
		printf("3.- Regresar\n");
		gotoxy(x,++y);
		menu(22,5,1,3);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case 1:
				IniciaVideoJuego(opc);
				break;
			case 2:
				IniciaVideoJuego(opc);
				break;
			case 3:
				menuEmpezar();
				break;
				//Salir del videojuego
		}
	}
}

void menuEmpezar(){
	setlocale(LC_CTYPE, "Spanish");
	
	opc = 0;
	
	while (opc != 3){
		system("color 02");
		x=25;
		y=5;
		system("cls");
		gotoxy(x,y);
		printf("1.- Jugador Nuevo");
		gotoxy(x,++y);
		printf("2.- Iniciar Sesion");
		gotoxy(x,++y);
		printf("3.- Cancelar\n");
		gotoxy(x,++y);
		menu(22,5,1,3);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case 1:
				menuDificultadNuevoJugador();
				break;
			case 2:
				menuDificultadIniciarSesion();
				break;
			case 3:
				menuProyecto();
				break;
		}
	}
}

void menuProyecto(){
	setlocale(LC_CTYPE, "Spanish");
	
	opc = 0;
	
	while (opc != 5){
		system("color 02");
		x=25;
		y=5;
		system("cls");
		gotoxy(x,y);
		printf("1.- Empezar");
		gotoxy(x,++y);
		printf("2.- Lista de los dioses");
		gotoxy(x,++y);
		printf("3.- Reglas\n");
		gotoxy(x,++y);
		printf("4.- Marcadores\n");
		gotoxy(x,++y);
		printf("5.- Salir\n");
		gotoxy(x,++y);
		menu(22,5,1,5);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case 1:
				menuEmpezar();
				Sleep(3000);
				fflush(stdin);
				getch();
				menuProyecto();
				//Videojuego con el modo facil y el modo avanzado
				break;
			case 2:
				mostrarDioses();
				getch();
				break;
			case 3:
				mostrarListaReglas();
				getch();
				break;
			case 4:
				mostrar_listaSiguiente();
				getch();
				menuProyecto();
				//Marcadores del videojuego
				break;
			case 5:
				opc = 5;
				Guardar();
				exit(0);
				//return;
				break;
		}
	}
}

void menu(int x, int y, int inicio, int fin){
	char tecla='\0'; //' ';
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(x,y);
	printf("%c",16);
	
	do{
		if(kbhit()){
			tecla = getch();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>inicio&&tecla==72){ //flecha arriba 
				y--;
				opc--;
			}
			if(opc<fin&&tecla==80){ //flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla != 13); //13--> enter
}
