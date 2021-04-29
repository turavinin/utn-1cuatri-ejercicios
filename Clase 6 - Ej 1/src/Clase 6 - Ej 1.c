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
int swapInt(int* numeroUno, int* numeroDos);

int main(void) {
	int a = 2;
	int b = 10;

	swapInt(&a, &b);

	printf("a = %d, b = %d", a, b);

}

int swapInt(int* a, int* b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;

	return 0;
}
