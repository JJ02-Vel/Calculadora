#include <stdio.h>
#include <stdbool.h>

// Declaraciones de variables globales
extern char direccion[];
extern FILE *arch, *fd;

extern int cases;
extern float sueldo;
extern int gasto;
extern bool hola;
extern char letra, caracter, fecha[50];

extern int AcuMensualidad;
extern int AcuServicio;
extern int AcuSemana;
extern int AcuDiario;
extern int AcuColaboracion;

// Declaraciones de las variables acumuladoras
extern int TotalMensualidad;
extern int TotalServicio;
extern int TotalSemana;
extern int TotalDiario;
extern int TotalColaboracion;
extern int TotalWiFi;
extern int TotalLuz;
extern int TotalAgua;
extern int TotalUniversidad;
extern int TotalNetflix;
extern int TotalSpotify;
extern int TotalPrestamos;

// Declaraciones de punteros
extern int *ptrAcuColaboracion;
extern int *ptrAcuDiario;
extern int *ptrAcuSemana;
extern int *ptrAcuServicio;
extern int *ptrAcuMensualidad;
extern float *ptrSueldo;
