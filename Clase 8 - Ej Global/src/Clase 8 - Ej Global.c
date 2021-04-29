
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

void iniciarArrInt(int arr[], int size);
void iniciarArrFloat(float arr[], int size);
void iniciarArrChar(char arr[], int size);
void iniciarArrString(char arr[][20], int size);
void cargarDatos(int indice[], int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int largoArrs);
void mostrarEstudiantes(int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int cantidadEstudiantes);
void swapIntArr(int arr1[], int arr2[], int i, int j);
void swapCharArr(char arr1[], char arr2[], int i, int j);
void swapFloatArr(float arr1[], float arr2[], int i, int j);
void swapStringArr(char arr1[][20], char arr2[][20], int i, int j);
void ordernarPorLegajo(int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int cantidadEstudiantes);
void ordernarPorApellido(int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int cantidadEstudiantes);
void ordernarPorPromedio(int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int cantidadEstudiantes);

int main(void) {
	setbuf(stdout, NULL);

	// Declaracion arrays
	int arrIndice[MAX];
	int arrLegajo[MAX];
	char arrSexo[MAX];
	int arrEdad[MAX];
	float arrNotaUno[MAX];
	float arrNotaDos[MAX];
	float arrPromedio[MAX];
	char arrNombre[MAX][20];


	// Inicializa arrays
	iniciarArrInt(arrIndice, MAX);
	iniciarArrInt(arrLegajo, MAX);
	iniciarArrChar(arrSexo, MAX);
	iniciarArrInt(arrEdad, MAX);
	iniciarArrFloat(arrNotaUno, MAX);
	iniciarArrFloat(arrNotaDos, MAX);
	iniciarArrFloat(arrPromedio, MAX);
	iniciarArrString(arrNombre, MAX);

	// Carga datos
	cargarDatos(arrIndice, arrLegajo, arrSexo, arrEdad, arrNotaUno, arrNotaDos, arrPromedio, arrNombre, MAX);

	// Ordenar datos
	//ordernarPorLegajo(arrLegajo, arrSexo, arrEdad, arrNotaUno, arrNotaDos, arrPromedio, arrNombre, MAX);
	//ordernarPorApellido(arrLegajo, arrSexo, arrEdad, arrNotaUno, arrNotaDos, arrPromedio, arrNombre, MAX);
	ordernarPorPromedio(arrLegajo, arrSexo, arrEdad, arrNotaUno, arrNotaDos, arrPromedio, arrNombre, MAX);

	// Mostrar
	mostrarEstudiantes(arrLegajo, arrSexo, arrEdad, arrNotaUno, arrNotaDos, arrPromedio, arrNombre, MAX);


	return EXIT_SUCCESS;
}

// INICIAR
void iniciarArrInt(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
void iniciarArrFloat(float arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
void iniciarArrChar(char arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		arr[i] = ' ';
	}
}
void iniciarArrString(char arr[][20], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		// Copia a cada indice del arr un espacio vacío
		strcpy(arr[i], " ");
	}
}

// CARGAR
void cargarDatos(int indice[], int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int largoArrs){
	// Carga de datos
	int i;
	for(i = 0; i < largoArrs; i++)
	{
		// Indice
		indice[i] = i;

		// Legajo
		printf("Ingrese el numero de lejago: ");
		fflush(stdin);
		scanf("%d", &legajo[i]);

		// Sexo
		printf("Ingrese el sexo (M / F): ");
		fflush(stdin);
		scanf("%c", &sexo[i]);

		// Edad
		printf("Ingrese la edad: ");
		fflush(stdin);
		scanf("%d", &edad[i]);

		// Nota uno
		printf("Ingrese la primera nota: ");
		fflush(stdin);
		scanf("%f", &primeraNota[i]);

		// Nota dos
		printf("Ingrese la segunda nota: ");
		fflush(stdin);
		scanf("%f", &segundaNota[i]);

		// Promedio
		float promedio;
		promedio = (primeraNota[i] + segundaNota[i]) / 2;
		prmedio[i] = promedio;

		// Nombre
		printf("Ingrese el nombre: ");
		fflush(stdin);
		gets(nombre[i]);

		printf("\n");
	}
}

// MOSTRAR
void mostrarEstudiantes(int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int cantidadEstudiantes)
{
	int i;
	for(i = 0; i < cantidadEstudiantes; i++)
	{
		printf("--- ESTUDIANTE %d ---\n", i+1);
		printf("Legajo: %d\nSexo: %c\nEdad: %d\nNota uno:%.1f\nNota dos: %.1f\nPromedio: %.1f\nNombre: %s\n", legajo[i], sexo[i], edad[i], primeraNota[i], segundaNota[i], prmedio[i], nombre[i]);
		printf("--- TERMINA ---\n\n");
	}
}

