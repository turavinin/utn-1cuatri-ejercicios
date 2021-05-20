#include "eRecaudacion.h"

// PARA ESPACIOS EN PRINTF
int w[MAX_COL] = {20, 20, 20, 20, 20};

// ARRAY MESES
eMeses listaMeses[MAX_ARR_MESES] = {
		{1, "Enero"},
		{2, "Febrero"},
		{3, "Marzo"},
		{4, "Abril"},
		{5, "Mayo"},
		{6, "Junio"},
		{7, "Julio"},
		{8, "Agisto"},
		{9, "Septiembre"},
		{10, "Octubre"},
		{11, "Noviembre"},
		{12, "Diciembre"},
};

// TIPOS
eTipo listaTipos[MAX_ARR_TIPO] = {
		{1, "ARBA"},
		{2, "IIBB"},
		{3, "GANANCIAS"},
};

// ESTADOS
eEstado listaEstados[MAX_ARR_ESTADO] = {
		{1, " "},
		{2, "Refinanciar"},
		{3, "Saldado"}
};

// *** ESTABLECER ID
int idRecaudacion = 100;
void eRecaudacion_EstablecerId(int* id)
{
	*id = idRecaudacion++;
}

// *** INICIAR ARRAY RECAUDACIONES
int iniciarRecaudaciones(eRecaudacion* eArr, int largoArr)
{
	int exitoFuncion = -1;
	eRecaudacion recaudacionVacia;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			eArr[i] = recaudacionVacia;
			eArr[i].isEmpty = 1;
		}
		exitoFuncion = 0;
	}
	return exitoFuncion;
}

// *** BUSQUEDAS / PETICIONES
int eRecaudacion_BuscarLibre(eRecaudacion* eArr, int largoArr, int* lugarLibre)
{
	int exitoFuncion = -1;
	if(eArr != NULL && largoArr > 0)
		{
			int i;
			for(i = 0; i < largoArr; i++)
			{
				if(eArr[i].isEmpty == 1)
				{
					*lugarLibre = i;
					exitoFuncion = 0;
					break;
				}
			}

			if(exitoFuncion == -1)
			{
				*lugarLibre = -1;
			}
		}
	return exitoFuncion;
}
int eRecaudacion_CheckExistencia(eRecaudacion* eArr, int largoArr)
{
	int exitoFuncion = -1;

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].isEmpty == 0)
			{
				exitoFuncion = 0;
				break;
			}
		}
	}

	return exitoFuncion;
}

