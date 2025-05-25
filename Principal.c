#include "librerias.h"
#include "declaracionVariables.h"
#include <string.h>

// Definición de variables globales
char direccion[] = "Gastoss.txt";
FILE *arch, *fd;

int cases = 0;
float sueldo = 0;
int gasto = 0;
bool hola = true;
char letra, caracter, fecha[50];

int AcuMensualidad = 0;
int AcuServicio = 0;
int AcuSemana = 0;
int AcuDiario = 0;
int AcuColaboracion = 0;

// Definición de las variables acumuladoras
int TotalMensualidad = 0;
int TotalServicio = 0;
int TotalSemana = 0;
int TotalDiario = 0;
int TotalColaboracion = 0;


// Definición de punteros
int *ptrAcuColaboracion;
int *ptrAcuDiario;
int *ptrAcuSemana;
int *ptrAcuServicio;
int *ptrAcuMensualidad;
float *ptrSueldo;

int main() {
#include "asignacionApuntadores.h"

    printf("<=<=<=<=<=<=<=<=<=<=<O>=>=>=>=>=>=>=>=>=>=>=>=>\n");
    printf("<--- Bienvenido a tu Calculadora de Gastos --->");
    printf("\n<----<----<----<----<>---->---->---->---->---->");
    printf("\nIngrese su sueldo mensual: Q.");
    scanf("%f", &sueldo);

    printf("\n Que desea hacer?");
    printf("\n_-_-_-_-_-_-_-_-_-");

    while (hola) {
        printf("\n\n1) Gastos Mensuales\n");
        printf("----------------------------------\n");
        printf("2) Gastos de Servicios\n");
        printf("----------------------------------\n");
        printf("3) Gastos Semanales\n");
        printf("----------------------------------\n");
        printf("4) Gastos Diarios\n");
        printf("----------------------------------\n");
        printf("5) Colaboracion en Casa\n");
        printf("----------------------------------\n");
        printf("6) Ver gastos\n");
        printf("----------------------------------\n");
        printf("7) Imprimir Gastos en Archivo txt\n");
        printf("----------------------------------\n");
        printf("0) Salir del programa\nOpcion: ");
        if (scanf(" %c", &letra) != 1) {
            printf("Entrada no válida. Intente de nuevo.\n");
            while (getchar() != '\n'); // Limpiar el búfer
            continue;
        }

        switch (letra) {
            case '1':
                mensualidad(ptrSueldo, ptrAcuMensualidad);
                break;
            case '2':
                servicio(ptrSueldo, ptrAcuServicio);
                break;
            case '3':
                semana(ptrSueldo, ptrAcuSemana);
                break;
            case '4':
                diario(ptrSueldo, ptrAcuDiario);
                break;
            case '5':
                colaboracion(ptrSueldo, ptrAcuColaboracion);
                break;
            case '6':
                printf("\nMostrando gastos acumulados...\n");
                printf("Mensuales:      %d pagos, Total gastado: %d\n", *ptrAcuMensualidad, TotalMensualidad);
                printf("Servicios:      %d pagos, Total gastado: %d\n", *ptrAcuServicio, TotalServicio);
                printf("Semanales:      %d pagos, Total gastado: %d\n", *ptrAcuSemana, TotalSemana);
                printf("Diarios:        %d pagos, Total gastado: %d\n", *ptrAcuDiario, TotalDiario);
                printf("Colaboracion:   %d pagos, Total gastado: %d\n", *ptrAcuColaboracion, TotalColaboracion);
                printf("Sueldo restante: %.2f\n", *ptrSueldo);
                printf("Detalle de gastos mensuales:\n");
                printf("  WiFi:         %d\n", TotalWiFi);
                printf("  Luz:          %d\n", TotalLuz);
                printf("  Agua:         %d\n", TotalAgua);
                printf("  Universidad:  %d\n", TotalUniversidad);
                printf("Detalle de gastos de Servicios:\n");
                printf("  Netflix:      %d\n", TotalNetflix);
                printf("  Spotify:      %d\n", TotalSpotify);
                printf("  Prestamos:    %d\n", TotalPrestamos);
                break;
            case '7':
                printf("\nImprimiendo gastos en archivo...\n");

                // Abrir el archivo en modo de escritura (append)
                fd = fopen(direccion, "a");
                if (fd == NULL) {
                    perror("Error al crear o abrir el archivo");
                    break; // Salir del case si no se puede abrir el archivo
                }

                // Solicitar la fecha de los gastos
                printf("Escribe la fecha (formato: DD/MM/AAAA): ");
                fflush(stdin); // Limpiar el búfer de entrada
                fgets(fecha, sizeof(fecha), stdin);
                fecha[strcspn(fecha, "\n")] = 0; // Eliminar el salto de línea al final

                // Escribir los datos en el archivo
                fprintf(fd, "Fecha: %s\n", fecha);
                fprintf(fd, "Categoría\t\tPagos\t\tMonto Total\n");
                fprintf(fd, "Mensual\t\t\t%d\t\t%d\n", *ptrAcuMensualidad, TotalMensualidad);
                fprintf(fd, "Servicios\t\t%d\t\t%d\n", *ptrAcuServicio, TotalServicio);
                fprintf(fd, "Semanales\t\t%d\t\t%d\n", *ptrAcuSemana, TotalSemana);
                fprintf(fd, "Diarios\t\t\t%d\t\t%d\n", *ptrAcuDiario, TotalDiario);
                fprintf(fd, "Colaboración\t\t%d\t\t%d\n", *ptrAcuColaboracion, TotalColaboracion);
                fprintf(fd, "Sueldo restante: %.2f\n", *ptrSueldo);

                // Agregar el detalle de gastos mensuales
                fprintf(fd, "Detalle de gastos mensuales:\n");
                fprintf(fd, "  WiFi:         %d\n", TotalWiFi);
                fprintf(fd, "  Luz:          %d\n", TotalLuz);
                fprintf(fd, "  Agua:         %d\n", TotalAgua);
                fprintf(fd, "  Universidad:  %d\n", TotalUniversidad);
                fprintf(fd, "\n");
                
                //agregare lo del detalle de los servicios
                fprintf(fd, "Detalle de gastos de servicios:\n");
                fprintf(fd, "  Netflix:      %d\n", TotalNetflix);
                fprintf(fd, "  Spotify:      %d\n", TotalSpotify);
                fprintf(fd, "  Prestamos:    %d\n", TotalPrestamos);
                // Confirmar que el archivo fue creado/actualizado
                printf("El archivo de texto ha sido creado/actualizado con el nombre 'Gastoss.txt'.\n");

                // Cerrar el archivo
                fclose(fd);
                break;
            case '0':
                printf("\nGracias por usar el programa :)\n");
                hola = false;
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    }

    return 0;
}