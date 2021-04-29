#ifndef CONVERSIONES_H_
#define CONVERSIONES_H_

/* brief Convierte temperatura
 * param1 Convertidor elegido por el usuario.
 * param2 Temperatura a convertir
 * */
float convertirTemperatura(int convertidorElegido, float temperatura);

/* brief Convierte Celsius a Fahrenheit
 * param1 Temperatura a convertir
 * */
float convertirAFahrenheit(float temperatura);

/* brief Convierte Fahrenheit a Celsius.
 * param1 Temperatura a convertir
 * */
float convertirACelsius(float temperatura);

#endif /* CONVERSIONES_H_ */
