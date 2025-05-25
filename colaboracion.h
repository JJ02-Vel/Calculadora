#include <stdio.h>
#include "declaracionVariables.h"

float colaboracion(float *ptrSueldo, int *ptrAcuColaboracion){
    int gasto;
    printf("Ingrese la cantidad de la colaboracion: "); 
    scanf("%d", &gasto);
    
    while (gasto > 0) {
        if (*ptrSueldo >= gasto) {
            *ptrSueldo -= gasto;
            (*ptrAcuColaboracion)++;
            TotalColaboracion += gasto;
            printf("Pago realizado. Sueldo restante: %.2f\n", *ptrSueldo);
        } else {
            printf("Fondos insuficientes para realizar el pago.\n");
            break;
        }
    
        printf("Desea realizar otro pago igual? (1 para si, 0 para no): ");
        int opcion;
        scanf("%d", &opcion);
    
        if (opcion == 0) {
            break;
        }
        printf("Ingrese la cantidad de su colaboracion: "); 
        scanf("%d", &gasto);
    }
    return *ptrSueldo;
}