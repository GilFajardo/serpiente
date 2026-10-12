#include "librerias.h"

int main(){
	int sigue = 1;
	
	primero = NULL;
	ultimo = NULL;
	primeroDioses = NULL;
	ultimoDioses = NULL;
	primeroPregunta = NULL;
	ultimoPregunta = NULL;
	srand(time(NULL));
	
	Lectura();
	Preguntas();
	LecturaReglas();
	
	//MostrarPreguntas();
	//getch();
	
	//PreguntaAleatoria();	
	
	//archivoEscritura();
	
	menuProyecto();
	
	//mostrar_listaSiguiente();
	
	return 0;
}
