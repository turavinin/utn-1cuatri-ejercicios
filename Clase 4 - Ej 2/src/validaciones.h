#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/* brief Pide por consola el convertidor
 * param1 La cantidad máxima de reintentos posibles.
 * */
int pedirConvertidor(int reintentosMaximos);

/* brief Valida la opcion del convertidor
 * param1 Puntero. Mensaje.
 * param2 Puntero. Mensaje de error.
 * param3 Primera opcion.
 * param4 Ultima opcion.
 * param4 La cantidad máxima de reintentos posibles.
 * */
int validarOpcion(char* mensaje, char* mensajeError, int numeroMinimo, int numeroMaximo, int reintentosPermitidos);

/* brief Dependiendo la opcion pide Celsius o Fahrenheit
 * param1 Opcion de convertidor.
 * param2 La cantidad máxima de reintentos posibles.
 * */
float pedirTemperatura(int opcionDeConvertidor, int reintentosPermitidos);

/* brief Valida Celsius
 * param1 Puntero. Mensaje a mostrar por consola
 * param2 Puntero. Mensaje de error.
 * param3 Temperatura mínima a ingresar permitida.
 * param4 Temperatura máxima a ingresar permitida.
 * param4 La cantidad máxima de reintentos posibles.
 * */
float validarCelsius(char* mensaje, char* mensajeError, float tempMinima, float tempMaxima, int reintentosPermitidos);

/* brief Valida Fahrenheit
 * param1 Puntero. Mensaje a mostrar por consola
 * param2 Puntero. Mensaje de error.
 * param3 Temperatura mínima a ingresar permitida.
 * param4 Temperatura máxima a ingresar permitida.
 * param4 La cantidad máxima de reintentos posibles.
 * */
float validarFahrenheit(char* mensaje, char* mensajeError, float tempMinima, float tempMaxima, int reintentosPermitidos);

#endif /* VALIDACIONES_H_ */
