#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
        printf("ERRO ao abrir o arquivo.");
        exit(-1);
    }
    return arq;
}
void limparBuffer(){
    // Limpar o buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void carregarArquivo(FILE * arquivo, Produto * vetProd, int *qtde) {
    fread( qtde, sizeof(int), 1, arquivo  );
    fread( vetProd, sizeof(Produto), *qtde, arquivo  );
}
void gravarArquivo(FILE * arquivo, Produto * vetProd, int qtde) {
    fwrite( &qtde, sizeof(int), 1, arquivo  );
    fwrite( vetProd, sizeof(Produto), qtde, arquivo  );
}

int correct(){
    SetConsoleOutputCP(65001);
    return 0;
}
void head(){
    correct();
    printf("\n ----------------------------------------------------");
    printf("\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    printf("\n\t Iniciando o programa.....");
    printf("\n----------------------------------------------------\n");
}

void copy(){
    correct();
    printf("\n----------------------------------------------------");
    printf("\n\t DEVS:");
    printf("\n\t LUIS_DAS_ARTIMANHAS.");
    printf("\n\t PINGOBRAS S.A");
    printf("\n----------------------------------------------------\n");
}

// inputs personalizados e modificados
float input(){
    float value;
    scanf("%f", &value);
    return value;
}
void lerString(char *destino) {
    fflush(stdout);
    scanf(" %100[^\n]", destino); // Limita o tamanho da entrada
    limparBuffer();
}

int menu() {
    correct();
	int op;
	// system("@cls||clear");  // LIMPA A TELA
	printf("\n\nSISTEMA De Estoque\n\n");
	printf("1 - Inserir\n");
	printf("2 - Pesquisar por número\n");
	printf("3 - Pesquisar por nome\n");
	printf("4 - Atualizar\n");
	printf("5 - Maior\n");
	printf("6 - Excluir\n");
	printf("7 - Listar\n");
	printf("0 - Sair\n");
	do {
		printf("Escolha sua opção: ");
		scanf(" %d", &op);
	} while(op < 0 || op > 7);
	return op;
}

// validadores
void validString(char data[],int tam){
    printf("\n \t Espaço Maximo: %d", tam);
    printf("\n \t Insira um texto: ");
    fgets(data, tam, stdin);
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

int validCod(){
    int cod;
    do{
        printf("\n Insira o código do Produto: ");
        cod = input();
    }while (cod < 1);
    return cod;
}

int validPreco(){
    int prise;
    do{
        printf("Insira o preço do Produto: ");
        prise = input();
    }while (prise < 0);
    return prise;
}

int validQuantidade(){
    int qtd;
    do{
        printf("Insira a quantidade do Produto: ");
        qtd = input();
    }while (qtd < 0);
    return qtd;
}

int validDia(){
    int dia;
    do{
        printf("Insira o dia de validade: ");
        dia = input();
    }while ((dia < 0) || (dia > 31));
    return dia;
}

int validMes(){
    int mes;
    do{
        printf("Insira o mês de validade: ");
        mes = input();
    }while ((mes < 0)||(mes > 12));
    return mes;
}

int validAno(){
    int ano;
    do{
        printf("Insira o Ano de validade: ");
        ano = input();
    }while ((ano < 0)||(ano > 3050));
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

void trocar(char msm[]) {
    int i;
    char e;
    int tam = strlen(msm);

    for (i = 0; i < tam; i++){
        e = msm[i];

        if(e == 'o'){
            msm[i] = '0';
        }else if (e == '0'){
            msm[i] = 'o';
        }

        if(e == 'a'){
            msm[i] = '@';
        }else if (e == '@'){
            msm[i] = 'a';
        }

        if(e == '\n'){
            msm[i] = '\0';
        }
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
// void pesqCod(Produto produtos[],int tam){

// }
// void pesqName(Produto produtos[],int tam){

// }
void inserir(Produto produtos[],int *tam){
    float prise = validPreco();
    char nome[101];
    int cod = validCod();
    int qtde = validQuantidade();
    int day = validDia();
    int month = validMes();
    int year = validAno();
    Produto produtoTemp = produtos[*tam];

    printf("\n Nome do Produto: ");
    scanf("%s", nome);

    produtoTemp.cod = cod;
    strcpy(produtoTemp.nome, nome);
    produtoTemp.prise = prise;
    produtoTemp.quantidade = qtde;
    produtoTemp.validade.dia = day;
    produtoTemp.validade.mes = month;
    produtoTemp.validade.ano = year;
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
                printf("\n SISTEMA: PROCURANDO...");
            }
        }
        printf("\n \t +------------------------------+ \n");
        printf("   \t || Código do Produto      || %.2d", cod);
        printf("\n \t || Maior Valor do Produto || R$ %.2d", maior);
        printf("\n \t +------------------------------+ \n");
    }else{
        printf("\n O banco de dados esta vazio, insira algo primeiro");
        }
}

// void delete(Produto produtos[],int *tam){

// }

void list(Produto produtos[],int tam){
    int i;
    Produto produto;

    for (i = 0; i < tam; i++){
        produto = produtos[i];
        printf("\n======================\n");
        printf("   \t Codigo do produto: %d", produto.cod);
        printf("\n \t Preço do produto: %f", produto.prise);
        printf("\n \t Quantidade do produto: %d", produto.quantidade);
        printf("\n \t Data de validade do produto: %d/%d/%d", produto.validade.dia,produto.validade.mes,produto.validade.ano);
        printf("\n======================\n");
    }
}