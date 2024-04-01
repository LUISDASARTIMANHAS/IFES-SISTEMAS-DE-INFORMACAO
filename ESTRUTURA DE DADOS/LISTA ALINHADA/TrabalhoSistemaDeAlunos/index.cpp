// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/* 
  Tarefa Avaliativa (Semana 08).
  implementação de uma lista encadeada aninhada.
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

TLista listas;




void insereDisciplina(TLista *lista, string Disciplina, int cargaHoraria){
    int inseriu = 0;
    TDisciplina *novo = (TDisciplina *)malloc(sizeof(TDisciplina));
    novo->cargaHoraria = cargaHoraria;
	strcpy(novo->nome, Disciplina);
   
    novo->prox = NULL;
    if (lista->inicioD == NULL){
        //Lista encontra-se vazia.
        //Inserir o primeiro e unico elemento da lista ate agora
        lista->inicioD = novo;
        lista->fimD = novo;
        lista->total = 1;
        inseriu = 1;
    }else{
        //Lista ja possui pelo menos 1 elemento
        TDisciplina *atual = lista->inicioD;
        TDisciplina *anterior = NULL;
        while (atual != NULL){
            if (strcmp(atual->nome,novo->nome) == 1){
                if (atual == lista->inicioD){
                    //Inserir novo no inicio da lista
                    novo->prox = atual;
                    lista->inicioD = novo;
                }else{
                    //Inserir novo no meio da lista
                    novo->prox = atual;
                    anterior->prox = novo;
                }
                inseriu = 1;
                lista->total++;
                break;
            }
            anterior = atual;
            atual = atual->prox; //move para o próximo elemento
        }
        if (!inseriu){
            //Inserir elemento no fim da lista
            lista->fimD->prox = novo;
            lista->fimD = novo;
            lista->total++;
        }
        lista->total++;
    }
}

void cadastraDisciplina(TLista *lista){
    int cargaHoraria;
    string nome;

    printf("Digite o nome da Disciplina: ");
    scanf(" %39[^\n]s", nome);
    fflush(stdin);
    printf("Digite qual e a carga horaria: ");
    scanf("%d", cargaHoraria);
    // fflush(stdin);

    insereDisciplina(lista, nome, cargaHoraria);
}

void exibeDisciplina(TLista *L){
	TDisciplina *atual = L->inicioD;
	int cont = 0;
	printf("\n\n\t\t===| EXIBE LISTA COMPLETA |===\n\n");
	while (atual != NULL){
		printf("(%d) - %s - %dH.\n",cont+1, atual->nome, atual->cargaHoraria);
		atual = atual->prox;
        cont++;
	}
	printf("\n\n");
}

void realizaOpcaoDesejada(TLista *listas, int op){
    switch (op){
    case 1:
        cadastraDisciplina(listas);
        break;
    
    case 2:
        exibeDisciplina(listas);
        break;
    
    case 3:
        // exibeTodasDisciplina(listas);
        break;
    
    case 4:
        // cadastraCurso(listas);
        break;
    
    case 5:
        // exibeTodosCursos(listas);
        break;
    
    case 6:
        // insereAlunoEmCurso(listas);
        break;
    
    case 7:
        // exibeTodosAlunos(listas);
        break;
    
    case 8:
        // insereDisciplina(listas);
        break;
    
    case 9:
        // insereDisciplina(listas);
        break;
    
    case 10:
        // insereDisciplina(listas);
        break;
    
    default:
        printf("\nERRO: Opção invalida, tente novamente\n");
        break;
    }
}

void inicializa(TLista *lista){
    lista->inicioC = NULL;
    lista->inicioD = NULL;
    lista->fimC = NULL;
    lista->fimD = NULL;
    lista->total = 0;
    insereDisciplina(lista, "Prog",30);   
}
//===================================================================
int main(){
    inicializa(&listas);
    int op;
    int sair = 0;
    do{
        op = menu();
        if (op == 0){
            sair = 1;
        }else if ((op < 0)||(op > 10)){
            printf("\nERRO: Opção invalida, tente novamente\n");
        }else{
            realizaOpcaoDesejada(&listas, op);
        }
    } while (sair != 1);
    return 0;
}
