/*
  Lista Duplamente Encadeada de Filmes.
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[40];

typedef struct tipoFilme {
	string titulo;
	int anoProducao;
	tipoFilme *ante; //ponteiro que aponta para o filme anterior.
	tipoFilme *prox; //ponteiro que aponta para o próximo filme.
}TFilme;

typedef struct tipoLista {
	TFilme *primeiro; //ponteiro que aponta para o primeiro Filme da Lista.
	TFilme *ultimo; //ponteiro que aponta para o último Filme da Lista.
	int total; //Quantidade de registros na Lista.
}TLista;

TLista lista; //Variável global

void inicializa(TLista *L);
void insere(TLista *L, string titulo, int ano);
int menu();
void entradaDeDados(TLista *L);
void exibe(TLista L);
void exclui(TLista *L, string titulo);
void selecionaFilmeExclusao(TLista *L);
TFilme *obtemFilme(TLista *L, string titulo);
void buscaAproximada(TLista L, string arg);
int encontradaParcial(string a, string b);

int main(){
	int opcao;
	
	inicializa(&lista);
	
	do{
		opcao = menu();
		
		switch(opcao){
			case 1: entradaDeDados(&lista); break;
			case 2: exibe(lista); break;
			case 3: selecionaFilmeExclusao(&lista); break;
			case 4: printf("\n\n\t\t=====| BUSCA APROXIMADA |=====\n\n");
			        printf("\tInforme ARGUMENTO de PESQUISA: ");
			        string arg;
			        fflush(stdin);
					gets(arg);
					buscaAproximada(lista, arg);
					break;
		}//switch
		
	}while(opcao != 0);
	
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
		//Lista encontra-se vazia: insere o único TFilme.
		L->primeiro = novo;
		L->ultimo = novo;
		flag = 1;
	} else {
		atual = L->primeiro;
		while (atual != NULL)	{
		   	if(strcmp(atual->titulo, novo->titulo) > 0)	{
		   		//Encontrada posição para a inserção do novo TFilme.
				flag = 1;
				
				
				if(atual == L->primeiro){
					//Inserir NOVO antes de ATUAL (o PRIMEIRO Filme da Lista).
					
        			novo->prox = atual;
	    			atual->ante = novo;

					L->primeiro = novo;	
				} else {
					//Caso contrário: Inserir NOVO antes de ATUAL (no MEIO da Lista).
        			novo->prox = atual;
        			novo->ante = atual->ante;
        			atual->ante->prox = novo;
	    			atual->ante = novo;
					
				}//if
				
				break;
		    }//if
		    atual = atual->prox; //move o ponteiro atual para o próximo TFilme.
		}//while
		
		if(!flag){
		   //Inserir NOVO como o Último TFilme da Lista.
		   L->ultimo->prox = novo;
		   novo->ante = L->ultimo;
		   L->ultimo = novo;	
		}//if
		
	}//if
	
	L->total++;
}
//==================================================================================
int menu(){
	int opcao;
	
	system("CLS"); //Limpa a tela
	
	printf("\n\n\t\t=====| MENU |=====\n\n");
	printf("\t0 - SAIR (Encerrar Aplicacao).\n\n");
	printf("\t1 - INSERIR novo filme.\n");
	printf("\t2 - EXIBE filmes.\n");
	printf("\t3 - EXCLUI filme.\n");
	printf("\t4 - Busca Aproximada (por TITULO).\n");
	printf("\n\nInforme OPCAO desejada: ");
	
	scanf("%d",&opcao);
	
	if((opcao < 0) || (opcao > 4)){
		printf("ERRO: opcao INVALIDA! Tente novamente.\n\n");
		system("PAUSE");
	}//if
	
	return opcao;
}
//===========================================================================
void entradaDeDados(TLista *L){
	string titulo;
	int ano;
	
	printf("\n\n\t\t=====| CADASTRO DE FILMES |=====\n\n");
	printf("\tInforme TITULO: ");
	fflush(stdin);
	gets(titulo);
	
	printf("\n\n\tInforme ANO de PRODUCAO: ");
	fflush(stdin);
	scanf("%d",&ano);
	
	insere(L, titulo, ano);
}
//===========================================================================
void exibe(TLista L){
	TFilme *atual = L.primeiro;
	int cont = 0;
	
	printf("\n\n\t\t=====| EXIBE TODOS OS FILMES |=====\n\n");
	
	while(atual != NULL){
		printf("\t(%d) - %s [%d].\n",++cont,atual->titulo, atual->anoProducao);
		atual = atual->prox;
	}//while
	
	printf("\n\n");
	system("PAUSE");
}
//===========================================================================
void exclui(TLista *L, string titulo){
	TFilme *atual = NULL;
	TFilme *anterior, *posterior;
	
	atual = obtemFilme(L, titulo);
	
	if(atual == NULL){
		printf("\n\n\tERRO:\n\tFILME NAO ENCONTRADO: %s.", titulo);
		printf("\n\tTENTE OUTRA VEZ.\n\n");
		system("PAUSE");
	} else {
		anterior = atual->ante;
		posterior = atual->prox;
		
		if(anterior != NULL){
			anterior->prox = posterior;
		} else {
			L->primeiro = posterior;
		}//if
		
		if(posterior != NULL){
			posterior->ante = anterior;
		} else {
			L->ultimo = anterior;
		}//if
		
		printf("\n\n\tAVISO:\n\tFILME EXCLUIDO com SUCESSO!\n\n");
		printf("\t\tTITULO EXCLUIDO: %s\n", atual->titulo);
		printf("\t\tANO de PRODUCAO EXCLUIDO: %d\n\n", atual->anoProducao);
		system("PAUSE");
		free(atual);
	}//if
	
}
//===========================================================================
void selecionaFilmeExclusao(TLista *L){
	string nome;
	
	printf("\n\n\n\t\t=====| EXCLUSAO de FILME |=====\n\n");
	printf("\tInforme TITULO a ser EXCLUIDO: ");
	fflush(stdin);
	gets(nome);
	
	exclui(L, nome);
	
}
//============================================================================
TFilme *obtemFilme(TLista *L, string titulo){
	TFilme *atual = L->primeiro;
	
	while(atual != NULL){
		if(strcmp(titulo, atual->titulo) == 0){
			break;
		}
		atual = atual->prox;
	}//while
	
	return atual;
}
//============================================================================
void buscaAproximada(TLista L, string arg) {
	TFilme *atual = L.primeiro;
	int cont = 0;
	
	while(atual != NULL){
		if(encontradaParcial(atual->titulo, arg)){
			printf("\t[%d] - %s (%d)\n", ++cont, atual->titulo, atual->anoProducao);
		} else {
		    printf("\t--------------------\n");
		}//if
		
		atual =  atual->prox;
	}//while
	
	printf("\n\n");
	system("PAUSE");
		
}
//============================================================================
int encontradaParcial(string a, string b){
	int encontrado = 0;
	int posA = 0; 
	int posB = 0;
	int tamanhoA = strlen(a);
	int tamanhoB = strlen(b);
	int cont = 0;
	
	while (posA < tamanhoA){
		if(a[posA] == b[posB]){
			cont++;
			posB++;
			
			if(cont == tamanhoB){
				encontrado = 1;
				break;
			}//if
		} else {
			cont = 0;
		    posB = 0;
		    if(a[posA] == b[posB]){
		    	cont++;
			}//if
		}//if
		
		posA++;
	}//while
	return encontrado;
}
//===========================================================================
