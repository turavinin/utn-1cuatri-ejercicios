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
#define LARGO_ARR 10

int main(void) {
	setbuf(stdout, NULL);
	int arrEnteros[LARGO_ARR];
	int numero;
	int contPositivos = 0;
	int contNegativos = 0;

	int i;
	for(i = 0; i < LARGO_ARR; i++)
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &numero);
		fflush(stdin);

		arrEnteros[i] = numero;

		if(numero%2 == 0)
		{
			contPositivos++;
		}
		else
		{
			contNegativos++;
		}
	}

	int arrNegativos[contNegativos];
	int arrPositivos[contPositivos];
	for(i = 0; i < LARGO_ARR; i++)
	{
		if(arrEnteros[i]%2 == 0)
		{
			arrPositivos[i] = arrEnteros[i];
		}
		else
		{
			arrNegativos[i] = arrEnteros[i];
		}
	}

	int j;
	for(i = 0; i < contNegativos - 1, i++)
	{
		for(j = 1; j < contNegativos; j++)
		{

		}
	}





}
