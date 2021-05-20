#include "informes.h"
int b[7] = {15, 15, 15, 15, 15, 15, 15};
void imprimirContribuyentes(eRecaudacion* recaudaArr, eContribuyente* contriArr, int largoArr)
{
	int exitoLocal = -1;
	int i;
	exitoLocal = eContribuyente_CheckExistencia(contriArr, largoArr);
	if(exitoLocal == 0)
	{
		exitoLocal = eRecaudacion_CheckExistencia(recaudaArr, largoArr);
		if(exitoLocal == 0)
		{
			for(i = 0; i < largoArr; i++)
			{
				printf("\n---------------------------------------------------------------------------------\n");
				printf("|CONTRIBUYENTE: ");
				imprimirContribuyente(contriArr[i]);
				printf("\n|");
				printf("\n|RECAUDACIONES: ");
				printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|\n", b[0],"ID RECAUDACION", b[1],"MES", b[2],"TIPO", b[3], "ESTADO", b[4], "IMPORTE");
				imprimirRecaudacionesPorContribuyente(recaudaArr, largoArr, contriArr[i].id);
			}
			system("pause");
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

}

void imprimirContribuyente(eContribuyente contribuyente)
{
	printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|", b[0],"ID", b[1],"NOMBRE", b[2],"APELLIDO", b[3],"CUIL", b[4],"");
	printf("\n|%-*d|%-*s|%-*s|%-*s|%-*s|", b[0], contribuyente.id,
											 b[1], contribuyente.nombre,
											 b[2], contribuyente.apellido,
											 b[3], contribuyente.cuil,
											 b[4], "");
}
void imprimirRecaudacionesPorContribuyente(eRecaudacion* recaudaArr, int largoArr, int idContribuyente)
{
	int i;
	for(i = 0; i < largoArr; i++)
	{
		if(recaudaArr[i].idContribuyente == idContribuyente)
		{
			printRecaudacion(recaudaArr[i]);
		}
	}
}

void printRecaudacion(eRecaudacion recaudacion)
{
	printf("|%-*d|%-*s|%-*s|%-*s|%-*.1f|\n",
			b[0], recaudacion.id,
			b[1], recaudacion.mes.mes,
			b[2], recaudacion.tipo.tipo,
			b[3], recaudacion.estado.estado,
			b[4], recaudacion.importe);
}

void printRecaudacionContri(eRecaudacion recaudacion, eContribuyente contribuyente)
{
	char nombreCompleto[MAX_CHAR];
    utn_FormatoNombreCompleto(contribuyente.nombre, contribuyente.apellido, nombreCompleto);

    printf("|%-*d|%-*s|%-*s|%-*s|%-*s|%-*s|%-*.1f|\n",
			b[0], recaudacion.id,
			b[1], nombreCompleto,
			b[2], contribuyente.cuil,
			b[3], recaudacion.mes.mes,
			b[4], recaudacion.tipo.tipo,
			b[5], recaudacion.estado.estado,
			b[6], recaudacion.importe);
}

void imprimirRecaudacionesSaldadas(eRecaudacion* recaudaArr, eContribuyente* contriArr, int largoArr)
{
	int exitoLocal = -1;
	int i;
	int posicionContribuyente;
	exitoLocal = eContribuyente_CheckExistencia(contriArr, largoArr);
	if(exitoLocal == 0)
	{
		exitoLocal = eRecaudacion_CheckExistencia(recaudaArr, largoArr);
		if(exitoLocal == 0)
		{
			printf("\n-----------------------------------------------------------------------------------------------------------------\n");
			printf("|RECAUDACIONES SALDADAS: ");
			for(i = 0; i < largoArr; i++)
			{
				if(recaudaArr[i].estado.id == 3 )
				{
					eContribuyente_GetContribuyenteById(contriArr, largoArr, recaudaArr[i].idContribuyente, &posicionContribuyente);
					printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|%-*s|%-*s|\n",
							b[0],"ID RECAUDACION", b[1],"CONTRIBUYENTE", b[2],"CUIL", b[3],"MES", b[4], "TIPO", b[5], "ESTADO", b[5], "IMPORTE");
					printRecaudacionContri(recaudaArr[i], contriArr[posicionContribuyente]);

				}
			}
			system("pause");
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

}


