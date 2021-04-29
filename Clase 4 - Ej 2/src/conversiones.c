#include <stdio.h>
#include <stdlib.h>



float convertirTemperatura(int convertidorElegido, float temperatura)
{
	float dataSalida;

	if(convertidorElegido == 1) // Caso C°
	{
		dataSalida = convertirAFahrenheit(temperatura);

		return dataSalida;
	}
	else // Caso F°
	{
		dataSalida = convertirACelsius(temperatura);

		return dataSalida;
	}
}

float convertirAFahrenheit(float temperatura)
{
	float dataSalida = temperatura * 9 / 5 + 32;

	return dataSalida;
}

float convertirACelsius(float temperatura)
{
	float dataSalida = (temperatura - 32) * 5 / 9;

	return dataSalida;
}




