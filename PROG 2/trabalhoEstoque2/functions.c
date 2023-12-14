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

#define SEPARETOR BLUE "\n================================================\n"  RESET

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

void trocarProduto(Produto vet[],int i,int f){
    Produto aux;
    aux = vet[i];
    vet[i] = vet[f];
    vet[f] = aux;
}

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
    printf(BLUE "\nSISTEMA: Carregando Autosave..." RESET);
    FILE * databaseR;
    databaseR = abrirArquivo("../data/database.bin", "rb");
    fread( qtde, sizeof(int), 1, databaseR  );
    fread( vetProd, sizeof(Produto), *qtde, databaseR  );
    fclose(databaseR);
}
void gravarDatabase(Produto * vetProd, int qtde) {
    printf(BLUE "\nSISTEMA: SALVANDO DADOS..." RESET);
    FILE *databaseW;
    databaseW = abrirArquivo("../data/database.bin", "wb");
    fwrite( &qtde, sizeof(int), 1, databaseW  );
    fwrite( vetProd, sizeof(Produto), qtde, databaseW  );
    fclose(databaseW);
    printf(GREEN "\nSISTEMA: Autosave concluido!" RESET);
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
	printf(GREEN "7 - Listar\n");
    printf("8 - Ordenar sistema por quicksort\n" );
    printf("9 - Ordenar sistema por heapsort\n"  RESET);
	printf(RED "0 - Sair\n" RESET);
	do {
		printf(YELLOW "Escolha sua opção: " RESET);
		scanf(" %d", &op);
	} while(op < 0 || op > 9);
	return op;
}

