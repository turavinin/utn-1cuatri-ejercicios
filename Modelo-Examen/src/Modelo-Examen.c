#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "ePantalla.h"
#include "eContratacion.h"
#include "informes.h"

#define MAX_ARR_PANTALLA 100
#define MAX_ARR_CONTRATACIONES 1000

int main(void) {
	setbuf(stdout, NULL);

	// VARIABLES
	int opcionMenu;
	int exitoFuncion;
	int existenciaProxPantallaLibre;
	int salidaAltaPantalla;

	// ARRAY
	ePantalla listaPantallas[MAX_ARR_PANTALLA];
	eContrato listaContratos[MAX_ARR_CONTRATACIONES];

	initPantallas(listaPantallas, MAX_ARR_PANTALLA);
	initContrataciones(listaContratos, MAX_ARR_CONTRATACIONES);



	// MENU
	do{

		exitoFuncion = exitoFuncion = utn_getNumberLimited(&opcionMenu,
				"\n--------------- MENU --------------- "
				"\n 1. Alta de pantalla"
				"\n 2. Modificar datos de pantalla."
				"\n 3. Baja de pantalla"
				"\n 4. Contratar una publicidad"
				"\n 5. Modificar condiciones de publicidad"
				"\n 6. Cancelar contratacion"
				"\n 7. Consulta facturacion"
				"\n 8. Lista de contrataciones"
				"\n 9. Lista pantallas"
				"\n 10.Informar"
				"\n 0. Salir"
				"\nSeleccione una opción (Ingrese su numero): ",
				"\n--- ¡LA OPCION INGRESADA ES INCORRECTA! --- \n",
				0, 10, 3);

	if(exitoFuncion == 0)
	{
		switch(opcionMenu)
		{
			case 1:
				Pantalla_Alta(listaPantallas, MAX_ARR_PANTALLA, existenciaProxPantallaLibre);
				if(existenciaProxPantallaLibre != -1)
				{
					utn_getCharDosOpciones(&salidaAltaPantalla, "¿Desea seguir? (S / N): ", "Error.", 's', 'n', 3);
				}
				else
				{
					salidaAltaPantalla = 'n';
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
		}
	}



	}while(opcionMenu != 0);




	return EXIT_SUCCESS;
}
