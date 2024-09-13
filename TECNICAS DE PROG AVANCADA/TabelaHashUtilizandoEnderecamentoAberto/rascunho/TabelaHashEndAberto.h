#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef char string[101];

#define INICIO "------------INICIO------------"
#define RESULTADO "------------RESULTADO------------"
#define CORTE "------------------------"
typedef struct tipoElemento{
    long long int valor;
    string nome;
    int flag;
    struct tipoElemento *prox;
} TElemento;

typedef struct tipoTabelaHash{
    TElemento *vetorElementos;
    int tamanho;
} TabelaHash;

void salvarDadosNoArquivo(TabelaHash *tabela, FILE *arquivoLista);
int funcaoHash(long long int matricula, int tamanho);
int contarMatriculas(FILE *arquivoLista);
int contarTotalMatriculas(TabelaHash *tabela);
int ehPrimo(int num);
int acharProximoPrimo(int num);
void inicializarTabelaHash(TabelaHash *tabela, int tamanho);
void inicializarTabela(TabelaHash *tabelaHash, FILE *arquivoLista);
void lerEInserirMatriculas(TabelaHash *tabelaHash, FILE *arquivoLista, int funcaoHashEscolhida);
void executarMenu(TabelaHash *tabelaHash, int funcaoHashEscolhida);
int pesquisarTabelaHash(TabelaHash *tabela, long long int matricula, int funcaoHashEscolhida);
void inserirTabelaHash(TabelaHash *tabela, long long int matricula, char *nome, int funcaoHashEscolhida);
void excluirTabelaHash(TabelaHash *tabela, long long int matricula, int funcaoHashEscolhida);
void exibeTabelaHash(TabelaHash *tabela);
void liberarTabelaHash(TabelaHash *tabela);
FILE *abrirArquivo(char *nomeArq, char *modo);
// void construirListaDoZero(TLista *lista);
// void lerArquivo(TLista *lista, FILE *arquivoLista);
// void inicializa(TLista *lista, FILE *arquivoLista);
// int pesquisarMatricula2(TLista *lista, long long int matriculaBusca);
// int pesquisarMatricula(TLista *lista);
// void inserir(TLista *lista, long long int valor, char *nome);
int pedirOpcao3();
// void exibeLista(TLista lista);
// void excluirLista(TLista *lista, long long int valor);
long long int pedirOpcao();
long long int pedirNum(int caminhoASerEscolhido);
void imprimirTabelaHash(TabelaHash *tabela);
void menuPrincipal(TabelaHash *tabelaHash, int funcaoHashEscolhida);
