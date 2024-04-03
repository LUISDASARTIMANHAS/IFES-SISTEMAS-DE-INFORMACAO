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


void cadastraDisciplina(TLista *lista){
    int cargaHoraria;
    string nome;

    printf("Digite o nome da Disciplina: ");
    scanf(" %39[^\n]s", nome);
    fflush(stdin);
    printf("Digite qual e a carga horaria: ");
    scanf("%d", &cargaHoraria);
    // fflush(stdin);

    insereDisciplina(lista, nome, cargaHoraria);
}

void exibeTodasDisciplina(TLista *L){
	TDisciplina *atual = L->inicioD;
	int cont = 0;
	printf("\n\n\t\t===| EXIBE TODAS AS DISCIPLINAS |===\n\n");
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
        // cadastraCurso(listas);
        break;
    
    case 4:
        exibeCurso(listas);
        break;
    
    case 5:
        // insereAlunoEmCurso(listas);
        break;
    
    case 6:
        exibeAlunosEmCurso(listas);
        break;
    
    case 7:
        // exibeTodosAlunos(listas);
        break;
    
    case 8:
        // insereHistorico(listas);
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
    insereDisciplina(lista, "Prog1",60);  
    insereDisciplina(lista, "Math",90);  
    insereDisciplina(lista, "ED",30);  
    insereDisciplina(lista, "POO",60);   
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
