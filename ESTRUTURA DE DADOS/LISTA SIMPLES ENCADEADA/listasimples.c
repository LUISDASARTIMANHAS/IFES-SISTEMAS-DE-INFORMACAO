#include <stdlib.h>
#include <stdio.h>
#include "functions.c"


int main(){
    head();
    

    copy();
    return 0;
}

void insere(Tlista *L; int valor){
    TElemento *novo = (TElemento *)malloc(sizeof(TElemento))
    novo ->valor = valor;
    novo ->prox = NULL;

    if(L-> inicio == NULL){
        L->inicio = novo;
        L->fim = novo;
        L->total = 1;
    }else{
        TElemento *atual = L -> inicio
        TElemento *anterior = NULL;
        while (atual != NULL){
            if(atual -> valor >= novo -> valor){
                if(anterior == NULL){
                    novo->prox = atual;
                    L->inicio = novo;
                }else{
                    novo->prox = atual
                    anterior->prox = novo
                }
                break
            }
            anterior = atual;
            atual = atual->prox;
        }
        L->total++;
    }
}