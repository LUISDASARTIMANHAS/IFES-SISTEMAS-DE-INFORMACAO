// ============================= BASE ======================
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// Defina constantes para as sequências de escape ANSI das cores
// EM CASO DE ERROS E FUNÇÕES DESTRUTIVAS
#define RED "\x1b[31m" 
// MENSAGEM DE INFORMAÇÃO OU SISTEMA
#define BLUE "\x1b[34m"
// MENSAGEM DE SUCESSO OU FUNÇÕES CONSTRUTIVAS
#define GREEN "\x1b[32m"
// MENSAGEMS DE AVISO OU PERGUNTA 
#define YELLOW "\x1b[33m"
// RESETA A COLORAÇÃO
#define RESET "\x1b[0m"

#define SEPARETOR BLUE "\n================================================\n"  RESET

typedef char string[101];

struct ClassDatabase {
    int codigo;
    string nome;
    float preco;
    int qtde;
};
typedef struct ClassDatabase Database;

struct ClassPilha{
    int digito;
    ClassPilha *prox,*ante;
};
typedef struct ClassPilha Pilha;

struct ClassTipoPilha{
    int digito;
    Pilha *topo;
    Pilha *base;
};
typedef struct ClassTipoPilha TPilha;

struct ClassTipoNo{
    int valor;
    int nivelProfundidade;
    ClassTipoNo *esq;
    ClassTipoNo *dir;
    ClassTipoNo *raiz;
    string nome;
};
typedef struct ClassTipoNo TNo;

FILE * abrirArquivo(char * nomeArq, char * modo) {
    // ABRIR o arquivo
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf(RED "ERRO ao abrir o arquivo." RESET);
        exit(-1);
    }
    return arq;
}
void carregarArquivo(FILE * arquivo, Database * vetProd, int *qtde) {
    fread( qtde, sizeof(int), 1, arquivo  );
    fread( vetProd, sizeof(Database), *qtde, arquivo  );
}
void gravarArquivo(FILE * arquivo, Database * vetProd, int qtde) {
    fwrite( &qtde, sizeof(int), 1, arquivo  );
    fwrite( vetProd, sizeof(Database), qtde, arquivo  );
}

FILE * autosave(FILE *arq, char * nomeArq){
	printf("\n\n\t AUTOSAVE EM ANDAMENTO.... \n\n");
	fclose(arq);
	printf("\n\n\t AUTOSAVE COMPLETO!. \n\n");
	arq = abrirArquivo(nomeArq,"a+");
	return arq;
}

// gera um numero aleatorio no intervalo n,
int aleatorio(int n){
    return (rand() % (n+1));
}

void correct(){
    SetConsoleOutputCP(65001);
}

void trocar(int vet[],int i,int f){
    int aux;
    aux = vet[i];
    vet[i] = vet[f];
    vet[f] = aux;
}
// ============================= FIM DO BASE ======================

