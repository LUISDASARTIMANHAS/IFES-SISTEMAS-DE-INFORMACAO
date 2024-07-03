#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo{
    char nome[100];
    int valor;
    struct tipoNo *esq;
    struct tipoNo *dir;
    struct tipoNo *raiz;
    int nivelProfundidade;
}TNo;

TNo *raiz; // raiz inicial da arvore

//===============================================================
TNo *criaNo(char *nome, TNo *raiz){
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    strcpy(novo->nome,nome);
    novo->nivelProfundidade = 1;
    novo->raiz = raiz;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
//===============================================================
void inicializa(TNo **raiz, char *nome){
    *raiz = criaNo(nome,NULL);
}
//===============================================================
void insere(TNo **raiz, char *nome){
    if(*raiz == NULL){
        // arvore vazia
        // printf("Primeiro no da arvore\n");
        *raiz = criaNo(nome,(*raiz));
    }else if (strcmp(nome,(*raiz)->nome) > 0){
        // insere na direita
        if ((*raiz)->dir == NULL){
            (*raiz)->dir = criaNo(nome,(*raiz));
            // printf("Foi inserido na direita\n");
        }else{
            // printf("chama a funçao para a direita\n");
            insere(&(*raiz)->dir,nome);
        }   
    }else{
        // insere na esquerda
        if ((*raiz)->esq == NULL){
            // printf("Foi inserido na esquerda\n");
            (*raiz)->esq = criaNo(nome,(*raiz));
        }else{
            // printf("chama a funçao para a esquerda\n");
            insere(&(*raiz)->esq,nome);
        }
    }   
}
//===============================================================
void caminhamentoEmOrdem(TNo *raiz){
    if(raiz != NULL){
        caminhamentoEmOrdem(raiz->esq);
        printf("%s, ",raiz->nome);
        caminhamentoEmOrdem(raiz->dir);
    }    
}
//===============================================================
void caminhamentoPreOrdem(TNo *raiz){
    if(raiz != NULL){
        printf("%s, ",raiz->nome);
        caminhamentoPreOrdem(raiz->esq);
        caminhamentoPreOrdem(raiz->dir);
    }   
}
//===============================================================
void caminhamentoPosOrdem(TNo *raiz){
    if(raiz != NULL){
        caminhamentoPosOrdem(raiz->esq);
        caminhamentoPosOrdem(raiz->dir);
        printf("%s, ",raiz->nome);
    }
} 
//===============================================================
TNo *busca(TNo *raiz, int argumento){
    if(raiz == NULL){
       return NULL;
    }else if (argumento == raiz->valor){
        //No encontrado
        return raiz;
    }else if (argumento > raiz->valor){
        printf("Visitando %s e descendo na direita\n", raiz->nome);
        return busca(raiz->dir,argumento);
    }else{
        printf("Visitando %s e descendo na esquerda\n", raiz->nome);
        return busca(raiz->esq,argumento);
    }
}
//===============================================================
TNo* minValueNode(TNo* no) {
    TNo* atual = no;
    while (atual->esq != NULL){
        atual = atual->esq;
    }    
    return atual;
}
//===============================================================
TNo* exclui(TNo **raiz, int argumento) {
    if (*raiz == NULL){
        return *raiz;
    }else if (argumento < (*raiz)->valor){
        (*raiz)->esq = exclui(&(*raiz)->esq, argumento);
    }else if (argumento > (*raiz)->valor){
        (*raiz)->dir = exclui(&(*raiz)->dir, argumento);
    }else {
        if ((*raiz)->esq == NULL) {
            TNo *temp = (*raiz)->dir;
            free(*raiz);
            return temp;
        } else if ((*raiz)->dir == NULL) {
            TNo *temp = (*raiz)->esq;
            free(*raiz);
            return temp;
        }
        TNo* temp = minValueNode((*raiz)->dir);
        (*raiz)->valor = temp->valor;
        (*raiz)->dir = exclui(&(*raiz)->dir, temp->valor);
    }
    return *raiz;
}
//===============================================================

//===============================================================

//===============================================================
int main(){
    inicializa(&raiz,"Zilian");
    insere(&raiz,"Asdrubal");
    insere(&raiz,"Julia");
    insere(&raiz,"Anakin");
    insere(&raiz,"Jack");
    insere(&raiz,"Ortencio");
    insere(&raiz,"Kleiton");
    insere(&raiz,"Xuxa");
    caminhamentoEmOrdem(raiz);
    printf("\t\t caminhamento em ordem \t\n");
    return 0;
}

