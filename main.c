#include <stdio.h>
#include "funciones.h"

int main() {
    char productos[MAX_PRODUCTOS][MAX_NOMBRE]; // Matriz para almacenar los nombres de los productos
    float precios[MAX_PRODUCTOS];              // Matriz para almacenar los precios de los productos
    int numProductos;

    // Solicitar al usuario el número de productos a ingresar (máximo 10)
    do {
        printf("Ingrese el número de productos (máximo %d): ", MAX_PRODUCTOS);
        scanf("%d", &numProductos);
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    } while (numProductos < 1 || numProductos > MAX_PRODUCTOS);

    // Ingresar los datos de los productos
    ingresarProductos(productos, precios, numProductos);

    // Calcular y mostrar el precio total del inventario
    printf("Precio total del inventario: %.2f\n", calcularTotal(precios, numProductos));

    // Encontrar y mostrar el producto más caro y el más barato
    char productoCaro[MAX_NOMBRE], productoBarato[MAX_NOMBRE];
    productoMasCaroBarato(productos, precios, numProductos, productoCaro, productoBarato);
    printf("Producto más caro: %s\n", productoCaro);
    printf("Producto más barato: %s\n", productoBarato);

    // Calcular y mostrar el precio promedio de los productos
    printf("Precio promedio de los productos: %.2f\n", calcularPromedio(precios, numProductos));

    // Bucle para buscar productos por su nombre hasta que el usuario decida salir
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

    // Preguntar si desea buscar otro producto
    printf("¿Desea buscar otro producto? (s/n): ");
    scanf(" %c", &continuarBusqueda);

    // Limpiar el búfer de entrada
    while (getchar() != '\n');
}
