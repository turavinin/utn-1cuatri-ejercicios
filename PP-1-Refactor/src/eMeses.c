#include "eMeses.h"

int eMeses_GetMes(eMeses* eArr, int largoArr, int* posicionMes, char* mensaje, char* mensajeError, int maxErrores)
{
	int exitoFuncion = -1;
	int exitoLocal = -1;
	int idMes;
	if(eArr != NULL && largoArr > 0)
	{
		exitoLocal = utn_getNumberLimited(&idMes, mensaje, mensajeError,
				1, 12, maxErrores);

		if(exitoLocal == 0)
		{
			int i;
			for(i = 0; i < largoArr; i++)
			{
				if(eArr[i].id == idMes)
				{
					*posicionMes = i;
					exitoFuncion = 0;
					exitoLocal = 0;
					break;
				}
			}
		}
	}


	return exitoFuncion;
}
