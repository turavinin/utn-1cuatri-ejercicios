
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mensajesConsola.h"
#include "validaciones.h"
#include "conversiones.h"

// GLOBALES
#define PRIMERA_OPCION 1
#define ULTIMA_OPCION 2
#define MAXREINTENTOS 3

int main(void) {
	setbuf(stdout, NULL);

	mensajeBienvenida();

	// Convertidor elegido
	int convertidorElegido = pedirConvertidor(MAXREINTENTOS);

	// Pedir temperatura
	float temperatura = pedirTemperatura(convertidorElegido, MAXREINTENTOS);

	// Convertir temperatura
	float temperaturaConvertida = convertirTemperatura(convertidorElegido, temperatura);

	// Mostrar temperatura
	mostrarTemperaturaConvertida(convertidorElegido, temperatura, temperaturaConvertida);


	return 0;
}
