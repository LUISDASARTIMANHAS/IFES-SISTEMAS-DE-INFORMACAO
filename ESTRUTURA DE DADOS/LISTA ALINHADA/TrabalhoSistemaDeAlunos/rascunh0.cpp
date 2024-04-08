// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA


// ==================== functions.c ========================== 
// ==================== functions.c ========================== 
// ==================== functions.c ========================== 
// ============================= BASE ======================
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// #include "utils.c"
// Defina constantes para as sequências de escape ANSI das cores

// RED ERROR
#define RED "\x1b[31m"
// BLUE SISTEMA
#define BLUE "\x1b[34m"
// GREEN OK 
#define GREEN "\x1b[32m"
// YELLOW PERGUNTAS
#define YELLOW "\x1b[33m"
// RESET REDEFINIR
#define RESET "\x1b[0m"
#define SEPARETOR BLUE "\n================================================\n"  RESET

typedef char string[101];

typedef struct ClassDatabaseTipoDisciplina {
	string nome;
	int cargaHoraria;
	ClassDatabaseTipoDisciplina *prox;
}TDisciplina;

typedef struct ClassDatabaseTipoHistorico {
	TDisciplina *disciplina;
	float nota;
	float percentualFrequencia;
	string condicao; // Aprovado, Reprovado ou Cursando.
	ClassDatabaseTipoHistorico *prox;	
}THistorico;

typedef struct ClassDatabaseTipoAluno {
    string nome;
	char sexo;
	THistorico *historico;
	ClassDatabaseTipoAluno *ante, *prox;
}TAluno;

typedef struct ClassDatabaseTipoCurso {
    string nome;
	TAluno *alunos;
	ClassDatabaseTipoCurso *ante, *prox;
}TCurso;

typedef struct ClassDatabaseTipoLista {
    TCurso *inicioC;
    TCurso *fimC;
    TDisciplina *inicioD;
    TDisciplina *fimD;
	int total;
}TLista;


// ============================= FIM DO BASE ======================
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


void insereDisciplina(TLista *lista, string nome, int cargaHoraria){
    int inseriu = 0;
    TDisciplina *novo = (TDisciplina *)malloc(sizeof(TDisciplina));
    novo->cargaHoraria = cargaHoraria;
	strcpy(novo->nome, nome);
   
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
    printf("\n\t Disciplina  %s Inserida!", nome);
}


void insereCurso(TLista *lista, string nome){
    TCurso *novo = (TCurso *)malloc(sizeof(TCurso));
    TCurso *atual;
    int flag = 0;
    novo->prox = NULL;
    novo->ante = NULL;
    if (lista->inicioC == NULL){
        //Lista encontra-se vazia.
        //Inserir o primeiro e unico elemento da lista ate agora
        lista->inicioC = novo;
        lista->fimC = novo;
        flag = 1;
    }else{
        //Lista ja possui pelo menos 1 elemento
        atual = lista->inicioC;
        while (atual != NULL){
            if (strcmp(atual->nome,novo->nome) > 0){
                //encontrada a posiçao para a inserçao do novo Tfilme
                flag = 1;
                
                if (atual == lista->inicioC){
                    //Inserir novo no inicio da lista
                    novo->prox = atual;
                    atual->ante = novo;
                    lista->inicioC = novo;
                }else{
                    //Inserir novo no meio da lista
                    novo->prox = atual;
                    novo->ante = atual->ante;
                    atual->ante->prox = novo;
                    atual->ante = novo;
                }
                break;
            }
            atual = atual->prox; //move para o próximo elemento
        }
        if (flag == 0){
            //inserir o novo como o ultimo Tfilme da lista
            lista->fimC->prox = novo;
            novo->ante = lista->fimC;
            lista->fimC = novo;
        }
    }
    lista->total++;
	printf("\n\t Curso  %s Inserido!", nome);
}

TCurso *localizaCurso(TLista *lista, string titulo){
	TCurso *atual = lista->inicioC;
	
	while (atual != NULL){
		if(strcmp(atual->nome, titulo) == 0){
			break;
		}//if
		atual = atual->prox;
	}//while
	return atual;
}

// ================ EXIBES =============== 

void exibeDisciplina(TLista *lista){
	TDisciplina *atual = lista->inicioD;
	int cont = 0;
	printf("\n\n\t\t===| EXIBE TODAS AS DISCIPLINAS |===\n\n");
	while (atual != NULL){
		printf("(%d) - %s - %dH.\n",cont+1, atual->nome, atual->cargaHoraria);
		atual = atual->prox;
        cont++;
	}
	printf("\n\n");
}

void exibeCurso(TLista *lista){
   TCurso *atual = lista->inicioC;
	int cont = 0;
	printf("\n\n\t\t===| EXIBE TODOS OS CURSOS |===\n\n");
	while (atual != NULL){
		printf("(%d) - %s.\n",cont+1,atual->nome );
		atual = atual->prox;
        cont++;
	}
	printf("\n\n"); 
}

void exibeAlunosEmCurso(TLista *lista){
	int cont = 0;
	TCurso *curso;
	TAluno *aluno = curso->alunos;
	string nome;
	
	printf("\n\n\t\t===| EXIBE TODOS OS ALUNOS EM UM CURSO |===\n\n");
	printf("\tInforme o NOME do CURSO: ");

	scanf(" %39[^\n]s", nome);
	fflush(stdin);
	
	curso = localizaCurso(lista, nome);
	
	if(curso == NULL){
		printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\tCURSO: %s.\n\n",curso->nome);
		system("PAUSE");
	} else {
		printf("O CURSO %s tem os seguintes ALUNOS matriculados", curso->nome);
		while (aluno->prox != NULL){
			printf("(%d) - %s - %s.\n",cont+1,aluno->nome, aluno->sexo );
			aluno = aluno->prox;
			cont++;
		}
	}
	printf("\n\n"); 
}


// ==================== functions.c ========================== 
// ==================== functions.c ========================== 
// ==================== functions.c ========================== 

// =============== INDEX.cpp ======================
// =============== INDEX.cpp ======================
// =============== INDEX.cpp ======================

TLista listas;


