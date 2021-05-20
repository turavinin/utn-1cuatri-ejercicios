#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "eRecaudacion.h"
#include "informes.h"


// DEFINES
#define LARGO_ARR 5

int main(void) {
	setbuf(stdout, NULL);

	// VARIABLES
	int exitoFuncion;
	int opcionMenu;


	// ARRAYS
	/*eContribuyente listaContribuyentes[LARGO_ARR];*/
	eRecaudacion listaRecaudaciones[LARGO_ARR];

	// INICIAR ARRAYS
	/*iniciarContribuyentes(listaContribuyentes, LARGO_ARR);*/
	iniciarRecaudaciones(listaRecaudaciones, LARGO_ARR);

	// HARDOCDE
	eContribuyente listaContribuyentes[LARGO_ARR] = {
			{1000, "aa", "aa", "20-19015157-4", 0},
			{1001, "yy", "yy", "30-19015157-4", 0},
			{1002, "ee", "ee", "40-19015157-4", 0},
			{1003, "dd", "dd", "50-19015157-4", 0},
			{1004, "bb", "bb", "60-19015157-4", 0}
	};

	do
	{
		exitoFuncion = utn_getNumberLimited(&opcionMenu,
						"\n|-----------------------MENU-------------------------|"
						"\n| 1. ALTA DE CONTRIBUYENTE                           |"
						"\n| 2. MODIFICAR DATOS DEL CONTRIBUYENTE               |"
						"\n| 3. BAJA DE CONTRIBUYENTE                           |"
						"\n| 4. RECAUDACION                                     |"
						"\n| 5. REFINANCIAR RECAUDACION                         |"
						"\n| 6. SALDAR RECAUDACION                              |"
						"\n| 7. IMPRIMIR CONTRIBUYENTES                         |"
						"\n| 8. IMPRIMIR RECAUDACION                            |"
						"\n| 0. SALIR                                           |"
						"\n|----------------------------------------------------|"
						"\n| Seleccione una opción (Ingrese su número): ",
						"\n|    --- ¡LA OPCION INGRESADA ES INCORRECTA! ---     |\n",
						0, 8, 3);

		if(exitoFuncion == 0)
		{
			switch(opcionMenu)
			{
				case 1:
					eContribuyente_Alta(listaContribuyentes, LARGO_ARR);
					break;
				case 2:
					eContribuyente_Modificar(listaContribuyentes, LARGO_ARR);
					break;
				case 3:
					eRecaudacion_Eliminar(listaRecaudaciones, listaContribuyentes, LARGO_ARR, LARGO_ARR);
					break;
				case 4:
					eRecaudacion_Alta(listaRecaudaciones, listaContribuyentes, LARGO_ARR);
					break;
				case 5:
					eRecaudacion_Operaciones(listaRecaudaciones, listaContribuyentes, LARGO_ARR, 1);
					break;
				case 6:
					eRecaudacion_Operaciones(listaRecaudaciones, listaContribuyentes, LARGO_ARR, 2);
					break;
				case 7:
					imprimirContribuyentes(listaRecaudaciones, listaContribuyentes, LARGO_ARR);
					break;
				case 8:
					imprimirRecaudacionesSaldadas(listaRecaudaciones, listaContribuyentes, LARGO_ARR);
					break;
			}
		}
	} while(opcionMenu != 0);




	return EXIT_SUCCESS;
}
