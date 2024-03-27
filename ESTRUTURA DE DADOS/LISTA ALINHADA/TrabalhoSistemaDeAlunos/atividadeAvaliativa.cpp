#include <stdlib.h>
#include <stdio.h>
#include "functions.c"


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
}TLista;

TLista listas;

int menu(){
    printf(BLUE"\n\n\t\t =====| MENU |=====\n\n");
    printf(RED"\t0 - Sair (Encerrar a Aplicacao).\n\n");
    printf(BLUE"\t1 - Inserir DISCIPLINA.\n\n");
    printf("\t2 - Exibe Todas as DICIPLINAS.\n\n");
    printf("\t3 - Inserir CURSO.\n\n");
    printf("\t4 - Exibe Todos os CURSOS.\n\n");
    printf("\t5 - Inserir ALUNO em CURSO.\n\n");
    printf("\t6 - Exibe Todos os ALUNOS de CURSO especifico.\n\n");
    printf(RED"\t7 - Excluir ALUNO de CURSO.\n\n");
    printf(BLUE"\t8 - Inserir HISTORICO para ALUNO.\n\n");
    printf("\t9 - Exibe HISTORICO de ALUNO.\n\n");
    printf(RED"\t10 - Excluir HISTORICO de ALUNO.\n\n"RESET);
}

void inicializa(TLista *DB){
    menu();
    copy();
}

int main(){
    inicializa(&listas);
    return 0;
}

