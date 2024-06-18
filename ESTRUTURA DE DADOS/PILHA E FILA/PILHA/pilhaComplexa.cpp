// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/*
  Rede Neural Artificial Evolutiva (RNA-E)
  
  Os pesos s�o atualizados a partir de um algoritmo
  gen�tico que busca minimizar os erros na fase de
  treinamento.
  
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

typedef struct pilhaComplexa{
    int digito;
    pilhaComplexa *prox,*ante;
}TElemento;

typedef struct tipoPilha{
    int digito;
    TElemento *topo;
    TElemento *base;
}TPilha;

TPilha pilha;

void inicializa(TPilha *P){
    P->base = NULL;
    P->topo = NULL;
}

void empilharPilha(TPilha *P, int valor){
    TElemento *novo = (TElemento*)malloc(sizeof(TElemento));

    novo->ante = NULL;
    novo->prox = NULL;
    novo->digito = valor;

    if (P->topo == NULL){
        // pilha vazia
        P->base = novo;
        P->topo = novo;
    }else{
        P->topo->prox = novo;
        novo->ante = P->topo;
        P->topo = novo;
    }
}

void desmembraPilha(TPilha *P, int num){
    int res, quoc = num;

    do{
        empilharPilha(P,(quoc % 10));
        quoc = quoc/10;
    } while (quoc > 0);
}

int desempilharPilha(TPilha *P){
    TElemento *atual;
    int res;

    if (P->topo != NULL){
        atual = P->topo;
        P->topo = P->topo->ante;
        P->topo->prox = NULL;
        res = P->topo->digito;
        free(atual);
    }else{
        res = -1;
    }
    return res;
}

int remontarPilha(TPilha *P){
    int valor = 0;
    int fator = 1;

    while (P->topo != NULL){
        valor = valor + (desempilharPilha(P) * fator);
    }
    
    return valor;
}
//===| Programa Principal |===========================
int main(){
    int num = 1991, reverso;
	SetConsoleOutputCP(65001);
    inicializa(&pilha);
    desmembraPilha(&pilha, 1991);
    reverso = remontarPilha(&pilha);

    printf("\n\n Comparando %d com %d.\n\n", num, reverso);

    if (num=reverso){
        printf("\n\n PALINDROMO!\n\n", num, reverso);
    }else{
        printf("\n\n NÃO E PALINDROMO\n\n");
    }
    
}