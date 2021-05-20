#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaUTN-validaciones.h"

// Defines
#define MAX_ARR 3
#define MAX_CHAR 50

// Estructuras
typedef struct {
	int IdEstudiante;
	int legajo;
	char sexo;
	int edad;
	float notaPrimera;
	float notaSegunda;
	float promedio;
	char apellido[MAX_CHAR];
	int IdCarrera;
	int estaLibre;
}alumno;

typedef struct{
	int IdCarrera;
	char NombreCarrera[MAX_CHAR];
	int estaLibre;
} Carrera;

// Funciones
int inicializarListaAlumnos(alumno* array, int largoArr);
int buscarLibre(alumno* array, int largoArr, int* posicionLibre);
int agregarAlumno(alumno* array, int posicion, int*contadorId);
int altaAlumno(alumno* array, int largoArr, int* contadorId);
int mostrarEstudiantes(alumno* array, int largoArr);
int eliminarAlumno(alumno* array, int largoArr);
int mostrarEstudiante(alumno* array, int largoArr);
int pedirLegajo(int* legajoEstudiante);
int ordenarPorLegajo(alumno* array, int largoArr);
int ordenarPorApellido(alumno* array, int largoArr);
int ordenarPorPromedio(alumno* array, int largoArr);
void swapArrayAlumnos(alumno* array, int primeraPosicion, int segundaPosicion);
int listaVacia(alumno* array, int largoArr);
int modificarApellido(alumno* array, int largoArr, int legajo);
int modificarEdad(alumno* array, int largoArr, int legajo);
int bajaEstudiante(alumno* array, int largoArr);
int mostrarEstudianteByLegajo(alumno* array, int largoArr, int legajo);
int ordenarAlumnos(alumno* array, int largoArr);
int modificarDatosAlumno(alumno* array, int largoArr);
int informarEstudiantesCarrera(Carrera* arrayCarrera, alumno* arrayAlumnos, int largoArr);
int buscarDescripcionCarrera(Carrera* arrCarrera, int largoArr, int IdCarrera, char* descripcion);
int mostrarEstudianteById(alumno* array, int largoArr, int IdEstudiante);
int mostrarEstudiandoByPosicion(alumno* arrayAlumnos, int posicionArr);
int informarEstudianteJoven(alumno* array, int largoArr);

int main(void) {
	setbuf(stdout, NULL);

	// Variables
	int opcionMenu;
	int exitoFuncion;
	int contadorId = 0;

	// Declara array de alumnos
	alumno listaAlumnos[MAX_ARR];

	// Inicializa lista
	inicializarListaAlumnos(listaAlumnos, MAX_ARR);

	// Carreras
	Carrera listaCarreras[MAX_ARR]={
			{1, "Programacion", 0},
			{2, "Medicina", 0},
			{3, "Filosofia", 0}
	};



	printf("*****  LIBRO DE ESTUDIANTES  *****\n");
	do
	{

		if(0%2)
		{
			switch(opcionMenu)
			{
				case 1: // Mostrar todos
					mostrarEstudiantes(listaAlumnos, MAX_ARR);
					break;
				case 2: // Mostrar uno
					mostrarEstudiante(listaAlumnos, MAX_ARR);
					break;
				case 3: // Alta
					altaAlumno(listaAlumnos, MAX_ARR, &contadorId);
					break;
				case 4: // Baja
					bajaEstudiante(listaAlumnos, MAX_ARR);
					break;
				case 5: // Ordenar
					ordenarAlumnos(listaAlumnos, MAX_ARR);
					break;
				case 6: // Modificar
					modificarDatosAlumno(listaAlumnos, MAX_ARR);
					break;
				case 7: // Mostrar por carrera
					informarEstudiantesCarrera(listaCarreras, listaAlumnos, MAX_ARR);
					break;
				case 8: // Mostrar joven
					informarEstudianteJoven(listaAlumnos, MAX_ARR);
					break;
			}
		}

	}while(opcionMenu != 9);
	return 0;
}


