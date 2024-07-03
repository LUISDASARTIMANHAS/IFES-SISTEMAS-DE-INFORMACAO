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
void inicializa(TNo **raiz, char *nome){
    *raiz = criaNo(nome,NULL);
}
//===============================================================
TNo *criaNo(char *nome, TNo **raiz){
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    strcpy(novo->nome,nome);
    
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
//===============================================================
void insere(TNo **raiz, char *nome){
    if(*raiz == NULL){
        // arvore vazia
        // printf("Primeiro no da arvore\n");
        *raiz = criaNo(nome,raiz);
    }else if (strc >= (*raiz)->valor){
        // insere na direita
        if ((*raiz)->dir == NULL){
            (*raiz)->dir = criaNo(valor);
            // printf("Foi inserido na direita\n");
        }else{
            // printf("chama a funçao para a direita\n");
            insere(&(*raiz)->dir,valor);
        }   
    }else{
        // insere na esquerda
        if ((*raiz)->esq == NULL){
            // printf("Foi inserido na esquerda\n");
            (*raiz)->esq = criaNo(valor);
        }else{
            // printf("chama a funçao para a esquerda\n");
            insere(&(*raiz)->esq,valor);
        }
    }   
}
//===============================================================
void caminhamentoEmOrdem(TNo *raiz){
    if(raiz != NULL){
        caminhamentoEmOrdem(raiz->esq);
        printf("%d, ",raiz->valor);
        caminhamentoEmOrdem(raiz->dir);
    }    
}
//===============================================================
void caminhamentoPreOrdem(TNo *raiz){
    if(raiz != NULL){
        printf("%d, ",raiz->valor);
        caminhamentoPreOrdem(raiz->esq);
        caminhamentoPreOrdem(raiz->dir);
    }   
}
//===============================================================
void caminhamentoPosOrdem(TNo *raiz){
    if(raiz != NULL){
        caminhamentoPosOrdem(raiz->esq);
        caminhamentoPosOrdem(raiz->dir);
        printf("%d, ",raiz->valor);
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
        printf("Visitando %d e descendo na direita\n", raiz->valor);
        return busca(raiz->dir,argumento);
    }else{
        printf("Visitando %d e descendo na esquerda\n", raiz->valor);
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
    insere(&raiz,);
    insere(&raiz,);
    insere(&raiz,);
    insere(&raiz,);
    insere(&raiz,);
    insere(&raiz,);
    insere(&raiz,);
    caminhamentoEmOrdem(raiz);
    printf("\t\t caminhamento em ordem \t\n");
    // caminhamentoPreOrdem(raiz);
    // printf("\t\t caminhamento pre ordem \t\n");
    // caminhamentoPosOrdem(raiz);
    // printf("\t\t caminhamento pos ordem \t\n");
    // printf("\n\n\t Buscando No com o valor 92\t\n\n");
    TNo*atual = busca(raiz,92);
    // if (atual != NULL){
    //     printf("Encontrado: %d \n", atual->valor);
    // }else{
    //     printf("Valor nao encontrado: \n");
    // }
    printf("\n\n\t Excluindo o valor 41\t\n\n");
    atual = exclui(&raiz,41);
    caminhamentoEmOrdem(raiz);
    printf("\n\n\t Excluindo o valor 32 \t\n\n");
    atual = exclui(&raiz,32);
    caminhamentoEmOrdem(raiz);
    return 0;
}
