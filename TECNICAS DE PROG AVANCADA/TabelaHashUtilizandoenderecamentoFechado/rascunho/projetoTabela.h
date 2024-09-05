#include <stdio.h>
#include <stdlib.h>

#define INICIO "------------INICIO------------" 
#define RESULTADO "------------RESULTADO------------"
#define CORTE "------------------------"
typedef struct tipoElemento{
    int valor;                     
    char nome[100];                
    struct tipoElemento *prox;     
} TElemento;

typedef struct tipoLista{
    TElemento *inicio, *fim;    
    int total;    
}TLista;

typedef struct tipoTabelaHash {
    TLista *vetorListas;  
    int tamanho;          
}TabelaHash;

int funcaoHash(int matricula, int tamanho);
int contarMatriculas(FILE *arquivoLista);
int contarTotalMatriculas(TabelaHash *tabela);
int ehPrimo(int num);
int acharProximoPrimo(int num);
void inicializarTabelaHash(TabelaHash *tabela, int tamanho);
void inicializarTabela(TabelaHash *tabelaHash, FILE *arquivoLista);
void lerEInserirMatrículas(TabelaHash *tabelaHash, FILE *arquivoLista);
void executarMenu(TabelaHash *tabelaHash);
int pesquisarTabelaHash(TabelaHash *tabela, int matricula);
void inserirTabelaHash(TabelaHash *tabela, int matricula, char *nome);
void excluirTabelaHash(TabelaHash *tabela, int matricula);
void exibeTabelaHash(TabelaHash *tabela);
void liberarTabelaHash(TabelaHash *tabela);
FILE * abrirArquivo(char * nomeArq, char * modo);
void construirListaDoZero(TLista *lista);
void lerArquivo(TLista *lista, FILE *arquivoLista);
void inicializa(TLista *lista, FILE *arquivoLista);
void gravarListaEmArquivo(TLista *lista, FILE *arquivoLista);
int pesquisarMatricula2(TLista *lista, int matriculaBusca); 
int pesquisarMatricula(TLista *lista);
void inserir(TLista *lista, int valor, char *nome);
int pedirOpcao3();
void exibeLista(TLista lista);
void excluirLista(TLista *lista, int valor);
int pedirOpcao();
int pedirNum(int caminhoASerEscolhido);
void imprimirTabelaHash(TabelaHash *tabela);
void menuPrincipal(TabelaHash *tabelaHash);
