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

char validSexo() {
    char sx;
    
    printf("Insira seu sexo(F/M): ");
    scanf(" %c", &sx);
    sx = toupper(sx);
    while (sx != 'F' && sx != 'M') {
        printf("Sexo invalido.\n");
        printf("Insira seu sexo(F/M): ");
        scanf(" %c", &sx);
        sx = toupper(sx);
    }
    return sx;
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
		printf("Escolha sua opcao: ");
		scanf(" %d", &op);
	} while(op < 0 || op > 10);
	return op;
}


// ============ LOCALIZADORES ==========

TCurso *localizaCurso(TLista *lista, string nomeCurso){
	TCurso *curso = lista->inicioC;
	
	while (curso != NULL){
		if(strcmp(curso->nome, nomeCurso) == 0){
			return curso;
		}//if
		curso = curso->prox;
	}//while
	return curso;
}

TAluno *localizaAluno(TLista *lista, string nomeAluno, string nomeCurso){
    TAluno *aluno;
	TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return aluno;
    }
    aluno = curso->alunos;


	while (aluno != NULL){
		if(strcmp(aluno->nome, nomeAluno) == 0){
			break;
		}//if
		aluno = aluno->prox;
	}//while
	return aluno;
}

TDisciplina *defineDisciplina(TLista *lista, string nomeDisciplina) {
    TDisciplina *atual = lista->inicioD;
    while (atual != NULL) {
        if (strcmp(atual->nome, nomeDisciplina) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    printf("\n\n\tERRO: Disciplina \"%s\" nao encontrada.\n\n", nomeDisciplina);
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

    return NULL; // Retorna NULL se o aluno nao for encontrado
}

// =================== INSERES ==============

void insereDisciplina(TLista *lista, string nome, int cargaHoraria){
    int inseriu = 0;
    TDisciplina *novo = (TDisciplina *)malloc(sizeof(TDisciplina));
    novo->cargaHoraria = cargaHoraria;
	strcpy(novo->nome, nome);

    // procura por diciplinas iguais
    TDisciplina *disciplina = defineDisciplina(lista, nome);

    if(disciplina){
        printf("\n\t Disciplina  %s Ja existe! Por favor insira outro nome.", nome);
        return;
    }

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
            atual = atual->prox; //move para o proximo elemento
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

    // procura por cursos iguais
    TCurso *curso = localizaCurso(lista, nome);

    if(curso != NULL){
        printf("\n\t Curso  %s Ja existe! Por favor insira outro nome.", nome);
        return;
    }

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
            atual = atual->prox; // Move para o proximo elemento
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
    // procura por cursos iguais
    TAluno *aluno = localizaAluno(lista, nomeAluno, nomeCurso);
    
    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }
    if(aluno != NULL){
        printf("\n\t Aluno  %s Ja existe! Por favor insira outro nome.", nomeAluno);
        return;
    }

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

void excluiAlunoEmCurso(TLista *lista) {
    printf("\n\n\t\t===| EXCLUIR ALUNO DE CURSO |===\n\n");

    string nomeCurso;
    printf("\tInforme o NOME do CURSO: ");
    inputS(nomeCurso);

    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        system("PAUSE");
        return;
    }

    if (curso->alunos == NULL) {
        printf("\n\n\tO CURSO %s ainda nao possui ALUNOS cadastrados.\n\n", nomeCurso);
        system("PAUSE");
        return;
    }

    string nomeAluno;
    printf("\tInforme o NOME do ALUNO a ser excluido: ");
    inputS(nomeAluno);

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
            printf("\n\n\tAluno \"%s\" excluido do curso %s.\n\n", nomeAluno, nomeCurso);
            system("PAUSE");
            return;
        }
        alunoAnterior = alunoAtual;
        alunoAtual = alunoAtual->prox;
    }

    printf("\n\n\tERRO: Aluno \"%s\" nao encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
    system("PAUSE");
}

