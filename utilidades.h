#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>

// Función genérica para realizar pagos
void realizarPago(float *ptrSueldo, int *ptrAcumulador, int *ptrTotal, int monto) {
    if (*ptrSueldo >= monto) {
        *ptrSueldo -= monto;
        (*ptrAcumulador)++;
        *ptrTotal += monto;
        printf("Pago realizado. Sueldo restante: %.2f\n", *ptrSueldo);
    } else {
        printf("Fondos insuficientes para realizar el pago.\n");
    }
}

#endif