//Lista Simplesmente Encadeada
//19-02-2024
//
#include <stdio.h>
#include <stdlib.h>

typedef struct tipoElemento {
	int valor;
	tipoElemento *prox;
}TElemento;

typedef struct tipoLista {
    TElemento *inicio;
    TElemento *fim;
    int total;
}TLista;

TLista lista; //vari�vel global

void inicializa(TLista *L);
void insere(TLista *L,int valor);
void exibeLista(TLista *L);
void exclui(TLista *L, int valor);

int main(){
	inicializa(&lista);
	insere(&lista,65);
	insere(&lista,21);
	insere(&lista,35);
	insere(&lista,82);
	exibeLista(lista);

	exclui(&lista,35);
	exclui(&lista,21);
	exclui(&lista,82);
	exclui(&lista,61);
	exclui(&lista,117);
	exibeLista(lista);
}

//==============================================
void inicializa(TLista *L){
	L->inicio = NULL;
	L->fim = NULL;
	L->total = 0;
}

//===============================================
void insere(TLista *L,int valor){
	int inseriu = 0;
	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	
	novo->valor = valor;
	novo->prox = NULL;
	
	if(L->inicio == NULL){
		//Lista encontra-se vazia.
		L->inicio = novo;
		L->fim = novo;
		L->total = 1;
		inseriu = 1;
	} else {
		//Lista possui pelo menos um elemento.
		TElemento *atual = L->inicio;
		TElemento *anterior = NULL;
		
		while(atual != NULL){
			if(atual->valor >= novo->valor)	{
				if(anterior == NULL){
					//Inserir novo antes do primeiro da primeiro da lista.
					novo->prox = atual;
					L->inicio = novo;
				}else{
					//inserir no meio da lista
					novo->prox = atual;
					anterior->prox = novo;
				}
				inseriu = 1;
				L->total++;
				break;
			}
			anterior = atual;
			atual = atual->prox; //move para o pr�ximo elemento
		}//while
	}//if
	if(!inseriu){
		// insere o elemento no fim da lista
		L->fim->prox = novo;
		L->fim = novo;
		L->total++;
	}
}

void exibeLista(TLista L){
	TElemento *atual = L.inicio;
	int count = 0;

	printf("\n\n\t===| EXIBE LISTA COMPLETA |===\n\n");
	while(atual != NULL){
		printf("(%d) - %d.\n",++count, atual->valor);
		atual = atual->prox;
	}
	printf("\n\n");
}
//===============================================

void exclui(TLista *L, int valor){
	TElemento *atual = L->inicio;
	TElemento *anterior = NULL;
	int count = 0;

	while(atual != NULL){
		if(count == 0){
			printf("\n\n\tExcluino o Elemento %d ...\n\n", atual->valor);
			count++;
		}
		if(atual->valor == valor){
			printf("\n\n\tEncontrado ELEMENTO a ser EXCLUIDO!\n\n");
			if(L->inicio == L->fim){
				L->inicio = NULL;
				L->fim = NULL;
			}else if(atual == L->inicio){
				L->inicio = atual->prox;
			}else if(atual == L->fim){
				L->fim = anterior;
				L->fim->prox = NULL;
			}else{
				anterior->prox = atual->prox;
			}
			free(atual);
			L->total--;
			break;
		}
		anterior = atual;
		atual = atual->prox;
	}
}