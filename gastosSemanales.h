#include <stdio.h>
#include "declaracionVariables.h"
#include "utilidades.h"

float semana(float *ptrSueldo, int *ptrAcuSemana) {
    int opcion = -1;
    int gasto = 0;

    while (opcion != 0) {
        printf("\nSeleccione el gasto semanal que desea pagar:\n");
        printf("1) Mercado\n");
        printf("2) Transporte\n");
        printf("3) Almuerzo\n");
        printf("0) Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1 || opcion < 0 || opcion > 3) {
            printf("Opcion no valida. Intente de nuevo.\n");
            while (getchar() != '\n'); // Limpiar el búfer
            continue;
        }

        switch (opcion) {
            case 1:
                printf("Ingrese el monto para Mercado: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n');
                    continue;
                }
                realizarPago(ptrSueldo, ptrAcuSemana, &TotalSemana, gasto);
                break;
            case 2:
                printf("Ingrese el monto para Transporte: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n');
                    continue;
                }
                realizarPago(ptrSueldo, ptrAcuSemana, &TotalSemana, gasto);
                break;
            case 3:
                printf("Ingrese el monto para Almuerzo: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n');
                    continue;
                }
                realizarPago(ptrSueldo, ptrAcuSemana, &TotalSemana, gasto);
                break;
            case 0:
                printf("Volviendo al menú principal...\n");
                return *ptrSueldo;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    }

    return *ptrSueldo;
}