#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMPTY 0
#define FULL 1

float GetFlotante(float* destino, char mensaje[], float menor, float mayor, int reintentos);
int GetEntero(int* destino, char mensaje[], int menor, int mayor, int reintentos);
int GetString(char cadena[], char mensaje[], char mensajeError[], int tam, int reintentos);
int GetCuit(char* cuitObjetivo, char mensaje[], int reintentos);
int EsSring(char cadena[]);
int EmpiezaCon(char* prefijo, char* cadena);
int ValidarCuit(char* cuit);
int StringContieneLetras(char cadena[]);
int AutoIncrementarId(int* id);
void FormatearCuit(char cuit[]);
int StringEsSoloNumeros(char cadena[]);
int GetCharDosOpciones(char* caracter, char* mensaje, char opc1, char opc2, char reintentos);
int GetChar(char* caracter, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
