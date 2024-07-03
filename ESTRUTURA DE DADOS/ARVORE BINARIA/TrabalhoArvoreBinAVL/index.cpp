// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/*
     BINARIA AVL
    balanceamento -2 ou maior que 2 esta desbalanceada
    algoritimo de insercção faz ajustes para manter o balanceamento 
    apenas movendo a raiz pode ser que balanceie a arvore
    vasculhar o proximo nivel para ver se esta balanceado
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

TNo *raiz;

void inicializa(TNo **R){
	printf("\t\t=====|  BINARIA AVL |=====");
    insereAVL(&raiz,"Astolfo",0);
    insereAVL(&raiz,"Julia",0);
    insereAVL(&raiz,"Anakin",0);
    insereAVL(&raiz,"Jack",0);
    insereAVL(&raiz,"Ortencio",0);
    insereAVL(&raiz,"Kleiton",0);
    insereAVL(&raiz,"Xuxa",0);

    printf("\t\t caminhamento em ordem \t\n");
    caminhamentoEmOrdemAVL(raiz);
    imprimeArvore(raiz);
}

//===| Programa Principal |===========================
int main(){
	SetConsoleOutputCP(65001);
	inicializa(&raiz);
}