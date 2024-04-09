// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
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

// inputs personalizados e modificados EX: variavel = input();
float input(){
    float value;
    fflush(stdin);
    scanf("%f", &value);
    return value;
}
// inputs personalizados e modificados EX: inputS(&variavel);
void inputS(char destino[]){
    fflush(stdin);
    scanf(" %100[^\n]s", destino);
}


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


// =================== INSERES ==============

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

// ============ LOCALIZADORES ==========

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

TAluno *localizaAluno(TLista *lista, string titulo){
	TAluno *atual= atual->prox;
	
	while (atual != NULL){
		if(strcmp(atual->nome, titulo) == 0){
			break;
		}//if
		atual = atual->prox;
	}//while
	return atual;
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

// =================== CADASTROS ===========
void cadastraDisciplina(TLista *lista){
    int cargaHoraria;
    string nome;

    printf("Digite o nome da Disciplina: ");
    inputS(nome);
    printf("Digite qual e a carga horaria: ");
    cargaHoraria = input();

    insereDisciplina(lista, nome, cargaHoraria);
}

void cadastraCurso(TLista *lista){
    string nome;

    printf("Digite o nome do Curso: ");
    inputS(nome);

    // insereCurso(lista, nome);
}

void cadastraAlunoEmCurso(TLista *lista){
    // int cargaHoraria;
    string alunoNome;
    string cursoNome;
    TCurso *curso;
    TAluno *aluno;

    printf("Digite o nome do ALUNO: ");
    inputS(alunoNome);
    printf("Digite o nome do Curso: ");
    inputS(cursoNome);

    curso = localizaCurso(lista,cursoNome);
    aluno = localizaAluno(lista,alunoNome);

    if(curso == NULL || aluno == NULL){
		printf("\n\n\tERRO: Curso ou Aluno procurado NAO foi encontrado.\n\tCURSO: %s.\n\n",curso->nome);
		system("PAUSE");
	} else {
		// insereAlunoEmCurso(lista, aluno, curso);
	}
}

void cadastraHistorico(TLista *lista){
    string disciplina;
    string aluno;
    int nota;
    float percentualFrequencia;

    printf("Digite o nome do ALUNO: ");
    inputS(aluno);
    printf("Digite o nome da Disciplina onde deseja cadastrar o Historico: ");
    inputS(disciplina);
    printf("Digite qual e a nota do aluno: ");
    nota = input();
    printf("Digite qual e o percentual de frequencia do aluno: ");
    percentualFrequencia = input();

    // insereHistorico(lista, disciplina, nota, percentualFrequencia);
}


// ================ EXIBES =============== 

void exibeDisciplina(TLista *lista){
	TDisciplina *disciplina = lista->inicioD;
	int cont = 0;
	printf("\n\n\t\t===| EXIBE TODAS AS DISCIPLINAS |===\n\n");
	while (disciplina != NULL){
		printf("(%d) - %s - %dH.\n",cont+1, disciplina->nome, disciplina->cargaHoraria);
		disciplina = disciplina->prox;
        cont++;
	}
    if(disciplina != NULL){
        printf("Nao foram encontradas Disciplinas Cadastradas");
    }
	printf("\n\n");
}

void exibeCurso(TLista *lista){
   TCurso *curso = lista->inicioC;
	int cont = 0;

	printf("\n\n\t\t===| EXIBE TODOS OS CURSOS |===\n\n");
	while (curso != NULL){
		printf("(%d) - %s.\n",cont+1,curso->nome );
		curso = curso->prox;
        cont++;
	}
    if(curso == NULL){
        printf("Nao foram encontrados Cursos Cadastrados");
    }
	printf("\n\n"); 
}

void exibeAlunosEmCurso(TLista *lista){
	int cont = 0;
	TCurso *curso;
	TAluno *aluno;
	string nome;
	
	printf("\n\n\t\t===| EXIBE TODOS OS ALUNOS EM UM CURSO |===\n\n");
	printf("\tInforme o NOME do CURSO: ");
    fflush(stdin);
    inputS(nome);
	
	curso = localizaCurso(lista, nome);
	
	if(curso == NULL){
		printf("\n\n\tERRO: Curso procurado %s NAO foi encontrado.\n\t.", nome);
        printf("\n\t CURSO ENCONTRADO: %s. \n\n", curso->nome);
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

void exibeHistorico(TLista *lista){
    THistorico *historico;
    int cont = 0;
	

	printf("\n\n\t\t===| EXIBE HISTORICO DE ALUNO |===\n\n");
	while (historico->prox != NULL){
		printf("(%d) - %s.\n",cont+1,historico->disciplina->nome);
        printf("- Frequencia: %f% \n", historico->percentualFrequencia);
        printf("- Nota: %f \n", historico->nota);
        printf("- Situacao: %s \n", historico->condicao);
		historico = historico->prox;
        cont++;
	}
    if(historico->prox == NULL){
        printf("Nao foram encontrados HISTORICOS Cadastrados");
    }
	printf("\n\n");
}