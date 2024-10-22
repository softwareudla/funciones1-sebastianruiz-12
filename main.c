#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int numProductos = 0;
    char nombreMasCaro[MAX_NOMBRE], nombreMasBarato[MAX_NOMBRE];
    char buscar[MAX_NOMBRE];
    int opcion;

    do {
        printf("\n=== SISTEMA DE GESTION DE INVENTARIO ===\n");
        printf("1. Ingresar productos\n");
        printf("2. Mostrar inventario\n");
        printf("3. Calcular total del inventario\n");
        printf("4. Mostrar productos mas caro y mas barato\n");
        printf("5. Calcular precio promedio\n");
        printf("6. Buscar producto\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProductos(nombres, precios, &numProductos);
                break;
            case 2:
                mostrarInventario(nombres, precios, numProductos);
                break;
            case 3:
                printf("\nTotal del inventario: %.2f\n", calcularTotal(precios, numProductos));
                break;
            case 4:
                encontrarExtremos(precios, numProductos, nombres, nombreMasCaro, nombreMasBarato);
                printf("\nProducto mas caro: %s\n", nombreMasCaro);
                printf("Producto mas barato: %s\n", nombreMasBarato);
                break;
            case 5:
                printf("\nPrecio promedio: %.2f\n", calcularPromedio(precios, numProductos));
                break;
            case 6:
                printf("Ingrese el nombre del producto a buscar: ");
                scanf(" %[^\n]", buscar);
                int indice = buscarProducto(nombres, numProductos, buscar);
                if (indice != -1) {
                    printf("Producto encontrado. Precio: %.2f\n", precios[indice]);
                } else {
                    printf("Producto no encontrado.\n");
                }
                break;
            case 7:
                printf("\n¡fin inventario!\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
        }
    } while (opcion != 7);

    return 0;
}