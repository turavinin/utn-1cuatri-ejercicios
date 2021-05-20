#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"


#ifndef EMESES_H_
#define EMESES_H_

// DEFINES
#define MAX_ERRORES 3

// STRUCT
typedef struct
{
	int id;
	char mes[15];
} eMeses;

int eMeses_GetMes(eMeses* eArr, int largoArr, int* posicionMes, char* mensaje, char* mensajeError, int maxErrores);

#endif /* EMESES_H_ */
