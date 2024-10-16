#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para ingresar los datos de los productos
void ingresarProductos(char productos[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i]);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

// Función para calcular el precio total del inventario
float calcularTotal(float precios[MAX_PRODUCTOS], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

// Función para determinar el producto más caro y el más barato
void productoMasCaroBarato(char productos[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos, char productoCaro[MAX_NOMBRE], char productoBarato[MAX_NOMBRE]) {
    int indiceCaro = 0, indiceBarato = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indiceCaro]) {
            indiceCaro = i;
        }
        if (precios[i] < precios[indiceBarato]) {
            indiceBarato = i;
        }
    }
    strcpy(productoCaro, productos[indiceCaro]);
    strcpy(productoBarato, productos[indiceBarato]);
}

// Función para calcular el precio promedio de los productos
float calcularPromedio(float precios[MAX_PRODUCTOS], int numProductos) {
    return calcularTotal(precios, numProductos) / numProductos;
}

// Función para buscar un producto por su nombre y devolver su precio
float buscarProducto(char productos[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos, char nombreProducto[MAX_NOMBRE]) {
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i], nombreProducto) == 0) {
            return precios[i];
        }
    }
    return -1; // Producto no encontrado
}
