#include <stdio.h>
#include <stdlib.h>
#include "projetoTabela.h"

//Feito por: Lucas Garcia de Souza

//=================================================
FILE * abrirArquivo(char * nomeArq, char * modo) {
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf("ERRO ao abrir o arquivo.");
        exit(-1);
    }
    return arq;
}
//=================================================
void construirListaDoZero(TLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->total = 0;
}
//=================================================
void lerArquivo(TLista *lista, FILE *arquivoLista) {
    int matricula;
    while (fscanf(arquivoLista, "%d", &matricula) != EOF) {
        inserir(lista, matricula);
    }
}
//=================================================
void inicializa(TLista *lista, FILE *arquivoLista) {
    construirListaDoZero(lista);
    fseek(arquivoLista, 0, SEEK_END);
    long tamanho = ftell(arquivoLista);
    if (tamanho != 0) {
        fseek(arquivoLista, 0, SEEK_SET);  
        lerArquivo(lista, arquivoLista);
    }
}
//=================================================
void gravarListaEmArquivo(TLista *lista, FILE *arquivoLista) {
    arquivoLista = abrirArquivo("lista_matricula.txt", "w");
    TElemento *atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivoLista, "%d\n", atual->valor);
        atual = atual->prox;
    }
    fclose(arquivoLista);
}
//=================================================
int pesquisarMatricula2(TLista *lista, int matriculaBusca) {
    TElemento *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == matriculaBusca) {
            printf("Matrícula %d encontrada na lista.\n", matriculaBusca);
            return 1; // Retorna 1 se encontrar a matrícula
        }
        atual = atual->prox;
    }
    printf("Matrícula %d não encontrada na lista.\n", matriculaBusca);
    return 0; // Retorna 0 se não encontrar a matrícula
}

//=================================================
int pesquisarMatricula(TLista *lista) {
    int matriculaBusca;
    printf("Digite a matrícula que deseja buscar: ");
    scanf("%d", &matriculaBusca);
    TElemento *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == matriculaBusca) {
            return matriculaBusca;
        }
        atual = atual->prox;
    }
    printf("Matrícula %d não encontrada na lista.\n", matriculaBusca);
}
//=================================================
void inserir(TLista *lista, int valor){
    TElemento *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return; // Se já existir, a função termina sem inserir
        }
        atual = atual->prox;
    }
    // Se a matrícula não existir, procede com a inserção
    TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
    novo->valor = valor;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        // Lista encontra-se vazia.
        // Inserir o primeiro e único elemento da lista até agora
        lista->inicio = novo;
        lista->fim = novo;
        lista->total = 1;
    } else {
        // Lista já possui pelo menos 1 elemento
        TElemento *anterior = NULL;
        atual = lista->inicio;
        while (atual != NULL) {
            if (atual->valor >= novo->valor) {
                if (anterior == NULL) {
                    // Inserir novo antes do primeiro da lista
                    novo->prox = atual;
                    lista->inicio = novo;
                } else {
                    // Inserir no meio da lista
                    novo->prox = atual;
                    anterior->prox = novo;
                }
                lista->total++;
                return; // Insere e termina a função
            }
            anterior = atual;
            atual = atual->prox; // move para o próximo elemento
        }
        // Inserir elemento no fim da lista
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->total++;
    }
}
//=================================================
void exibeLista(TLista lista){
    TElemento *atual = lista.inicio;
    int cont = 0;
    printf("\n\n\n\t\t===| EXIBE LISTA COMPLETA |===\n\n");
    while (atual != NULL){
        printf("\n%s\n", RESULTADO);
        printf("Numero do %d da lista e: (%d)\n", ++cont, atual->valor);
        atual = atual->prox;
    }
    printf("%s\n", CORTE);

}
//=================================================
void excluirLista(TLista *lista, int valor){
    TElemento *atual = lista->inicio;
    TElemento *anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            // Encontra o elemento a ser excluído
            if (atual == lista->inicio) {
                // Exclusão do primeiro elemento da lista
                printf("\n\n\tExcluindo o ELEMENTO %d ...\n", atual->valor);
                lista->inicio = atual->prox;
                if (lista->inicio == NULL) {
                    // A lista tinha apenas um elemento
                    lista->fim = NULL;
                }
            } else if (atual == lista->fim) {
                // Exclusão do último elemento da lista
                printf("\n\n\tExcluindo o ELEMENTO %d ...\n", atual->valor);
                lista->fim = anterior;
                lista->fim->prox = NULL;
            } else {
                // Exclusão de um elemento do meio da lista
                printf("\n\n\tExcluindo o ELEMENTO %d ...\n", atual->valor);
                anterior->prox = atual->prox;
            }
            free(atual);
            lista->total--;
            return; // Sai da função após excluir o elemento
        }
        anterior = atual;
        atual = atual->prox; // move para o próximo elemento
    }
    printf("Elemento %d não encontrado na lista.\n", valor);
}
//=================================================
int pedirOpcao(){
    int op;
    printf("\n%s\n", INICIO);
    do{
        printf("1 - Inserir na Lista\n");
        printf("2 - Exibe Lista\n");
        printf("3 - Excluir da Lista\n");
        printf("4 - Pesquisar Matricula\n");
        printf("5 - Total de Matriculas\n");
        printf("6 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);
        printf("%s\n", CORTE);
    } while ((op < 1)||(op > 6));
    return op;
}
//=================================================
int pedirNum(int caminhoASerEscolhido){
    int num;
    if (caminhoASerEscolhido == 0){
        printf("Digite um numero para ser inserido: ");
        scanf("%d", &num);
    }else{
        printf("Digite um numero para ser excluido: ");
        scanf("%d", &num);
    }
    return num;
}
//================================================
void menuPrincipal(TLista *listaEncadeada){
    int op, numInseri;
    int repete = 0;
    do{
        op = pedirOpcao();
        switch (op){
        case 1:
            numInseri = pedirNum(0);
            inserir(listaEncadeada,numInseri);
            break;
        case 2:
            exibeLista(*listaEncadeada);
            break;
        case 3:
            numInseri = pedirNum(1);
            excluirLista(listaEncadeada,numInseri);
            break;
        case 4:
            int matriculaBusca = pesquisarMatricula(listaEncadeada);
            printf("Matrícula %d encontrada na lista.\n", matriculaBusca);
            break;
        case 5:
            printf("O total de matriculas presente na lista e: %d\n", listaEncadeada->total);
            break;
        case 6:
            repete = 1;
            break;
        default:
            break;
        }
    } while (repete == 0);
}
//================================================
int main(){
    FILE *arquivoLista = abrirArquivo("lista_matricula.txt","r");
    TLista listaEncadeada;
    inicializa(&listaEncadeada,arquivoLista);
    menuPrincipal(&listaEncadeada);
    gravarListaEmArquivo(&listaEncadeada,arquivoLista);
    fclose(arquivoLista);
    return 0;
}
