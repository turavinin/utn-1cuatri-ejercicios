#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#ifndef EPANTALLA_H_
#define EPANTALLA_H_

#define MAX_CHAR 100
#define MAX_ERRORES 3
#define MAX_COL 5

// ESTRUCTURA
typedef struct
{
	int id;
	int tipo;
	char nombre[MAX_CHAR];
	char direccion[MAX_CHAR];
	float precioDiario;
	int isEmpty;
} ePantalla;


// ID
void ePantalla_SetId(int* id);

// INIT STRUCT
int initPantallas(ePantalla* eArr, int largoArr);

// ADD
int searhPantallaLibre(ePantalla* eArr, int largoArr, int* posLibre);
int addPantalla(ePantalla* eArr, int largoArr, int id, int tipo, char* nombre, char* direccion, float precio, int posLibre);
int Pantalla_Alta(ePantalla* eArr, int largoArr, int* existenciaProxLibre);

#endif /* EPANTALLA_H_ */
