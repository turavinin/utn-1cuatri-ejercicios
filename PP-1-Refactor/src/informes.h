#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "eRecaudacion.h"

#ifndef INFORMES_H_
#define INFORMES_H_

// PRINTF

/**
 * \brief Funcion general que imprime contribuyentes con todas sus recaudaciones listadas.
 * \param (recaudaArr) eRecaudacion*.
 * \param (contriArr) eContribuyente*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
void imprimirContribuyentes(eRecaudacion* recaudaArr, eContribuyente* contriArr, int largoArr);
/**
 * \brief Imprime los datos del contribuyente.
 * \param (contribuyente) eContribuyente.
 * \return 0 (= true) and -1 (=false)
 **/
void imprimirContribuyente(eContribuyente contribuyente);
/**
 * \brief Pasado el ID del contribuyente, imprime los todas sus recaudaciones.
 * \param (recaudaArr) eRecaudacion*.
 * \param (largoArr) int.
 * \param (idContribuyente) int.
 * \return 0 (= true) and -1 (=false)
 **/
void imprimirRecaudacionesPorContribuyente(eRecaudacion* recaudaArr, int largoArr, int idContribuyente);
/**
 * \brief Imprime los datos de la recaudacion.
 * \param (recaudacion) eRecaudacion.
 * \return 0 (= true) and -1 (=false)
 **/
void printRecaudacion(eRecaudacion recaudacion);
/**
 * \brief Imprime la recaudacion con datos de su contribuyente insertados en la tabla.
 * \param (recaudacion) eRecaudacion.
 * \param (contribuyente) eContribuyente.
 * \return 0 (= true) and -1 (=false)
 **/
void printRecaudacionContri(eRecaudacion recaudacion, eContribuyente contribuyente);
/**
 * \brief Imprime las recaudaciones saldadas de cada contribuyente
 * \param (recaudaArr) eRecaudacion*.
 * \param (contriArr) eContribuyente*.
 * \param (largoArr) int.
 * \return 0 (= true) and -1 (=false)
 **/
void imprimirRecaudacionesSaldadas(eRecaudacion* recaudaArr, eContribuyente* contriArr, int largoArr);
#endif /* INFORMES_H_ */
