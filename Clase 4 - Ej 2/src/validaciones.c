#include <stdio.h>
#include <stdlib.h>
#include "mensajesConsola.h"
#include "validaciones.h"

int pedirConvertidor(int reintentosMaximos)
{
	mostrarOpciones();

	int dataSalida = validarOpcion("Ingrese opción 1 o 2: ", "Error. No existe esa opción.\n\n", 1, 2, reintentosMaximos);

	return dataSalida;
}

int validarOpcion(char* mensaje, char* mensajeError, int numeroMinimo, int numeroMaximo, int reintentosPermitidos)
{
	int dataSalida;

	while(reintentosPermitidos > 0)
	{
		printf(mensaje);
		if(scanf("%d", &dataSalida) == 1) // Si no ocurre ningun error.
		{
			if(dataSalida >= numeroMinimo && dataSalida <= numeroMaximo) // Validacion de rango
			{
				break;
			}
		}
		fflush(stdin);

		reintentosPermitidos--;
		printf(mensajeError);
	}

	return dataSalida;
}

float pedirTemperatura(int opcionDeConvertidor, int reintentosMaximos)
{
	float dataSalida;

	if(opcionDeConvertidor == 1) // Caso C° a F°
	{
		float minC = 0;
		float maxC = 100;
		dataSalida = validarCelsius("\nIngrese la temperatura en Celsius (entre 0 y 100): ", "Error de ingreso.\n", minC, maxC, reintentosMaximos);

		return dataSalida;
	}
	else // Caso F° a C°
	{
		float minF = 32;
		float maxF = 212;
		dataSalida = validarFahrenheit("\nIngrese la temperatura en Fahrenheit (entre 32 y 212): ", "Error de ingreso.\n", minF, maxF, reintentosMaximos);
		return dataSalida;
	}
}

float validarCelsius(char* mensaje, char* mensajeError, float tempMinima, float tempMaxima, int reintentosPermitidos)
{
	float dataSalida;

	while(reintentosPermitidos > 0)
	{
		printf(mensaje);
		if(scanf("%f", &dataSalida) == 1)
		{
			if(dataSalida >= tempMinima && dataSalida <= tempMaxima)
			{
				break;
			}
		}
		reintentosPermitidos--;
		printf(mensajeError);
	}

	return dataSalida;
}

float validarFahrenheit(char* mensaje, char* mensajeError, float tempMinima, float tempMaxima, int reintentosPermitidos)
{
	float dataSalida;

	while(reintentosPermitidos > 0)
	{
		printf(mensaje);
		if(scanf("%f", &dataSalida) == 1)
		{
			if(dataSalida >= tempMinima && dataSalida <= tempMaxima)
			{
				break;
			}
		}
		reintentosPermitidos--;
		printf(mensajeError);
	}

	return dataSalida;
}
