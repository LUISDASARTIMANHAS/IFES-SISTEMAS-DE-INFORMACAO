#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo {
    char nome[100];
    int valor;
    struct tipoNo *esq;
    struct tipoNo *dir;
    struct tipoNo *raiz;
    int nivelProfundidade;
} TNo;

TNo *raiz; // raiz inicial da arvore
//======================================================================
int altura(TNo *N) {
    if (N == NULL)
        return 0;
    return N->nivelProfundidade;
}
//======================================================================
int max(int a, int b) {
    return (a > b) ? a : b;
}
//======================================================================
TNo *criaNo(char *nome, TNo *raiz) {
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    strcpy(novo->nome, nome);
    novo->nivelProfundidade = 1;
    novo->raiz = raiz;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
//======================================================================
void inicializa(TNo **raiz, char *nome) {
    *raiz = criaNo(nome, NULL);
}
//======================================================================
TNo *rotacaoDireita(TNo *y) {
    TNo *x = y->esq;
    TNo *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    if (T2 != NULL)
        T2->raiz = y;

    x->raiz = y->raiz;
    y->raiz = x;

    y->nivelProfundidade = max(altura(y->esq), altura(y->dir)) + 1;
    x->nivelProfundidade = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}
//======================================================================
TNo *rotacaoEsquerda(TNo *x) {
    TNo *y = x->dir;
    TNo *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    if (T2 != NULL)
        T2->raiz = x;

    y->raiz = x->raiz;
    x->raiz = y;

    x->nivelProfundidade = max(altura(x->esq), altura(x->dir)) + 1;
    y->nivelProfundidade = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}
//======================================================================
int getBalanco(TNo *N) {
    if (N == NULL)
        return 0;
    return altura(N->esq) - altura(N->dir);
}
//======================================================================
TNo *insere(TNo *no, char *nome) {
    if (no == NULL)
        return criaNo(nome, no);

    if (strcmp(nome, no->nome) < 0) {
        no->esq = insere(no->esq, nome);
        no->esq->raiz = no;
    } else if (strcmp(nome, no->nome) > 0) {
        no->dir = insere(no->dir, nome);
        no->dir->raiz = no;
    } else {
        return no;
    }

    no->nivelProfundidade = 1 + max(altura(no->esq), altura(no->dir));

    int balanco = getBalanco(no);

    if (balanco > 1 && strcmp(nome, no->esq->nome) < 0)
        return rotacaoDireita(no);

    if (balanco < -1 && strcmp(nome, no->dir->nome) > 0)
        return rotacaoEsquerda(no);

    if (balanco > 1 && strcmp(nome, no->esq->nome) > 0) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    if (balanco < -1 && strcmp(nome, no->dir->nome) < 0) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}
//======================================================================
TNo *minValueNode(TNo *no) {
    TNo *atual = no;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}
//======================================================================
TNo *exclui(TNo *no, char *nome) {
    if (no == NULL)
        return no;

    if (strcmp(nome, no->nome) < 0) {
        no->esq = exclui(no->esq, nome);
    } else if (strcmp(nome, no->nome) > 0) {
        no->dir = exclui(no->dir, nome);
    } else {
        if ((no->esq == NULL) || (no->dir == NULL)) {
            TNo *temp = no->esq ? no->esq : no->dir;

            if (temp == NULL) {
                temp = no;
                no = NULL;
            } else {
                *no = *temp;
            }
            free(temp);
        } else {
            TNo *temp = minValueNode(no->dir);
            strcpy(no->nome, temp->nome);
            no->dir = exclui(no->dir, temp->nome);
        }
    }

    if (no == NULL)
        return no;

    no->nivelProfundidade = 1 + max(altura(no->esq), altura(no->dir));

    int balanco = getBalanco(no);

    if (balanco > 1 && getBalanco(no->esq) >= 0)
        return rotacaoDireita(no);

    if (balanco > 1 && getBalanco(no->esq) < 0) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    if (balanco < -1 && getBalanco(no->dir) <= 0)
        return rotacaoEsquerda(no);

    if (balanco < -1 && getBalanco(no->dir) > 0) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}
//======================================================================
void caminhamentoEmOrdem(TNo *raiz) {
    if (raiz != NULL) {
        caminhamentoEmOrdem(raiz->esq);
        printf("%s, ", raiz->nome);
        caminhamentoEmOrdem(raiz->dir);
    }
}
//======================================================================
void caminhamentoPreOrdem(TNo *raiz) {
    if (raiz != NULL) {
        printf("%s, ", raiz->nome);
        caminhamentoPreOrdem(raiz->esq);
        caminhamentoPreOrdem(raiz->dir);
    }
}
//======================================================================
void caminhamentoPosOrdem(TNo *raiz) {
    if (raiz != NULL) {
        caminhamentoPosOrdem(raiz->esq);
        caminhamentoPosOrdem(raiz->dir);
        printf("%s, ", raiz->nome);
    }
}
//======================================================================
void imprimeArvore(TNo *no) {
    if (no == NULL)
        return;

    printf("Nó: %s, Antecedente: %s, Profundidade: %d\n",
           no->nome,
           no->raiz ? no->raiz->nome : "NULL",
           no->nivelProfundidade);

    imprimeArvore(no->esq);
    imprimeArvore(no->dir);
}
//======================================================================
int main() {
    inicializa(&raiz, "Zilian");
    raiz = insere(raiz, "Asdrubal");
    raiz = insere(raiz, "Julia");
    raiz = insere(raiz, "Anakin");
    raiz = insere(raiz, "Jack");
    raiz = insere(raiz, "Ortencio");
    raiz = insere(raiz, "Kleiton");
    raiz = insere(raiz, "Xuxa");

    caminhamentoEmOrdem(raiz);
    printf("\t\t caminhamento em ordem \t\n");
    printf("Impressão da árvore com antecedente e profundidade:\n");
    imprimeArvore(raiz);

    raiz = exclui(raiz, "Ortencio");

    caminhamentoEmOrdem(raiz);
    printf("\t\t caminhamento em ordem após exclusão de Ortencio \t\n");
    printf("Impressão da árvore com antecedente e profundidade após exclusão:\n");
    imprimeArvore(raiz);

    return 0;
}