int eRecaudacion_GetId(eRecaudacion* eArr, int largoArr, int* id, char* mensaje, char* mensajeError, char* mensajeNoEncontrado, int maxErrores)
{
	int exitoFuncion = -1;
	int exitoLocal = -1;
	int auxId;
	if(eArr != NULL && largoArr > 0)
	{
		exitoLocal = utn_getNumber(&auxId, mensaje, mensajeError, maxErrores);

		if(exitoLocal == 0)
		{
			int i;
			for(i = 0; i < largoArr; i++)
			{
				if(eArr[i].id == auxId && eArr[i].isEmpty == 0)
				{
					*id = auxId;
					exitoFuncion = 0;
					exitoLocal = 0;
					break;
				}
				exitoLocal = -1;
			}

			if(exitoLocal == -1)
			{
				printf(mensajeNoEncontrado);
			}
		}
	}
	return exitoFuncion;
}
int eRecaudacion_GetRecaudacionById(eRecaudacion* eArr, int largoArr, int idRecaudacions, int* posicionRecaudacion)
{
	int exitoFuncion = -1;
	int auxPos;

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].id == idRecaudacions)
			{
				auxPos = i;
				*posicionRecaudacion = auxPos;
				exitoFuncion = 0;
				break;
			}
		}
	}


	return exitoFuncion;
}
int eRecaudacion_GetRecaudacionByContri(eRecaudacion* eArr, int largoArr, int idContribuyente, int* posiciones, int* largoPosiciones)
{
	int exitoFuncion = -1;

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		int j = 0;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].idContribuyente == idContribuyente && eArr[i].isEmpty == 0)
			{
				posiciones[j] = i;
				exitoFuncion = 0;
				j++;
			}
		}

		if(posiciones != NULL && j > 0)
		{
			*largoPosiciones = j;
			exitoFuncion = 0;
		}
	}


	return exitoFuncion;
}
// *** AGREGAR RECAUDACION
int eRecaudacion_Agregar(eRecaudacion* eRecaudaArr, int largoArr, int posRecauda, int idRecaudacion, int idContribuyente, int posMes, int posTipo, int posEstado, float importe)
{
	int exitoFuncion = -1;
	if(eRecaudaArr != NULL && largoArr > 0)
	{
		eRecaudaArr[posRecauda].id = idRecaudacion;
		eRecaudaArr[posRecauda].idContribuyente = idContribuyente;
		eRecaudaArr[posRecauda].mes = listaMeses[posMes];
		eRecaudaArr[posRecauda].tipo = listaTipos[posTipo];
		eRecaudaArr[posRecauda].estado = listaEstados[posEstado];
		eRecaudaArr[posRecauda].importe = importe;
		eRecaudaArr[posRecauda].isEmpty = 0;
		exitoFuncion = 0;

	}
	return exitoFuncion;
}
int eRecaudacion_Alta(eRecaudacion* eRecaudaArr, eContribuyente* eContriArr, int largoArr)
{
	int exitoFuncion = -1;
	int exitoLocal = -1;
	int lugarLibre = -1;
	int siguienteLibre = -1;
	char opcionSalir = 'n';
	int idRecaudacion;
	int posicionContribuyente;

	int existeContribuyente = eContribuyente_CheckExistencia(eContriArr, largoArr);

	if(existeContribuyente == 0)
	{
		do
			{
				exitoLocal = eRecaudacion_BuscarLibre(eRecaudaArr, largoArr, &lugarLibre);
				if(exitoLocal == 0)
				{
					exitoLocal = -1;
					// Aux
					int auxIdContribuyente;
					int auxPosicionMes;
					int auxPosicionTipo;
					float auxImporte;

					eContribuyente_PrintTablaContribuyentes(eContriArr, largoArr);

					printf("\n| AGREGAR RECAUDACION ----------------|\n");
					if(eContribuyente_GetId(eContriArr, largoArr, &auxIdContribuyente,
							"| Ingrese el ID del contribuyente: ",
							"| -- Ingreso incorrecto --\n",
							"\n ---- NO SE ENCONTRO AL CONTRIBUYENTE BUSCADO ----", MAX_ERRORES) == 0 &&
							eMeses_GetMes(listaMeses, MAX_ARR_MESES, &auxPosicionMes,
									"\n| INGRESE EL MES (NUMERO) ------------|"
									"\n| 1.Enero                             |"
									"\n| 2.Febrero                           |"
									"\n| 3.Marzo                             |"
									"\n| 4.Abril                             |"
									"\n| 5.Mayo                              |"
									"\n| 6.Junio                             |"
									"\n| 7.Julio                             |"
									"\n| 8.Agosto                            |"
									"\n| 9.Septiembre                        |"
									"\n| 10.Octubre                          |"
									"\n| 11.Noviembre                        |"
									"\n| 12.Diciembre                        |"
									"\n|-------------------------------------|"
									"\n| Selecciones una opcion: ",
									"\n|     ---- OPCION INCORRECTA ----     |\n",
									MAX_ERRORES) == 0 &&
									eTipo_GetTipo(listaTipos, MAX_ARR_TIPO, &auxPosicionTipo,
																"\n| INGRESE EL TIPO (NUMERO) ----------|"
																"\n| 1.ARBA                             |"
																"\n| 2.IIBB                             |"
																"\n| 3.GANANCIAS                        |"
																"\n|------------------------------------|"
																"\n| Selecciones una opcion: ",
																"\n|     ---- OPCION INCORRECTA ----    |\n",
																MAX_ERRORES) == 0 &&
																utn_getFloat(&auxImporte,
																		"| Ingrese importe: ",
																		"| -- Ingreso incorrecto --\n",
																		MAX_ERRORES) == 0)
					{
						eRecaudacion_EstablecerId(&idRecaudacion);
						eContribuyente_GetContribuyenteById(eContriArr, largoArr, auxIdContribuyente, &posicionContribuyente);
						exitoLocal = eRecaudacion_Agregar(eRecaudaArr, largoArr, lugarLibre,
															idRecaudacion, auxIdContribuyente, auxPosicionMes,
															auxPosicionTipo, 0, auxImporte);

						printf("\n|RECAUDACION CREADA:");
						eRecaudacion_PrintRecaudacionCompleta(eRecaudaArr[lugarLibre], eContriArr[posicionContribuyente], 1);
						exitoFuncion = 0;
					}

					if(exitoLocal == 0)
						{
							exitoLocal = eRecaudacion_BuscarLibre(eRecaudaArr, largoArr, &siguienteLibre);
							if(exitoLocal == 0)
							{
								exitoLocal = utn_getCharDosOpciones(&opcionSalir,
										"|¿Desea agregar otra recaudación? (S / N): ",
										"| -- Ingreso incorrecto --\n",
										's', 'n', MAX_ERRORES);
								if(exitoLocal != 0)
								{
									opcionSalir = 'n';
								}
							}
						}
						else
						{
							exitoFuncion = -1;
						}
				}

			}while(opcionSalir != 'n' && exitoLocal == 0);


			if(lugarLibre == -1)
			{
				printf("\n ---- ¡ESPACIO EN LA MEMORIA INSUFICIENTE! ----");
				system("pause");
			}

			if(exitoFuncion != 0)
			{
				printf("\n ---- ¡NO SE PUDO INGRESAR LA RECAUDACION! ----\n");
				system("pause");
			}
	}
	else
	{
		printf("\n ---- ¡NO EXISTEN CONTRIBUYENTES! ----\n");
		system("pause");
	}

	return exitoFuncion;
}

