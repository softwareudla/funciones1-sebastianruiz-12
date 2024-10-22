#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

// Declaraciones de las funciones

void ingresarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int *numProductos);
float calcularTotal(float precios[MAX_PRODUCTOS], int numProductos);
void encontrarExtremos(float precios[MAX_PRODUCTOS], int numProductos, char nombres[MAX_PRODUCTOS][MAX_NOMBRE], 
                       char nombreMasCaro[MAX_NOMBRE], char nombreMasBarato[MAX_NOMBRE]);
float calcularPromedio(float precios[MAX_PRODUCTOS], int numProductos);
int buscarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int numProductos, char buscar);
void mostrarInventario(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos);

#endif