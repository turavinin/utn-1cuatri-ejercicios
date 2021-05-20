#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// DIRECCION
typedef struct {
	int IdDireccion;
	char Direccion[20];
	int IsEmpty;
}Direccion;

// PROVEEDOR
typedef struct {
	int IdProveedor;
	char RazonSocial[20];
	Direccion IdDireccion;
	int IsEmpty;
}Proveedor;

// PRODUCTO
typedef struct {
	int IdProducto;
	char Descripcion[20];
	float Precio;
	Proveedor IdProveedor;
	int IsEmpty;
}Producto;


int main(void) {
	return EXIT_SUCCESS;
}
