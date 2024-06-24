//Pilha ...... 17/06/2024

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoElemento {
	int digito;
	tipoElemento *ante, *prox;
}TElemento;

typedef struct tipoPilha {
	TElemento *topo;
	TElemento *base;
}TPilha;

TPilha pilha;

void inicializa(TPilha *P);
void desmembrar(TPilha *P, int numero);
void empilhar(TPilha *P, int valor);
int remontar(TPilha *P);
int desempilhar(TPilha *P);


int main(){
	int numero = 1992, reverso;
	
	inicializa(&pilha);

	desmembrar(&pilha, numero);
	reverso = remontar(&pilha);
	
	printf("\n\nComparando %d com %d.\n\n", numero, reverso);
	
	if(numero == reverso){
		printf("\nPALINDROMO...\n\n");
	} else {
	    printf("\nNAO EH PALINDROMO...\n\n");
	}//if
	
	system("PAUSE");
}

//===| Fun��es |======================================================
void inicializa(TPilha *P){
	P->base = NULL;
	P->topo = NULL;	
}
//====================================================================
void desmembrar(TPilha *P, int numero){
	int quoc = numero;
	
	do{
		printf("\n>>> %d em %d\n", quoc%10, quoc);
		
		empilhar(P, (quoc % 10));
		quoc = quoc / 10;			
	}while(quoc > 0);
	
}
//====================================================================
void empilhar(TPilha *P, int valor){
	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	
	novo->ante = NULL;
	novo->prox = NULL;
	novo->digito = valor;
	
	if(P->topo == NULL){
		//Pilha VAZIA...
		P->base = novo;
		P->topo = novo;
	} else {
		P->topo->prox = novo;
		novo->ante = P->topo;
		P->topo = novo;
	}//if
}
//====================================================================
int remontar(TPilha *P){
	int valor = 0;
	int fator = 1;
	
	while(P->topo != NULL){
		valor = valor + (desempilhar(P) * fator);
		fator = fator * 10;
		
		printf("\n\n valor= %d    fator= %d",valor, fator);
	}//while
	
	return valor;
}
//====================================================================
int desempilhar(TPilha *P){
	TElemento *atual;
	int resultado;
	
	if(P->topo != NULL){
		atual = P->topo;
		P->topo = P->topo->ante;
		if(P->topo != NULL) {
			P->topo->prox = NULL;
			P->base = NULL;
		}
		resultado = atual->digito;
		free(atual);
	} else {
		resultado = -666;
	}//if
	
	return resultado;
	
}
//====================================================================

