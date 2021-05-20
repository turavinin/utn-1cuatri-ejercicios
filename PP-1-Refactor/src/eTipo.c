#include "eTipo.h"

int eTipo_GetTipo(eTipo* eArr, int largoArr, int* posicionTipo, char* mensaje, char* mensajeError, int maxErrores)
{
	int exitoFuncion = -1;
	int exitoLocal = -1;
	int idTipo;
	if(eArr != NULL && largoArr > 0)
	{
		exitoLocal = utn_getNumberLimited(&idTipo, mensaje, mensajeError,
				1, 3, maxErrores);

		if(exitoLocal == 0)
		{
			int i;
			for(i = 0; i < largoArr; i++)
			{
				if(eArr[i].id == idTipo)
				{
					*posicionTipo = i;
					exitoFuncion = 0;
					exitoLocal = 0;
					break;
				}
			}
		}
	}


	return exitoFuncion;
}