void insereHistorico(TLista *lista, string nomeAluno, string nomeDisciplina, string nomeCurso) {
    // Encontra o curso onde o aluno está matriculado
    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    // Pesquisa o aluno na lista de alunos do curso
    TAluno *aluno = localizaAluno(lista, nomeAluno, curso->nome);

    if (aluno == NULL) {
        printf("\n\n\tERRO: Aluno \"%s\" nao encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
        return;
    }

    // Encontra a disciplina na lista
    TDisciplina *disciplina = defineDisciplina(lista, nomeDisciplina);

    if (disciplina != NULL) {
        // Cria um novo historico e preenche suas informações
        THistorico *novoHistorico = (THistorico *)malloc(sizeof(THistorico));
        novoHistorico->disciplina = disciplina;
        printf("Digite a nota que o aluno teve nessa disciplina: ");
        scanf("%f", &novoHistorico->nota);
        printf("Digite o percentual de presença que o aluno teve nessa disciplina: ");
        scanf("%f", &novoHistorico->percentualFrequencia);
        printf("Digite a condiçao que esse aluno está nessa disciplina (Aprovado/Reprovado/Cursando): ");
        inputS(novoHistorico->condicao);

        // Insere o novo historico na lista de historicos do aluno
        novoHistorico->prox = aluno->historico;
        aluno->historico = novoHistorico;

        printf("\n\n\tHistorico inserido com sucesso para a disciplina \"%s\".\n\n", nomeDisciplina);
    }
}


void excluiHistorico(TLista *lista) {
    printf("\n\n\t\t===| EXCLUIR HISToRICO DE ALUNO |===\n\n");

    string nomeCurso, nomeAluno, nomeDisciplina;

    printf("\tInforme o NOME do CURSO: ");
    inputS(nomeCurso);

    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    printf("\tInforme o NOME do ALUNO: ");
    inputS(nomeAluno);

    TAluno *aluno = curso->alunos;

    while (aluno != NULL) {
        if (strcmp(aluno->nome, nomeAluno) == 0) {
            printf("\tInforme o NOME da DISCIPLINA: ");
            inputS(nomeDisciplina);

            if (aluno->historico == NULL) {
                printf("\n\n\tO ALUNO %s nao possui historico cadastrado.\n\n", nomeAluno);
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
                    printf("\n\n\tHISToRICO da DISCIPLINA \"%s\" excluído com sucesso para o ALUNO %s.\n\n", nomeDisciplina, nomeAluno);
                    return;
                }
                historicoAnterior = historicoAtual;
                historicoAtual = historicoAtual->prox;
            }

            printf("\n\n\tERRO: Historico da disciplina \"%s\" nao encontrado para o ALUNO %s.\n\n", nomeDisciplina, nomeAluno);
            return;
        }
        aluno = aluno->prox;
    }

    printf("\n\n\tERRO: Aluno \"%s\" nao encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
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

    insereCurso(lista, nome);
}

void cadastraAlunoEmCurso(TLista *lista){
    // int cargaHoraria;
    string alunoNome;
    string cursoNome;
    char sexo;

    printf("Digite o nome do ALUNO: ");
    inputS(alunoNome);
    sexo = validSexo();
    printf("Digite o nome do Curso: ");
    inputS(cursoNome);

	insereAlunoEmCurso(lista, cursoNome, alunoNome, sexo);

}

void cadastraHistorico(TLista *lista){
    string disciplina;
    string aluno;
    string curso;

    printf("Digite o nome do ALUNO: ");
    inputS(aluno);
    printf("Digite o nome do CURSO: ");
    inputS(curso);
    printf("Digite o nome da DISCIPLINA: ");
    inputS(disciplina);
    insereHistorico(lista, aluno, disciplina, curso);
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
    system("PAUSE");
	printf("\n\n");
}

void exibeCurso(TLista *lista){
   TCurso *curso = lista->inicioC;
	int cont = 1;

	printf("\n\n\t\t===| EXIBE TODOS OS CURSOS |===\n\n");
    while (curso->prox != NULL){
        printf("\n\t(%d) - %s.\n",cont,curso->nome);
        curso = curso->prox;
        cont++;
    }
    if(curso->prox != NULL){
        printf("Nao foram encontrados Cursos Cadastrados");
    }
    system("PAUSE");
	printf("\n\n"); 
}

void exibeAlunosEmCurso(TLista *lista){
	int cont = 0;
	TCurso *curso;
	TAluno *aluno;
	string nome;
	
	printf("\n\n\t\t===| EXIBE TODOS OS ALUNOS EM UM CURSO |===\n\n");
	printf("\tInforme o NOME do CURSO: ");
    inputS(nome);
	
	curso = localizaCurso(lista, nome);
	
	if(curso == NULL){
		printf("\n\n\tERRO: Curso procurado %s NAO foi encontrado.\n\t.", nome);
        printf("\n\t CURSO ENCONTRADO: %s. \n\n", curso->nome);
		system("PAUSE");
	} else {
        aluno = curso->alunos;
		printf("\n\nO CURSO %s tem os seguintes ALUNOS matriculados\n", curso->nome);
		while (aluno != NULL){
			printf("(%d) - %s - %c.\n",cont+1,aluno->nome, aluno->sexo);
			aluno = aluno->prox;
			cont++;
		}
	}
    system("PAUSE");
	printf("\n\n"); 
}

void exibeHistoricoAluno(TLista *lista) {
    printf("\n\n\t\t===| EXIBIR HISToRICO DE ALUNO |===\n\n");

    string nomeCurso, nomeAluno;

    printf("\tInforme o NOME do CURSO: ");
    inputS(nomeCurso);

    TCurso *curso = localizaCurso(lista, nomeCurso);

    if (curso == NULL) {
        printf("\n\n\tERRO: Curso procurado NAO foi encontrado.\n\n");
        return;
    }

    printf("\tInforme o NOME do ALUNO: ");
    inputS(nomeAluno);

    TAluno *aluno = curso->alunos;

    while (aluno != NULL) {
        if (strcmp(aluno->nome, nomeAluno) == 0) {
            if (aluno->historico == NULL) {
                printf("\n\n\tO ALUNO %s nao possui historico cadastrado.\n\n", nomeAluno);
                return;
            }

            printf("\n\n\t===| HISToRICO DO ALUNO %s |===\n\n", nomeAluno);
            THistorico *historico = aluno->historico;
            int cont = 1;

            while (historico != NULL) {
                printf("\n\t(%d) - DISCIPLINA %s.",cont,historico->disciplina->nome);
                printf("\n\t- Frequencia: %.2f% \n", historico->percentualFrequencia);
                printf("\n\t- Nota: %.2f", historico->nota);
                printf("\n\t- Situacao: %s\n", historico->condicao);
                historico = historico->prox;
                cont++;
            }

            system("PAUSE");
            printf("\n\n");
            return;
        }
        aluno = aluno->prox;
    }

    printf("\n\n\tERRO: Aluno \"%s\" nao encontrado no curso %s.\n\n", nomeAluno, nomeCurso);
}
