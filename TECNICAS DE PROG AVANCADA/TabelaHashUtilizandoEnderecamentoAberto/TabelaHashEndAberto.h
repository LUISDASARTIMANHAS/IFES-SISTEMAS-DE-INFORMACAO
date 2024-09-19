//Feito por: Lucas Garcia E Luis Augusto
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef char string[101];
typedef clock_t processTime;

#define INICIO "------------INICIO------------"
#define RESULTADO "------------RESULTADO------------"
#define CORTE "------------------------"

typedef struct tipoElemento {
    long long int valor; // Valor da matrícula
    string nome;         // Nome associado à matrícula
    int flag;            // Flag para indicar o estado do elemento (0: vazio, 1: ocupado, 2: removido)
} TElemento;

typedef struct tipoTabelaHash {
    TElemento *vetor; // Vetor que armazena os elementos da tabela hash
    int tamanho;      // Tamanho da tabela hash
} TabelaHash;

void salvarDadosNoArquivo(TabelaHash *tabela, FILE *arquivoLista);
int funcaoHash(long long int matricula, int tamanho);
int contarMatriculas(FILE *arquivoLista);
int contarTotalMatriculas(TabelaHash *tabela);
int ehPrimo(int num);
int acharProximoPrimo(int num);
void inicializarTabelaHash(TabelaHash *tabela, int tamanho);
void inicializarTabela(TabelaHash *tabelaHash, FILE *arquivoLista);
void lerEInserirMatriculas(TabelaHash *tabelaHash, FILE *arquivoLista);
void executarMenu(TabelaHash *tabelaHash);
int pesquisarTabelaHash(TabelaHash *tabela, long long int matricula);
void inserirTabelaHash(TabelaHash *tabela, long long int matricula, char *nome);
void excluirTabelaHash(TabelaHash *tabela, long long int matricula);
void exibeTabelaHash(TabelaHash *tabela);
void liberarTabelaHash(TabelaHash *tabela);
FILE *abrirArquivo(char *nomeArq, char *modo);
void calcularTempo(double ini, double fim);
long long int pedirOpcao();
long long int pedirNum(int caminhoASerEscolhido);
int pedirOpcao3();