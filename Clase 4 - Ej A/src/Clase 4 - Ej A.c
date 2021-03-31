#include <stdio.h>
#include <stdlib.h>

void mostrarMenu();

int main(void) {
	setbuf(stdout, NULL);

	mostrarMenu();


	return EXIT_SUCCESS;
}

void mostrarMenu()
{

	printf("\n 1.Loguearse");
	printf("\n 2.Comprar");
	printf("\n 3.Ver mis compras");
	printf("\n 4.Vender");
	printf("\n 5.Salir");
}
