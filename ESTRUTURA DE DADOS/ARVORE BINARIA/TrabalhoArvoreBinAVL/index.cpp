// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/*
     BINARIA AVL
    balanceamento -2 ou maior que 2 esta desbalanceada
    algoritimo de insercção faz ajustes para manter o balanceamento 
    apenas movendo a raiz pode ser que balanceie a arvore
    vasculhar o proximo nivel para ver se esta balanceado

    Processo de inserção na AVL
A inserção em uma árvore AVL é similar à inserção em uma árvore binária de busca.  Depois de inserir um elemento, no entanto, você precisa ajustar as propriedades da AVL utilizando rotações para esquerda ou para a direita:

Se houver um desbalanceamento na subárvore da direita do filho da esquerda do nó, faça uma rotação dupla à direita.
Se houver um desbalanceamento na subárvore da esquerda do filho da esquerda do nó, faça uma rotação simples à direita.
Se houver um desbalanceamento na subárvore da direita do filho da direita do nó, faça uma rotação simples à esquerda.
Se houver um desbalanceamento  na subárvore da esquerda do filho da direita do nó, faça uma rotação dupla à esquerda.  
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

TNo *raiz;

void inicializa(TNo **R){
    int op;
    string user;

    raiz = criaNoAVL("Zilian",raiz);
    raiz = insereAVL(raiz,"Astolfo");
    raiz = insereAVL(raiz,"Julia");
    raiz = insereAVL(raiz,"Anakin");
    raiz = insereAVL(raiz,"Jack");
    raiz = insereAVL(raiz,"Ortencio");
    raiz = insereAVL(raiz,"Kleiton");
    raiz = insereAVL(raiz,"Xuxa");
    raiz = insereAVL(raiz,"Mephisto");
    raiz = insereAVL(raiz,"Soul");
    raiz = insereAVL(raiz,"Bob");
    raiz = insereAVL(raiz,"Ruben");
    raiz = insereAVL(raiz,"Luis Augusto");
    raiz = insereAVL(raiz,"Lucas Garcia");
    raiz = insereAVL(raiz,"End");

    printf("\n\t\t caminhamento em ordem \t\n");
    caminhamentoEmOrdemAVL(raiz);
    printf("\n\nImpressão da árvore com antecedente e profundidade:\n");

    system("PAUSE");
    raiz = excluiAVL(raiz, "Ortencio");

    caminhamentoEmOrdemAVL(raiz);

    printf("\n\n\t\t caminhamento em ordem após exclusão de Ortencio \t\n");
    printf("\nImpressão da árvore com antecedente e profundidade após exclusão:\n");
    criaTabelaImpressaArvore(raiz);
    system("PAUSE");

    do{
        op = menu();
    switch (op){
        case 1:
        // Inserir
        criaTabelaImpressaArvore(raiz);
        printf("\n Insira um nome de Usuario: ");
        inputS(user);
        raiz = insereAVL(raiz,user);
        system("PAUSE");
        break;
        case 2:
        // Exluir
        criaTabelaImpressaArvore(raiz);
        printf("\n Insira um nome de Usuario: ");
        inputS(user);
        raiz = excluiAVL(raiz, user);
        break;
        case 3:
        // Listar
        criaTabelaImpressaArvore(raiz);
        system("PAUSE");
        break;
        case 4:
        // pre ordem
        printf("\n\t\t caminhamento em pre ordem \t\n");
        caminhamentoPreOrdem(raiz);
        criaTabelaImpressaArvore(raiz);
        system("PAUSE");
        break;
        case 5:
        // em ordem
        printf("\n\t\t caminhamento em ordem \t\n");
        caminhamentoEmOrdemAVL(raiz);
        criaTabelaImpressaArvore(raiz);
        system("PAUSE");
        break;
        case 6:
        // pos ordem
        printf("\n\t\t caminhamento em pos ordem \t\n");
        caminhamentoPosOrdem(raiz);
        criaTabelaImpressaArvore(raiz);
        system("PAUSE");
        break;
    default:
        printf("\nSaindo do programa e encerrando a aplicacao\n");
        break;
    }
    } while (op != 0);
}

//===| Programa Principal |===========================
int main(){
	SetConsoleOutputCP(65001);
	inicializa(&raiz);
}
