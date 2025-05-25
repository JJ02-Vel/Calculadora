#include <stdio.h>
#include "declaracionVariables.h"
#include "utilidades.h"

int TotalNetflix = 0;
int TotalSpotify = 0;
int TotalPrestamos = 0;

float servicio(float *ptrSueldo, int *ptrAcuServicio) {
    int opcion = -1;
    int gasto = 0;

    while (opcion != 0) {
        printf("\nSeleccione el servicio que desea pagar:\n");
        printf("1) Netflix\n");
        printf("2) Spotify\n");
        printf("3) Prestamos\n");
        printf("0) Volver al menu principal\n");
        printf("Opcion: "); 
        if (scanf("%d", &opcion) != 1 || opcion < 0 || opcion > 3) {
            printf("Opción no válida. Intente de nuevo.\n");
            while (getchar() != '\n'); // Limpiar el búfer
            continue;
        }

        switch (opcion) {
            case 1:
                printf("Ingrese el monto para Netflix: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n'); // Limpiar el búfer
                    continue;
                }
                TotalNetflix += gasto;
                realizarPago(ptrSueldo, ptrAcuServicio, &TotalServicio, gasto);
                break;
            case 2:
                printf("Ingrese el monto para Spotify: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n'); // Limpiar el búfer
                    continue;
                }
                TotalSpotify += gasto;
                realizarPago(ptrSueldo, ptrAcuServicio, &TotalServicio, gasto);
                break;
            case 3:
                printf("Ingrese el monto para Prestamos: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n'); // Limpiar el búfer
                    continue;
                }
                TotalPrestamos += gasto;
                realizarPago(ptrSueldo, ptrAcuServicio, &TotalServicio, gasto);
                break;
            case 0:
                printf("Volviendo al menu principal...\n");
                return *ptrSueldo;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    }

    return *ptrSueldo;
}