int inicializarListaAlumnos(alumno* array, int largoArr)
{
	int exito = -1;
	alumno estudiante;
	estudiante.IdCarrera = 0;
	estudiante.edad = 0;

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
int agregarAlumno(alumno* array, int posicion, int* Id)
{
	int exitoFuncion = -1;
	int carreraElegida;

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

    exitoFuncion = utn_getNumberLimited(&carreraElegida,
    						"\n     - Ingrese carrera: \n        1.Programacion.\n        2.Medicina\n        3.Filosofia\n        Selecciones una opcion: ",
    						"\n----- Opción ingresasa es incorrecta ----- \n", 1, 3,
    						3);
    switch(carreraElegida)
    {
    case 1:
    	estudiante.IdCarrera = 1;
    	break;
    case 2:
    	estudiante.IdCarrera = 2;
    	break;
    case 3:
    	estudiante.IdCarrera = 3;
    	break;
    }

    estudiante.estaLibre = 0;

    estudiante.IdEstudiante = *Id;
    (*Id)++;

    array[posicion] = estudiante;

    if(exitoFuncion == -1)
    {
    	alumno estudianteVacio;
    	estudianteVacio.estaLibre = 1;
    	array[posicion] = estudianteVacio;
    }

    return exitoFuncion;
}
int altaAlumno(alumno* array, int largoArr, int* contId)
{
	int auxContadorId = *contId;
	int posicionLibre;
	int exitoFuncion = buscarLibre(array, largoArr, &posicionLibre);
	if(exitoFuncion == 0)
	{
		exitoFuncion = agregarAlumno(array, posicionLibre, &auxContadorId);
		*contId = auxContadorId;
	}

	return exitoFuncion;
}
int mostrarEstudiantes(alumno* array, int largoArr)
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
				printf("---Apellido: %s\n", array[i].apellido);
				printf("-----------\n");
				exito = 0;
			}
		}
		printf("\n   -------- ******* --------\n");
	}

	return exito;
}
int mostrarEstudiante(alumno* array, int largoArr)
{

	int legajoEstudiante;
	int exitoFuncion = pedirLegajo(&legajoEstudiante);

	if(exitoFuncion == 0)
	{
		if(array != NULL)
		{
			int i;
			printf("\n   -------- ALUMNO --------\n");
			for(i = 0; i < largoArr; i++)
			{
				if(array[i].legajo == legajoEstudiante)
				{
					printf("\n---Legajo: %d\n", array[i].legajo);
					printf("---Sexo: %c\n", array[i].sexo);
					printf("---Edad: %d\n", array[i].edad);
					printf("---Nota primera: %.1f\n", array[i].notaPrimera);
					printf("---Nota segunda: %.1f\n", array[i].notaSegunda);
					printf("---Promedio: %.1f\n", array[i].promedio);
					printf("---Apellido: %s\n", array[i].apellido);
					break;
				}
			}
			printf("\n   -------- ******* --------\n");
		}
		else
		{
			exitoFuncion = -1;
			printf("        ---NO SE ENCONTRÓ AL ALUMNO\n");
		}

	}

	return exitoFuncion;
}
int pedirLegajo(int* legajoEstudiante)
{
	int exito = -1;
	int legajo;
	int exitoFuncion = utn_getNumber(&legajo, "        ***Ingrese el legajo del alumno: ", "----- Ingreso incorrecto -----\n", 3);

	if(exitoFuncion)
	{
		*legajoEstudiante = legajo;
		exito = 0;
	}
	else
	{
		printf("MUCHOS ERRORES");
	}

	return exito;
}
int ordenarPorLegajo(alumno* array, int largoArr)
{
	int exito = -1;

	if(array != NULL && largoArr > 0)
	{

		int i;
		int j;
		for(i = 0; i < largoArr - 1; i++)
		{
			for(j = i + 1; j < largoArr; j++)
			{
				if(array[i].legajo > array[j].legajo)
				{
					swapArrayAlumnos(array, i, j);
				}
			}
		}
	}

	return exito;
}
int ordenarPorApellido(alumno* array, int largoArr)
{
	int exito = -1;

	if(array != NULL && largoArr > 0)
	{

		int i;
		int j;
		for(i = 0; i < largoArr - 1; i++)
		{
			for(j = i + 1; j < largoArr; j++)
			{
				if(strcmp(array[i].apellido, array[j].apellido) > 0)
				{
					swapArrayAlumnos(array, i, j);
				}
			}
		}
	}

	return exito;

}
int ordenarPorPromedio(alumno* array, int largoArr)
{
	int exito = -1;

		if(array != NULL && largoArr > 0)
		{

			int i;
			int j;
			for(i = 0; i < largoArr - 1; i++)
			{
				for(j = i + 1; j < largoArr; j++)
				{
					if(array[i].promedio < array[j].promedio || (array[i].promedio == array[j].promedio && array[i].legajo > array[j].legajo))
					{
						swapArrayAlumnos(array, i, j);
					}
				}
			}
		}

		return exito;
}
void swapArrayAlumnos(alumno* array, int primeraPosicion, int segundaPosicion)
{
	alumno aux;
	aux = array[primeraPosicion];
	array[primeraPosicion] = array[segundaPosicion];
	array[segundaPosicion] = aux;
}
int listaVacia(alumno* array, int largoArr)
{
	int exito = 0;
		int i;

		if(array != NULL && largoArr > 0)
		{
			for(i = 0; i < largoArr; i++)
			{
				if(array[i].estaLibre == 1)
				{
					exito = -1;
					break;
				}
			}
		}

		return exito;
}
int modificarApellido(alumno* array, int largoArr, int legajo)
{
	int exito = -1;

	if(array != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(array[i].legajo == legajo)
			{
				printf("     - Ingrese el nuevo apellido: ");
				fflush(stdin);
				gets(array[i].apellido);
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
int modificarEdad(alumno* array, int largoArr, int legajo)
{
	int exito = -1;

	if(array != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(array[i].legajo == legajo)
			{
			    printf("     - Ingrese nueva edad: ");
			    fflush(stdin);
			    scanf("%d", &array[i].edad);
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
int eliminarAlumno(alumno* array, int largoArr)
{
	int exito = -1;
	int legajo;
	alumno estudianteVacio;
	estudianteVacio.estaLibre = 1;
	int exitoFuncion = utn_getNumber(&legajo, "***INGRESE EL NUMERO DE LEGAJO DEL ALUMNO: ", "----- Ingreso incorrecto -----\n", 3);

	if(exitoFuncion)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(array[i].legajo == legajo)
			{
				printf("***SE ELIMINO EL SIGUIENTE ESTUDIANTE:\n");
				mostrarEstudianteByLegajo(array, largoArr, legajo);
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
int bajaEstudiante(alumno* array, int largoArr)
{
	int opcionBaja;
	int exitoFuncion = -1;

	do {
		int exitoFuncion = utn_getNumberLimited(&opcionBaja,
						"\n        ELIMINAR ALUMNO\n        1.Ingresar numero de legajo.\n        2.Cancelar\n        Selecciones una opcion: ",
						"\n----- Opción ingresasa es incorrecta ----- \n", 1, 2,
						3);
		if (exitoFuncion == 0) {

			switch (opcionBaja) {
			case 1:
				mostrarEstudiantes(array, largoArr);
				exitoFuncion = eliminarAlumno(array, largoArr);
				if (exitoFuncion == 0) {
					opcionBaja = 2;
				}
				break;
			case 2:
				break;
			}
		} else {
			printf("\n ---- ERROS MAXIMOS ALCANZADOS ----");
			break;
		}
	} while (opcionBaja != 2);

	return exitoFuncion;
}
int mostrarEstudianteByLegajo(alumno* array, int largoArr, int legajo)
{
	int exitoFuncion = -1;

	if (array != NULL && largoArr > 0)
	{
		int i;
		printf("\n   -------- ALUMNO --------\n");
		for (i = 0; i < largoArr; i++) {
			if (array[i].legajo == legajo) {
				printf("\n---Legajo: %d\n", array[i].legajo);
				printf("---Sexo: %c\n", array[i].sexo);
				printf("---Edad: %d\n", array[i].edad);
				printf("---Nota primera: %.1f\n", array[i].notaPrimera);
				printf("---Nota segunda: %.1f\n", array[i].notaSegunda);
				printf("---Promedio: %.1f\n", array[i].promedio);
				printf("---Apellido: %s\n", array[i].apellido);
				exitoFuncion = 0;
				break;
			}
		}
		printf("\n   -------- ******* --------\n");
	}
	else
	{
		printf("        ---NO SE ENCONTRÓ AL ALUMNO\n");
	}

	return exitoFuncion;
}
int ordenarAlumnos(alumno* array, int largoArr)
{

	int exitoFuncion = -1;
	int opcionOrden;

	do
	{
		exitoFuncion = utn_getNumberLimited(&opcionOrden,
						"\n        ORDENAR ALUMNOS\n        1.Por legajo.\n        2.Apellido\n        3.Promedio\n        4.Cancelar\n        Selecciones una opcion: ",
						"\n----- Opción ingresasa es incorrecta ----- \n", 1, 4,
						3);
		if (exitoFuncion == 0) {
			if (listaVacia(array, largoArr) == -1 || opcionOrden == 4) {
				switch (opcionOrden) {
				case 1:
					ordenarPorLegajo(array, largoArr);
					opcionOrden = 4;
					break;
				case 2:
					ordenarPorApellido(array, largoArr);
					opcionOrden = 4;
					break;
				case 3:
					ordenarPorPromedio(array, largoArr);
					opcionOrden = 4;
					break;
				}
			}
			printf("\n ----- NO HAY ALUMNOS -----\n");
			opcionOrden = 4;
		}

	} while (opcionOrden != 4);

	return exitoFuncion;
}
int modificarDatosAlumno(alumno* array, int largoArr)
{
	int exitoFuncion = -1;
	int opcionModificar;
	int opcionBaja;
	int legajoEstudiante;
	exitoFuncion = pedirLegajo(&legajoEstudiante);

	if(exitoFuncion == 0)
	{
		do {
			exitoFuncion =
					utn_getNumberLimited(&opcionModificar,
							"\n       MODIFICAR ALUMNO\n        1.Modificar apellido.\n        2.Modificar edad\n        3.Cancelar\n        Selecciones una opcion: ",
							"\n----- Opción ingresasa es incorrecta ----- \n",
							1, 3, 3);

			if (exitoFuncion == 0) {
				exitoFuncion = -1;
				switch (opcionModificar) {
				case 1:
					mostrarEstudiantes(array, largoArr);
					exitoFuncion = modificarApellido(array, largoArr,
							legajoEstudiante);
					if (exitoFuncion == 0) {
						opcionBaja = 3;
					}
					break;
				case 2:
					mostrarEstudiantes(array, largoArr);
					exitoFuncion = modificarEdad(array, largoArr,
							legajoEstudiante);
					if (exitoFuncion == 0) {
						opcionBaja = 3;
					}
					break;
				}
			} else {
				printf("\n ---- ERROS MAXIMOS ALCANZADOS ----");
				exitoFuncion = -1;
				break;
			}
		} while (opcionBaja != 3);
	}

	return exitoFuncion;

}
int mostrarEstudianteById(alumno* array, int largoArr, int IdEstudiante)
{
	int exitoFuncion = -1;
	if (array != NULL) {
		int i;
		for (i = 0; i < largoArr; i++) {
			if (array[i].IdEstudiante == IdEstudiante) {
				printf("-------------------\n");
				printf("---Legajo: %d\n", array[i].legajo);
				printf("---Sexo: %c\n", array[i].sexo);
				printf("---Edad: %d\n", array[i].edad);
				printf("---Nota primera: %.1f\n", array[i].notaPrimera);
				printf("---Nota segunda: %.1f\n", array[i].notaSegunda);
				printf("---Promedio: %.1f\n", array[i].promedio);
				printf("---Apellido: %s\n", array[i].apellido);
				printf("-------------------\n");
				exitoFuncion = 0;
				break;
			}
		}
		printf("\n   -------- ******* --------\n");
	} else {
		exitoFuncion = -1;
		printf("        ---NO SE ENCONTRÓ AL ALUMNO\n");
	}

	return exitoFuncion;
}
int buscarDescripcionCarrera(Carrera* arrCarrera, int largoArr, int IdCarrera, char* descripcion)
{
	int exitoFuncion = -1;
	char auxDesciprcion[20];

	if(arrCarrera != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(arrCarrera[i].IdCarrera == IdCarrera)
			{
				strcpy(auxDesciprcion, arrCarrera[i].NombreCarrera);
				strcpy(descripcion, auxDesciprcion);
				exitoFuncion = 0;

			}
		}
	}

	return exitoFuncion;
}
int informarEstudiantesCarrera(Carrera* arrayCarrera, alumno* arrayAlumnos, int largoArr)
{
	int exitoFuncion = -1;
	int numeroCarrera;
	char descripcionCarrera[20];

	exitoFuncion = utn_getNumberLimited(&numeroCarrera,
					"\n        MOSTRAR ESTUDIANTES POR CARRERA\n        1.Programacion\n        2.Medicina\n        3.Filosofia\n        4.Cancelar\n        Selecciones una opcion: ",
					"\n----- Opción ingresasa es incorrecta ----- \n", 1, 4,
					3);
	if(exitoFuncion == 0 && arrayCarrera != NULL && arrayAlumnos != NULL && largoArr > 0)
	{
		if(numeroCarrera != 4)
		{
			exitoFuncion = buscarDescripcionCarrera(arrayCarrera, largoArr, numeroCarrera, descripcionCarrera);
			if(exitoFuncion == 0)
			{
				printf("\n-- Los alumnos de %s son: \n\n", descripcionCarrera);
				int i;
				for(i = 0; i < largoArr; i++)
				{
					if(arrayAlumnos[i].IdCarrera == numeroCarrera)
					mostrarEstudianteById(arrayAlumnos, largoArr, arrayAlumnos[i].IdEstudiante);
				}
			}
		}
	}
	return exitoFuncion;
}
int mostrarEstudiandoByPosicion(alumno unAlumno)
{
	int exitoFuncion = -1;

	if(arrayAlumnos != NULL && posicionArr >= 0)
	{
		printf("-------------------\n");
		printf("---Legajo: %d\n", arrayAlumnos[posicionArr].legajo);
		printf("---Sexo: %c\n", arrayAlumnos[posicionArr].sexo);
		printf("---Edad: %d\n", arrayAlumnos[posicionArr].edad);
		printf("---Nota primera: %.1f\n", arrayAlumnos[posicionArr].notaPrimera);
		printf("---Nota segunda: %.1f\n", arrayAlumnos[posicionArr].notaSegunda);
		printf("---Promedio: %.1f\n", arrayAlumnos[posicionArr].promedio);
		printf("---Apellido: %s\n", arrayAlumnos[posicionArr].apellido);
		printf("-------------------\n");
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int informarEstudianteJoven(alumno* array, int largoArr)
{
	int exitoFuncion = -1;
	int flagJoven = 0;
	int posicionJoven;
	int edadJoven = 0;
	int i;

	if(array != NULL && largoArr > 0)
	{
		for(i = 0; i < largoArr; i++)
		{
			if(flagJoven == 0 || (array[i].edad < edadJoven && array[i].edad != 0))
			{
				flagJoven = 1;
				posicionJoven = i;
				edadJoven = array[i].edad;
			}
		}

		mostrarEstudiandoByPosicion(array[posicionJoven]); // ACA PUEDO PASAR EL STRUCt DIRECTAMENTE
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
