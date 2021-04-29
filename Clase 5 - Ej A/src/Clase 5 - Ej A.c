/*
ENTREGADO
 */

#include <stdio.h>
#include <stdlib.h>
#define LARGOARR 4

int main(void) {
	setbuf(stdout, NULL);

	int arrLegajo[LARGOARR];
	int arrEdad[LARGOARR];
	float arrSueldo[LARGOARR];

	float sueldo;
	float totalSueldos = 0;
	float promedio;


	int i;
	for(i = 0; i < LARGOARR; i++)
	{
		printf("Ingrese la edad del empleado: ");
		scanf("%d", &arrEdad[i]);
		fflush( stdin );

		printf("Ingrese el sueldo del empleado: ");
		scanf("%f", &sueldo);
		fflush( stdin );

		arrSueldo[i] = sueldo;
		arrLegajo[i] = i;

		totalSueldos += sueldo;

		printf("\n");
	}

	printf("Los datos de los empleados son: \n");

	for(i = 0; i < LARGOARR; i++)
	{
		printf("%d° Empleado. Edad: %d, Sueldo: %f, Legajo: %i.\n", i+1, arrEdad[i], arrSueldo[i], arrLegajo[i]);
	}

	promedio = totalSueldos / LARGOARR;
	printf("El promedio de sueldos es %f", promedio);


	return 0;
}