void head(){
    correct();
    FILE * logs;
    logs = abrirArquivo("../data/logs.txt","a+");
    printf(SEPARETOR);
    printf(BLUE"\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    printf("\n\t Iniciando o programa....." RESET);
    printf(SEPARETOR);
    // save in logs
    fprintf(logs,SEPARETOR);
    fprintf(logs,"\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    fprintf(logs,"\n\t Iniciando programa.....");
    fprintf(logs,SEPARETOR);
    fclose(logs);
}

void copy(){
    FILE * logs;
    logs = abrirArquivo("../data/logs.txt","a+");
    correct();
    printf(SEPARETOR);
    printf(BLUE "\n\t DEVS:");
    printf("\n\t LUIS_DAS_ARTIMANHAS.");
    printf("\n\t PINGOBRAS S.A" RESET);
    printf(SEPARETOR);
    // save in logs
    fprintf(logs,"\n----------------------------------------------------");
    fprintf(logs,"\n\t DEVS:");
    fprintf(logs,"\n\t LUIS_DAS_ARTIMANHAS.");
    fprintf(logs,"\n\t PINGOBRAS S.A");
    fprintf(logs,"\n----------------------------------------------------\n");
    fclose(logs);
}

// inputs personalizados e modificados
float input(){
    float value;
    scanf("%f", &value);
    return value;
}
float inputBoleano(){
	int value;
	do{
		fflush(stdin);
		scanf("%d", &value);
	}while(value != 1 && value != 0);
	return value;
}
void inputS(char destino[]){
    scanf(" %100[^\n]s", destino);
}


// validadores
void validNome(char destino[]){
    do{
        printf(YELLOW "\nInsira o nome do Produto: " RESET);
        inputS(destino);
    }while (strlen(destino) < 3);
}

int validCod(){
    int cod;
    do{
        printf(YELLOW "\nInsira o código do Produto: " RESET);
        cod = input();
    }while (cod < 1);
    return cod;
}

float validTaxa(){
    float porcent;
    printf(YELLOW "\nInsira a porcentagem de aumento ou desconto: " RESET);
    int tax = input();

    while((tax <= 0 ) || (tax > 100)){
        printf(RED "\nA taxa não pode ser menor do que 0 ou maior que 100!\n" RESET);
        printf(YELLOW "\nInsira a porcentagem de aumento ou desconto: " RESET);
        tax = input();
    }
    porcent = (tax/100);
    return porcent;
}

int validQuantidade(){
    int qtd;
    do{
        printf(YELLOW "\nInsira a quantidade do Produto: " RESET);
        qtd = input();
    }while (qtd < 0);
    return qtd;
}

int validDia(){
    int dia;
    do{
        printf(YELLOW "\nInsira o dia de validade: " RESET);
        dia = input();
    }while ((dia < 1) || (dia > 31));
    return dia;
}

int validMes(){
    int mes;
    do{
        printf(YELLOW "\nInsira o mês de validade: " RESET);
        mes = input();
    }while ((mes < 1)||(mes > 12));
    return mes;
}

int validAno(){
    int ano;
    do{
        printf(YELLOW "\nInsira o Ano de validade: " RESET);
        ano = input();
    }while ((ano < 1900)||(ano > 3050));
    return ano;
}
int validNum(){
    printf("Insira um numero: ");
    int num = input();

    while(num < 0){
        printf("Salario invalido.");
        printf("Insira Seu salario: ");
        num = input();
    }
    return num;
}
int validNota(){
    float nota;
    do{
        printf("Insira uma Nota: ");
        nota = input();
    }while ((nota < 0) || ( nota > 10));
    return nota;
}
int validMatricula(){
    float matricula;
    do{
        printf("Insira sua matricula: ");
        matricula = input();
    }while (matricula < 0);
    return matricula;
}
float validPreco(){
    float prise;
    do{
        printf(YELLOW "\nInsira o preço do Produto: " RESET);
        prise = input();
    }while (prise < 0);
    return prise;
}
int validIdade(){
    printf("Insira sua idade: ");
    int idade = input();
    while((idade <= 0) || (idade >= 50)){
        printf("Idade invalida.");
        printf("Insira sua idade: ");
        idade = input();
        
    }
    return idade;
}
int validSalario(){
    printf("Insira seu salario: ");
    int salario = input();
    
    while(salario < 0){
        printf("Salario invalido.");
        printf("Insira Seu salario: ");
        salario = input();
    }
    return salario;
}
int validAltura(){
    float alt;
    do{
        printf("Insira a altura: ");
        alt = input();
    }while (alt < 0);
    return alt;
}
int validBase(){
    float base;
    do{
        printf("Insira a base: ");
        base = input();
    }while (base < 0);
    return base;
}
int validRaio(){
    float raio;
    do{
        printf("Insira o raio: ");
        raio = input();
    }while (raio < 0);
    return (raio*raio);
}

int validQTD(){
    float qtd;
    do{
        printf("Insira a quantidade de produto: ");
        qtd = input();
    }while (qtd < 0);
    return qtd;
}
void imprimirArray(int *array, int qtde){
    int i;

    for (i = 0; i < qtde; i++){
        printf("%d  ",array[i]);
    }
}
int fatorial(){
    int i,num, fat;
    printf("Informe o número: ");
    scanf("%d", &num);
    fat = 1;
    for(i=num; i > 1 ; i--) {
        fat = fat * i;
    }
    return fat;
}
int fatorialAuto(int num){
    int i, fat;
    fat = 1;
    for(i=num; i > 1 ; i--) {
        fat = fat * i;
        printf("\n Efetuando Fatorial !%d\n",i);
    }
    return fat;
}
int lerOpcaoCalc() {
    int op;
    printf("\n\nCALCULAR A ÁREA:\n");
    printf("1-Retângulo\n");
    printf("2-Círculo\n");
    printf("0-Sair\n");
    printf("Informe sua opção: ");
    scanf("%d", &op);
    // VALIDAR a opção entre 0, 1 e 2
    return op;
}

int somar(int num1, int num2){
    int total = num1 + num2;
    printf("\nSomando os numeros: %d + %d\n", num1,num2);
    return total;
}
int diminuir(int num1, int num2){
    int total = num1 - num2;
    printf("\n Subtraindo os numeros: %d - %d\n", num1,num2);
    return total;
}
float calcMedia3(float n1,float n2,float n3){
    float media = (n1 + n2 + n3 )/3;
    return media;
}
int menuPay(){
    printf("\n=======SELECIONAR FORMA DE PAGAMENTO=======\n");
    printf("1-A vista\n");
    printf("2-A prazo\n");
    printf("=====================\n");
    printf("Forma: ");
    int opc = input();

    return opc;
}

int calcArRetangulo(){
    float base = validBase();
    float altura = validAltura();
    float area = base * altura;
    return area;
}
int calcArCirculo(){
    float raio = validRaio();
    float area = M_PI * raio;
    return area;
}

// void saveArray(int *i,int *array,int data){
//     char continuar;
//     do{
//         array[*i] = data;
//         (*i)++;
//         printf("\nDeseja continuar? ");
//         scanf(" %c",&continuar);
//         continuar = toupper(continuar);
//     } while(continuar == "S");
// }

// ============= heapSort =========

void atualizarHeap(int vetor[], int raiz, int n ) {
	int filhoEsq = 2 * raiz + 1;
	int filhoDir = 2 * raiz + 2;

	int maior;
	if ( filhoEsq >= n) {
		// SEM NENHUM FILHO
		return;
	} else if ( filhoDir >= n ){
		// SOMENTE o FILHO DA ESQUERDA
		maior = filhoEsq;
	} else if ( vetor[filhoEsq] > vetor[filhoDir]  ) {
		maior = filhoEsq;
	} else {
		maior = filhoDir;
	}

	if ( vetor[maior] > vetor[raiz]  ) {
		trocar(vetor, maior, raiz);
		atualizarHeap(vetor, maior, n);
	} else {
		return;
	}
}

void construirHeap(int vet[],int tam){
    int i;

	for(i = (tam/2)-1; i>=0; i--) {
		atualizarHeap(vet, i, tam);
	}
}

void heapSort(int vetor[], int tam ) {
	long int n = tam;
	construirHeap(vetor,n);
	while (n > 1) {
		trocar(vetor,0,n-1);
		n--;
		atualizarHeap(vetor,0,n);
	}
	printf("\n\nTROCAS");
}

// ============= heapSort =========


// ============== FUNÇÕES O TRABALHO ========================

int menu() {
    correct();
	int op;
	system("@cls||clear");  // LIMPA A TELA
	printf(BLUE "\n\n\t\t =====| ARVORE BINARIA AVL |===== \n\n" RESET);
	printf(GREEN "1 - Inserir\n");
	printf(RED "2 - Excluir\n" RESET);
	printf(GREEN "3 - Listar\n");
    printf(GREEN "4 - Pre Ordem\n");
    printf(GREEN "5 - Em Ordem\n");
    printf(GREEN "6 - Pos Ordem\n"  RESET);
	printf(RED "0 - Sair\n" RESET);
	do {
		printf(YELLOW "Escolha sua opção: " RESET);
		scanf(" %d", &op);
	} while(op < 0 || op > 6);
	return op;
}

TNo *criaNoAVL(char *nome, TNo *raiz){
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    strcpy(novo->nome,nome);
    novo->nivelProfundidade = 1;
    novo->raiz = raiz;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void criaTabelaImpressaArvore(TNo *no){
    // Imprime o nó atual
    printf("\n\t\t| ");
    printf("%d",no->nivelProfundidade);
    printf(" \t\t| ");
    printf("Nó: %s",no->nome);
    printf(" \t| ");
    if(no->raiz != NULL){
        printf("Antecedente: %s",no->raiz->nome);
    }else{
        printf("Antecedente: %s","NULL");
    }
    printf("   \t|");
}


//===============================================================
void caminhamentoEmOrdemAVL(TNo *raiz){
    if(raiz != NULL){
        caminhamentoEmOrdemAVL(raiz->esq);
        criaTabelaImpressaArvore(raiz);
        caminhamentoEmOrdemAVL(raiz->dir);
    }    
}
//===============================================================
void caminhamentoPreOrdem(TNo *raiz){
    if(raiz != NULL){
        criaTabelaImpressaArvore(raiz);
        caminhamentoPreOrdem(raiz->esq);
        caminhamentoPreOrdem(raiz->dir);
    }   
}
//===============================================================
void caminhamentoPosOrdem(TNo *raiz){
    if(raiz != NULL){
        caminhamentoPosOrdem(raiz->esq);
        caminhamentoPosOrdem(raiz->dir);
        criaTabelaImpressaArvore(raiz);
    }
} 
//===============================================================

// ======================== FUNÇÕES BASICAS ========================
int nivelProfundidade(TNo *N) {
    if (N == NULL) {
        return 0;
    }
    return N->nivelProfundidade;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
        return b;
}

int getBalanco(TNo *N) {
    if (N == NULL) {
        return 0;
    }
    return nivelProfundidade(N->esq) - nivelProfundidade(N->dir);
}

TNo *minValueNodeAVL(TNo *no) {
    TNo *atual = no;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

TNo *rotacaoDireita(TNo *y) {
    TNo *x = y->esq;
    TNo *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    if (T2 != NULL) {
        T2->raiz = y;
    }
    x->raiz = y->raiz;
    y->raiz = x;

    y->nivelProfundidade = max(nivelProfundidade(y->esq), nivelProfundidade(y->dir)) + 1;
    x->nivelProfundidade = max(nivelProfundidade(x->esq), nivelProfundidade(x->dir)) + 1;

    return x;
}
TNo *rotacaoEsquerda(TNo *x) {
    TNo *y = x->dir;
    TNo *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    if (T2 != NULL) {
        T2->raiz = x;
    }
    y->raiz = x->raiz;
    x->raiz = y;

    x->nivelProfundidade = max(nivelProfundidade(x->esq), nivelProfundidade(x->dir)) + 1;
    y->nivelProfundidade = max(nivelProfundidade(y->esq), nivelProfundidade(y->dir)) + 1;

    return y;
}

TNo *balancearNo(TNo *no) {
    int balanco = getBalanco(no);

    if (balanco > 1) {
	// Desbalanceada para a esquerda
        if (getBalanco(no->esq) >= 0) {
		// Rotaçao simples à direita
            no = rotacaoDireita(no);
        } else {
		// Rotaçao dupla à direita (esquerda-direita)
            no->esq = rotacaoEsquerda(no->esq);
            no = rotacaoDireita(no);
        }
    } else if (balanco < -1) {
	    // Desbalanceada para a direita
        if (getBalanco(no->dir) <= 0) {
		// Rotaçao simples à esquerda
            no = rotacaoEsquerda(no);
        } else {
		// Rotaçao dupla à esquerda (direita-esquerda)
            no->dir = rotacaoDireita(no->dir);
            no = rotacaoEsquerda(no);
        }
    }

    return no;
}

// ======================== FIM DAS FUNÇÕES BASICAS ========================

TNo *insereAVL(TNo *no, char *nome){
    if (no == NULL) {
        printf(GREEN "\n Usuario %s Foi inserido com sucesso!\n" RESET,nome);
        return criaNoAVL(nome, no);
    }

    if (strcmp(nome, no->nome) < 0) {
        no->esq = insereAVL(no->esq, nome);
        no->esq->raiz = no;
    } else if (strcmp(nome, no->nome) > 0) {
        no->dir = insereAVL(no->dir, nome);
        no->dir->raiz = no;
    } else {
        return no;
    }

    no->nivelProfundidade = 1 + max(nivelProfundidade(no->esq), nivelProfundidade(no->dir));
    return balancearNo(no);
}

TNo *excluiAVL(TNo *no, char *nome) {
    if (no == NULL) {
        printf(RED "\n Erro: Não foi possivel excuir usuario %s, Arvore vazia!\n" RESET,nome);
        return no;
    }

    if (strcmp(nome, no->nome) < 0) {
        no->esq = excluiAVL(no->esq, nome);
    } else if (strcmp(nome, no->nome) > 0) {
        no->dir = excluiAVL(no->dir, nome);
    } else {
        if (no->esq == NULL || no->dir == NULL) {
            TNo *temp = no->esq;
            if (temp == NULL) {
                temp = no->dir;
            }

            if (temp == NULL) {
                temp = no;
                no = NULL;
            } else {
                *no = *temp;
            }
            printf(GREEN "\n Usuario %s Foi Excluido com sucesso!\n" RESET,nome);
            free(temp);
        } else {
            TNo *temp = minValueNodeAVL(no->dir);
            strcpy(no->nome, temp->nome);
            no->dir = excluiAVL(no->dir, temp->nome);
        }
    }

    if (no == NULL) {
        return no;
    }

    no->nivelProfundidade = 1 + max(nivelProfundidade(no->esq), nivelProfundidade(no->dir));
    return balancearNo(no);
}

void imprimeArvore(TNo *no) {
    // Imprime o nó atual
    printf("\n \t\t| Profundidade \t| Nó A - Z\t\t| Antecedente   \t| ");
    caminhamentoPreOrdem(no);
    printf("\n \t\t=========================================================\n ");
}