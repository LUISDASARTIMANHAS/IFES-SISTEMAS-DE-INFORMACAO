// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/* 
  Tarefa Avaliativa (Semana 08).
  implementação de uma lista encadeada aninhada.
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functions.c>

typedef char string[40];

typedef struct tipoDisciplina {
	string nome;
	int cargaHoraria;
	tipoDisciplina *prox;
}TDisciplina;

typedef struct tipoHistorico {
	TDisciplina *disciplina;
	float nota;
	float percentualFrequencia;
	string condicao; // Aprovado, Reprovado ou Cursando.
	tipoHistorico *prox;	
}THistorico;

typedef struct tipoAluno {
	string nome;
	char sexo;
	THistorico *historico;
	tipoAluno *ante, *prox;
}TAluno;

typedef struct tipoCurso {
	string nome;
	TAluno *alunos;
	tipoCurso *ante, *prox;
}TCurso;

typedef struct tipoLista {
	TCurso *inicioC;
	TCurso *fimC;
	TDisciplina *inicioD;
	TDisciplina *fimD;
    int total;
}TLista;

TLista listas;

int menu(){
	int op;
	printf("\n\n\t\t====| MENU |=====\n\n");
	printf("\t0 - Sair (Encerrar a Aplicacao).\n\n");
	printf("\t1 - Inserir DISCIPLINA.\n");
	printf("\t2 - Exibe Todas as DISCIPLINAS.\n\n");
	printf("\t3 - Inserir CURSO.\n");
	printf("\t4 - Exibir Todos os CURSOS.\n\n");
	printf("\t5 - Inserir ALUNO em CURSO.\n");
	printf("\t6 - Exibir Todos os ALUNOS de CURSO especifico.\n");
	printf("\t7 - Excluir ALUNO de CURSO.\n\n");
	printf("\t8 - Inserir HISTORICO para ALUNO.\n");
	printf("\t9 - Exibir HISTORICO de ALUNO.\n");
	printf("\t10 - Excluir HISTORICO de ALUNO.\n\n");
	do {
		printf("Escolha sua opção: ");
		scanf(" %d", &op);
	} while(op < 0 || op > 10);
	return op;
}

void inicializa(TLista *lista){
    lista->inicioC = NULL;
    lista->inicioD = NULL;
    lista->fimC = NULL;
    lista->fimD = NULL;
    lista->total = 0;        
}

void cadastraDisciplina(TDisciplina *novo){
    printf("Digite o nome da Disciplina: ");
    scanf(" %39[^\n]s", novo->nome);
    printf("Digite qual e a carga horaria: ");
    scanf("%d", &novo->cargaHoraria);
}

void insereDisciplina(TLista *lista){
    int inseriu = 0;
    TDisciplina *novo = (TDisciplina *)malloc(sizeof(TDisciplina));
    cadastraDisciplina(novo);
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
        insereDisciplina(listas);
        break;
    
    case 2:
        exibeDisciplina(listas);
        break;
    
    case 3:
        insereDisciplina(listas);
        break;
    
    case 4:
        insereDisciplina(listas);
        break;
    
    case 5:
        insereDisciplina(listas);
        break;
    
    case 6:
        insereDisciplina(listas);
        break;
    
    case 7:
        insereDisciplina(listas);
        break;
    
    case 8:
        insereDisciplina(listas);
        break;
    
    case 9:
        insereDisciplina(listas);
        break;
    
    case 10:
        insereDisciplina(listas);
        break;
    
    default:
        break;
    }
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
