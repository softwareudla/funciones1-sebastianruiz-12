#include <stdio.h>
#include "funciones.h"

int main(){
    char productos[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios [MAX_PRODUCTOS];
    int numProductos;

    do{
        printf("Ingrese el numero de productos(maximo %d):",MAX_PRODUCTOS);
        scanf("%d", &numProductos);
        while(getchar() != '\n');
    } while (numProductos < 1 || numProductos > MAX_PRODUCTOS);
    
    ingresarProductos(productos, precios, numProductos);

    printf("Precio total del inventario: %.2f\n", calcularTotal(precios, numProductos));

    char productoCaro[MAX_NOMBRE], productoBarato[MAX_NOMBRE];
    productoMasCaroBarato(productos, precios, numProductos, productoCaro, productoBarato);
    printf("Producto mas caro: %s\n", productoCaro);
    printf("Producto mas barato: %s\n", productoBarato);

    printf("Precio promedio de los productos: %.2f\n", calcularPromedio(precios, numProductos));

    char nombreProducto[MAX_NOMBRE];
    char continuarBusqueda = 's';
    while (continuarBusqueda == 's' || continuarBusqueda == 's'){
        printf("Ingrese el nombre del producto a buscar:");
        scanf("%s", &nombreProducto);
     
     float precio = buscarProducto(productos, precios, numProductos, nombreProducto);
    if (precio != -1) {
        printf("El precio del producto %s es: %.2f\n", nombreProducto, precio);
    } else {
        printf("Producto no encontrado.\n");
    }

    printf("¿Desea buscar otro producto? (s/n): ");
    scanf(" %c", &continuarBusqueda);

    while (getchar() != '\n');

    }
}
