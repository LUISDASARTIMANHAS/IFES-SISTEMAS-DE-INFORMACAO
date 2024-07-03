// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/*
    ARVORE BINARIA AVL
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
	printf("\t\t=====| ARVORE BINARIA AVL |=====");
    insereAVL(&raiz,"Asdrubal");
    insereAVL(&raiz,"Julia");
    insereAVL(&raiz,"Anakin");
    insereAVL(&raiz,"Jack");
    insereAVL(&raiz,"Ortencio");
    insereAVL(&raiz,"Kleiton");
    insereAVL(&raiz,"Xuxa");

    printf("\t\t caminhamento em ordem \t\n");
    caminhamentoEmOrdemAVL(raiz);
}

//===| Programa Principal |===========================
int main(){
	SetConsoleOutputCP(65001);
	inicializa(&raiz);
}