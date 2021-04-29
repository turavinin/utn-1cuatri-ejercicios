/*
 ENTREGADO
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
		return numero;
	}

	resultado = numero * factorial(numero - 1);

	return resultado;

}
