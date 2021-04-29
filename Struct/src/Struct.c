#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct direccion{ // Tiene que estar definido antes que almuno
	char calle[20];
	int numero;
};

struct alumno{
	char nombre[20];
	char apellido[20];
	char apodo[20];
	int edad;
	float primeraNota;
	float segundaNota;
	float promedio;
	struct direccion domicilio;
};

int main(void) {

	struct alumno listaAlumnos[3];

	// Inicializa alumnoUno
	struct alumno alumnoUno;
		// Pone nombre
		strcpy(alumnoUno.nombre, "Pepe");

		//Pide apellido
		printf("Ingrese el apellido: ");
		gets(alumnoUno.nombre);

		// Pone edad
		alumnoUno.edad = 28;

		// Pide notas
		printf("Ingrese primera nota: %d");
		scanf("%d", &alumnoUno.primeraNota);
		scanf("%f", &listaAlumnos[0].segundaNota);

		// Calcula promedio
		alumnoUno.promedio = (alumnoUno.primeraNota + alumnoUno.segundaNota) / 2;

		// Anidado
		strcpy(alumnoUno.domicilio.calle, "Av.Rivadavia");



	// Asigna en array
	listaAlumnos[0] = alumnoUno;
	listaAlumnos[0].domicilio.numero = 2020;
	strcpy(listaAlumnos[0].apodo, "Maquinola");

	printf("El promedio es: %.1f", listaAlumnos[0].promedio);



}
