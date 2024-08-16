#include <stdio.h>
#include <stdlib.h>
// Defina constantes para as sequências de escape ANSI das cores
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define SEPARETOR BLUE "\n================================================\n"  RESET

typedef struct tipoElemento {
	int valor;
	struct tipoElemento *prox;
}TElemento;

typedef struct tipoLista {
    TElemento *inicio;
    TElemento *fim;
    int total;
}TLista;

void inicializa(TLista *L);
void inserirNovaMatricula(TLista *L,int valor);
void imprimirMatricula(TLista L);
void totalDeMatriculas(TLista L);
void pesquisarMatricula(TLista L,int valor);
void removerMatricula(TLista *L, int valor);
int menu();