#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaUTN-validaciones.h"

// Defines
#define MAX_ARR 3
#define MAX_CHAR 50

// Estructuras
typedef struct {
	int legajo;
	char sexo;
	int edad;
	float notaPrimera;
	float notaSegunda;
	float promedio;
	char apellido[MAX_CHAR];
	int estaLibre;
}alumno;

// Funciones
int inicializarListaAlumnos(alumno* array, int largoArr);
int buscarLibre(alumno* array, int largoArr, int* posicionLibre);
int agregarAlumno(alumno* array, int posicion);
int mostrarAlumnos(alumno* array, int largoArr);
int eliminarAlumno(alumno* array, int largoArr);

int main(void) {
	setbuf(stdout, NULL);

	// Variables
	int opcionMenu;
	int opcionBaja;
	int exitoFuncion;
	int lugarLibre;

	// Declara array de alumnos
	alumno listaAlumnos[MAX_ARR];

	// Inicializa lista
	inicializarListaAlumnos(listaAlumnos, MAX_ARR);

	printf("*****  LIBRO DE ESTUDIANTES  *****\n");
	do
	{
		exitoFuncion = utn_getNumberLimited(&opcionMenu,
											"\n------- MENU -------\n 1.Mostrar estudiantes.\n 2.Mostrar un estudiante.\n 3.Agregar estudiante.\n 4.Eliminar estudiante.\n 5.Salir.\nSeleccione una opción (ingrese su numero): ",
											"\n----- Opción ingresasa es incorrecta ----- \n",
											1, 5, 3);
		if(exitoFuncion == 0)
		{
			switch(opcionMenu)
			{
				case 1: // Mostrar todos
					mostrarAlumnos(listaAlumnos, MAX_ARR);
					break;
				case 2: // Mostrar uno
					break;
				case 3: // Alta
					exitoFuncion = buscarLibre(listaAlumnos, MAX_ARR, &lugarLibre);
					if(exitoFuncion == 0)
					{
						exitoFuncion = agregarAlumno(listaAlumnos, lugarLibre);
					}
					break;
				case 4: // Baja
					do
					{
					exitoFuncion = utn_getNumberLimited(&opcionBaja,
									"\n        ELIMINAR ALUMNO\n        1.Ingresar numero de legajo.\n        2.Cancelar\n        Selecciones una opcion: ",
									"\n----- Opción ingresasa es incorrecta ----- \n",
									1, 2, 3);
						if (exitoFuncion == 0)
						{
							switch(opcionBaja)
							{
								case 1:
									exitoFuncion = eliminarAlumno(listaAlumnos, MAX_ARR);
									if(exitoFuncion == 0)
									{
										opcionBaja = 2;
									}
									break;
								case 2:
									break;
							}
						}
						else
						{
							printf("\n ---- ERROS MAXIMOS ALCANZADOS ----");
							break;
						}
					}while(opcionBaja != 2);
					break;
			}
		}

	}while(opcionMenu != 5);
	return 0;
}


int inicializarListaAlumnos(alumno* array, int largoArr)
{
	int exito = -1;
	alumno estudiante;

	if(array != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < MAX_ARR; i++)
		{
			array[i] = estudiante;
			array[i].estaLibre = 1;
		}

		exito = 0;
	}

	return exito;
}
int buscarLibre(alumno* array, int largoArr, int* posicionLibre)
{
	int exito = -1;
	int i;

	if(array != NULL && largoArr > 0)
	{
		for(i = 0; i < largoArr; i++)
		{
			if(array[i].estaLibre == 1)
			{
				*posicionLibre = i;
				exito = 0;
				break;
			}
		}
	}


	return exito;
}
int agregarAlumno(alumno* array, int posicion)
{
	int exito = 0;

    alumno estudiante;

	printf("\n      ¡SE ENCONTRÓ UN LUGAR LIBRE!\n");

    printf("     - Ingrese legajo: ");
    fflush(stdin);
    scanf("%d", &estudiante.legajo);

    printf("     - Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &estudiante.sexo);

    printf("     - Ingrese edad: ");
    fflush(stdin);
    scanf("%d", &estudiante.edad);

    printf("     - Ingrese primera nota: ");
    fflush(stdin);
    scanf("%f", &estudiante.notaPrimera);

    printf("     - Ingrese segunda nota: ");
    fflush(stdin);
    scanf("%f", &estudiante.notaSegunda);

    estudiante.promedio = (estudiante.notaPrimera + estudiante.notaSegunda) / 2;

    printf("     - Ingrese apellido: ");
    fflush(stdin);
    gets(estudiante.apellido);

    estudiante.estaLibre = 0;

    array[posicion] = estudiante;

    return exito;
}
int mostrarAlumnos(alumno* array, int largoArr)
{
	int exito = -1;
	int i;
	if(array != NULL && largoArr > 0)
	{
		printf("\n   -------- ALUMNOS --------\n");
		for(i = 0; i < largoArr; i++)
		{
			if(array[i].estaLibre == 0)
			{
				printf("---Legajo: %d\n", array[i].legajo);
				printf("---Sexo: %c\n", array[i].sexo);
				printf("---Edad: %d\n", array[i].edad);
				printf("---Nota primera: %.1f\n", array[i].notaPrimera);
				printf("---Nota segunda: %.1f\n", array[i].notaSegunda);
				printf("---Promedio: %.1f\n", array[i].promedio);
				printf("---Apellido: %s\n\n", array[i].apellido);
				exito = 0;
			}
		}
		printf("\n   -------- ******* --------\n");
	}

	return exito;
}

int eliminarAlumno(alumno* array, int largoArr)
{
	int exito = -1;
	int legajo;
	alumno estudianteVacio;
	estudianteVacio.estaLibre = 1;
	int exitoFuncion = utn_getNumber(&legajo, "        ***Ingrese el legajo del alumno: ", "----- Ingreso incorrecto -----\n", 3);

	if(exitoFuncion)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(array[i].legajo == legajo)
			{
				printf("        ***SE ELIMINO EL ESTUDIANTE DE LEGAJO %d\n", array[i].legajo);
				array[i] = estudianteVacio;
				exito = 0;
				break;
			}
			else
			{
				printf("\n ---- ¡NO SE ENCONTRO EL ALUMNO! ----");
				break;
			}
		}
	}

	return exito;
}





