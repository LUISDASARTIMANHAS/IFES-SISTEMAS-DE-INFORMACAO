#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
TLista lista;

void insereAtor(TLista *DB, string nome){
    TAtor *novo = (TAtor *)malloc(sizeof(TAtor));
    TAtor *atual = DB->inicioA;
    TAtor *anterior = NULL;
    int inseriu = 0;

    novo->prox = NULL;
    strcpy(novo->nome,nome);

    if(DB->inicioA == NULL){
        DB->inicioA = novo;
        DB->fimA = novo;
    }else{
        while (atual != NULL){
            if (strcmp(atual->nome,novo->nome) > 0){
                inseriu = 1;
                novo->prox = atual;
                DB->inicioA = novo;
            }else{
                novo->prox = anterior->prox;
                anterior->prox = novo;
            }
        anterior = atual;
        atual = atual->prox;   
        }
        if (!inseriu){
            DB->fimA->prox = novo;
            DB->fimA = novo;
        } 
    }
}

void cadastraAtor(TLista *DB){
    string nome;

    printf("\n\n\t=====| INSERE ATOR|=====\n\n");
    printf("\tInforme o nome do ator: ");
    fflush(stdin);
    inputS(&nome);
}

// ====================================== FIM DA BASE ============================

void inicializa(TLista *DB){
    DB->inicioF = NULL;
    DB->inicioA = NULL;
    DB->fimF = NULL;
    DB->fimA = NULL;

    insereAtor(DB,"Tobey Maguire");
    insereAtor(DB,"Christen Dusten");
    insereAtor(DB,"Chartol");
    insereAtor(DB,"Tobey Maguire");
}

int main(){
    inicializa(&lista);
    return 0;
}