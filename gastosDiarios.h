#include <stdio.h>
#include "declaracionVariables.h"

float diario(float *ptrSueldo, int *ptrAcuDiario) {
    int gasto;
    printf("Ingrese la cantidad de su gasto diario: "); 
    scanf("%d", &gasto);
    
    while (gasto > 0) {
        if (*ptrSueldo >= gasto) {
            *ptrSueldo -= gasto;
            (*ptrAcuDiario)++;
            TotalDiario += gasto;
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
        printf("Ingrese la cantidad de su gasto diario: "); 
        scanf("%d", &gasto);
    }

    return *ptrSueldo; // Devuelve el sueldo restante
}