void cadastraDisciplina(TLista *lista){
    int cargaHoraria;
    string nome;

    printf("Digite o nome da Disciplina: ");
    scanf(" %39[^\n]s", nome);
    fflush(stdin);
    printf("Digite qual e a carga horaria: ");
    scanf("%d", &cargaHoraria);
    fflush(stdin);

    insereDisciplina(lista, nome, cargaHoraria);
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

    exibeDisciplina(lista);
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

// =============== INDEX.cpp ======================
// =============== INDEX.cpp ======================
// =============== INDEX.cpp ======================

/* 
  Tarefa Avaliativa (Semana 08).
  implementação de uma lista encadeada aninhada.
  
*/
/* 
  Tarefa Avaliativa (Semana 08).
  implementação de uma lista encadeada aninhada.
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void insereDisciplina(TLista *lista, string nome, int cargaHoraria){
    int inseriu = 0;
    TDisciplina *novo = (TDisciplina *)malloc(sizeof(TDisciplina));
    novo->cargaHoraria = cargaHoraria;
    strcpy(novo->nome,nome);
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

TDisciplina *defineHisitorico(TLista *lista, string nome){
	TDisciplina *atual = L->inicioD;
	while(atual != NULL)	{
		if(strcmp(atual->nome, nome) == 0) {
			break;
		}//if
		atual = atual->prox;
	}//while
	return atual;
}

TDisciplina *pesquisarDisciplina(string nome){
	
}

void insereHistorico(TAluno *aluno, THistorico *historico){
	string nomeDisci;
	printf("Digite o nome da disciplina: ");
	scanf(" %39[^\n]s", nomeDisci);
	historico->disciplina = pesquisarDisciplina(nomeDisci);
	printf("Digite a nota que o aluno teve nessa disciplina: ");
	scanf("%f", &historico->nota);
	printf("Digite o percentual de presença que o aluno teve nessa disciplina: ");
	scanf("%f", &historico->percentualFrequencia);
	printf("Digite a condiçao que esse aluno esta nessa disciplina(Aprovado/Reprovado/Cursando): ");
	scanf(" %39[^\n]s", historico->condicao);
}

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
	insereDisciplina(lista,"Prog I",90); 
	insereDisciplina(lista,"Prog II",90);
	insereDisciplina(lista,"ED",60);
	insereDisciplina(lista,"OAC",60);
	insereDisciplina(lista,"Adm Financeira",60);
	insereDisciplina(lista,"Redes",60);
	insereDisciplina(lista,"SO",60);     
	
	insereHistorico(lista,);
}

void cadastraDisciplina(TLista *lista){
	string nome;
	int cargahoraria;
    printf("Digite o nome da Disciplina: ");
    scanf(" %39[^\n]s", nome);
    printf("Digite qual e a carga horaria: ");
    scanf("%d", &cargahoraria);
    insereDisciplina(lista,nome,cargahoraria);
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

/*void insereAluno(string curso, string nomeAluno, char sexo){
    TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
    TAluno *atual;
    int flag = 0;

    novo->prox = NULL;
    novo->ante = NULL;
    if (lista->primeiro == NULL){
        //Lista encontra-se vazia.
        //Inserir o primeiro e unico elemento da lista ate agora
        lista->primeiro = novo;
        lista->ultimo = novo;
        flag = 1;
    }else{
        //Lista ja possui pelo menos 1 elemento
        atual = lista->primeiro;
        while (atual != NULL){
            if (strcmp(atual->nome,novo->nome) > 0){
                //encontrada a posiçao para a inserçao do novo Tfilme
                flag = 1;
                
                if (atual == lista->primeiro){
                    //Inserir novo no inicio da lista
                    novo->prox = atual;
                    atual->ante = novo;
                    lista->primeiro = novo;
                }else{
                    //Inserir novo no meio da lista
                    novo->prox = atual;
                    novo->ante = atual->ante;
                    atual->ante->prox = novo;
                    atual->ante = novo;
                }
                break;
            }
            atual = atual->prox; //move para o próximo elemento
        }
        if (flag == 0){
            //inserir o novo como o ultimo Tfilme da lista
            lista->ultimo->prox = novo;
            novo->ante = lista->ultimo;
            lista->ultimo = novo;
        }
    }
    lista->total++;
}*/



void insereCurso(TLista *lista, string nome){
    TCurso *novo = (TCurso *)malloc(sizeof(TCurso));
    TCurso *atual;
    int flag = 0;
    ////inserir dados
    // insereAlunosNoCurso();
    novo->prox = NULL;
    novo->ante = NULL;
    if (lista->inicioC == NULL){
        //Lista encontra-se vazia.
        //Inserir o primeiro e unico elemento da lista ate agora
        lista->inicioC = novo;
        lista->fimC = novo;
        flag = 1;
    }else{
        //Lista ja possui pelo menos 1 elemento
        atual = lista->inicioC;
        while (atual != NULL){
            if (strcmp(atual->nome,novo->nome) > 0){
                //encontrada a posiçao para a inserçao do novo Tfilme
                flag = 1;
                
                if (atual == lista->inicioC){
                    //Inserir novo no inicio da lista
                    novo->prox = atual;
                    atual->ante = novo;
                    lista->inicioC = novo;
                }else{
                    //Inserir novo no meio da lista
                    novo->prox = atual;
                    novo->ante = atual->ante;
                    atual->ante->prox = novo;
                    atual->ante = novo;
                }
                break;
            }
            atual = atual->prox; //move para o próximo elemento
        }
        if (flag == 0){
            //inserir o novo como o ultimo Tfilme da lista
            lista->fimC->prox = novo;
            novo->ante = lista->fimC;
            lista->fimC = novo;
        }
    }
    lista->total++;
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
        //insereDisciplina(listas);
        break;
    
    case 4:
        //insereDisciplina(listas);
        break;
    
    case 5:
        //insereDisciplina(listas);
        break;
    
    case 6:
        //insereDisciplina(listas);
        break;
    
    case 7:
        //insereDisciplina(listas);
        break;
    
    case 8:
        //insereDisciplina(listas);
        break;
    
    case 9:
        //insereDisciplina(listas);
        break;
    
    case 10:
        //insereDisciplina(listas);
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

//========================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[40];

typedef struct tipoDisciplina {
    string nome;
    int cargaHoraria;
    struct tipoDisciplina *prox;
} TDisciplina;

typedef struct tipoHistorico {
    TDisciplina *disciplina;
    float nota;
    float percentualFrequencia;
    string condicao; // Aprovado, Reprovado ou Cursando.
    struct tipoHistorico *prox;
} THistorico;

typedef struct tipoAluno {
    string nome;
    char sexo;
    THistorico *historico;
    struct tipoAluno *ante, *prox;
} TAluno;

typedef struct tipoCurso {
    string nome;
    TAluno *alunos;
    struct tipoCurso *ante, *prox;
} TCurso;

typedef struct tipoLista {
    TCurso *inicioC;
    TCurso *fimC;
    TDisciplina *inicioD;
    TDisciplina *fimD;
    int total;
} TLista;

void insereDisciplina(TLista *lista, string nome, int cargaHoraria) {
    TDisciplina *novo = (TDisciplina *)malloc(sizeof(TDisciplina));
    strcpy(novo->nome, nome);
    novo->cargaHoraria = cargaHoraria;
    novo->prox = NULL;

    if (lista->inicioD == NULL) {
        // Lista encontra-se vazia.
        // Inserir o primeiro e único elemento da lista até agora
        lista->inicioD = novo;
        lista->fimD = novo;
        lista->total = 1;
    } else {
        // Lista já possui pelo menos 1 elemento
        TDisciplina *atual = lista->inicioD;
        TDisciplina *anterior = NULL;
        while (atual != NULL) {
            if (strcmp(atual->nome, novo->nome) > 0) {
                if (atual == lista->inicioD) {
                    // Inserir novo no início da lista
                    novo->prox = atual;
                    lista->inicioD = novo;
                } else {
                    // Inserir novo no meio da lista
                    novo->prox = atual;
                    anterior->prox = novo;
                }
                lista->total++;
                return;
            }
            anterior = atual;
            atual = atual->prox; // Move para o próximo elemento
        }
        // Inserir elemento no fim da lista
        lista->fimD->prox = novo;
        lista->fimD = novo;
        lista->total++;
    }
}

TCurso *localizaCurso(TLista *lista, string titulo) {
    TCurso *atual = lista->inicioC;
    while (atual != NULL) {
        if (strcmp(atual->nome, titulo) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void exibeDisciplina(TLista *lista) {
    TDisciplina *atual = lista->inicioD;
    int cont = 0;
    printf("\n\n\t\t===| EXIBE TODAS AS DISCIPLINAS |===\n\n");
    while (atual != NULL) {
        printf("(%d) - %s - %dH.\n", cont + 1, atual->nome, atual->cargaHoraria);
        atual = atual->prox;
        cont++;
    }
    printf("\n\n");
}

void insereCurso(TLista *lista, string nome) {
    TCurso *novo = (TCurso *)malloc(sizeof(TCurso));
    strcpy(novo->nome, nome);
    novo->alunos = NULL;
    novo->prox = NULL;
    novo->ante = NULL;

    if (lista->inicioC == NULL) {
        // Lista encontra-se vazia.
        // Inserir o primeiro e único elemento da lista até agora
        lista->inicioC = novo;
        lista->fimC = novo;
        lista->total = 1;
    } else {
        // Lista já possui pelo menos 1 elemento
        TCurso *atual = lista->inicioC;
        while (atual != NULL) {
            if (strcmp(atual->nome, novo->nome) > 0) {
                if (atual == lista->inicioC) {
                    // Inserir novo no início da lista
                    novo->prox = atual;
                    atual->ante = novo;
                    lista->inicioC = novo;
                } else {
                    // Inserir novo no meio da lista
                    novo->prox = atual;
                    novo->ante = atual->ante;
                    atual->ante->prox = novo;
                    atual->ante = novo;
                }
                lista->total++;
                return;
            }
            atual = atual->prox; // Move para o próximo elemento
        }
        // Inserir elemento no fim da lista
        lista->fimC->prox = novo;
        novo->ante = lista->fimC;
        lista->fimC = novo;
        lista->total++;
    }
}

void exibeCurso(TLista *lista) {
    TCurso *atual = lista->inicioC;
    int cont = 0;
    printf("\n\n\t\t===| EXIBE TODOS OS CURSOS |===\n\n");
    while (atual != NULL) {
        printf("(%d) - %s.\n", cont + 1, atual->nome);
        atual = atual->prox;
        cont++;
    }
    printf("\n\n");
}

void exibeAlunosEmCurso(TLista *lista) {
    int cont = 0;
    TCurso *curso;
    TAluno *aluno;

    string nome;
    printf("\n\n\t\t===| EXIBE TODOS OS ALUNOS EM UM CURSO |===\n\n");
    printf("\tInforme o NOME do CURSO: ");
    scanf(" %39[^\n]s", nome);
    fflush(stdin);

    curso = localizaCurso(lista, nome);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    printf("O CURSO %s tem os seguintes ALUNOS matriculados:\n", curso->nome);
    aluno = curso->alunos;
    while (aluno != NULL) {
        printf("(%d) - %s - %c.\n", cont + 1, aluno->nome, aluno->sexo);
        aluno = aluno->prox;
        cont++;
    }
    printf("\n\n");
}

void cadastraAluno(string nomeAluno, char *sexoAluno){
    printf("\tInforme o NOME do ALUNO: ");
    scanf(" %39[^\n]s", nomeAluno);
    printf("\tInforme o SEXO do ALUNO (M/F): ");
    scanf(" %c", sexoAluno);
}

void insereAlunoEmCurso(TLista *lista, string nomeCurso,string nomeAluno,char sexoAluno) {
    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    //cadastraAluno(nomeAluno,&sexoAluno);

    TAluno *novoAluno = (TAluno *)malloc(sizeof(TAluno));
    strcpy(novoAluno->nome, nomeAluno);
    novoAluno->sexo = sexoAluno;
    novoAluno->historico = NULL;
    novoAluno->prox = NULL;
    novoAluno->ante = NULL;

    if (curso->alunos == NULL) {
        curso->alunos = novoAluno;
    } else {
        TAluno *atual = curso->alunos;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoAluno;
        novoAluno->ante = atual;
    }

    printf("\n\n\tALUNO inserido com sucesso no CURSO %s.\n\n", nomeCurso);
}

void exibeTodosAlunos(TLista *lista) {
    printf("\n\n\t\t===| EXIBIR TODOS OS ALUNOS |===\n\n");

    TCurso *cursoAtual = lista->inicioC;
    int contCurso = 0;
    while (cursoAtual != NULL) {
        printf("\tCurso: %s\n", cursoAtual->nome);
        
        TAluno *alunoAtual = cursoAtual->alunos;
        int contAluno = 0;
        while (alunoAtual != NULL) {
            printf("\t  (%d) - Nome: %s, Sexo: %c\n", contAluno + 1, alunoAtual->nome, alunoAtual->sexo);
            alunoAtual = alunoAtual->prox;
            contAluno++;
        }

        cursoAtual = cursoAtual->prox;
        contCurso++;
    }

    if (contCurso == 0) {
        printf("\tNenhum aluno cadastrado.\n");
    }

    printf("\n\n");
}

void excluirAluno(TLista *lista) {
    printf("\n\n\t\t===| EXCLUIR ALUNO DE CURSO |===\n\n");

    string nomeCurso;
    printf("\tInforme o NOME do CURSO: ");
    scanf(" %39[^\n]s", nomeCurso);

    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    if (curso->alunos == NULL) {
        printf("\n\n\tO CURSO %s ainda não possui ALUNOS cadastrados.\n\n", nomeCurso);
        return;
    }

    string nomeAluno;
    printf("\tInforme o NOME do ALUNO a ser excluído: ");
    scanf(" %39[^\n]s", nomeAluno);

    TAluno *alunoAtual = curso->alunos;
    TAluno *alunoAnterior = NULL;

    while (alunoAtual != NULL) {
        if (strcmp(alunoAtual->nome, nomeAluno) == 0) {
            if (alunoAnterior == NULL) {
                curso->alunos = alunoAtual->prox;
            } else {
                alunoAnterior->prox = alunoAtual->prox;
            }
            free(alunoAtual);
            printf("\n\n\tAluno \"%s\" excluído do curso %s.\n\n", nomeAluno, nomeCurso);
            return;
        }
        alunoAnterior = alunoAtual;
        alunoAtual = alunoAtual->prox;
    }

    printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
}

TDisciplina *defineDisciplina(TLista *lista, string nomeDisciplina) {
    TDisciplina *atual = lista->inicioD;
    while (atual != NULL) {
        if (strcmp(atual->nome, nomeDisciplina) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    printf("\n\n\tERRO: Disciplina \"%s\" não encontrada.\n\n", nomeDisciplina);
    return NULL;
}

TAluno *pesquisaAluno(TCurso *curso, string nomeAluno) {
    if (curso == NULL || curso->alunos == NULL) {
        return NULL;
    }

    TAluno *alunoAtual = curso->alunos;

    while (alunoAtual != NULL) {
        if (strcmp(alunoAtual->nome, nomeAluno) == 0) {
            return alunoAtual; // Retorna o ponteiro para o aluno encontrado
        }
        alunoAtual = alunoAtual->prox;
    }

    return NULL; // Retorna NULL se o aluno não for encontrado
}


void insereHistorico(string nomeAluno, TLista *lista, string nomeDisciplina) {
    // Encontra o curso onde o aluno está matriculado
    string nomeCurso;
    printf("\tInforme o NOME do CURSO: ");
    scanf(" %39[^\n]s", nomeCurso);

    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    // Pesquisa o aluno na lista de alunos do curso
    TAluno *aluno = pesquisaAluno(curso, nomeAluno);

    if (aluno == NULL) {
        printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
        return;
    }

    // Encontra a disciplina na lista
    TDisciplina *disciplina = defineDisciplina(lista, nomeDisciplina);

    if (disciplina != NULL) {
        // Cria um novo histórico e preenche suas informações
        THistorico *novoHistorico = (THistorico *)malloc(sizeof(THistorico));
        novoHistorico->disciplina = disciplina;
        printf("Digite a nota que o aluno teve nessa disciplina: ");
        scanf("%f", &novoHistorico->nota);
        printf("Digite o percentual de presença que o aluno teve nessa disciplina: ");
        scanf("%f", &novoHistorico->percentualFrequencia);
        printf("Digite a condição que esse aluno está nessa disciplina (Aprovado/Reprovado/Cursando): ");
        scanf(" %39[^\n]s", novoHistorico->condicao);

        // Insere o novo histórico na lista de históricos do aluno
        novoHistorico->prox = aluno->historico;
        aluno->historico = novoHistorico;

        printf("\n\n\tHistórico inserido com sucesso para a disciplina \"%s\".\n\n", nomeDisciplina);
    }
}


/*void insereHistoricoAluno(TLista *lista) {
    printf("\n\n\t\t===| INSERIR HISTÓRICO PARA ALUNO |===\n\n");

    string nomeCurso, nomeAluno, nomeDisciplina;
    float nota;
    float percentualFrequencia;
    string condicao;

    printf("\tInforme o NOME do CURSO: ");
    scanf(" %39[^\n]s", nomeCurso);

    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    printf("\tInforme o NOME do ALUNO: ");
    scanf(" %39[^\n]s", nomeAluno);

    TAluno *aluno = curso->alunos;

    while (aluno != NULL) {
        if (strcmp(aluno->nome, nomeAluno) == 0) {
            printf("\tInforme o NOME da DISCIPLINA: ");
            scanf(" %39[^\n]s", nomeDisciplina);
            printf("\tInforme a NOTA do ALUNO nessa DISCIPLINA: ");
            scanf("%f", &nota);
            printf("\tInforme o PERCENTUAL de FREQUÊNCIA do ALUNO nessa DISCIPLINA: ");
            scanf("%f", &percentualFrequencia);
            printf("\tInforme a CONDIÇÃO do ALUNO nessa DISCIPLINA (Aprovado/Reprovado/Cursando): ");
            scanf(" %39[^\n]s", condicao);

            THistorico *novoHistorico = (THistorico *)malloc(sizeof(THistorico));
            novoHistorico->disciplina = defineHistorico(lista, nomeDisciplina);
            novoHistorico->nota = nota;
            novoHistorico->percentualFrequencia = percentualFrequencia;
            strcpy(novoHistorico->condicao, condicao);
            novoHistorico->prox = NULL;

            if (aluno->historico == NULL) {
                aluno->historico = novoHistorico;
            } else {
                THistorico *atual = aluno->historico;
                while (atual->prox != NULL) {
                    atual = atual->prox;
                }
                atual->prox = novoHistorico;
            }

            printf("\n\n\tHISTÓRICO inserido com sucesso para o ALUNO %s na DISCIPLINA %s.\n\n", nomeAluno, nomeDisciplina);
            return;
        }
        aluno = aluno->prox;
    }

    printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
}*/

void exibeHistoricoAluno(TLista *lista) {
    printf("\n\n\t\t===| EXIBIR HISTÓRICO DE ALUNO |===\n\n");

    string nomeCurso, nomeAluno;

    printf("\tInforme o NOME do CURSO: ");
    scanf(" %39[^\n]s", nomeCurso);

    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    printf("\tInforme o NOME do ALUNO: ");
    scanf(" %39[^\n]s", nomeAluno);

    TAluno *aluno = curso->alunos;

    while (aluno != NULL) {
        if (strcmp(aluno->nome, nomeAluno) == 0) {
            if (aluno->historico == NULL) {
                printf("\n\n\tO ALUNO %s não possui histórico cadastrado.\n\n", nomeAluno);
                return;
            }

            printf("\n\n\t===| HISTÓRICO DO ALUNO %s |===\n\n", nomeAluno);
            THistorico *historico = aluno->historico;
            int cont = 1;

            while (historico != NULL) {
                printf("\t%d. DISCIPLINA: %s, NOTA: %.2f, PERCENTUAL DE FREQUÊNCIA: %.2f, CONDIÇÃO: %s\n",
                       cont, historico->disciplina->nome, historico->nota, historico->percentualFrequencia, historico->condicao);
                historico = historico->prox;
                cont++;
            }

            printf("\n\n");
            return;
        }
        aluno = aluno->prox;
    }

    printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
}

void excluiHistoricoAluno(TLista *lista) {
    printf("\n\n\t\t===| EXCLUIR HISTÓRICO DE ALUNO |===\n\n");

    string nomeCurso, nomeAluno, nomeDisciplina;

    printf("\tInforme o NOME do CURSO: ");
    scanf(" %39[^\n]s", nomeCurso);

    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    printf("\tInforme o NOME do ALUNO: ");
    scanf(" %39[^\n]s", nomeAluno);

    TAluno *aluno = curso->alunos;

    while (aluno != NULL) {
        if (strcmp(aluno->nome, nomeAluno) == 0) {
            printf("\tInforme o NOME da DISCIPLINA: ");
            scanf(" %39[^\n]s", nomeDisciplina);

            if (aluno->historico == NULL) {
                printf("\n\n\tO ALUNO %s não possui histórico cadastrado.\n\n", nomeAluno);
                return;
            }

            THistorico *historicoAtual = aluno->historico;
            THistorico *historicoAnterior = NULL;

            while (historicoAtual != NULL) {
                if (strcmp(historicoAtual->disciplina->nome, nomeDisciplina) == 0) {
                    if (historicoAnterior == NULL) {
                        aluno->historico = historicoAtual->prox;
                    } else {
                        historicoAnterior->prox = historicoAtual->prox;
                    }
                    free(historicoAtual);
                    printf("\n\n\tHISTÓRICO da DISCIPLINA \"%s\" excluído com sucesso para o ALUNO %s.\n\n", nomeDisciplina, nomeAluno);
                    return;
                }
                historicoAnterior = historicoAtual;
                historicoAtual = historicoAtual->prox;
            }

            printf("\n\n\tERRO: Histórico da disciplina \"%s\" não encontrado para o ALUNO %s.\n\n", nomeDisciplina, nomeAluno);
            return;
        }
        aluno = aluno->prox;
    }

    printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
}


void cadastraDisciplina(TLista *lista) {
    string nome;
    int cargaHoraria;

    printf("Digite o nome da Disciplina: ");
    scanf(" %39[^\n]s", nome);
    printf("Digite qual é a carga horária: ");
    scanf("%d", &cargaHoraria);
    insereDisciplina(lista, nome, cargaHoraria);
}

string *cadastraCurso(TLista *lista){
    string nomeCurso;
    printf("\n\n\t\t===| INSERIR ALUNO EM CURSO |===\n\n");
    printf("\tInforme o NOME do CURSO: ");
    scanf(" %39[^\n]s", nomeCurso);
    string nomeAluno;
    char sexoAluno;
    cadastraAluno(nomeAluno,&sexoAluno);
    insereAlunoEmCurso(lista,nomeCurso,nomeAluno,sexoAluno);
}

void realizaOpcaoDesejada(TLista *listas, int op) {
    switch (op) {
        case 1:
            cadastraDisciplina(listas);
            break;

        case 2:
            exibeDisciplina(listas);
            break;

        case 3:
           // insereCurso(listas);
            break;

        case 4:
            exibeCurso(listas);
            break;

        case 5:
            //insereAlunoEmCurso(listas);
            break;

        case 6:
            exibeAlunosEmCurso(listas);
            break;

        case 7:
           //exibeTodosAlunos(listas);
           excluirAluno(listas);
            break;

        case 8:
            //insereHistorico(listas);
            break;

        case 9:
            exibeHistoricoAluno(listas);
            break;

        case 10:
            excluiHistoricoAluno(listas);
            break;

        default:
            printf("\nERRO: Opção inválida, tente novamente\n");
            break;
    }
}

void inicializa(TLista *lista) {
    lista->inicioC = NULL;
    lista->inicioD = NULL;
    lista->fimC = NULL;
    lista->fimD = NULL;
    lista->total = 0;
    insereDisciplina(lista, "Prog1", 60);
    insereDisciplina(lista, "Math", 90);
    insereDisciplina(lista, "ED", 30);
    insereDisciplina(lista, "POO", 60);
    exibeDisciplina(lista);
    insereCurso(lista,"SI");
    insereCurso(lista,"Matematica");
    insereCurso(lista,"Adm");
    insereAlunoEmCurso(lista,"SI","Pedro",'M');
    insereAlunoEmCurso(lista,"SI","Lucas",'M');
    insereAlunoEmCurso(lista,"SI","Luis",'M');
    insereAlunoEmCurso(lista,"SI","Maria",'F');
    insereHistorico("Pedro",lista,"Prog1");
    insereHistorico("Lucas",lista,"Prog1");
    insereHistorico("Lucas",lista,"ED");
    insereHistorico("Maria",lista,"POO");
}

int menu() {
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
    } while (op < 0 || op > 10);
    return op;
}

int main() {
    TLista listas;
    inicializa(&listas);
    int op;
    int sair = 0;
    do {
        op = menu();
        if (op == 0) {
            sair = 1;
        } else if ((op < 0) || (op > 10)) {
            printf("\nERRO: Opção inválida, tente novamente\n");
        } else {
            realizaOpcaoDesejada(&listas, op);
        }
    } while (sair != 1);
    return 0;
}
// codigo funcional 08/04
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef char string[40];

// typedef struct tipoDisciplina {
//     string nome;
//     int cargaHoraria;
//     struct tipoDisciplina *prox;
// } TDisciplina;

// typedef struct tipoHistorico {
//     TDisciplina *disciplina;
//     float nota;
//     float percentualFrequencia;
//     string condicao; // Aprovado, Reprovado ou Cursando.
//     struct tipoHistorico *prox;
// } THistorico;

// typedef struct tipoAluno {
//     string nome;
//     char sexo;
//     THistorico *historico;
//     struct tipoAluno *ante, *prox;
// } TAluno;

// typedef struct tipoCurso {
//     string nome;
//     TAluno *alunos;
//     struct tipoCurso *ante, *prox;
// } TCurso;

// typedef struct tipoLista {
//     TCurso *inicioC;
//     TCurso *fimC;
//     TDisciplina *inicioD;
//     TDisciplina *fimD;
//     int total;
// } TLista;

// void insereDisciplina(TLista *lista, string nome, int cargaHoraria) {
//     TDisciplina *novo = (TDisciplina *)malloc(sizeof(TDisciplina));
//     strcpy(novo->nome, nome);
//     novo->cargaHoraria = cargaHoraria;
//     novo->prox = NULL;

//     if (lista->inicioD == NULL) {
//         // Lista encontra-se vazia.
//         // Inserir o primeiro e único elemento da lista até agora
//         lista->inicioD = novo;
//         lista->fimD = novo;
//         lista->total = 1;
//     } else {
//         // Lista já possui pelo menos 1 elemento
//         TDisciplina *atual = lista->inicioD;
//         TDisciplina *anterior = NULL;
//         while (atual != NULL) {
//             if (strcmp(atual->nome, novo->nome) > 0) {
//                 if (atual == lista->inicioD) {
//                     // Inserir novo no início da lista
//                     novo->prox = atual;
//                     lista->inicioD = novo;
//                 } else {
//                     // Inserir novo no meio da lista
//                     novo->prox = atual;
//                     anterior->prox = novo;
//                 }
//                 lista->total++;
//                 return;
//             }
//             anterior = atual;
//             atual = atual->prox; // Move para o próximo elemento
//         }
//         // Inserir elemento no fim da lista
//         lista->fimD->prox = novo;
//         lista->fimD = novo;
//         lista->total++;
//     }
// }

// TCurso *localizaCurso(TLista *lista, string titulo) {
//     TCurso *atual = lista->inicioC;
//     while (atual != NULL) {
//         if (strcmp(atual->nome, titulo) == 0) {
//             return atual;
//         }
//         atual = atual->prox;
//     }
//     return NULL;
// }

// void exibeDisciplina(TLista *lista) {
//     TDisciplina *atual = lista->inicioD;
//     int cont = 0;
//     printf("\n\n\t\t===| EXIBE TODAS AS DISCIPLINAS |===\n\n");
//     while (atual != NULL) {
//         printf("(%d) - %s - %dH.\n", cont + 1, atual->nome, atual->cargaHoraria);
//         atual = atual->prox;
//         cont++;
//     }
//     printf("\n\n");
// }

// void insereCurso(TLista *lista, string nome) {
//     TCurso *novo = (TCurso *)malloc(sizeof(TCurso));
//     strcpy(novo->nome, nome);
//     novo->alunos = NULL;
//     novo->prox = NULL;
//     novo->ante = NULL;

//     if (lista->inicioC == NULL) {
//         // Lista encontra-se vazia.
//         // Inserir o primeiro e único elemento da lista até agora
//         lista->inicioC = novo;
//         lista->fimC = novo;
//         lista->total = 1;
//     } else {
//         // Lista já possui pelo menos 1 elemento
//         TCurso *atual = lista->inicioC;
//         while (atual != NULL) {
//             if (strcmp(atual->nome, novo->nome) > 0) {
//                 if (atual == lista->inicioC) {
//                     // Inserir novo no início da lista
//                     novo->prox = atual;
//                     atual->ante = novo;
//                     lista->inicioC = novo;
//                 } else {
//                     // Inserir novo no meio da lista
//                     novo->prox = atual;
//                     novo->ante = atual->ante;
//                     atual->ante->prox = novo;
//                     atual->ante = novo;
//                 }
//                 lista->total++;
//                 return;
//             }
//             atual = atual->prox; // Move para o próximo elemento
//         }
//         // Inserir elemento no fim da lista
//         lista->fimC->prox = novo;
//         novo->ante = lista->fimC;
//         lista->fimC = novo;
//         lista->total++;
//     }
// }

// void exibeCurso(TLista *lista) {
//     TCurso *atual = lista->inicioC;
//     int cont = 0;
//     printf("\n\n\t\t===| EXIBE TODOS OS CURSOS |===\n\n");
//     while (atual != NULL) {
//         printf("(%d) - %s.\n", cont + 1, atual->nome);
//         atual = atual->prox;
//         cont++;
//     }
//     printf("\n\n");
// }

// void exibeAlunosEmCurso(TLista *lista) {
//     int cont = 0;
//     TCurso *curso;
//     TAluno *aluno;

//     string nome;
//     printf("\n\n\t\t===| EXIBE TODOS OS ALUNOS EM UM CURSO |===\n\n");
//     printf("\tInforme o NOME do CURSO: ");
//     scanf(" %39[^\n]s", nome);
//     fflush(stdin);

//     curso = localizaCurso(lista, nome);

//     if (curso == NULL) {
//         printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
//         return;
//     }

//     printf("O CURSO %s tem os seguintes ALUNOS matriculados:\n", curso->nome);
//     aluno = curso->alunos;
//     while (aluno != NULL) {
//         printf("(%d) - %s - %c.\n", cont + 1, aluno->nome, aluno->sexo);
//         aluno = aluno->prox;
//         cont++;
//     }
//     printf("\n\n");
// }

// void cadastraAluno(string nomeAluno, char *sexoAluno){
//     printf("\tInforme o NOME do ALUNO: ");
//     scanf(" %39[^\n]s", nomeAluno);
//     printf("\tInforme o SEXO do ALUNO (M/F): ");
//     scanf(" %c", sexoAluno);
// }

// void insereAlunoEmCurso(TLista *lista, string nomeCurso,string nomeAluno,char sexoAluno) {
//     TCurso *curso = localizaCurso(lista, nomeCurso);

//     if (curso == NULL) {
//         printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
//         return;
//     }

//     //cadastraAluno(nomeAluno,&sexoAluno);

//     TAluno *novoAluno = (TAluno *)malloc(sizeof(TAluno));
//     strcpy(novoAluno->nome, nomeAluno);
//     novoAluno->sexo = sexoAluno;
//     novoAluno->historico = NULL;
//     novoAluno->prox = NULL;
//     novoAluno->ante = NULL;

//     if (curso->alunos == NULL) {
//         curso->alunos = novoAluno;
//     } else {
//         TAluno *atual = curso->alunos;
//         while (atual->prox != NULL) {
//             atual = atual->prox;
//         }
//         atual->prox = novoAluno;
//         novoAluno->ante = atual;
//     }

//     printf("\n\n\tALUNO inserido com sucesso no CURSO %s.\n\n", nomeCurso);
// }

// void cadastrarAlunoCurso(TLista *lista){
//     string nomeCurso,nomeAluno;
//     char sexoAluno;
//     printf("Digite o nome do aluno: ");
//     scanf(" %39[^\n]s", nomeAluno);
//     printf("Digite o nome do curso: ");
//     scanf(" %39[^\n]s", nomeCurso);
//     printf("Digite o sexo do aluno(M-masculino/F-feminino: ");
//     scanf("%c", sexoAluno);
//     insereAlunoEmCurso(lista,nomeCurso,nomeAluno,sexoAluno);
// }

// void exibeTodosAlunos(TLista *lista) {
//     printf("\n\n\t\t===| EXIBIR TODOS OS ALUNOS |===\n\n");

//     TCurso *cursoAtual = lista->inicioC;
//     int contCurso = 0;
//     while (cursoAtual != NULL) {
//         printf("\tCurso: %s\n", cursoAtual->nome);
        
//         TAluno *alunoAtual = cursoAtual->alunos;
//         int contAluno = 0;
//         while (alunoAtual != NULL) {
//             printf("\t  (%d) - Nome: %s, Sexo: %c\n", contAluno + 1, alunoAtual->nome, alunoAtual->sexo);
//             alunoAtual = alunoAtual->prox;
//             contAluno++;
//         }

//         cursoAtual = cursoAtual->prox;
//         contCurso++;
//     }

//     if (contCurso == 0) {
//         printf("\tNenhum aluno cadastrado.\n");
//     }

//     printf("\n\n");
// }

// void excluirAluno(TLista *lista) {
//     printf("\n\n\t\t===| EXCLUIR ALUNO DE CURSO |===\n\n");

//     string nomeCurso;
//     printf("\tInforme o NOME do CURSO: ");
//     scanf(" %39[^\n]s", nomeCurso);

//     TCurso *curso = localizaCurso(lista, nomeCurso);

//     if (curso == NULL) {
//         printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
//         return;
//     }

//     if (curso->alunos == NULL) {
//         printf("\n\n\tO CURSO %s ainda não possui ALUNOS cadastrados.\n\n", nomeCurso);
//         return;
//     }

//     string nomeAluno;
//     printf("\tInforme o NOME do ALUNO a ser excluído: ");
//     scanf(" %39[^\n]s", nomeAluno);

//     TAluno *alunoAtual = curso->alunos;
//     TAluno *alunoAnterior = NULL;

//     while (alunoAtual != NULL) {
//         if (strcmp(alunoAtual->nome, nomeAluno) == 0) {
//             if (alunoAnterior == NULL) {
//                 curso->alunos = alunoAtual->prox;
//             } else {
//                 alunoAnterior->prox = alunoAtual->prox;
//             }
//             free(alunoAtual);
//             printf("\n\n\tAluno \"%s\" excluído do curso %s.\n\n", nomeAluno, nomeCurso);
//             return;
//         }
//         alunoAnterior = alunoAtual;
//         alunoAtual = alunoAtual->prox;
//     }

//     printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
// }

// TDisciplina *defineDisciplina(TLista *lista, string nomeDisciplina) {
//     TDisciplina *atual = lista->inicioD;
//     while (atual != NULL) {
//         if (strcmp(atual->nome, nomeDisciplina) == 0) {
//             return atual;
//         }
//         atual = atual->prox;
//     }
//     printf("\n\n\tERRO: Disciplina \"%s\" não encontrada.\n\n", nomeDisciplina);
//     return NULL;
// }

// TAluno *pesquisaAluno(TCurso *curso, string nomeAluno) {
//     if (curso == NULL || curso->alunos == NULL) {
//         return NULL;
//     }

//     TAluno *alunoAtual = curso->alunos;

//     while (alunoAtual != NULL) {
//         if (strcmp(alunoAtual->nome, nomeAluno) == 0) {
//             return alunoAtual; // Retorna o ponteiro para o aluno encontrado
//         }
//         alunoAtual = alunoAtual->prox;
//     }

//     return NULL; // Retorna NULL se o aluno não for encontrado
// }


// void insereHistorico(string nomeAluno, TLista *lista, string nomeDisciplina) {
//     // Encontra o curso onde o aluno está matriculado
//     string nomeCurso;
//     printf("\tInforme o NOME do CURSO: ");
//     scanf(" %39[^\n]s", nomeCurso);

//     TCurso *curso = localizaCurso(lista, nomeCurso);

//     if (curso == NULL) {
//         printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
//         return;
//     }

//     // Pesquisa o aluno na lista de alunos do curso
//     TAluno *aluno = pesquisaAluno(curso, nomeAluno);

//     if (aluno == NULL) {
//         printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
//         return;
//     }

//     // Encontra a disciplina na lista
//     TDisciplina *disciplina = defineDisciplina(lista, nomeDisciplina);

//     if (disciplina != NULL) {
//         // Cria um novo histórico e preenche suas informações
//         THistorico *novoHistorico = (THistorico *)malloc(sizeof(THistorico));
//         novoHistorico->disciplina = disciplina;
//         printf("Digite a nota que o aluno teve nessa disciplina: ");
//         scanf("%f", &novoHistorico->nota);
//         printf("Digite o percentual de presença que o aluno teve nessa disciplina: ");
//         scanf("%f", &novoHistorico->percentualFrequencia);
//         printf("Digite a condição que esse aluno está nessa disciplina (Aprovado/Reprovado/Cursando): ");
//         scanf(" %39[^\n]s", novoHistorico->condicao);

//         // Insere o novo histórico na lista de históricos do aluno
//         novoHistorico->prox = aluno->historico;
//         aluno->historico = novoHistorico;

//         printf("\n\n\tHistórico inserido com sucesso para a disciplina \"%s\".\n\n", nomeDisciplina);
//     }
// }

// void exibeHistoricoAluno(TLista *lista) {
//     printf("\n\n\t\t===| EXIBIR HISTÓRICO DE ALUNO |===\n\n");

//     string nomeCurso, nomeAluno;

//     printf("\tInforme o NOME do CURSO: ");
//     scanf(" %39[^\n]s", nomeCurso);

//     TCurso *curso = localizaCurso(lista, nomeCurso);

//     if (curso == NULL) {
//         printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
//         return;
//     }

//     printf("\tInforme o NOME do ALUNO: ");
//     scanf(" %39[^\n]s", nomeAluno);

//     TAluno *aluno = curso->alunos;

//     while (aluno != NULL) {
//         if (strcmp(aluno->nome, nomeAluno) == 0) {
//             if (aluno->historico == NULL) {
//                 printf("\n\n\tO ALUNO %s não possui histórico cadastrado.\n\n", nomeAluno);
//                 return;
//             }

//             printf("\n\n\t===| HISTÓRICO DO ALUNO %s |===\n\n", nomeAluno);
//             THistorico *historico = aluno->historico;
//             int cont = 1;

//             while (historico != NULL) {
//                 printf("\t%d. DISCIPLINA: %s, NOTA: %.2f, PERCENTUAL DE FREQUÊNCIA: %.2f, CONDIÇÃO: %s\n",
//                        cont, historico->disciplina->nome, historico->nota, historico->percentualFrequencia, historico->condicao);
//                 historico = historico->prox;
//                 cont++;
//             }

//             printf("\n\n");
//             return;
//         }
//         aluno = aluno->prox;
//     }

//     printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
// }

// void excluiHistoricoAluno(TLista *lista) {
//     printf("\n\n\t\t===| EXCLUIR HISTÓRICO DE ALUNO |===\n\n");

//     string nomeCurso, nomeAluno, nomeDisciplina;

//     printf("\tInforme o NOME do CURSO: ");
//     scanf(" %39[^\n]s", nomeCurso);

//     TCurso *curso = localizaCurso(lista, nomeCurso);

//     if (curso == NULL) {
//         printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
//         return;
//     }

//     printf("\tInforme o NOME do ALUNO: ");
//     scanf(" %39[^\n]s", nomeAluno);

//     TAluno *aluno = curso->alunos;

//     while (aluno != NULL) {
//         if (strcmp(aluno->nome, nomeAluno) == 0) {
//             printf("\tInforme o NOME da DISCIPLINA: ");
//             scanf(" %39[^\n]s", nomeDisciplina);

//             if (aluno->historico == NULL) {
//                 printf("\n\n\tO ALUNO %s não possui histórico cadastrado.\n\n", nomeAluno);
//                 return;
//             }

//             THistorico *historicoAtual = aluno->historico;
//             THistorico *historicoAnterior = NULL;

//             while (historicoAtual != NULL) {
//                 if (strcmp(historicoAtual->disciplina->nome, nomeDisciplina) == 0) {
//                     if (historicoAnterior == NULL) {
//                         aluno->historico = historicoAtual->prox;
//                     } else {
//                         historicoAnterior->prox = historicoAtual->prox;
//                     }
//                     free(historicoAtual);
//                     printf("\n\n\tHISTÓRICO da DISCIPLINA \"%s\" excluído com sucesso para o ALUNO %s.\n\n", nomeDisciplina, nomeAluno);
//                     return;
//                 }
//                 historicoAnterior = historicoAtual;
//                 historicoAtual = historicoAtual->prox;
//             }

//             printf("\n\n\tERRO: Histórico da disciplina \"%s\" não encontrado para o ALUNO %s.\n\n", nomeDisciplina, nomeAluno);
//             return;
//         }
//         aluno = aluno->prox;
//     }

//     printf("\n\n\tERRO: Aluno \"%s\" não encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
// }

// void cadastraHistoricoAluno(TLista *lista){
//     string nomeAluno, nomeDisciplina;
//     printf("Digite o nome do Aluno: ");
//     scanf(" %39[^\n]s \n",nomeAluno);
//     scanf("Digite o nome da disciplina em que o historico sera inserido: ");
//     scanf(" %39[^\n]s",nomeDisciplina);
//     insereHistorico(nomeAluno,lista,nomeDisciplina);
// }


// void cadastraDisciplina(TLista *lista) {
//     string nome;
//     int cargaHoraria;

//     printf("Digite o nome da Disciplina: ");
//     scanf(" %39[^\n]s", nome);
//     printf("Digite qual é a carga horária: ");
//     scanf("%d", &cargaHoraria);
//     insereDisciplina(lista, nome, cargaHoraria);
// }

// string *cadastraCurso2(TLista *lista){
//     string nomeCurso;
//     printf("\n\n\t\t===| INSERIR ALUNO EM CURSO |===\n\n");
//     printf("\tInforme o NOME do CURSO: ");
//     scanf(" %39[^\n]s", nomeCurso);
//     string nomeAluno;
//     char sexoAluno;
//     cadastraAluno(nomeAluno,&sexoAluno);
//     insereAlunoEmCurso(lista,nomeCurso,nomeAluno,sexoAluno);
// }

// void cadastraCurso1(TLista *lista){
//     string nomeCurso;
//     printf("Digite o nome do curso: ");
//     scanf(" %39[^\n]s", nomeCurso);
//     insereCurso(lista,nomeCurso);
// }

// void realizaOpcaoDesejada(TLista *listas, int op) {
//     switch (op) {
//         case 1:
//             cadastraDisciplina(listas);
//             break;

//         case 2:
//             exibeDisciplina(listas);
//             break;

//         case 3:
//             cadastraCurso1(listas);
//             break;

//         case 4:
//             exibeCurso(listas);
//             break;

//         case 5:
//             cadastraCurso2(listas);
//             break;

//         case 6:
//             exibeAlunosEmCurso(listas);
//             break;

//         case 7:
//            excluirAluno(listas);
//             break;

//         case 8:
//             cadastraHistoricoAluno(listas);
//             break;

//         case 9:
//             exibeHistoricoAluno(listas);
//             break;

//         case 10:
//             excluiHistoricoAluno(listas);
//             break;

//         default:
//             printf("\nERRO: Opção inválida, tente novamente\n");
//             break;
//     }
// }

// void inicializa(TLista *lista) {
//     lista->inicioC = NULL;
//     lista->inicioD = NULL;
//     lista->fimC = NULL;
//     lista->fimD = NULL;
//     lista->total = 0;
// }

// int menu() {
//     int op;
//     printf("\n\n\t\t====| MENU |=====\n\n");
//     printf("\t0 - Sair (Encerrar a Aplicacao).\n\n");
//     printf("\t1 - Inserir DISCIPLINA.\n");
//     printf("\t2 - Exibe Todas as DISCIPLINAS.\n\n");
//     printf("\t3 - Inserir CURSO.\n");
//     printf("\t4 - Exibir Todos os CURSOS.\n\n");
//     printf("\t5 - Inserir ALUNO em CURSO.\n");
//     printf("\t6 - Exibir Todos os ALUNOS de CURSO especifico.\n");
//     printf("\t7 - Excluir ALUNO de CURSO.\n\n");
//     printf("\t8 - Inserir HISTORICO para ALUNO.\n");
//     printf("\t9 - Exibir HISTORICO de ALUNO.\n");
//     printf("\t10 - Excluir HISTORICO de ALUNO.\n\n");
//     do {
//         printf("Escolha sua opção: ");
//         scanf(" %d", &op);
//     } while (op < 0 || op > 10);
//     return op;
// }

// int main() {
//     TLista listas;
//     inicializa(&listas);
//     int op;
//     int sair = 0;
//     do {
//         op = menu();
//         if (op == 0) {
//             sair = 1;
//         } else if ((op < 0) || (op > 10)) {
//             printf("\nERRO: Opção inválida, tente novamente\n");
//         } else {
//             realizaOpcaoDesejada(&listas, op);
//         }
//     } while (sair != 1);
//     return 0;
// }


