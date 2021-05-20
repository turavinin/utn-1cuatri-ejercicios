#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#ifndef ECONTRATACION_H_
#define ECONTRATACION_H_
#define MAX_CHAR 100


// ESTRUCTURA
typedef struct
{
	int id;
	int idPantalla;
	char cuitCliente[MAX_CHAR];
	int diasContrato;
	char nombreArchivo[MAX_CHAR];
	int isEmpty;
} eContrato;


// ID
void eContrato_SetId(int* id);

// INIT STRUCT
int initContrataciones(eContrato* eArr, int largoArr);

#endif /* ECONTRATACION_H_ */
