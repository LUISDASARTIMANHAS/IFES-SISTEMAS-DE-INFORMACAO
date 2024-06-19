#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

TPilha pilha;

void inicializa(TPilha *P){
    correct();
    P->base = NULL;
    P->topo = NULL;
}

//===| Programa Principal |===========================
int main(){
    int num = 1991, reverso;
    inicializa(&pilha);
    desmembrarPilha(&pilha, 1991);
    reverso = remontarPilha(&pilha);

    printf("\n\n Comparando %d com %d.\n\n", num, reverso);

    if (num == reverso){
        printf("\n\n PALINDROMO!\n\n", num, reverso);
    }else{
        printf("\n\n NÃO E PALINDROMO\n\n");
    }
}