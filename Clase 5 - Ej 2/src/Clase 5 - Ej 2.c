/*

 */

#include <stdio.h>
#include <stdlib.h>
#define LARGO_ARR 4

int main(void) {
	setbuf(stdout, NULL);

	int arrNumeros[LARGO_ARR];
	int arrPares[LARGO_ARR];
	int arrImpares[LARGO_ARR];
	int numeroIngresado;
	int contPositivos = 0;
	int contNegativos = 0;
	int sumaPares = 0;

	int i;
	for(i = 0; i < LARGO_ARR; i++)
	{
		printf("Ingrese un numero entre -1000 y 1000: ");
		scanf("%d", &numeroIngresado);
		fflush( stdin );

		while(numeroIngresado < -1000 || numeroIngresado > 1000)
		{
			printf("Error. Ingrese un numero entre -1000 y 1000: ");
			scanf("%d", &numeroIngresado);
			fflush( stdin );
		}

		if(numeroIngresado > 0)
		{
			contPositivos++;
		}
		else if(numeroIngresado < 0)
		{
			contNegativos++;
		}

		if(numeroIngresado%2 == 0)
		{

		}


	}


	return 0;
}
