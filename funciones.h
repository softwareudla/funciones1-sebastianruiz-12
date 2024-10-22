#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

// Ahora las funciones retornan valores en lugar de usar punteros
int ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int numActual);
float calcularTotal(float precios[], int numProductos);
void encontrarExtremos(float precios[], int numProductos, char nombres[][MAX_NOMBRE], 
                      char nombreMasCaro[], char nombreMasBarato[]);
float calcularPromedio(float precios[], int numProductos);
int buscarProducto(char nombres[][MAX_NOMBRE], int numProductos, char buscar[]);
void mostrarInventario(char nombres[][MAX_NOMBRE], float precios[], int numProductos);

#endif