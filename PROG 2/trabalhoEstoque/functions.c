#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Crie um sistema para gerenciar o estoque de uma empresa. Seu sistema deve ter:
//  Estrutura Data, com dia, mês e ano.
//  Estrutura Produto, que possui código, nome, preço, quantidade em estoque e data de validade (struct Data acima).
// Seu sistema conterá um vetor de Produto
struct Date{
    int dia;
    int mes;
    int ano;
};typedef struct Date Data;
struct Produto{
    int cod;
    char nome[100];
    float prise;
    int quantidade;
    Data validade;
};typedef struct Produto Produto;


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

int menu() {
    correct();
	int op;
	system("@cls||clear");  // LIMPA A TELA
    head();
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
pesqCod(){

}

inserir(){

}