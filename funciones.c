#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int *numProductos) {
    printf("¿Cuantos productos desea ingresar (max %d)? ", MAX_PRODUCTOS);
    scanf("%d", numProductos);
    
    if (*numProductos > MAX_PRODUCTOS) {
        *numProductos = MAX_PRODUCTOS;
        printf("Se limitara a %d productos.\n", MAX_PRODUCTOS);
    }
    
    for (int i = 0; i < *numProductos; i++) {
        printf("\nProducto %d:\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", nombres[i]);
        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
}

float calcularTotal(float precios[], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

void encontrarExtremos(float precios[], int numProductos, char nombres[][MAX_NOMBRE], 
                char *nombreMasCaro, char *nombreMasBarato) {
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

float calcularPromedio(float precios[], int numProductos) {
    if (numProductos == 0) return 0;
    return calcularTotal(precios, numProductos) / numProductos;
}

int buscarProducto(char nombres[][MAX_NOMBRE], int numProductos, const char *buscar) {
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrarInventario(char nombres[][MAX_NOMBRE], float precios[], int numProductos) {
    printf("\nInventario actual:\n");
    printf("%-30s %s\n", "Producto", "Precio");
    printf("----------------------------------------\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%-30s %.2f\n", nombres[i], precios[i]);
    }
} FUNCIONES.C