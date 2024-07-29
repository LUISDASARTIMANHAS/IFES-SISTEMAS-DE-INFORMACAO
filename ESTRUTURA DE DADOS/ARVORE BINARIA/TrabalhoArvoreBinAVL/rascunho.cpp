#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo {
    char nome[100];
    int nivelProfundidade;
    struct tipoNo *esq;
    struct tipoNo *dir;
    struct tipoNo *raiz;
} TNo;

TNo *raiz; // raiz inicial da arvore
//=============================================================================
int nivelProfundidade(TNo *N) {
    if (N == NULL) {
        return 0;
    }
    return N->nivelProfundidade;
}
//=============================================================================
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}
//=============================================================================
int getBalanco(TNo *N) {
    if (N == NULL) {
        return 0;
    }
    return nivelProfundidade(N->esq) - nivelProfundidade(N->dir);
}
//=============================================================================
TNo *criaNoAVL(char *nome, TNo *raiz) {
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    strcpy(novo->nome, nome);
    novo->nivelProfundidade = 1;
    novo->raiz = raiz;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
//=============================================================================
void inicializa(TNo **raiz, char *nome) {
    *raiz = criaNoAVL(nome, NULL);
}
//=============================================================================
TNo *rotacaoDireita(TNo *y) {
    TNo *x = y->esq;
    TNo *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    if (T2 != NULL) {
        T2->raiz = y;
    }
    x->raiz = y->raiz;
    y->raiz = x;

    y->nivelProfundidade = max(nivelProfundidade(y->esq), nivelProfundidade(y->dir)) + 1;
    x->nivelProfundidade = max(nivelProfundidade(x->esq), nivelProfundidade(x->dir)) + 1;

    return x;
}
//=============================================================================
TNo *rotacaoEsquerda(TNo *x) {
    TNo *y = x->dir;
    TNo *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    if (T2 != NULL) {
        T2->raiz = x;
    }
    y->raiz = x->raiz;
    x->raiz = y;

    x->nivelProfundidade = max(nivelProfundidade(x->esq), nivelProfundidade(x->dir)) + 1;
    y->nivelProfundidade = max(nivelProfundidade(y->esq), nivelProfundidade(y->dir)) + 1;

    return y;
}
//=============================================================================
TNo *balancearNo(TNo *no) {
    int balanco = getBalanco(no);

    if (balanco > 1) {
        if (getBalanco(no->esq) >= 0) {
            no = rotacaoDireita(no);
        } else {
            no->esq = rotacaoEsquerda(no->esq);
            no = rotacaoDireita(no);
        }
    } else if (balanco < -1) {
        if (getBalanco(no->dir) <= 0) {
            no = rotacaoEsquerda(no);
        } else {
            no->dir = rotacaoDireita(no->dir);
            no = rotacaoEsquerda(no);
        }
    }

    return no;
}
//=============================================================================
TNo *insereAVL(TNo *no, char *nome) {
    if (no == NULL) {
        return criaNoAVL(nome, no);
    }

    if (strcmp(nome, no->nome) < 0) {
        no->esq = insereAVL(no->esq, nome);
        no->esq->raiz = no;
    } else if (strcmp(nome, no->nome) > 0) {
        no->dir = insereAVL(no->dir, nome);
        no->dir->raiz = no;
    } else {
        return no;
    }

    no->nivelProfundidade = 1 + max(nivelProfundidade(no->esq), nivelProfundidade(no->dir));
    return balancearNo(no);
}
//=============================================================================
TNo *minValueNode(TNo *no) {
    TNo *atual = no;
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}
//=============================================================================
TNo *excluiAVL(TNo *no, char *nome) {
    if (no == NULL) {
        return no;
    }

    if (strcmp(nome, no->nome) < 0) {
        no->esq = excluiAVL(no->esq, nome);
    } else if (strcmp(nome, no->nome) > 0) {
        no->dir = excluiAVL(no->dir, nome);
    } else {
        if (no->esq == NULL || no->dir == NULL) {
            TNo *temp = no->esq;
            if (temp == NULL) {
                temp = no->dir;
            }

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
            no->dir = excluiAVL(no->dir, temp->nome);
        }
    }

    if (no == NULL) {
        return no;
    }

    no->nivelProfundidade = 1 + max(nivelProfundidade(no->esq), nivelProfundidade(no->dir));
    return balancearNo(no);
}
//=============================================================================
void caminhamentoEmOrdem(TNo *raiz) {
    if (raiz != NULL) {
        caminhamentoEmOrdem(raiz->esq);
        printf("%s, ", raiz->nome);
        caminhamentoEmOrdem(raiz->dir);
    }
}
//=============================================================================
void caminhamentoPreOrdem(TNo *raiz) {
    if (raiz != NULL) {
        printf("%s, ", raiz->nome);
        caminhamentoPreOrdem(raiz->esq);
        caminhamentoPreOrdem(raiz->dir);
    }
}
//=============================================================================
void caminhamentoPosOrdem(TNo *raiz) {
    if (raiz != NULL) {
        caminhamentoPosOrdem(raiz->esq);
        caminhamentoPosOrdem(raiz->dir);
        printf("%s, ", raiz->nome);
    }
}
//=============================================================================
void imprimeArvore(TNo *no) {
    if (no == NULL) {
        return;
    }

    printf("Nó: %s, Antecedente: %s, Profundidade: %d\n",
           no->nome,
           no->raiz != NULL ? no->raiz->nome : "NULL",
           no->nivelProfundidade);

    imprimeArvore(no->esq);
    imprimeArvore(no->dir);
}
//=============================================================================
int main() {
    inicializa(&raiz, "Zilian");
    raiz = insereAVL(raiz, "Asdrubal");
    raiz = insereAVL(raiz, "Julia");
    raiz = insereAVL(raiz, "Anakin");
    raiz = insereAVL(raiz, "Jack");
    raiz = insereAVL(raiz, "Ortencio");
    raiz = insereAVL(raiz, "Kleiton");
    raiz = insereAVL(raiz, "Xuxa");

    caminhamentoEmOrdem(raiz);
    printf("\t\t caminhamento em ordem \t\n");
    printf("Impressão da árvore com antecedente e profundidade:\n");
    imprimeArvore(raiz);

    raiz = excluiAVL(raiz, "Ortencio");

    caminhamentoEmOrdem(raiz);
    printf("\t\t caminhamento em ordem após exclusão de Ortencio \t\n");
    printf("Impressão da árvore com antecedente e profundidade após exclusão:\n");
    imprimeArvore(raiz);

    return 0;
}
