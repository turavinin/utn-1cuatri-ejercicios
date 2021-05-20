#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "eMeses.h"
#include "eTipo.h"
#include "eEstado.h"
#include "eContribuyente.h"



#ifndef ERECAUDACION_H_
#define ERECAUDACION_H_

// DEFINE
#define MAX_ARR_MESES 12
#define MAX_ARR_TIPO 3
#define MAX_ARR_ESTADO 3
#define MAX_CHAR 100
#define MAX_ERRORES 3
#define MAX_COL 5


// STRUCT
typedef struct
{
	int id;
	int idContribuyente;
	eMeses mes;
	eTipo tipo;
	eEstado estado;
	float importe;
	int isEmpty;
} eRecaudacion;


/**
 * \brief Incrementa en uno el ID de Recaudacion
 * \param (id) int*.
 * \return 0 (= true) and -1 (=false)
 **/
void eRecaudacion_EstablecerId(int* id);
/**
 * \brief Incializa el array de Recaudacion, seteando a cada posición una estructura vacía y seteando el isEmpty en 1
 * \param (eArr) eRecaudacion*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
int iniciarRecaudaciones(eRecaudacion* eArr, int largoArr);
/**
 * \brief Busca un lugar libre en el array de Recaudacion. En caso de exito devuelve por referencia la posición libre.
 * \param (eArr) eRecaudacion*.
 * \param (largoArr) int.
 * \param (lugarLibre) int*.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_BuscarLibre(eRecaudacion* eArr, int largoArr, int* lugarLibre);
/**
 * \brief Chequea si existe alguna posición ocupada en el array de Recaudacion.
 * \param (eArr) eRecaudacion*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_CheckExistencia(eRecaudacion* eArr, int largoArr);
/**
 * \brief Pide al usuario por consola un ID de Recaudacion.
 * \param (eArr) eRecaudacion*.
 * \param (largoArr) int.
 * \param (id) int*.
 * \param (mensaje) char*.
 * \param (mensajeError) char*.
 * \param (mensajeNoEncontrado) char*.
 * \param (maxErrores) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_GetId(eRecaudacion* eArr, int largoArr, int* id, char* mensaje, char* mensajeError, char* mensajeNoEncontrado, int maxErrores);
/**
 * \brief A partir del ID pasado, busca y devuelve la posición del Recaudacion
 * \param (eArr) eRecaudacion*.
 * \param (largoArr) int.
 * \param (idContribuyente) int.
 * \param (posicionRecaudacion) int*.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_GetRecaudacionById(eRecaudacion* eArr, int largoArr, int idRecaudacions, int* posicionRecaudacion);
int eRecaudacion_GetId(eRecaudacion* eArr, int largoArr, int* id, char* mensaje, char* mensajeError, char* mensajeNoEncontrado, int maxErrores);
/**
 * \brief A partir del ID del contribuyente, busca todas las recaudaciones que perteneces a ese contribuyente.
 * \param (eArr) eRecaudacion*.
 * \param (largoArr) int.
 * \param (idContribuyente) int.
 * \param (posiciones) int*.
 * \param (largoPosiciones) int*.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_GetRecaudacionByContri(eRecaudacion* eArr, int largoArr, int idContribuyente, int* posiciones, int* largoPosiciones);
/**
 * \brief Recibe la información de la recaudación a ingresar, y la guarda en una posición del array.
 * \param (eRecaudaArr) eRecaudacion*.
 * \param (largoArr) int.
 * \param (posRecauda) int.
 * \param (idRecaudacion) int.
 * \param (idContribuyente) int.
 * \param (posMes) int.
 * \param (posTipo) int.
 * \param (posEstado) int.
 * \param (importe) importe.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_Agregar(eRecaudacion* eRecaudaArr, int largoArr, int posRecauda, int idRecaudacion, int idContribuyente, int posMes, int posTipo, int posEstado, float importe);
/**
 * \brief Función general de alta de recaudación. Pide por consola la información.
 * \param (eRecaudaArr) eRecaudacion*.
 * \param (eContriArr) eContribuyente*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_Alta(eRecaudacion* eRecaudaArr, eContribuyente* eContriArr, int largoArr);
/**
 * \brief Realiza las operaciones "refinanciar" y "saldar" de una recaudación.
 * \param (eRecaudaArr) eRecaudacion*.
 * \param (eContriArr) eContribuyente*.
 * \param (largoArr) int.
 * \param (pasajeEstado) int. [1]: Refinancias; [2]: Saldar.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_Operaciones(eRecaudacion* eRecaudaArr, eContribuyente* eContriArr, int largoArr, int pasajeEstado);
/**
 * \brief Elimina todas las recaudaciones de las posiciones pasadas.
 * \param (eRecaudaArr) eRecaudacion*.
 * \param (posiciones) int*.
 * \param (largoPos) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_EliminarTodas(eRecaudacion* eRecaudaArr, int* posiciones, int largoPos);
/**
 * \brief Funcion general que elimina contribuyente y todas sus recaudaciones.
 * \param (eRecaudaArr) eRecaudacion*.
 * \param (eContriArr) eContribuyente*.
 * \param (largoRecauda) int.
 * \param (largoContri) int.
 * \return 0 (= true) and -1 (=false)
 **/
int eRecaudacion_Eliminar(eRecaudacion* eRecaudaArr, eContribuyente* eContriArr, int largoRecauda, int largoContri);
/**
 * \brief Print de contribuyente y sus recaudaciones.
 * \param (recaudacion) eRecaudacion.
 * \param (contribuyente) eContribuyente*.
 * \param (opcionEncabezado) int [1]: Con encabezado.
 * \return 0 (= true) and -1 (=false)
 **/
void eRecaudacion_PrintRecaudacionCompleta(eRecaudacion recaudacion, eContribuyente contribuyente, int opcionEncabezado);
/**
 * \brief Imprime recaudacion.
 * \param (recaudacion) eRecaudacion.
 * \param (opcionEncabezado) int [1]: Con encabezado.
 * \return 0 (= true) and -1 (=false)
 **/
void eRecaudacion_PrintRecaudacion(eRecaudacion recaudacion, int opcionEncabezado);
/**
 * \brief Imprime todas las recaudaciones.
 * \param (recaudacion) eRecaudacion.
 * \param (opcionEncabezado) int [1]: Con encabezado.
 * \return 0 (= true) and -1 (=false)
 **/
void eRecaudacion_PrintRecaudaciones(eRecaudacion* eArr, int largoArr);
/**
 * \brief Imprime todas las recaudaciones no saldadas.
 * \param (recaudacion) eRecaudacion.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
void eRecaudacion_PrintRecaudacionNoSaldadas(eRecaudacion* eArr, int largoArr);
#endif /* ERECAUDACION_H_ */
