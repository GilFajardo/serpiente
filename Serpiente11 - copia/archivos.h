void Guardar(){
	Jugador *aux = primero;
	ofstream archivo("jugadores.txt");
	while(aux != NULL){
		archivo<<aux->idJugador<<"\t";
		archivo<<aux->nombre<<"\t";
		archivo<<aux->correo<<"\t";
		archivo<<aux->edad<<"\t";
		archivo<<aux->Username<<"\t";
		archivo<<aux->password<<"\t";
		archivo<<aux->score<<"\n";
		aux = aux->sig;
	}
}

void Lectura(){
    FILE *arch = NULL;
      if ((arch = fopen("jugadores.txt", "r")) == NULL) {
      printf("Error al intentar abrir el archivo\n");
      exit(1);
    }

    while (!feof(arch)) {
    	Jugador *nuevoJugador = new Jugador;
        nuevoJugador->sig = NULL;
        fscanf(arch, "%d\t", &nuevoJugador->idJugador);
        fscanf(arch, "%[^\t]\t", nuevoJugador->nombre);
        fscanf(arch, "%[^\t]\t", nuevoJugador->correo);
        fscanf(arch, "%d\t", &nuevoJugador->edad);
        fscanf(arch, "%[^\t]\t", nuevoJugador->Username);
        fscanf(arch, "%[^\t]\t", nuevoJugador->password);
        fscanf(arch, "%d\n", &nuevoJugador->score);
        
        if (primero == NULL) {
            primero = nuevoJugador;
            ultimo = nuevoJugador;
        } else {
            ultimo->sig = nuevoJugador;
            ultimo = nuevoJugador;
        }
    }
    fclose(arch);
}

void Preguntas(){
    FILE *arch = NULL;
      if ((arch = fopen("preguntas2.txt", "r")) == NULL) {
      printf("Error al intentar abrir el archivo\n");
      exit(1);
    }

    while (!feof(arch)) {
    	Dioses *nuevoDioses = new Dioses;
        nuevoDioses->preguntas = NULL;
        nuevoDioses->sig = NULL;
        
        fscanf(arch, "%[^\t]\t", nuevoDioses->Nombre);
        fscanf(arch, "%[^\n]\n", nuevoDioses->informacion);
        
        for (int i = 0; i < 3; i++) {
        	Pregunta *nuevoPregunta = new Pregunta;
        	fscanf(arch, "%d\t", &nuevoPregunta->NumPregunta);
        	fscanf(arch, "%[^\n]\n", nuevoPregunta->Pregunta);
        	nuevoPregunta->sig = NULL;
			
            if (nuevoDioses->preguntas == NULL) {
            	nuevoDioses->preguntas = nuevoPregunta;
            } else {
                struct Pregunta *auxiliarPregunta = nuevoDioses->preguntas;
                while (auxiliarPregunta->sig != NULL) {
                    auxiliarPregunta = auxiliarPregunta->sig;
                }
                auxiliarPregunta->sig = nuevoPregunta;
            }
		}
		
        if (primeroDioses == NULL) {
            primeroDioses = nuevoDioses;
            ultimoDioses = nuevoDioses;
        } else {
            ultimoDioses->sig = nuevoDioses;
            ultimoDioses = nuevoDioses;
        }
    }
    fclose(arch);
}

void LecturaReglas(){
    FILE *arch = NULL;
      if ((arch = fopen("reglas.txt", "r")) == NULL) {
      printf("Error al intentar abrir el archivo\n");
      exit(1);
    }

    while (!feof(arch)) {
    	//Jugador *nuevoJugador = new Jugador;
        //nuevoJugador->sig = NULL;
        Reglas *nuevaRegla = new Reglas;
        nuevaRegla->sig;
        fscanf(arch, "%d\t", &nuevaRegla->numRegla);
        fscanf(arch, "%[^\n]\n", nuevaRegla->Regla);
        fflush(stdin);
        /*
        fscanf(arch, "%d\t", &nuevoJugador->idJugador);
        fscanf(arch, "%[^\t]\t", nuevoJugador->nombre);
        fscanf(arch, "%[^\t]\t", nuevoJugador->correo);
        fscanf(arch, "%d\t", &nuevoJugador->edad);
        fscanf(arch, "%[^\t]\t", nuevoJugador->Username);
        fscanf(arch, "%[^\t]\t", nuevoJugador->password);
        fscanf(arch, "%d\n", &nuevoJugador->score);
        */
        
        if (primeroReglas == NULL) {
            primeroReglas = nuevaRegla;
            ultimoReglas = nuevaRegla;
        } else {
            ultimoReglas->sig = nuevaRegla;
            ultimoReglas = nuevaRegla;
        }
    }
    fclose(arch);
}
