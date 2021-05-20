#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"

#ifndef ETIPO_H_
#define ETIPO_H_


// DEFINES
#define MAX_ERRORES 3

// STRUCT
typedef struct
{
	int id;
	char tipo[15];
} eTipo;

int eTipo_GetTipo(eTipo* eArr, int largoArr, int* posicionTipo, char* mensaje, char* mensajeError, int maxErrores);

#endif /* ETIPO_H_ */
