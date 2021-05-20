#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int IdLocalidad;
	char Descripcion[50];
	int CodigoPostal;
	int IsEmpty;
} Localidad;

typedef struct{
	int IdAlumno;
	char Nombre[20];
	int IdLocalidad;
	int IsEmpty;
} Alumno;

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
