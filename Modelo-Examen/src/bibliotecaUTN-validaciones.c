#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

// INT
int isNumerical(char* cadena)
{
	int exitoFuncion = 0;

	int i = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				exitoFuncion = -1;
				break;
			}
			i++;
		}
	}

	return exitoFuncion;
}
int getInt(int* pResultado)
{
	int exitoFuncion = -1;
	char buffer[64];
	scanf("%s", buffer);
	if(isNumerical(buffer) == 0)
	{
		*pResultado = atoi(buffer);
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int utn_getNumberLimited(int* pNumero, char* mensaje, char* mensajeError, int numeroMinimo, int numeroMaximo, int reintentosMaximos)
{
	int exitoFuncion = -1;
	int numero;

	while(reintentosMaximos > 0)
	{
		printf(mensaje);
		if(getInt(&numero) == 0)
		{
			if(numero <= numeroMaximo && numero >= numeroMinimo)
			{
				break;
			}
		}
		fflush(stdin);
		reintentosMaximos--;
		printf(mensajeError);
	}

	if(reintentosMaximos > 0)
	{
		exitoFuncion = 0;
		*pNumero = numero;
	}

	return exitoFuncion;
}
int utn_getNumber(int* pNumero, char* mensaje, char* mensajeError, int reintentosMaximos)
{
	int exitoFuncion = -1;
	int numero;

	while(reintentosMaximos > 0)
	{
		printf(mensaje);
		if(getInt(&numero) == 0)
		{
				break;
		}
		fflush(stdin);
		reintentosMaximos--;
		printf(mensajeError);
	}

	if(reintentosMaximos > 0)
	{
		exitoFuncion = 0;
		*pNumero = numero;
	}

	return exitoFuncion;
}

// FLOAT
int isFloating(char* cadena)
{
	int exitoFuncion = 0;
	int i = 0;
	int banderaFloatPoint = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.' || banderaFloatPoint == 1))
			{
				exitoFuncion = -1;
				break;
			}

			if(cadena[i] == '.')
			{
				banderaFloatPoint = 1;
			}

			i++;
		}
	}
	return exitoFuncion;
}
int getFloat(float* pResultado)
{
	int exitoFuncion = -1;
	char buffer[64];
	scanf("%s", buffer);
	if(isFloating(buffer) == 0)
	{
		*pResultado = strtof(buffer, NULL);
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int utn_getFloat(float* pNumero, char* mensaje, char* mensajeError, int reintentosMaximos)
{
	int exitoFuncion = -1;
	float numero;

	while(reintentosMaximos > 0)
	{
		printf(mensaje);
		if(getFloat(&numero) == 0)
		{
				break;
		}
		fflush(stdin);
		reintentosMaximos--;
		printf(mensajeError);
	}

	if(reintentosMaximos > 0)
	{
		exitoFuncion = 0;
		*pNumero = numero;
	}

	return exitoFuncion;
}
int utn_getFloatLimited(float* pNumero, char* mensaje, char* mensajeError, float numeroMin, float numeroMax, int reintentosMax)
{
	int exitoFuncion = -1;
		float numero;

		while(reintentosMax > 0)
		{
			printf(mensaje);
			if(getFloat(&numero) == 0)
			{
				if(numero <= numeroMax && numero >= numeroMin)
				{
					break;
				}
			}
			fflush(stdin);
			reintentosMax--;
			printf(mensajeError);
		}

		if(reintentosMax > 0)
		{
			exitoFuncion = 0;
			*pNumero = numero;
		}

		return exitoFuncion;

	return exitoFuncion;
}

// CHAR
int utn_getCharDosOpciones(char* pChar, char* mensajeConOpciones, char* mensajeError, char opcionUno, char opcionDos, int reintentosMaximos)
{
	int exitoFuncion = -1;
	char letra;
	int errores = 0;
	opcionUno = tolower(opcionUno);
	opcionDos = tolower(opcionDos);

	printf(mensajeConOpciones);
	fflush(stdin);
	scanf("%c", &letra);
	letra = tolower(letra);

	while(letra != opcionUno && letra != opcionDos && errores < reintentosMaximos)
	{
		printf(mensajeError);
		printf(mensajeConOpciones);
		fflush(stdin);
		scanf("%c", &letra);
		letra = tolower(letra);
		errores++;
	}

	if(letra == opcionUno)
	{
		*pChar = opcionUno;
		exitoFuncion = 0;
	}
	else if(letra == opcionDos)
	{
		*pChar = opcionDos;
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int utn_getCharTresOpciones(char* pChar, char* mensajeConOpciones, char* mensajeError, char opcionUno, char opcionDos, char opcionTres, int reintentosMaximos)
{
		int exitoFuncion = -1;
		char letra;
		int errores = 0;
		opcionUno = tolower(opcionUno);
		opcionDos = tolower(opcionDos);
		opcionTres = tolower(opcionTres);

		printf(mensajeConOpciones);
		fflush(stdin);
		scanf("%c", &letra);
		letra = tolower(letra);

		while(letra != opcionUno && letra != opcionDos && letra != opcionTres && errores < reintentosMaximos)
		{
			printf(mensajeError);
			fflush(stdin);
			scanf("%c", &letra);
			letra = tolower(letra);
			errores++;
		}

		if(letra == opcionUno)
		{
			*pChar = opcionUno;
			exitoFuncion = 0;
		}
		else if(letra == opcionDos)
		{
			*pChar = opcionDos;
			exitoFuncion = 0;
		}else if(letra == opcionTres)
		{
			*pChar = opcionTres;
			exitoFuncion = 0;
		}

		return exitoFuncion;
}

// STRING
int esStringAlpha(char* cadena)
{
	int exitoFuncion = -1;
	int largoCadena = strlen(cadena);
	int i;
	if(cadena != NULL && largoCadena > 0)
	{
		exitoFuncion = 0;
		for(i = 0; i < largoCadena; i++)
		{
			if(isalpha(cadena[i]) == 0)
			{
				exitoFuncion = -1;
				break;
			}
		}
	}

	return exitoFuncion;
}
int esStringAlphaCompuesto(char* cadena)
{
	int exitoFuncion = -1;
	int largoCadena = strlen(cadena);
	int i;
	if(cadena != NULL && largoCadena > 0)
	{
		exitoFuncion = 0;
		for(i = 0; i < largoCadena; i++)
		{
			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0)
			{
				exitoFuncion = -1;
				break;
			}
		}
	}

	return exitoFuncion;
}
int utn_getStringLimited(char* pString, char* mensaje, char* mensajeError, int maximosCaracteres, int maximosErrores)
{
	int exitoFuncion = -1;
	int errores = 1;
	char auxString[200];

	printf(mensaje);
	fflush(stdin);
	gets(auxString);

	while((strlen(auxString) > maximosCaracteres || esStringAlpha(auxString) == -1) && errores <= maximosErrores)
	{
		printf(mensajeError);
		printf(mensaje);
		fflush(stdin);
		errores++;
		gets(auxString);
	}

	if(errores <= maximosErrores)
	{
		strcpy(pString, auxString);
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int utn_getStringCompuesto(char* pString, char* msj, char* msjError, int maxChar, int maxErr)
{
	int exito = -1;
	char auxString[200];

	printf(msj);
	fflush(stdin);
	gets(auxString);

	while((strlen(auxString) > maxChar || esStringAlphaCompuesto(auxString) == -1) && maxErr > 0)
		{
			printf(msjError);
			printf(msj);
			fflush(stdin);
			maxErr--;
			gets(auxString);
		}

		if(maxErr > 0)
		{
			strcpy(pString, auxString);
			exito = 0;
		}

		return exito;

	return exito;
}

// MAIL
int isStringMail(char* cadena)
{
	int exitoFuncion = -1;
	int banderaArroba = 0;
	int banderaPunto = 0;
	int largoCadena = strlen(cadena);
	int i;
	if(cadena != NULL && largoCadena > 0)
	{
		//if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.' || banderaFloatPoint == 1))

		printf("\nEntro a if basico.");
		exitoFuncion = 0;
		for(i = 0; i < largoCadena; i++)
		{
			printf("\nCaracter a analizar: %c", cadena[i]);
			if(((isspace(cadena[i]) != 0) ||
			             cadena[i] == '!' || cadena[i] == '#' || cadena[i] == '$' ||
						 cadena[i] == '%' || cadena[i] == '^' || cadena[i] == '&' || cadena[i] == '*' ||
						 cadena[i] == '(' || cadena[i] == ')' || cadena[i] == '-' || cadena[i] == '{' ||
						 cadena[i] == '}' || cadena[i] == '[' || cadena[i] == ']' || cadena[i] == ':' ||
						 cadena[i] == ';' || cadena[i] == '"' || cadena[i] == '\''|| cadena[i] == '<'||
						 cadena[i] == '>' || cadena[i] == '/' || cadena[i] == '?' || cadena[i] == '~' ||
						 cadena[i] == '`') || ((cadena[i] == '.' && banderaPunto == 1) || (cadena[i] == '@' && banderaArroba == 1)))
			{
				printf("\nRechaza caracter: %c", cadena[i]);
				exitoFuncion = -1;
				break;
			} // Termina el if interno

			// Cambia banderas
			if(cadena[i] == '.')
			{
				printf("\nCambia bandera del punto.");
				banderaPunto = 1;
			}

			if(cadena[i] == '@')
			{
				printf("\nCambia bandera del arroba.");
				banderaArroba = 1;
			}

		} // Termina el for

		// Analiza si hubo @ y . (obligatorios en mail)
		if(banderaArroba == 0 || banderaPunto == 0)
		{
			printf("\nNo hay presencia de @ y/o .");
			exitoFuncion = -1;
		}
	}

	return exitoFuncion;
}
int utn_getMailLimited(char* pString, char* mensaje, char* mensajeError, int maximosCaracteres, int reintentosMaximos)
{
	int exitoFuncion = -1;

	int errores = 1;
	char auxString[200];

	printf(mensaje);
	fflush(stdin);
	gets(auxString);
	printf("\nEntra a funcion getLimited.");
	while((strlen(auxString) > maximosCaracteres || isStringMail(auxString) == -1) && errores <= reintentosMaximos)
	{
		printf("\nErrores: %d", errores);
		printf(mensajeError);
		fflush(stdin);
		gets(auxString);
		errores++;
	}

	if(errores <= reintentosMaximos)
	{
		strcpy(pString, auxString);
		exitoFuncion = 0;
	}

	return exitoFuncion;
}

























