// Feito por: Lucas Garcia E Luis Augusto
#ifndef FILESYS_H
#define FILESYS_H
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// Defina constantes para as sequências de escape ANSI das cores
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define SEPARETOR BLUE "\n================================================\n"  RESET

typedef char string[101];

// Funções que serão implementadas no arquivo .c
FILE *abrirArquivo(char *nomeArq, char *modo);
int freadINT (FILE *arquivo);
void freadSTRING (FILE *arquivo, char valdestino[]);
float freadFloat (FILE *arquivo);
double freadDouble (FILE *arquivo);

void fWiriteINT (FILE *arquivo, int value);
void fWiriteSTRING (FILE *arquivo, char value[]);
void fWiriteFLOAT (FILE *arquivo, float value);
void fWiriteDOUBLE (FILE *arquivo, double value);

float input();
double inputDouble();
long long int inputDLLD();
int inputBoleano();
void inputS(char destino[]);

double getTime();
void calcularTempo(double ini);
void correct();
#endif