#include <stdio.h>
#include <stdlib.h>

void arrVectorial(int lista[], int largo);
void arrVectorialPuntero(int lista[], int largo);
void arrPuntero(int* lista, int largo);
void arrPuntero2(int* lista, int largo);
int main(void) {

	int lista[3] =
	{
			1,
			2,
			3
	};


//	arrVectorial(lista, 3);
//	arrVectorialPuntero(lista, 3);
//	arrPuntero(lista, 3);
	arrPuntero2(lista, 3);
	return EXIT_SUCCESS;
}


void arrVectorial(int lista[], int largo)
{
	for(int i = 0; i < largo; i++)
	{
		printf("Los datos son: %d\n", lista[i]);
	}
}

void arrVectorialPuntero(int lista[], int largo)
{
	for(int i = 0; i < largo; i++)
	{
		printf("Los datos son: %d\n", *(lista + i));
	}
}

void arrPuntero(int* lista, int largo)
{
	for(int i = 0; i < largo; i++)
	{
		lista[i] = i + 2;
		printf("Los datos son: %d\n", lista[i]);
	}
}

void arrPuntero2(int* lista, int largo)
{
	for(int i = 0; i < largo; i++)
	{
		*(lista + i) = i * 10;
		printf("Los datos son: %d\n", *(lista + i));
	}
}
