#include <stdio.h>
#include <stdlib.h>

void mensajeBienvenida(void)
{
	printf("¡Bienvenido/a al convertidor de temperatura! \n");
}
void mostrarOpciones(void)
{
	printf("\nConvertidor Celsius a Fahrenheit (1).\n"
			"Convertidor de Fahrenheit a Celsius (2).\n");
}
void mostrarTemperaturaConvertida(int opcionElegida, float temperaturaOriginal, float temperaturaConvertida)
{
	if(opcionElegida == 1) // Caso C°
	{
		printf("%.1f°C equivale a %.1f°F", temperaturaOriginal, temperaturaConvertida);
	}
	else // Caso F°
	{
		printf("%.1f°F equivale a %.1f°C", temperaturaOriginal, temperaturaConvertida);
	}
}