// *** OPERACIONES DE RECAUDACION
int eRecaudacion_Operaciones(eRecaudacion* eRecaudaArr, eContribuyente* eContriArr, int largoArr, int pasajeEstado)
{
	int exitoFuncion = -1;
	int exitoLocal = -1;
	int idRecaudacion;
	int posicionRecaudacion;
	int posicionContribuyente;
	int existeRecaudacion;
	char confirmacion = 'n';

	int existeContribuyente = eContribuyente_CheckExistencia(eContriArr, largoArr);
	if(existeContribuyente == 0)
	{
		existeRecaudacion = eRecaudacion_CheckExistencia(eRecaudaArr, largoArr);
		if(existeRecaudacion == 0)
		{
			if(pasajeEstado == 1)
			{
				eRecaudacion_PrintRecaudaciones(eRecaudaArr, largoArr);
			}else if(pasajeEstado == 2)
			{
				eRecaudacion_PrintRecaudacionNoSaldadas(eRecaudaArr, largoArr);
			}

			exitoLocal = eRecaudacion_GetId(eRecaudaArr, largoArr, &idRecaudacion,
										   "\n| Ingrese el ID de la recaudación: ",
										   "| -- Error.",
										   "\n| ---- NO SE ENCONTRO AL CONTRIBUYENTE BUSCADO ----\n",
										   MAX_ERRORES);
			if(exitoLocal == 0)
			{
				eRecaudacion_GetRecaudacionById(eRecaudaArr, largoArr, idRecaudacion, &posicionRecaudacion);
				eContribuyente_GetContribuyenteById(eContriArr, largoArr, eRecaudaArr[posicionRecaudacion].idContribuyente, &posicionContribuyente);

				printf("\n|CONTRIBUYENTE DE LA RECAUDACION:");
				eContribuyente_PrintContribuyenteBasico(eContriArr[posicionContribuyente], 1);

				exitoLocal = utn_getCharDosOpciones(&confirmacion,
							"|¿Confirma la operación? (S / N): ",
							"| -- Ingreso incorrecto --\n",
							's', 'n', MAX_ERRORES);

				if(confirmacion == 's')
				{
					if(pasajeEstado == 1) // Refinanciar
					{
						eRecaudaArr[posicionRecaudacion].estado = listaEstados[1];
					} else if(pasajeEstado == 2) // Saldar
					{
						eRecaudaArr[posicionRecaudacion].estado = listaEstados[2];
					}

					printf("\n|ESTADO DE RECAUDACION ACTUALIZADO:");
					eRecaudacion_PrintRecaudacionCompleta(eRecaudaArr[posicionRecaudacion], eContriArr[posicionContribuyente], 1);
					exitoFuncion = 0;
					system("pause");
				}
			}
		}
		else
		{
			printf("\n ---- ¡NO HAY RECAUDACIONES CARGADAS! ----\n");
			system("pause");
		}
	}
	else
	{
		printf("\n ---- ¡NO EXISTEN CONTRIBUYENTES! ----\n");
		system("pause");
	}


	return exitoFuncion;
}

