// Desenvolvido por Lucas Garcia de Souza & LUIS AUGUSTO DE SOUZA 
#include <windows.h>
#define _USE_MATH_DEFINES
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

typedef struct tipoElemento {
	long int valor;
    string nome;
	struct tipoElemento *prox;
}TElemento;

typedef struct tipoLista {
    TElemento *inicio;
    TElemento *fim;
    int total;
}TLista;

typedef struct tipoTabelaHash{
    TLista *vetorListas;
    int tamanho;
} TabelaHash;


void inicializa(TLista *L);
void inserirNovaMatricula(TLista *L);
void imprimirMatricula(TLista L);
void totalDeMatriculas(TLista L);
void pesquisarMatricula(TLista L);
void removerMatricula(TLista *L);
int menu();
int menuHash();
int menuMetodoHash();
// gera um numero aleatorio no intervalo n,
int aleatorio(int n);
double aleatorio_quebrado();
double aleatorio_intervalo(double min, double max);
int switchMenuHash();