// ORDENAR
// ---- Legajo
void ordernarPorLegajo(int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int cantidadEstudiantes)
{
	int i;
	int j;
	for(i = 0; i < cantidadEstudiantes - 1; i++)
	{
		for(j = i + 1; j < cantidadEstudiantes; j++)
		{
			if(legajo[i] > legajo[j])
			{
				// Swap legajo
				swapIntArr(legajo, legajo, i, j);

				// Swap sexo
				swapCharArr(sexo, sexo, i, j);

				// Swap edad
				swapIntArr(edad, edad, i, j);

				// Swap notas y promedio
				swapFloatArr(primeraNota, primeraNota, i, j);
				swapFloatArr(segundaNota, segundaNota, i, j);
				swapFloatArr(prmedio, prmedio, i, j);

				// Swap nombre
				swapStringArr(nombre, nombre, i, j);
			}
		}
	}
}

// --- Apellido
void ordernarPorApellido(int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int cantidadEstudiantes)
{
	int i;
	int j;
	for(i = 0; i < cantidadEstudiantes - 1; i++)
	{
		for(j = i + 1; j < cantidadEstudiantes; j++)
		{
			if(strcmp(nombre[i], nombre[j]) > 0)
			{
				// Swap legajo
				swapIntArr(legajo, legajo, i, j);

				// Swap sexo
				swapCharArr(sexo, sexo, i, j);

				// Swap edad
				swapIntArr(edad, edad, i, j);

				// Swap notas y promedio
				swapFloatArr(primeraNota, primeraNota, i, j);
				swapFloatArr(segundaNota, segundaNota, i, j);
				swapFloatArr(prmedio, prmedio, i, j);

				// Swap nombre
				swapStringArr(nombre, nombre, i, j);
			}
		}
	}
}

// ---- Promedio
void ordernarPorPromedio(int legajo[], char sexo[], int edad[], float primeraNota[], float segundaNota[], float prmedio[], char nombre[][20], int cantidadEstudiantes)
{
	int i;
	int j;
	for(i = 0; i < cantidadEstudiantes - 1; i++)
	{
		for(j = i + 1; j < cantidadEstudiantes; j++)
		{
			if(prmedio[i] < prmedio[j] || (prmedio[i] == prmedio[j] && legajo[i] > legajo[j]))
			{
				// Swap legajo
				swapIntArr(legajo, legajo, i, j);

				// Swap sexo
				swapCharArr(sexo, sexo, i, j);

				// Swap edad
				swapIntArr(edad, edad, i, j);

				// Swap notas y promedio
				swapFloatArr(primeraNota, primeraNota, i, j);
				swapFloatArr(segundaNota, segundaNota, i, j);
				swapFloatArr(prmedio, prmedio, i, j);

				// Swap nombre
				swapStringArr(nombre, nombre, i, j);
			}

			/*else if(prmedio[i] == prmedio[j] && legajo[i] > legajo[j])
			{
				// Swap legajo
				swapIntArr(legajo, legajo, i, j);

				// Swap sexo
				swapCharArr(sexo, sexo, i, j);

				// Swap edad
				swapIntArr(edad, edad, i, j);

				// Swap notas y promedio
				swapFloatArr(primeraNota, primeraNota, i, j);
				swapFloatArr(segundaNota, segundaNota, i, j);

				// Swap nombre
				swapStringArr(nombre, nombre, i, j);

			}*/
		}
	}
}

// SAWAPS
void swapIntArr(int arr1[], int arr2[], int i, int j)
{
	int aux;
	aux = arr1[i];
	arr1[i] = arr2[j];
	arr2[j] = aux;
}
void swapFloatArr(float arr1[], float arr2[], int i, int j)
{
	float aux;
	aux = arr1[i];
	arr1[i] = arr2[j];
	arr2[j] = aux;
}
void swapCharArr(char arr1[], char arr2[], int i, int j)
{
	char aux;
	aux = arr1[i];
	arr1[i] = arr2[j];
	arr2[j] = aux;
}
void swapStringArr(char arr1[][20], char arr2[][20], int i, int j)
{
	char aux[20];
	strcpy(aux, arr1[i]);
	strcpy(arr1[i], arr2[j]);
	strcpy(arr1[j], aux);
}


