#ifndef MENSAJESCONSOLA_H_
#define MENSAJESCONSOLA_H_

/* brief Muestra mensaje de bienvenida a consola.
 * */
void mensajeBienvenida(void);

/* brief Muestra mensaje las opciones de conversión en consola.
 * */
void mostrarOpciones(void);

/* brief Muestra la temperatura original y la temperatura equivalente en el otro tipo de escala.
 * param1 Recibe la opcion elegida del menu de opciones.
 * param2 Recibe la temperatura original.
 * param3 Recibe la temperatura convertida al otro tipo de escala.
 * */
void mostrarTemperaturaConvertida(int opcionElegida, float temperaturaOriginal, float temperaturaConvertida);

#endif /* MENSAJESCONSOLA_H_ */
