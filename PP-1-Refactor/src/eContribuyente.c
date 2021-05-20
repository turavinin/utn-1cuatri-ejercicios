#include "eContribuyente.h"

// *** CONFIGURACION PARA PRINTF
int a[MAX_COL] = {15, 15, 15, 15, 15};

// *** ESTABLECER ID
int idContribuyente = 1000;
void eContribuyente_EstablecerId(int* id)
{
	*id = idContribuyente++;
}

// *** INICIAR ARRAY CONTRIBUYENTES
int iniciarContribuyentes(eContribuyente* eArr, int largoArr)
{
	int exitoFuncion = -1;
	eContribuyente contribuyenteVacio;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			eArr[i] = contribuyenteVacio;
			eArr[i].isEmpty = 1;
		}
		exitoFuncion = 0;
	}
	return exitoFuncion;
}

// *** BUSQUEDAS / PETICIONES
int eContribuyente_BuscarLibre(eContribuyente* eArr, int largoArr, int* lugarLibre)
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
int eContribuyente_CheckExistencia(eContribuyente* eArr, int largoArr)
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
int eContribuyente_GetId(eContribuyente* eArr, int largoArr, int* id, char* mensaje, char* mensajeError, char* mensajeNoEncontrado, int maxErrores)
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
int eContribuyente_GetContribuyenteById(eContribuyente* eArr, int largoArr, int idContribuyente, int* posicionContribuyente)
{
	int exitoFuncion = -1;
	int auxPos;

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].id == idContribuyente)
			{
				auxPos = i;
				*posicionContribuyente = auxPos;
				exitoFuncion = 0;
				break;
			}
		}
	}


	return exitoFuncion;
}
int eContribuyente_GetNombreCompletoById(eContribuyente* eArr, int largoArr, int idContribuyente, char* nombreCompleto)
{
	int exitoFuncion = -1;
	char auxString[MAX_CHAR];

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].id == idContribuyente)
			{
				utn_FormatoNombreCompleto(eArr[i].nombre, eArr[i].apellido, auxString);
				strcpy(nombreCompleto, auxString);
				exitoFuncion = 0;
				break;
			}
		}
	}


	return exitoFuncion;
}
// *** AGREGAR CONTRIBUYENTE
int eContribuyente_Agregar(eContribuyente* eArr, int largoArr, int posicion, int id, char* nombre, char* apellido, char* cuil)
{
	int exitoFuncion = -1;
	if(eArr != NULL && largoArr > 0)
	{
		eArr[posicion].id = id;
		strcpy(eArr[posicion].nombre, nombre);
		strcpy(eArr[posicion].apellido, apellido);
		strcpy(eArr[posicion].cuil, cuil);
		eArr[posicion].isEmpty = 0;
		exitoFuncion = 0;
	}
	return exitoFuncion;
}
int eContribuyente_Alta(eContribuyente* eArr, int largoArr)
{
	int exitoFuncion = -1;
	int exitoLocal = -1;
	int lugarLibre = -1;
	int siguienteLibre = -1;
	char opcionSalir = 'n';
	int id;

	do
	{
		exitoLocal = eContribuyente_BuscarLibre(eArr, largoArr, &lugarLibre);
		if(exitoLocal == 0)
		{
			exitoLocal = -1;
			// Variables aux
			char auxNombre[MAX_CHAR];
			char auxApellido[MAX_CHAR];
			char auxCuil[MAX_CHAR];

			printf("\n| AGREGAR CONTRIBUYENTE ------------------------|\n");
			if(utn_getStringLimited(auxNombre,
					"| Ingrese el nombre: ",
					"| -- Ingreso incorrecto --\n",
					MAX_CHAR, MAX_ERRORES) == 0 &&
					utn_getStringLimited(auxApellido,
							"| Ingrese el apellido: ",
							"| -- Ingreso incorrecto --\n",
							MAX_CHAR, MAX_ERRORES) == 0 &&
							utn_getCuil(auxCuil,
									"| Ingrese el cuil: ",
									"| -- Ingreso incorrecto --\n",
									MAX_ERRORES) == 0)
			{
				eContribuyente_EstablecerId(&id);
				exitoLocal = eContribuyente_Agregar(eArr, largoArr, lugarLibre, id, auxNombre, auxApellido, auxCuil);

				printf("\n|CONTRIBUYENTE CREADO:");
				eContribuyente_PrintContribuyenteBasico(eArr[lugarLibre], 1);

				exitoFuncion = 0;
			}

			if(exitoLocal == 0)
			{
				exitoLocal = eContribuyente_BuscarLibre(eArr, largoArr, &siguienteLibre);
				if(exitoLocal == 0)
				{
					exitoLocal = utn_getCharDosOpciones(&opcionSalir,
							"|¿Desea agregar otro contribuyente? (S / N): ",
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
		printf("\n// ¡ESPACIO EN LA MEMORIA INSUFICIENTE!  //");
	}

	if(exitoFuncion != 0)
	{
		printf("\n// ¡NO SE PUDO INGRESAR AL CONTRIBUYENTE!  //\n");
	}


	return exitoFuncion;
}

// *** MODIFICAR CONTRIBUYENTE
int eContribuyente_EditarNombre(eContribuyente* eArr, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxChar, int maxError, int posicion)
{
	int exitoFuncion = -1;
	char nombre[maxChar];
	int exitoLocal = utn_getStringLimited(nombre, mensaje, errorMensaje, maxChar, maxError);

	if(exitoLocal == 0)
	{
		strcpy(eArr[posicion].nombre, nombre);
		exitoFuncion = 0;
	}
	else{
		printf(finalErrorMensaje);
	}

	return exitoFuncion;
}
int eContribuyente_EditarApellido(eContribuyente* eArr, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxChar, int maxError, int posicion)
{
	int exitoFuncion = -1;
	char apellido[maxChar];
	int exitoLocal = utn_getStringLimited(apellido, mensaje, errorMensaje, maxChar, maxError);

	if(exitoLocal == 0)
	{
		strcpy(eArr[posicion].apellido, apellido);
		exitoFuncion = 0;
	}
	else{
		printf(finalErrorMensaje);
	}

	return exitoFuncion;
}
int eContribuyente_EditarCuil(eContribuyente* eArr, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxError, int posicion)
{
	int exitoFuncion = -1;
	char cuil[MAX_CHAR];
	int exitoLocal = utn_getCuil(cuil, mensaje, errorMensaje, maxError);

	if(exitoLocal == 0)
	{
		strcpy(eArr[posicion].cuil, cuil);
		exitoFuncion = 0;
	}
	else{
		printf(finalErrorMensaje);
	}

	return exitoFuncion;
}
int eContribuyente_Modificar(eContribuyente* eArr, int largoArr)
{
	int exitoFuncion = -1;
	int exitoLocal = -1;
	int opcionEditar;
	int posicionContribuyente;
	int idContribuyente;

	exitoLocal = eContribuyente_CheckExistencia(eArr, largoArr);
	if(exitoLocal == 0)
	{
		do
		{
			exitoLocal = utn_getNumberLimited(&opcionEditar,
					"\n| MODIFICAR CONTRIBUYENTE -------------------|"
					"\n| 1.Modificar nombre                         |"
					"\n| 2.Modificar apellido                       |"
					"\n| 3.Modificar cuil                           |"
					"\n| 0.Cancelar                                 |"
					"\n|--------------------------------------------|"
					"\n| Selecciones una opcion: ",
					"\n|          // OPCION INCORRECTA //           |",
					0, 3, MAX_ERRORES);

			if(exitoLocal == 0 && opcionEditar != 0)
			{
				eContribuyente_PrintTablaContribuyentes(eArr, largoArr);
				exitoLocal = eContribuyente_GetId(eArr, largoArr, &idContribuyente,
												  "\n| Ingrese el ID del contribuyente: ",
												  "| -- Error.",
												  "\n\n    // NO SE ENCONTRO AL CONTRIBUYENTE BUSCADO //\n\n", MAX_ERRORES);
				if(exitoLocal == 0)
				{
					eContribuyente_GetContribuyenteById(eArr, largoArr, idContribuyente, &posicionContribuyente);
					switch(opcionEditar)
					{
						case 1:
							eContribuyente_EditarNombre(eArr,
														"| Ingrese el nuevo nombre del contribuyente: ",
														"| -- Error.\n",
														"\n\n    // NO FUE POSIBLE EDITAR EL NOMBRE. INTENE DE NUEVO. //\n\n",
														MAX_CHAR, MAX_ERRORES, posicionContribuyente);
							opcionEditar = 0;
							break;
						case 2:
							eContribuyente_EditarApellido(eArr,
														 "| Ingrese el nuevo apellido del contribuyente: ",
									                     "| -- Error.\n",
														 "\n\n    // NO FUE POSIBLE EDITAR EL APELLIDO. INTENE DE NUEVO. //\n\n",
														 MAX_CHAR, MAX_ERRORES, posicionContribuyente);
							opcionEditar = 0;
							break;
						case 3:
							eContribuyente_EditarCuil(eArr,
														 "| Ingrese el nuevo cuil del contribuyente: ",
														 "| -- Error.\n",
														 "\n\n    // NO FUE POSIBLE EDITAR EL CUIL. INTENE DE NUEVO. //\n\n",
														 MAX_ERRORES, posicionContribuyente);
							opcionEditar = 0;
							break;
					}
				}

			}

		}while(opcionEditar != 0 || exitoLocal != 0);

		if(exitoLocal != 0)
		{
			printf("\n\n    // NO FUE POSIBLE MODIFICAR AL CONTRIBUYENTE //\n\n");
			system("pause");
		}
		else
		{
			exitoFuncion = 0;
			printf("\n| EL CONTRIBUYENTE FUE EDITADO CORRECTAMENTE:");
			eContribuyente_PrintContribuyenteBasico(eArr[posicionContribuyente], 1);
			printf("\n");
			system("pause");
		}

	}
	else
	{
		printf("\n    // NO SE ENCONTRO CONTRIBUYENTE EN LA BASE //\n\n");
		system("pause");
	}

	return exitoFuncion;
}

// *** ELIMINAR
int eContribuyente_EliminarById(eContribuyente* eArr, int largoArr, int idContribuyente)
{
	int exitoFuncion = -1;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].id == idContribuyente && eArr[i].isEmpty == 0)
			{
				eArr[i].isEmpty = 1;
				exitoFuncion = 0;
			}
		}
	}

	return exitoFuncion;
}
int econtribuyente_Baja(eContribuyente* eArr, int largoArr, int* idContribuyente)
{
	int exitoFuncion = -1;
	int exitoLocal = -1;;
	char confirmacion = 'n';
	int auxId;

	if(eArr != NULL && largoArr > 0)
	{
		int existenEmpleados = eContribuyente_CheckExistencia(eArr, largoArr);
		if(existenEmpleados == 0)
		{
			eContribuyente_PrintTablaContribuyentes(eArr, largoArr);
			printf("\n| BAJA DE CONTRIBUYENTE: ");
			exitoLocal = eContribuyente_GetId(eArr, largoArr, &auxId,
					  "\n| Ingrese ID del contribuyente: ",
					  "\n| --Error.",
					  "\n| ---- NO SE ENCONTRO AL CONTRIBUYENTE EN LA BASE ----\n",
					  3);

			if(exitoLocal == 0)
			{
				exitoLocal = utn_getCharDosOpciones(&confirmacion,
											"|¿Confirma la eliminación del contribuyente? (S / N): ",
											"| -- Ingreso incorrecto --\n",
											's', 'n', MAX_ERRORES);
				if(exitoLocal == 0)
				{
					*idContribuyente = auxId;
					eContribuyente_EliminarById(eArr, largoArr, auxId);
					exitoFuncion = 0;
				}
			}
		}
		else
		{
			printf("\n ---- ¡NO EXISTEN CONTRIBUYENTES! ----\n");
		}
	}

	return exitoFuncion;
}
// *** PRINTS
void eContribuyente_PrintContribuyenteBasico(eContribuyente contribuyente, int opcionEncabezado)
{
	if(opcionEncabezado == 1)
	{
		printf("\n|%-*s|%-*s|%-*s|%-*s|\n", a[0],"ID", a[1],"NOMBRE", a[2],"APELLIDO", a[3],"CUIL");
	}
	printf("|%-*d|%-*s|%-*s|%-*s|\n", a[0], contribuyente.id, a[1], contribuyente.nombre, a[2], contribuyente.apellido, a[3], contribuyente.cuil);
}
void eContribuyente_PrintTablaContribuyentes(eContribuyente* eArr, int largoArr)
{
	printf("\n|CONTRIBUYENTES: ");
	printf("\n|%-*s|%-*s|%-*s|%-*s|\n", a[0],"ID", a[1],"NOMBRE", a[2],"APELLIDO", a[3],"CUIL");
	int i;
	for(i = 0; i < largoArr; i++)
	{
		if(eArr[i].isEmpty == 0)
		{
			eContribuyente_PrintContribuyenteBasico(eArr[i], 0);
		}
	}
}

