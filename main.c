#include <stdio.h>
#include "funciones.h"

int main() {
    char productos[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int numProductos;

    // Solicitar al usuario el número de productos a ingresar (máximo 10)
    do {
        printf("Ingrese el número de productos (máximo %d): ", MAX_PRODUCTOS);
        scanf("%d", &numProductos);
        while(getchar() != '\n'); // Limpiar el búfer de entrada
    } while (numProductos < 1 || numProductos > MAX_PRODUCTOS);

    ingresarProductos(productos, precios, numProductos);

    // Calcular y mostrar el precio total del inventario
    printf("Precio total del inventario: %.2f\n", calcularTotal(precios, numProductos));

    char productoCaro[MAX_NOMBRE], productoBarato[MAX_NOMBRE];
    productoMasCaroBarato(productos, precios, numProductos, productoCaro, productoBarato);
    printf("Producto más caro: %s\n", productoCaro);
    printf("Producto más barato: %s\n", productoBarato);

    printf("Precio promedio de los productos: %.2f\n", calcularPromedio(precios, numProductos));

    char nombreProducto[MAX_NOMBRE];
    char continuarBusqueda = 's';
    while (continuarBusqueda == 's' || continuarBusqueda == 'S') {
        printf("Ingrese el nombre del producto a buscar: ");
        scanf("%s", nombreProducto);
     
        float precio = buscarProducto(productos, precios, numProductos, nombreProducto);
        if (precio != -1) {
            printf("El precio del producto %s es: %.2f\n", nombreProducto, precio);
        } else {
            printf("Producto no encontrado.\n");
        }

        printf("¿Desea buscar otro producto? (s/n): ");
        scanf(" %c", &continuarBusqueda);
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    }

    return 0;
}