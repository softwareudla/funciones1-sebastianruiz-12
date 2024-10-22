#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para ingresar productos
void ingresarProductos(char nombres[10][50], float precios[10], int *numProductos) {
    printf("¿Cuantos productos desea ingresar (max %d)? ", MAX_PRODUCTOS);
    scanf("%d", numProductos);

    if (*numProductos > MAX_PRODUCTOS) {
        *numProductos = MAX_PRODUCTOS;
        printf("Se limitará a %d productos.\n", MAX_PRODUCTOS);
    }

    for (int i = 0; i < *numProductos; i++) {
        printf("\nProducto %d:\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", nombres[i]);
        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
}

// Función para calcular el total de los precios
float calcularTotal(float precios[10], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

// Función para encontrar los productos más caro y más barato
void encontrarExtremos(float precios[10], int numProductos, char nombres[10][50], 
                       char nombreMasCaro[50], char nombreMasBarato[50]) {
    int indexMasCaro = 0, indexMasBarato = 0;

    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indexMasCaro]) {
            indexMasCaro = i;
        }
        if (precios[i] < precios[indexMasBarato]) {
            indexMasBarato = i;
        }
    }

    strcpy(nombreMasCaro, nombres[indexMasCaro]);
    strcpy(nombreMasBarato, nombres[indexMasBarato]);
}

// Función para calcular el promedio de los precios
float calcularPromedio(float precios[10], int numProductos) {
    if (numProductos == 0) return 0;
    return calcularTotal(precios, numProductos) / numProductos;
}

// Función para buscar un producto
int buscarProducto(char nombres[10][50], int numProductos, const char *buscar) {
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            return i;
        }
    }
    return -1;
}

// Función para mostrar el inventario de productos
void mostrarInventario(char nombres[10][50], float precios[10], int numProductos) {
    printf("\nInventario actual:\n");
    printf("%-30s %s\n", "Producto");
