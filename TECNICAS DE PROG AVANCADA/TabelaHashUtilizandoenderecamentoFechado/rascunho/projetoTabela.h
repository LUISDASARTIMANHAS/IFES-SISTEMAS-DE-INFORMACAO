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

#define INICIO "------------INICIO------------"
#define RESULTADO "------------RESULTADO------------"
#define CORTE "------------------------"
typedef struct tipoElemento{
    long int valor;
    string nome;
    struct tipoElemento *prox;
} TElemento;

typedef struct tipoLista{
    TElemento *inicio, *fim;
    int total;
} TLista;

typedef struct tipoTabelaHash{
    TLista *vetorListas;
    int tamanho;
} TabelaHash;

int funcaoHash(long int matricula, int tamanho);
int contarMatriculas(FILE *arquivoLista);
int contarTotalMatriculas(TabelaHash *tabela);
int ehPrimo(int num);
int acharProximoPrimo(int num);
void inicializarTabelaHash(TabelaHash *tabela, int tamanho);
void inicializarTabela(TabelaHash *tabelaHash, FILE *arquivoLista);
void lerEInserirMatriculas(TabelaHash *tabelaHash, FILE *arquivoLista);
void executarMenu(TabelaHash *tabelaHash);
int pesquisarTabelaHash(TabelaHash *tabela, long int matricula);
void inserirTabelaHash(TabelaHash *tabela, long int matricula, char *nome);
void excluirTabelaHash(TabelaHash *tabela, long int matricula);
void exibeTabelaHash(TabelaHash *tabela);
void liberarTabelaHash(TabelaHash *tabela);
FILE *abrirArquivo(char *nomeArq, char *modo);
void construirListaDoZero(TLista *lista);
void lerArquivo(TLista *lista, FILE *arquivoLista);
void inicializa(TLista *lista, FILE *arquivoLista);
void gravarListaEmArquivo(TLista *lista, FILE *arquivoLista);
int pesquisarMatricula2(TLista *lista, long int matriculaBusca);
int pesquisarMatricula(TLista *lista);
void inserir(TLista *lista, long int valor, char *nome);
int pedirOpcao3();
void exibeLista(TLista lista);
void excluirLista(TLista *lista, long int valor);
long int pedirOpcao();
long int pedirNum(int caminhoASerEscolhido);
void imprimirTabelaHash(TabelaHash *tabela);
void menuPrincipal(TabelaHash *tabelaHash);
