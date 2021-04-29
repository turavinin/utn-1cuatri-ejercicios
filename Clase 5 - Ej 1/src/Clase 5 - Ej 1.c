/*
ENTREGADO
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int notas[5];
	int suma = 0;
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("Ingrese una nota: ");
		scanf("%d", &notas[i]);
		fflush( stdin );
		suma += notas[i];
	}

	printf("\nLa suma de los numeros es: %d\n", suma);
	printf("Las notas son: ");

	for(i = 0; i < 5; i++)
	{
		printf("%d, ", notas[i]);
	}


	return 0;
}