int menuOrdenar() {
    correct();
	int op;
	// system("@cls||clear");  // LIMPA A TELA
	printf(BLUE "\n\nSISTEMA DE ESTOQUE\n\n" RESET);
    printf(GREEN"1 - Ordenar sistema por quicksort\n" );
    printf("2 - Ordenar sistema por heapsort\n"  RESET);
	printf(RED "0 - Sair\n" RESET);
	do {
		printf(YELLOW "Escolha sua opção: " RESET);
		scanf(" %d", &op);
	} while(op < 0 || op > 9);
	return op;
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

float validPreco(){
    float prise;
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

int menuUpdate() {
    correct();
	int op;
	// system("@cls||clear");  // LIMPA A TELA
	printf(BLUE "\n\nSISTEMA DE ESTOQUE\n\n" RESET);
	printf(GREEN "1 - Aplicar desconto\n");
	printf("2 - Aplicar aumento\n");
	do {
		printf(YELLOW "Escolha sua opção: " RESET);
		scanf(" %d", &op);
	} while(op < 1 || op > 2);
	return op;
}

// funções

int pesqCod(Produto produtos[],int tam){
    if(tam >= 1){
        int cod = validCod();
        int i;
        for(i=0; i <= tam; i++){
            Produto produtoTemp = produtos[i];

            if(produtos[i].cod == cod){
                printf(GREEN"\nO Produto procurado foi encontrado!",RESET);
                printf(SEPARETOR);
                printf(BLUE"   \t Nome do produto: %s", produtoTemp.nome);
                printf(     "\n \t código do produto: %d", produtoTemp.cod);
                printf(     "\n \t Preço do produto: %0.2f", produtoTemp.prise);
                printf(     "\n \t Quantidade do produto: %d", produtoTemp.quantidade);
                printf(     "\n \t Data de validade do produto: %0.2d/%0.2d/%0.2d", produtoTemp.validade.dia,produtoTemp.validade.mes,produtoTemp.validade.ano,RESET);
                printf(SEPARETOR);
                return i;
            }else{
                printf(BLUE"\nSISTEMA: PROCURANDO...",RESET);
            }
        }
        printf(RED "\nO Produto não esta repetido e não foi encontado!" RESET);
        return -1;
    }else{
        printf(RED "\nSISTEMA: O banco de dados esta vazio, insira algo primeiro" RESET);
    }
    return -1;
}


int pesqName(Produto produtos[],int tam){
    if(tam >= 1){
        char pesq[101];
        int i;
        int comparador = 1;
        validNome(pesq);

        for(i=0; i <= tam; i++){
            Produto produtoTemp = produtos[i];
            comparador = strcmp(produtoTemp.nome, pesq);

            if(comparador == 0){
                printf(GREEN"\nO Produto procurado foi encontrado!",RESET);
                printf(SEPARETOR);
                printf(BLUE"   \t Nome do produto: %s", produtoTemp.nome);
                printf(     "\n \t código do produto: %d", produtoTemp.cod);
                printf(     "\n \t Preço do produto: %0.2f", produtoTemp.prise);
                printf(     "\n \t Quantidade do produto: %d", produtoTemp.quantidade);
                printf(     "\n \t Data de validade do produto: %0.2d/%0.2d/%0.2d", produtoTemp.validade.dia,produtoTemp.validade.mes,produtoTemp.validade.ano,RESET);
                printf(SEPARETOR);
                return i;
            }else{
                printf(BLUE"\nSISTEMA: PROCURANDO...",RESET);
            }
        }
        printf(RED "\nO Produto não foi encontado!" RESET);
        return -1;
    }else{
        printf(RED "\nSISTEMA: O banco de dados esta vazio, insira algo primeiro" RESET);
    }
    return -1;
}


void inserir(Produto produtos[],int *tam){
    char name[101];
    validNome(name);
    float prise = validPreco();
    int qtde = validQuantidade();
    int day = validDia();
    int month = validMes();
    int year = validAno();
    int cod = validCod();
    printf(BLUE"\nSISTEMA: Confirme o código do produto!"RESET);
    int pesq = pesqCod(produtos,*tam);

    if(pesq == -1){
    strcpy(produtos[*tam].nome,name);
    produtos[*tam].cod = cod;
    produtos[*tam].prise = prise;
    produtos[*tam].quantidade = qtde;
    produtos[*tam].validade.dia = day;
    produtos[*tam].validade.mes = month;
    produtos[*tam].validade.ano = year;
    (*tam)++;
    }else{
        printf(SEPARETOR);
        printf(RED"\nERRO: O código do produto já existe!"RESET);
        printf(BLUE"\nSISTEMA: Saindo para o menu para preservar os arquivos!"RESET);
        printf(SEPARETOR);
    }
}


void update(Produto produtos[],int tam){
    int op;
    int pos = pesqCod(produtos, tam);
    float taxa;
    float taxaRend;
    float total;
    if(tam >= 1){
        if(pos > 0 ){
            float prodPrise = produtos[pos].prise;
            taxa = validTaxa();
            op = menuUpdate();
            taxaRend = taxa * prodPrise;

            switch ( op ) {
                case 1:
                    //desconto
                    total = prodPrise - taxaRend;
                break;
                case 2:
                    //aumento
                    total = prodPrise + taxaRend;
                break;
                default:
                printf ("\n\nOpção inválida!\n\n");
                }
            produtos[pos].prise = total;

            printf(BLUE "SISTEMA: O rendimento ou desconto de R$ %f foi aplicado no valor do produto!",taxaRend,RESET);
        }else{
            printf(RED "Não foi possivel aplicar o rendimento" RESET);
        }
    }else{
        printf("\n O banco de dados esta vazio, insira algo primeiro");
    }
}

void finderMaior(Produto produtos[],int tam){
    char nome[101];
    int cod;
    int qtde;
    int maior = 0;
    int i;
    int day,month,year;
    float prise;

    if(tam >= 1){
        for(i = 0; i <= tam; i++){
            Produto produtoTemp = produtos[i];

            if (produtoTemp.prise >= maior){
                maior = produtoTemp.prise;
                strcpy(nome,produtoTemp.nome);
                cod = produtoTemp.cod;
                prise = produtoTemp.prise;
                qtde = produtoTemp.quantidade;
                day = produtoTemp.validade.dia;
                month = produtoTemp.validade.mes;
                year = produtoTemp.validade.ano;
            }else{
                printf(BLUE"\n SISTEMA: PROCURANDO...",RESET);
            }
        }
        printf(SEPARETOR);
        printf(BLUE"   \t Nome do produto: %s", nome);
        printf(     "\n \t código do produto: %d", cod);
        printf(     "\n \t Preço do produto: %0.2f", prise);
        printf(     "\n \t Quantidade do produto: %d", qtde);
        printf(     "\n \t Data de validade do produto: %0.2d/%0.2d/%0.2d", day,month,year,RESET);
        printf(SEPARETOR);
    }else{
        printf(RED "\nSISTEMA: O banco de dados esta vazio, insira algo primeiro" RESET);
    }
}

void delete(Produto produtos[],int *tam){
    int i;
    if((*tam) >= 1){
        printf(YELLOW"\nALERTA: Tenha certeza que o código do produto esta certo!");
        printf("\nALERTA: ERROS no código do produto ocasionarão em exclusão permanente de um produto incorreto!"RESET);
        int pos = pesqCod(produtos,*tam);

        if(pos != -1){
            for (i = pos; i < (*tam- 1); i++) {
            produtos[i] = produtos[i+1];
        }
        (*tam)--;
        printf(SEPARETOR);
        printf(BLUE"\nSISTEMA: Produto deletado com sucesso!"RESET);
        printf(SEPARETOR);
        }else{
            printf(RED "\nSISTEMA: O código do produto e invalido ou não esta cadastrado!" RESET);
        }
    }else{
        printf(RED "\nSISTEMA: O banco de dados esta vazio, insira algo primeiro" RESET);
    }
}

void list(Produto produtos[],int tam){
    int i;
    if(tam >= 1){
        for (i = 0; i < tam; i++){
            Produto produtoTemp = produtos[i];
            printf(SEPARETOR);
            printf(BLUE"   \t Nome do produto: %s", produtoTemp.nome);
            printf(     "\n \t código do produto: %d", produtoTemp.cod);
            printf(     "\n \t Preço do produto: %0.2f", produtoTemp.prise);
            printf(     "\n \t Quantidade do produto: %d", produtoTemp.quantidade);
            printf(     "\n \t Data de validade do produto: %0.2d/%0.2d/%0.2d", produtoTemp.validade.dia,produtoTemp.validade.mes,produtoTemp.validade.ano,RESET);
            printf(SEPARETOR);
        }
    }else{
        printf(RED "\nSISTEMA: O banco de dados esta vazio, insira algo primeiro" RESET);
    }
}

void ordenar(Produto vetor[],int tam){
    int op;
    do{
        op = menuOrdenar();
        switch ( op ) {
            case 1:
                // QUICKSORT
                quickSort(vetor,0,tam-1);
            break;
            case 2:
                // HEAPSORT
                heapSort(vetor,tam);
            break;
            default:
                printf ("\n\nOpção inválida!\n\n");
        }
    } while (op != 0);
}

int particao(Produto vet[], int ini,int fim){
    int pivo = vet[ini].cod;
    int i = ini + 1;
    int f = fim;

    while (i <= f){
        if (vet[i].cod <= pivo){
            i++;
        }else if (vet[f].cod > pivo){
            f--;
        }
        else{
            trocarProduto(vet, i, f);
            i++;
            f--;
        }
    }
    trocarProduto(vet, ini, f);
    return f;
}

void quickSort(Produto vet[], int ini, int fim){
    int posPivo;

    if (ini < fim){
        posPivo = particao(vet,ini,fim);
        quickSort(vet, ini, posPivo - 1);
        quickSort(vet, posPivo + 1, fim);
    }
}

void atualizarHeap(Produto vetor[], int raiz, int n ) {
	int filhoEsq = 2 * raiz + 1;
	int filhoDir = 2 * raiz + 2;

	int maior;
	if ( filhoEsq >= n) {
		// SEM NENHUM FILHO
		return;
	} else if ( filhoDir >= n ){
		// SOMENTE o FILHO DA ESQUERDA
		maior = filhoEsq;
	} else if ( vetor[filhoEsq].cod > vetor[filhoDir].cod  ) {
		maior = filhoEsq;
	} else {
		maior = filhoDir;
	}

	if ( vetor[maior].cod > vetor[raiz].cod  ) {
		trocarProduto(vetor, maior, raiz);
		atualizarHeap(vetor, maior, n);
	} else {
		return;
	}
}

void construirHeap(Produto vet[],int tam){
    int i;

	for(i = (tam/2)-1; i>=0; i--) {
		atualizarHeap(vet, i, tam);
	}
}

void heapSort(Produto vetor[], int tam ) {
	int n = tam;
    printf(BLUE "\nSISTEMA: Organizando o banco de dados... \n Isso pode levar um tempo, por favor, aguarde enquanto o sistema está organizando as informações." RESET);
	construirHeap(vetor,n);
	while (n > 1) {
		trocarProduto(vetor,0,n-1);
		n--;
		atualizarHeap(vetor,0,n);
	}
}