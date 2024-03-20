#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

typedef struct tipoFilme {
	string titulo;
	int anoProducao;
	tipoFilme *ante; //ponteiro que aponta para o filme anterior.
	tipoFilme *prox; //ponteiro que aponta para o pr�ximo filme.
}TFilme;

typedef struct tipoLista {
	TFilme *primeiro; //ponteiro que aponta para o primeiro Filme da Lista.
	TFilme *ultimo; //ponteiro que aponta para o �ltimo Filme da Lista.
	int total; //Quantidade de registros na Lista.
}TLista;

TLista lista;
void inicializa(TLista *L);
int myMenu();
void inicializa(TLista *L);
void entradaDeDados(TLista *L);
void insere(TLista *L, string titulo, int ano);

int main(){
	int op;
	correct();
	inicializa(&lista);
	do{
		op = myMenu();
		switch (op){
		case 1:
			entradaDeDados(&lista);
			break;
		}
	} while (op !=0);
	
	
}

///=================================================================================
void inicializa(TLista *L){
	L->primeiro = NULL;
	L->ultimo = NULL;
	L->total = 0;
}
//==================================================================================

void insere(TLista *L, string titulo, int ano){
	TFilme *novo = (TFilme *)malloc(sizeof(TFilme));
	TFilme *atual; 
	int flag = 0;

	novo->anoProducao = ano;
	strcpy(novo->titulo, titulo);
	novo->prox = NULL;
	novo->ante = NULL;

	if(L->primeiro == NULL){
		L->primeiro = novo;
		L->ultimo = novo;
		flag = 1;
	}else{
		atual = L->primeiro;
		while (atual !=NULL){
			if (strcmp(atual->titulo, novo->titulo) > 0){
				flag = 1;

				if (atual=L->primeiro){
					novo->prox = atual;
					atual->ante = novo;
					L->primeiro = novo;
				}else{
					novo->prox = atual;
					novo->ante = atual->ante;
					atual->ante->prox = novo;
					atual->ante = novo;
				}

				break;
			}
			atual = atual->prox;
		}
		if (!flag){
			L->ultimo->prox = novo;
			novo->ante = L->ultimo;
			L->ultimo = novo;
		}
		
	}

	L->total++;
}

void entradaDeDados(TLista *L){
	string titulo;
	int ano;

	printf("\n\n\t\t=====| CADASTRO DE FILMES |=====");
	printf("\tInforme TITULO: ");
	fflush(stdin);
	inputS(titulo);

	printf("\tInforme TITULO: ");
	fflush(stdin);
	ano = input();

	insere(L,titulo,ano);
}

void imprimi(TLista L){
	TFilme *atual = L.primeiro;
	int count = 0;

	while (atual !=NULL){
		printf(SEPARETOR);
		printf("\t|| TFILME ||\n");
		printf("\t|| %d || %s || %d || %p || %p ||",++count, atual->titulo,atual->anoProducao,atual->ante,atual->prox);
		atual = atual->prox;
	}	
	printf(SEPARETOR);
}

//===========================================================================
void exclui(TLista *L, string titulo){
	TFilme *atual,*anterior; 
	int flag = 0;
}
//===========================================================================
void selecionaFilmeExclusao(TLista *L){
	
}
//============================================================================

int myMenu() {
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
