#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

TPilha pilha;

void inicializa(TPilha *P){
    P->base = NULL;
    P->topo = NULL;
}

void empilharPilha(TPilha *P, int valor){
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));

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
    Pilha *atual;
    int res;

    if (P->topo != NULL){
        atual = P->topo;
        P->topo = P->topo->ante;
        P->topo->prox = atual;
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