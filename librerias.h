#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
 
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27
 
using namespace std;

/*
int cuerpoS[200][2];
int nS = 1, tamS = 5, dirS = 3;
int xS = 10, yS = 12;
int xc = 30, yc = 15;
int velocidad = 140;
char teclaS;
*/

struct Jugador{
	int idJugador; 
	char nombre[100];
	char correo[100];
	int edad;
	char Username[100];
	char password[100];
	int score;
	struct Jugador *sig; 
}*primero, *ultimo;

struct Pregunta{
	int NumPregunta;
	char Pregunta[100];
	struct Pregunta *sig;
}*primeroPregunta, *ultimoPregunta;

struct Dioses{
	char Nombre[100];
	char informacion[1000];
	struct Pregunta *preguntas;
	struct Dioses *sig;
}*primeroDioses, *ultimoDioses;

struct Reglas{
	int numRegla;
	char Regla[300];
	struct Reglas *sig;	
}*primeroReglas, *ultimoReglas;

char InicioSesion[100] = "";
char Password[100] = "";

int opc = 0, x = 0, y = 0;

#include "archivos.h"
#include "prototipos.h"
#include "validaciones.h"
#include "registro.h"
#include "funciones.h"
#include "menu.h"