// *** ELIMINAR TODOS LOS DATOS
int eRecaudacion_EliminarTodas(eRecaudacion* eRecaudaArr, int* posiciones, int largoPos)
{
	int exitoFuncion = -1;
	if(eRecaudaArr != NULL && posiciones > 0)
	{
		int i;
		for(i = 0; i < largoPos; i++)
		{
			eRecaudaArr[posiciones[i]].isEmpty = 1;
		}
		exitoFuncion = 0;
	}
	return exitoFuncion;
}
int eRecaudacion_Eliminar(eRecaudacion* eRecaudaArr, eContribuyente* eContriArr, int largoRecauda, int largoContri)
{
	int exitoFuncion = -1;
	int idContribuyente;
	int posRecaudacion[largoRecauda];
	int largoPosicionesRecauda;
	int exitoLocal = econtribuyente_Baja(eContriArr, largoContri, &idContribuyente);

	if(exitoLocal == 0)
	{
		eRecaudacion_GetRecaudacionByContri(eRecaudaArr, largoRecauda, idContribuyente, posRecaudacion, &largoPosicionesRecauda); // PUEDE HABER PROBLEMAS EN ESTO
		eRecaudacion_EliminarTodas(eRecaudaArr, posRecaudacion, largoPosicionesRecauda);
	}

	return exitoFuncion;
}

// *** PRINTS
void eRecaudacion_PrintRecaudacionCompleta(eRecaudacion recaudacion, eContribuyente contribuyente, int opcionEncabezado)
{
	char nombreCompletoContribuyente[MAX_CHAR];
	utn_FormatoNombreCompleto(contribuyente.nombre, contribuyente.apellido, nombreCompletoContribuyente);

	if(opcionEncabezado == 1)
	{
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID RECAUDACION", w[1], "CONTRIBUYENTE", w[2],"MES", w[3],"TIPO", w[4], "ESTADO", w[5], "IMPORTE");
	}

	printf("|%-*d|%-*s|%-*s|%-*s|%-*s|%-*.1f|\n", w[0], recaudacion.id,
											      w[1], nombreCompletoContribuyente,
												  w[2], recaudacion.mes.mes,
												  w[3], recaudacion.tipo.tipo,
												  w[4], recaudacion.estado.estado,
												  w[5], recaudacion.importe);
}
void eRecaudacion_PrintRecaudacion(eRecaudacion recaudacion, int opcionEncabezado)
{
	if(opcionEncabezado == 1)
	{
		printf("\n|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID RECAUDACION", w[1],"MES", w[2],"TIPO", w[3],"IMPORTE");
	}

	printf("|%-*d|%-*s|%-*s|%-*.1f|\n", w[0], recaudacion.id,
										w[1], recaudacion.mes.mes,
										w[2], recaudacion.tipo.tipo,
										w[3], recaudacion.importe);
}
void eRecaudacion_PrintRecaudaciones(eRecaudacion* eArr, int largoArr)
{
	printf("\n|RECAUDACIONES: ");
	printf("\n|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID RECAUDACION", w[1],"MES", w[2],"TIPO", w[3],"IMPORTE");
	int i;
	for(i = 0; i < largoArr; i++)
	{
		if(eArr[i].isEmpty == 0)
		{
			eRecaudacion_PrintRecaudacion(eArr[i], 0);
		}
	}
}
void eRecaudacion_PrintRecaudacionNoSaldadas(eRecaudacion* eArr, int largoArr)
{
	printf("\n|RECAUDACIONES: ");
	printf("\n|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID RECAUDACION", w[1],"MES", w[2],"TIPO", w[3],"IMPORTE");
	int i;
	for(i = 0; i < largoArr; i++)
	{
		if(eArr[i].isEmpty == 0 && eArr[i].estado.id != 3)
		{
			eRecaudacion_PrintRecaudacion(eArr[i], 0);
		}
	}
}



