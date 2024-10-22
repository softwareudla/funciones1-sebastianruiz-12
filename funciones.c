#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int numActual) {
    int cantidadNueva;
    printf("¿Cuantos productos desea ingresar (max %d)? ", MAX_PRODUCTOS - numActual);
    scanf("%d", &cantidadNueva);
    
    if (cantidadNueva > MAX_PRODUCTOS - numActual) {
        cantidadNueva = MAX_PRODUCTOS - numActual;
        printf("Se limitara a %d productos.\n", cantidadNueva);
    }
    
    for (int i = numActual; i < numActual + cantidadNueva; i++) {
        printf("\nProducto %d:\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", nombres[i]);
        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
    
    return numActual + cantidadNueva;
}

float calcularTotal(float precios[], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

void encontrarExtremos(float precios[], int numProductos, char nombres[][MAX_NOMBRE], 
                      char nombreMasCaro[], char nombreMasBarato[]) {
    int indexMasCaro = 0, indexMasBarato = 0;
    
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indexMasCaro]) {
            indexMasCaro = i;
        }
        if (precios[i] < precios[indexMasBarato]) {
            indexMasBarato = i;
        }
    }
    
   
    int i;
    for (i = 0; nombres[indexMasCaro][i] != '\0'; i++) {
        nombreMasCaro[i] = nombres[indexMasCaro][i];
    }
    nombreMasCaro[i] = '\0';
    
    for (i = 0; nombres[indexMasBarato][i] != '\0'; i++) {
        nombreMasBarato[i] = nombres[indexMasBarato][i];
    }
    nombreMasBarato[i] = '\0';
}

float calcularPromedio(float precios[], int numProductos) {
    if (numProductos == 0) return 0;
    return calcularTotal(precios, numProductos) / numProductos;
}

int buscarProducto(char nombres[][MAX_NOMBRE], int numProductos, char buscar[]) {
    for (int i = 0; i < numProductos; i++) {
        int j;
        int iguales = 1;
        for (j = 0; nombres[i][j] != '\0' && buscar[j] != '\0'; j++) {
            if (nombres[i][j] != buscar[j]) {
                iguales = 0;
                break;
            }
        }
        if (iguales && nombres[i][j] == '\0' && buscar[j] == '\0') {
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
}


