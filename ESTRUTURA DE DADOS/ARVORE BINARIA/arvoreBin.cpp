#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

TNo *raiz;

void inicializa(TNo **R){
    correct();
    (*R) = NULL;
}

// balanceamento -2 ou maior que 2 esta desbalanceada
// algoritimo de insercção faz ajustes para manter o balanceamento 
// apenas movendo a raiz pode ser que balanceie a arvore
//  vasculhar o proximo nivel para ver se esta balanceado


//===| Programa Principal |===========================
int main(){
    inicializa(&raiz);
    insereArvBin(&raiz,56);
    insereArvBin(&raiz,99);
    insereArvBin(&raiz,86);
    insereArvBin(&raiz,92);
    insereArvBin(&raiz,41);
    insereArvBin(&raiz,32);
    insereArvBin(&raiz,35);
    
    printf("\n Em ordem \n");
    caminhamentoEmOrdemBin(raiz);
    
    printf("\n Pre ordem \n");
    caminhamentoPreOrdemBin(raiz);
    
    printf("\n Pos ordem \n");
    caminhamentoPosOrdemBin(raiz);

    printf("\n Buscando Nó com valor 92");
    TNo *atual = buscaArvBin(&raiz,92);
    if (atual != NULL){
        printf("\n Encontrado %d", atual->valor);
    }else{
        printf("\n Valor não encontrado!");
    }
    
    return 0;
}