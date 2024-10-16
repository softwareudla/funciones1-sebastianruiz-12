#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char productos[MAX_PRODUCTOS][MAX_NOMBRE],float precios[MAX_PRODUCTOS],int numProductos){
    for (int i = 0; i < numProductos; i++){
        printf("Ingrese el nombre del producto %d:",i + 1);
        scanf("%s",productos[i]);
        printf("Ingrese el precio del producto %d:",i + 1);
        scanf("%f", &precios[i]);
    }

    
}

float calcularTotal(float precios[MAX_PRODUCTOS],int numProductos){
    float total = 0;
    for(int i = 0; i< numProductos; i++){
        total+= precios[i];
    }
    return total;
}

void productoMasCaroBarato(char productos[MAX_PRODUCTOS][MAX_NOMBRE],float precios[MAX_PRODUCTOS],int numProductos,char productoCaro[MAX_NOMBRE],char productoBarato[MAX_NOMBRE]){
    int indiceCaro = 0, indiceBarato = 0;
    for(int i = 1; i < numProductos; i++){
        if(precios[i] > precios [indiceCaro]){
            indiceCaro = i;
        }
        if(precios[i] < precios[indiceCaro]){
            indiceBarato = i;
        }
    }
    strcpy(productoCaro, productos[indiceCaro]);
    strcpy(productoBarato, productos[indiceBarato]);
}

float calcularPromedio(float precios[MAX_PRODUCTOS], int numProductos){
    return calcularTotal(precios, numProductos)/ numProductos;
}

float buscarProducto(char productos[MAX_PRODUCTOS][MAX_NOMBRE],float precios[MAX_PRODUCTOS], int numProductos, char nombreProducto[MAX_NOMBRE]){
    for(int i = 0; i < numProductos; i++){
        if (strcmp(productos[i], nombreProducto) == 0) {
            return precios[i];
        }
    }
    return -1;
}


