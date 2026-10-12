int generaID(const char *mensaje, int x, int y){
	bool bandera = true;
	
	int numRandom = 0, rep = 0;
	
	do{
		struct Jugador *auxiliar = primero;
		rep = 0;
		gotoxy(x, y);
        printf("                              ");
        gotoxy(x, y);
        //fflush(stdin);
        printf("%s", mensaje);
        numRandom = rand() % 90000 + 10000;
        printf("%d", numRandom);
        //scanf("%d", &numRandom);
        fflush(stdin);
		
		//numRandom = rand() % 90000 + 10000;
		while(auxiliar!=NULL){
			if(numRandom == auxiliar->idJugador){
				rep++;
			}
			auxiliar = auxiliar->sig;
		}	
	}while(rep != 0);
	
	return numRandom;
}

void validaPassword(const char *mensaje, char cadena[], int x, int y) {
    bool bandera = true;

    while (bandera) {
        gotoxy(x, y);
        printf("                              ");
        gotoxy(x, y);
        printf("%s", mensaje);
        scanf("%[^\n]", cadena);
        fflush(stdin);

        if (strlen(cadena) > 100) {
            continue;
        } else {
            bool caracteresValidos = true;

            for (int i = 0; i < strlen(cadena); i++) {
                if (!(isalpha(cadena[i]) || isdigit(cadena[i]) || cadena[i] == ' ')) {
                    caracteresValidos = false;
                    break;
                }
            }

            if (caracteresValidos) {
                bandera = false;
            }
        }
    }
}

void validaUsername(const char *mensaje, char cadena[], int x, int y) {
    bool bandera = true;

    while (bandera) {
        gotoxy(x, y);
        printf("                              ");
        gotoxy(x, y);
        printf("%s", mensaje);
        scanf("%[^\n]", cadena);
        fflush(stdin);

        if (strlen(cadena) > 100) {
            continue;
        } else {
            bool caracteresValidos = true;

            for (int i = 0; i < strlen(cadena); i++) {
                if (!(isalpha(cadena[i]) || isdigit(cadena[i]) || cadena[i] == ' ')) {
                    caracteresValidos = false;
                    break;
                }
            }

            if (caracteresValidos) {
                bandera = false;
            }
        }
    }
}

void validaCadena(const char *mensaje, char cadena[], int x, int y){
	bool bandera = true;
	
	while(bandera){
		gotoxy(x,y);
		printf("                              ");
		gotoxy(x,y);
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		//gets(cadena);
		fflush(stdin);
		if(strlen(cadena)>100) continue;
		else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isalpha(cadena[i]) || cadena[i] == ' '){ //isalpha: para comprobar que es un caracter 
					if(i == (strlen(cadena)-1)){
						bandera = false;
					}
				}else break;
			}
		}
	}
}

void valida_email(const char *mensaje, char cadena[], int x, int y){
	bool bandera = true;

    while (bandera) {
        gotoxy(x, y);
        printf("                              ");
        gotoxy(x, y);
        printf("%s", mensaje);
        scanf("%[^\n]", cadena);
        fflush(stdin);

        if (strlen(cadena) > 100) {
            continue;
        } else {
            bool contienePunto = false;

            for (int i = 0; i < strlen(cadena); i++) {
                if (isalpha(cadena[i]) || cadena[i] == ' ') {
                    if (i == (strlen(cadena) - 1)) {
                        for (int j = 0; j < strlen(cadena); j++) {
                            cadena[j] = tolower(cadena[j]);
                        }
                        bandera = false;
                    }
                } else if (cadena[i] == '.') {
                    contienePunto = true;
                } else {
                    break;
                }
            }

            if (!contienePunto) {
                bandera = true;
            }
        }
    }
}

int validaEntero(const char mensaje[]){
	fflush(stdin);
	int valida=0;
	int entero=0;
	
	do{
		printf("%s", mensaje);
		valida = scanf("%d", &entero);
		fflush(stdin);
	}while(valida != 1);
	
	return entero;
}

int validaIdJugador(const char mensaje[]){
	fflush(stdin);
	int valida=0;
	int entero=0;
	
	do{
		system("cls");
		gotoxy(25,5);
		printf("%s", mensaje);
		valida = scanf("%d", &entero);
		fflush(stdin);
	}while(valida != 1);
	
	return entero;
}

float validaFlotante(const char mensaje[]){
	fflush(stdin);
	int valida=0;
	float flotante=0;
	
	do{
		gotoxy(25,8);
		printf("                              ");
		gotoxy(25,8);
		printf("%s", mensaje);
		valida = scanf("%f", &flotante);
		fflush(stdin);
	}while(valida != 1);
	
	return flotante;
}

