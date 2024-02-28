#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// #include "functions.c"

typedef char string[40];

typedef struct tipoElemento {
    float idade;
    float altura;
    float peso;
	string nome;
    float imc;
    int grupo;
    int centroide;
    tipoElemento *prox;
}TElemento;

typedef struct tipoLista{
    TElemento *inicio;
    TElemento *fim;
    int total;
    int k;
}TLista;

TLista lista; //vari�vel global
void inicializa(TLista *L);
void insere(TLista *L, float idade, float altura, float peso, string nome);
void escolheCentroides(TLista *L);
void exibe(TLista L);

int main(){
    inicializa(&lista);
}

void inicializa(TLista *L){
    L->inicio = NULL;
    L->fim = NULL;
    L->total = 0;

    printf("\n\n\t Informe a quantidade de Grupos: ");
    scanf("%d", &L->k);

    insere(L,23,1.8,81,"Pedro");
    insere(L,21,1.76,67,"Anna");
    insere(L,21,1.72,61,"Cinthia");
    insere(L,17,1.72,72,"Jose");
    insere(L,35,1.77,96,"Silvano");
    insere(L,28,1.68,69,"Evelyn");
    insere(L,56,1.77,94,"Asdrubal");
    insere(L,35,175,85,"Jambira");
    insere(L,20,1.65,100,"Desideiro");
    insere(L,46,1.82,102,"Ramiro");
    insere(L,38,1.70,65,"Paula");
    insere(L,39,1.65,68,"Claudia");
    insere(L,18,1.66,65,"Sofia");
    insere(L,58,1.86,99,"Astolfo");
    insere(L,52,1.80,120,"Demostenes");
    insere(L,28,1.68,69,"Josefino");
}

void insere(TLista *L, float idade, float altura, float peso, string nome){
    TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
    novo->idade = idade;
    novo->grupo = -1;
    novo->altura = altura;
    novo->peso = peso;
    novo->imc = (peso/(altura*altura));
    novo->prox = NULL;
    strcpy(novo->nome,nome);
    novo->centroide = 0;

    if (L->inicio == NULL){
        L->inicio = novo;
        L->inicio = novo;
        L->fim = novo;
    }else{
        TElemento *atual = L->inicio;
        TElemento *anterior = NULL;
        int inserido = 0;

        while (atual != NULL){
        if(strcmp(atual->nome, novo->nome) == 1){

            if(atual == L->inicio){
                novo->prox = atual;
                L->inicio = novo;
            }else{
                novo->prox = atual;
                anterior->prox = novo;
            }
            anterior = atual;
            atual = atual->prox;
        }
        inserido = 1;
        break;
    }

    if (!inserido){
        L->fim->prox = novo;
        L->fim = novo;
    }
        // ordenar(L,&inserido);

    }

}

void exibe(TLista L){
    TElemento *atual = L.inicio;
    int cont = 0;

    printf("\t");
    while (atual != NULL){
        if(atual->grupo == -1){
			printf("\t(%d) - %s : %.2f ... SEM GRUPO.\n", ++cont, atual->nome, atual->imc);
		} else {
			printf("\t(%d) - %s : %.2f ... GRUPO: %d\n", ++cont, atual->nome, atual->imc, atual->grupo);
		}//if
        atual = atual->prox;
    }
}

void escolheCentroides(TLista *L){
    int gruposPercorridos = 0;
    int listaPercoriida = 1;
    int ramdomNum = 1;
    TElemento *atual = L->inicio;

   //Função que escolhe randomicamente um centroide para cada grupo.
   //O usuário-final define a quantidade de grupos existentes (k) durante a execução
   //do programa.
   //Esta função sorteia um TElemento para Centróide de cada grupo.

    // repetir N vezes grupos
    while(gruposPercorridos <= L->k){
    // percorrer lista
    while ((atual != NULL) && (ramdomNum == listaPercoriida)){
        atual->centroide = gruposPercorridos;

        atual = atual->prox;
    }
}
}

// void ordenar(TLista *L,int *inserido){
//     while (atual != NULL){
//         if(strcmp(atual->nome, novo->nome) == 1){

//             if(atual == L->inicio){
//                 novo->prox = atual;
//                 L->inicio = novo;
//             }else{
//                 novo->prox = atual;
//                 anterior->prox = novo;
//             }
//             anterior = atual;
//             atual = atual->prox;
//         }
//         *inserido = 1;
//         break;
//     }

//     if (!inserido){
//         L->fim->prox = novo;
//         L->fim = novo;
//     }
// }