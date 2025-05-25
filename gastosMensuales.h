#include <stdio.h>
#include "declaracionVariables.h"
#include "utilidades.h"

int TotalWiFi = 0;
int TotalLuz = 0;
int TotalAgua = 0;
int TotalUniversidad = 0;

float mensualidad(float *ptrSueldo, int *ptrAcuMensualidad) {
    int opcion = -1;
    int gasto = 0;                                                                                        


    while (opcion != 0) {
        printf("\nSeleccione el gasto mensual que desea pagar:\n");
        printf("1) Pago de WiFi\n");
        printf("2) Pago de electriciddad\n");
        printf("3) Pago de servicio de agua\n");  
        printf("4) Pago de universidad\n");
        printf("0) Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1 || opcion < 0 || opcion > 4) {
            printf("Opcion no valida. Intente de nuevo.\n");
            while (getchar() != '\n'); // Limpiar el búfer
            continue;
        }

        switch (opcion) {
            case 1:
                printf("Ingrese el monto para WiFi: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n'); // Limpiar el búfer
                    continue;
                }
                TotalWiFi += gasto;
                realizarPago(ptrSueldo, ptrAcuMensualidad, &TotalMensualidad, gasto);
                break;
            case 2:
                printf("Ingrese el monto para la electricidad: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n'); // Limpiar el búfer
                    continue;
                }
                TotalLuz += gasto;
                realizarPago(ptrSueldo, ptrAcuMensualidad, &TotalMensualidad, gasto);
                break;
            case 3:
                printf("Ingrese el monto para el servicio de Agua: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0) {
                    printf("Monto no válido. Intente de nuevo.\n");
                    while (getchar() != '\n'); // Limpiar el búfer
                    continue;
                }
                TotalAgua += gasto;
                realizarPago(ptrSueldo, ptrAcuMensualidad, &TotalMensualidad, gasto);
                break;
            case 4:
                printf("Ingrese el monto de la Universidad: ");
                if (scanf("%d", &gasto) != 1 || gasto <= 0){
                    printf("Monto no valido. Intentelo de nuevo\n");
                    while (getchar() != '\n');
                    continue;
                }
                TotalUniversidad += gasto;
                realizarPago(ptrSueldo, ptrAcuMensualidad, &TotalMensualidad, gasto);
                break;
            case 0:
                printf("Volviendo al menu principal...\n");
                return *ptrSueldo;
            default:
                printf("Opción no valida. Intente de nuevo.\n");
                break;
        }
    }

    return *ptrSueldo;
}