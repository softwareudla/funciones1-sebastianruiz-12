#ifndef INVENTARIO_H
#define INVENTARIO_H

// Constantes para definir las dimensiones de los arreglos
#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

// Declaración de funciones para gestionar el inventario
void ingresarProductos(char productos[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos);
float calcularTotal(float precios[MAX_PRODUCTOS], int numProductos);
void productoMasCaroBarato(char productos[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos, char productoCaro[MAX_NOMBRE], char productoBarato[MAX_NOMBRE]);
float calcularPromedio(float precios[MAX_PRODUCTOS], int numProductos);
float buscarProducto(char productos[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos, char nombreProducto[MAX_NOMBRE]);

#endif
