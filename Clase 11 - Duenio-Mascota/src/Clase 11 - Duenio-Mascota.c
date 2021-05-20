#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int IdDuenio;
	char Nombre[20];
	int Edad;
	char Sexo;
	int IsEmpty;
} Duenio;

typedef struct{
	char NombreRaza[20];
	int IsEmpty;
} Raza;

typedef struct{
	int IdMascota;
	char nombre[20];
	Raza RazaMascota;
	char Sexo;
	int IdDuenio;
	int IsEmpty;
} Mascota;


/*typedef struct{
	int IdMascota;
	char nombre[20];
	RazaMascota IdRaza;
	char Sexo;
	Duenio IdDuenio;
	int IsEmpty;
} Mascota;*/

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
