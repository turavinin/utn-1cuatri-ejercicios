/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int numero);

int main(void) {
	setbuf(stdout, NULL);

	int resultado = factorial(5);
	printf("El resultado factorial es: %d", resultado);

	return EXIT_SUCCESS;
}


int factorial(int numero)
{
	int resultado;

	if(numero == 1)
	{
		return 1;
	}

	resultado = numero * factorial(numero - 1);

	return resultado;

}
