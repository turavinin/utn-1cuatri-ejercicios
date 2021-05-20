#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "eContratacion.h"


// ID AUTOINCREMENTAL
int idContrato = 0;
void eContrato_SetId(int* id)
{
	*id = idContrato++;
}

// INIT ESTRUCTURA
int initContrataciones(eContrato* eArr, int largoArr)
{
	int exitoFuncion = -1;
	eContrato contratoVacio;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			eArr[i] = contratoVacio;
			eArr[i].isEmpty = 1;
		}
		exitoFuncion = 0;
	}
	return exitoFuncion;
}
