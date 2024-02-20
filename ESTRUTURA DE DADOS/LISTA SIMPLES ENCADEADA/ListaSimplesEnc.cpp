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

TLista lista; //variável global

void inicializa(TLista *L);
void insere(TLista *L;int valor);


int main(){
	inicializa(&lista);
	
}
//==============================================
void inicializa(TLista *L){
	L->inicio = NULL;
	L->fim = NULL;
	L->total = 0;
}
//===============================================
void insere(TLista *L;int valor){
	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	
	novo->valor = valor;
	novo->prox = NULL;
	
	if(L->inicio == NULL){
		//Lista encontra-se vazia.
		L->inicio = novo;
		L->fim = novo;
		L->total = 1;
	} else {
		//Lista possui pelo menos um elemento.
		TElemento *atual = L->inicio;
		TElemento *anterior = NULL;
		
		while(atual != NULL){
			if(atual->valor >= novo->valor)	{
				if(anterior == NULL){
					//Inserir novo como primeiro da lista.
					novo->prox = atual;
					L->inicio = novo;
				}else{
					//inserir no meio da lista
					novo->prox = atual;
					anterior->prox = novo;
				}
				break;
			}
			anterior = atual;
			atual = atual->prox; //move para o próximo elemento
		}//while
		L->total++;
	}//if
	
}
//===============================================
