#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Defina constantes para as sequências de escape ANSI das cores
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define SEPARETOR BLUE "\n=====================================\n"  RESET

struct Date{
    int dia;
    int mes;
    int ano;
};typedef struct Date Data;
struct ClassProduto{
    int cod;
    char nome[101];
    float prise;
    int quantidade;
    Data validade;
};typedef struct ClassProduto Produto;

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
void carregarDatabase( Produto * vetProd, int *qtde) {
    FILE * databaseR;
    databaseR = abrirArquivo("../data/database.bin", "rb");
    fread( qtde, sizeof(int), 1, databaseR  );
    fread( vetProd, sizeof(Produto), *qtde, databaseR  );
    fclose(databaseR);
}
void gravarDatabase(Produto * vetProd, int qtde) {
    FILE *databaseW;
    databaseW = abrirArquivo("../data/database.bin", "wb");
    fwrite( &qtde, sizeof(int), 1, databaseW  );
    fwrite( vetProd, sizeof(Produto), qtde, databaseW  );
    fclose(databaseW);
}

int correct(){
    SetConsoleOutputCP(65001);
    return 0;
}
void head(){
    correct();
    printf(SEPARETOR);
    printf(BLUE"\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    printf("\n\t Iniciando o programa....." RESET);
    printf(SEPARETOR);
}

void copy(){
    correct();
    printf(SEPARETOR);
    printf(BLUE "\n\t DEVS:");
    printf("\n\t LUIS_DAS_ARTIMANHAS.");
    printf("\n\t PINGOBRAS S.A" RESET);
    printf(SEPARETOR);
}

// inputs personalizados e modificados
float input(){
    float value;
    scanf("%f", &value);
    return value;
}
void inputS(char destino[]){
    scanf(" %100[^\n]s", destino);
}

int menu() {
    correct();
	int op;
	// system("@cls||clear");  // LIMPA A TELA
	printf(BLUE "\n\nSISTEMA DE ESTOQUE\n\n" RESET);
	printf(GREEN "1 - Inserir\n");
	printf("2 - Pesquisar por número\n");
	printf("3 - Pesquisar por nome\n");
	printf("4 - Atualizar\n");
	printf("5 - Maior\n" RESET);
	printf(RED "6 - Excluir\n" RESET);
	printf(GREEN "7 - Listar\n"  RESET);
	printf(RED "0 - Sair\n" RESET);
	do {
		printf(YELLOW "Escolha sua opção: " RESET);
		scanf(" %d", &op);
	} while(op < 0 || op > 7);
	return op;
}

// validadores
int validCod(){
    int cod;
    do{
        printf(YELLOW "\nInsira o código do Produto: " RESET);
        cod = input();
    }while (cod < 1);
    return cod;
}

int validPreco(){
    int prise;
    do{
        printf(YELLOW "\nInsira o preço do Produto: " RESET);
        prise = input();
    }while (prise < 0);
    return prise;
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
    }while ((dia < 0) || (dia > 31));
    return dia;
}

int validMes(){
    int mes;
    do{
        printf(YELLOW "\nInsira o mês de validade: " RESET);
        mes = input();
    }while ((mes < 0)||(mes > 12));
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

void inversor(char database[]){
    int fim = strlen(database)-1;
    int i;
    char e;

    for (i = 0; i < fim; i++,fim--){
        e = database[i];
        database[i] = database[fim];
        database[fim] = e;
    }
}

void separador(char msm[],char pars[],char impars[]){
    int par = 0;
    int impar = 1;
    int i;
    char ePar,eImpar;
    int tam = strlen(msm);
    int tamSubsStrs = tam/2;

    for (i = 0; i < tam; i++,par=par+2,impar=impar+2){
        ePar = msm[par];
        eImpar= msm[impar];

        pars[i] = ePar;
        impars[i] = eImpar;
    }
    inversor(impars);
    pars[tamSubsStrs] = '\0';
    impars[tamSubsStrs] = '\0';
}

void intercalador(char cripto[],char pars[],char impars[]){
    int tamPars = strlen(pars);
    int tamImpars = strlen(impars);
    int tam = (tamPars + tamImpars);
    int i;
    int iPar=0;
    int iImpar=0;
    char ePar,eImpar;

    for (i = 0; i < tam; i++){
        ePar = pars[iPar];
        eImpar = impars[iImpar];

        if (i % 2 == 0){
            cripto[i] = ePar;
            iPar++;
        }else{
            cripto[i] = eImpar;
            iImpar++;
        }
    }
    cripto[tam] = '\0';
}
int pesqCod(Produto produtos[],int tam){
    if(tam >= 1){
        int cod = validCod();
        int i;
        for(i=0; i <= tam; i++){
            if(produtos[i].cod == cod){
                printf(GREEN "\nO código do investimento procurado foi encontrado!" RESET);
                return i;
            }
            else{
                printf(BLUE "\nSISTEMA: PROCURANDO..." RESET);
            }
        }
        printf(RED "\nO código do investimento não esta repetido e não foi encontado!" RESET);
        return -1;
    }else{
        printf(RED "\n O banco de dados esta vazio, insira algo primeiro" RESET);
    }
}
void pesqName(Produto produtos[],int tam){

}
void inserir(Produto produtos[],int *tam){
    char nome[101];
    float prise = validPreco();
    int cod = validCod();
    int qtde = validQuantidade();
    int day = validDia();
    int month = validMes();
    int year = validAno();
    printf(YELLOW "\nInsira o nome do Produto: " RESET);
    inputS(nome);

    strcpy(produtos[*tam].nome,nome);
    produtos[*tam].cod = cod;
    produtos[*tam].prise = prise;
    produtos[*tam].quantidade = qtde;
    produtos[*tam].validade.dia = day;
    produtos[*tam].validade.mes = month;
    produtos[*tam].validade.ano = year;
    (*tam)++;

}

// void update(Produto produtos[],int tam){

// }

void finderMaior(Produto produtos[],int tam){
    int i,cod,maior;

    if(tam >= 1){
        for(i =0; i >= tam; i++){
            Produto produtoTemp = produtos[i];

            if (produtoTemp.prise >= maior){
                maior = produtoTemp.prise;
                cod = produtoTemp.cod;
            }
            else{
                printf(BLUE "\n SISTEMA: PROCURANDO..." RESET);
            }
        }
        printf(SEPARETOR);
        printf(BLUE "   \t || Código do Produto      || %d", cod);
        printf(     "\n \t || Preço Maior do Produto || R$ %0.2d", maior,RESET);
        printf(SEPARETOR);
    }
    else{
        printf("\n O banco de dados esta vazio, insira algo primeiro");
    }
}

// void delete(Produto produtos[],int *tam){

// }

void list(Produto produtos[],int tam){
    int i;

    for (i = 0; i < tam; i++){
        printf(SEPARETOR);
        printf(BLUE "   \t Nome do produto: %s", produtos[i].nome);
        printf("\n \t Codigo do produto: %d", produtos[i].cod);
        printf("\n \t Preço do produto: %0.2f", produtos[i].prise);
        printf("\n \t Quantidade do produto: %d", produtos[i].quantidade);
        printf("\n \t Data de validade do produto: %0.2d/%0.2d/%0.2d", produtos[i].validade.dia,produtos[i].validade.mes,produtos[i].validade.ano,RESET);
        printf(SEPARETOR);
    }
}