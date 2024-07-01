#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo {
	int valor;
	tipoNo *esq;
	tipoNo *dir;
}TNo;

TNo *raiz;

void inicializa(TNo **R);
TNo *criaNo(int valor);
void insere(TNo **R, int valor);
void caminhamento_Em_Ordem(TNo *R);
void caminhamento_Pre_Ordem(TNo *R);
void caminhamento_Pos_Ordem(TNo *R);
TNo *busca(TNo **R, int argumento);
TNo *exclui(TNo **R, int argumento);

int main(){
	inicializa(&raiz);
	
	insere(&raiz, 56);
	insere(&raiz, 99);
	insere(&raiz, 86);
	insere(&raiz, 92);
	insere(&raiz, 41);
	insere(&raiz, 32);
	insere(&raiz, 35);
	
	printf("\n\n\tCaminhamento EM ORDEM: ");
	caminhamento_Em_Ordem(raiz);
	
	printf("\n\n\tCaminhamento PRE ORDEM:");
	caminhamento_Pre_Ordem(raiz);

	printf("\n\n\tCaminhamento POS ORDEM:");
	caminhamento_Pos_Ordem(raiz);
	
	printf("\n\n\tBuscando NO com valor 92:\n");
	TNo *atual = busca(&raiz,92);
	if (atual != NULL) printf("\n\tEncontrado: ", atual->valor);
	else printf("\n\tVALOR NAO ENCONTRADO!!!");
	
}

//=====| Fun��es |=================================================
void inicializa(TNo **R){
	*R = NULL;
}
//=================================================================
TNo *criaNo(int valor){
	TNo *novo = (TNo *)malloc(sizeof(TNo));
	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}
//=================================================================
void insere(TNo **R, int valor){
	if(*R == NULL){
		//�rvore vazia.
		*R = criaNo(valor);
	} else if(valor >= (*R)->valor){
		//Inser��o � Direita.
		if((*R)->dir == NULL){
			(*R)->dir = criaNo(valor);
		} else {
			insere(&(*R)->dir, valor);
		}
	} else {
		//Inser��o � Esquerda.
		if((*R)->esq == NULL){
			(*R)->esq = criaNo(valor);
		} else {
			insere(&(*R)->esq, valor);
		}
	}//if
}
//=================================================================
void caminhamento_Em_Ordem(TNo *R){
	if(R != NULL){
		caminhamento_Em_Ordem(R->esq);
		printf("%d, ", R->valor);
		caminhamento_Em_Ordem(R->dir);
	}//if
}
//=================================================================
void caminhamento_Pre_Ordem(TNo *R){
	if(R != NULL){
		printf("%d, ", R->valor);
		caminhamento_Pre_Ordem(R->esq);
		caminhamento_Pre_Ordem(R->dir);
	}//if
}
//=================================================================
void caminhamento_Pos_Ordem(TNo *R){
	if(R != NULL){
		caminhamento_Pos_Ordem(R->esq);
		caminhamento_Pos_Ordem(R->dir);
		printf("%d, ", R->valor);
	}//if
}
//==================================================================
TNo *busca(TNo **R, int argumento){
	printf("\n %d == %d",argumento,(*R)->valor);
	if(*R == NULL){
		return NULL;
	} else if(argumento == (*R)->valor){
		//No Encontrado.
		return *R;
	} else if(argumento > (*R)->valor){
		//Desce pela Direita.
		printf("Visitando %d e DESCENDO pela DIREITA...", (*R)->valor);
		return busca(&(*R)->dir, argumento);
	} else {
		//Desce pela Esquerda.
		printf("Visitando %d e DESCENDO pela ESQUERDA...", (*R)->valor);
		return busca(&(*R)->esq, argumento);
	}//if
}
//==================================================================
TNo *exclui(TNo **R, int argumento){
	
}
//==================================================================



