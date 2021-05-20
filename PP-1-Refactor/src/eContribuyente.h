#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"

#ifndef ECONTRIBUYENTE_H_
#define ECONTRIBUYENTE_H_

// DEFINE
#define MAX_CHAR 100
#define MAX_ERRORES 3
#define MAX_COL 5

// STRUCT
typedef struct
{
	int id;
	char nombre[MAX_CHAR];
	char apellido[MAX_CHAR];
	char cuil[MAX_CHAR];
	int isEmpty;
} eContribuyente;


/**
 * \brief Incrementa en uno el ID del Contribuyente
 * \param (id) int*.
 * \return 0 (= true) and -1 (=false)
 **/
void eContribuyente_EstablecerId(int* id);
/**
 * \brief Incializa el array de Contribuyente, seteando a cada posición una estructura vacía y seteando el isEmpty en 1
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
int iniciarContribuyentes(eContribuyente* eArr, int largoArr);
/**
 * \brief Busca un lugar libre en el array de contribuyentes. En caso de exito devuelve por referencia la posición libre.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \param (lugarLibre) int*.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_BuscarLibre(eContribuyente* eArr, int largoArr, int* lugarLibre);
/**
 * \brief Chequea si existe alguna posición ocupada en el array de contribuyentes.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_CheckExistencia(eContribuyente* eArr, int largoArr);
/**
 * \brief Pide al usuario por consola un ID de contribuyente.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \param (id) int*.
 * \param (mensaje) char*.
 * \param (mensajeError) char*.
 * \param (mensajeNoEncontrado) char*.
 * \param (maxErrores) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_GetId(eContribuyente* eArr, int largoArr, int* id, char* mensaje, char* mensajeError, char* mensajeNoEncontrado, int maxErrores);
/**
 * \brief A partir del ID pasado, busca y devuelve la posición del contribuyente
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \param (idContribuyente) int.
 * \param (posicionContribuyente) int*.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_GetContribuyenteById(eContribuyente* eArr, int largoArr, int idContribuyente, int* posicionContribuyente);
/**
 * \brief A partir del ID pasado, busca y formate el nombre y el apellido del contribuyente en una sola variable.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \param (idContribuyente) int.
 * \param (nombreCompleto) char*.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_GetNombreCompletoById(eContribuyente* eArr, int largoArr, int idContribuyente, char* nombreCompleto);
/**
 * \brief Agrega los datos pasados y la posición del array.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \param (posicion) int.
 * \param (id) int.
 * \param (nombre) char*.
 * \param (apellido) char*.
 * \param (cuil) char*.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_Agregar(eContribuyente* eArr, int largoArr, int posicion, int id, char* nombre, char* apellido, char* cuil);
/**
 * \brief Funcion general de alta de contribuyente. Pide por consola los datos y los guarda en una posición libre del array.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_Alta(eContribuyente* eArr, int largoArr);
/**
 * \brief Pide el nombre por consola y edita el nombre del contribuyente de la posición pasada.
 * \param (eArr) eContribuyente*.
 * \param (mensaje) char*.
 * \param (errorMensaje) char*.
 * \param (finalErrorMensaje) char*.
 * \param (maxChar) int.
 * \param (maxError) int.
 * \param (posicion) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_EditarNombre(eContribuyente* eArr, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxChar, int maxError, int posicion);
/**
 * \brief Pide el apellido por consola y edita el nombre del contribuyente de la posición pasada.
 * \param (eArr) eContribuyente*.
 * \param (mensaje) char*.
 * \param (errorMensaje) char*.
 * \param (finalErrorMensaje) char*.
 * \param (maxChar) int.
 * \param (maxError) int.
 * \param (posicion) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_EditarApellido(eContribuyente* eArr, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxChar, int maxError, int posicion);
/**
 * \brief Pide el cuil por consola y edita el nombre del contribuyente de la posición pasada.
 * \param (eArr) eContribuyente*.
 * \param (mensaje) char*.
 * \param (errorMensaje) char*.
 * \param (finalErrorMensaje) char*.
 * \param (maxChar) int.
 * \param (maxError) int.
 * \param (posicion) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_EditarCuil(eContribuyente* eArr, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxError, int posicion);
/**
 * \brief Función general para modificar los datos del contribuyente.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_Modificar(eContribuyente* eArr, int largoArr);
/**
 * \brief Función que cambia la propiedad "isEmpty" en 1 del contribuyente con el ID pasado.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \param (idContribuyente) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eContribuyente_EliminarById(eContribuyente* eArr, int largoArr, int idContribuyente);
/**
 * \brief Función general que pide por consola el ID del contribuyente y lo elimina.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \param (idContribuyente) int*.
 * \return 0 (= true) and -1 (=false)
 **/
int econtribuyente_Baja(eContribuyente* eArr, int largoArr, int* idContribuyente);

/**
 * \brief Imprime en pantalla la información de un contribuyente.
 * \param (contribuyente) eContribuyente.
 * \param (opcionEncabezado) int: [1]: Imprime con encabezado; [2]: Imprime sin encabezado
 * \return 0 (= true) and -1 (=false)
 **/
void eContribuyente_PrintContribuyenteBasico(eContribuyente contribuyente, int opcionEncabezado);
/**
 * \brief Imprime en pantalla a todos los contribuyentes.
 * \param (eArr) eContribuyente*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
void eContribuyente_PrintTablaContribuyentes(eContribuyente* eArr, int largoArr);
#endif /* ECONTRIBUYENTE_H_ */
