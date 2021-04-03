#include <stdio.h>
#include <stdlib.h>

void mostrarMenu();
void mostrarMenuVenta();
void anunciarCompra();
void anunciarFaltaDeStock();
void mostrarCantidadProductos(int cantidad);
void anunciarVentaDeProducto();

int pedirOpcion();
int validarLogueo(int opcionElegida);


int main(void) {
	setbuf(stdout, NULL);

	int seguir = 0;
	int logueado = 0;

	int opcionElegida;




	// Compra
	int flagCompra = 0;
	int contCompras = 0;

	// Venta
	int flagVenta = 0;

	do {
		mostrarMenu();
		opcionElegida = pedirOpcion();

		if(logueado == 0)
		{
			logueado = validarLogueo(opcionElegida);
		}
		else if(opcionElegida == 2)
		{
			anunciarCompra();
			contCompras++;
		}
		else if(opcionElegida == 3)
		{
			if(contCompras == 0)
			{
				anunciarFaltaDeStock();
			}
			else
			{
				mostrarCantidadProductos(contCompras);
			}
		} else if (opcionElegida == 4)
		{
			if(contCompras == 0)
			{
				anunciarFaltaDeStock();
			}
			else
			{
				do {
					mostrarMenuVenta();


				} while (condition);




				anunciarVentaDeProducto();
				contCompras--;
			}
		} else
		{

		}












	} while (seguir == 0);




	return EXIT_SUCCESS;
}

int validarLogueo(int opcionElegida) {
	int esValido = 0;

	do {
		if (opcionElegida != 1) {
			fflush(stdin);
			printf("\n Debe loguearse antes de entrar en otra opcion.");
			opcionElegida = pedirOpcion();
		} else {
			printf("\n Se logueo! \n");
			esValido = 1;
		}

	} while (esValido == 0);

	return opcionElegida;
}

void mostrarMenu()
{
	printf("\n 1.Loguearse");
	printf("\n 2.Comprar");
	printf("\n 3.Ver mis compras");
	printf("\n 4.Vender");
	printf("\n 5.Salir \n \n ");
}

void mostrarMenuVenta()
{
	printf("\n 1.Vender");
	printf("\n 2.Hacer factura");
	printf("\n 3.Volver atrás");
}

void anunciarCompra()
{
	printf("Compró un producto!\n");
}

void anunciarFaltaDeStock()
{
	printf("No tiene ningun producto.\n")
}

void anunciarVentaDeProducto()
{
	printf("Acaba de vender un producto.\n")
}

void mostrarCantidadProductos(int cantidad)
{
	printf("Usted tiene %d productos.", cantidad);
}

int pedirOpcion()
{
	int opcion;

	fflush(stdin);
	printf("\n Elija la opción: ");
	fflush(stdin);
	scanf("%d", &opcion);

	while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5)
	{
		fflush(stdin);
		printf("Opción incorrecta. Elija la opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
	}

	return opcion;
}
