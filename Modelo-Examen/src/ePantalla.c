#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "ePantalla.h"


// ID AUTOINCREMENTAL
int idPantalla = 0;
void ePantalla_SetId(int* id)
{
	*id = idPantalla++;
}

// INIT ESTRUCTURA
int initPantallas(ePantalla* eArr, int largoArr)
{
	int exitoFuncion = -1;
	ePantalla pantallaVacia;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			eArr[i] = pantallaVacia;
			eArr[i].isEmpty = 1;
		}
		exitoFuncion = 0;
	}
	return exitoFuncion;
}

// ADD
int searhPantallaLibre(ePantalla* eArr, int largoArr, int* posLibre)
{
	int exitoFuncion = -1;

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].isEmpty == 1)
			{
				*posLibre = i;
				exitoFuncion = 0;
				break;
			}
		}

		if(exitoFuncion == -1)
		{
			*posLibre = -1;
		}
	}
	return exitoFuncion;
}
int addPantalla(ePantalla* eArr, int largoArr, int id, int tipo, char* nombre, char* direccion, float precio, int posLibre)
{
	int exitoFuncion = -1;
	if(eArr != NULL && largoArr > 0)
	{
		eArr[posLibre].id = id;
		eArr[posLibre].tipo = tipo;
		strcpy(eArr[posLibre].nombre, nombre);
		strcpy(eArr[posLibre].direccion, direccion);
		eArr[posLibre].precioDiario = precio;
		eArr[posLibre].isEmpty = 0;
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int Pantalla_Alta(ePantalla* eArr, int largoArr, int* existenciaProxLibre)
{
	int exitoFuncion = -1;
	int posLibre;
	int auxProxLibre = *existenciaProxLibre;
	int exito = searhPantallaLibre(eArr, largoArr, &posLibre);

	if(exito == 0)
	{
		// Variable datos
		int exito;
		int tipo;
		char nombre[MAX_CHAR];
		char direccion[MAX_CHAR];
		float precioDiario;

		// AGREGAR TIPO
		if(utn_getStringLimited(nombre, "\nIngrese nombre de pantalla: ", "-- Error de carga. ", MAX_CHAR, MAX_ERRORES) == 0 &&
		utn_getStringLimited(direccion, "Ingrese direccion de pantalla: ", "-- Error de carga. ", MAX_CHAR, MAX_ERRORES) == 0 &&
		utn_getFloat(&precioDiario, "Ingrese precio de pantalla: ", "-- Error de carga. ", MAX_ERRORES) == 0)
		{
			int id;
			ePantalla_SetId(&id);
			exito = addPantalla(eArr, largoArr, id, tipo, nombre, direccion, precioDiario, posLibre);
			exitoFuncion = 0;
		}
		else
		{
			exito = -1;
		}

		searhPantallaLibre(eArr, largoArr, &auxProxLibre);
		if(auxProxLibre == -1)
		{
			*existenciaProxLibre = auxProxLibre;
		}
	}

	if(exito != 0)
	{
		printf("---- ERROR AL INGRESAR PANTALLA ----");
	}

	return exitoFuncion;
}

