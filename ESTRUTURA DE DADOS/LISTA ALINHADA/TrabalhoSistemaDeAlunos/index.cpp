// <code-runner> --compile-options -static -static-libgcc -static-libstdc++ </code-runner>

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

void cadastraCurso(TLista *lista){
    // int cargaHoraria;
    // string nome;

    // printf("Digite o nome da Disciplina: ");
    // printf("Digite qual e a carga horaria: ");

    // insereCurso(lista, nome, cargaHoraria);
}

void cadastraAlunoEmCurso(TLista *lista){
    // int cargaHoraria;
    // string nome;

    // printf("Digite o nome da Disciplina: ");
    // printf("Digite qual e a carga horaria: ");

    // insereAlunoEmCurso(lista, nome, cargaHoraria);
}

void cadastraHistorico(TLista *lista){
    string disciplina;
    string condicao;
    int nota;
    float percentualFrequencia;

    printf("Digite o nome da Disciplina onde deseja cadastrar o Historico: ");
    inputS(disciplina);
    printf("Digite qual e a nota do aluno: ");
    nota = input();
    printf("Digite qual e o percentual de frequencia do aluno: ");
    percentualFrequencia = input();

    // insereHistorico(lista, disciplina, nota, percentualFrequencia);
}

void exibeHistorico(TLista *lista){

}

void realizaOpcaoDesejada(TLista *listas){
    int op;
    do{
        op = menu();
    switch (op){
        case 1:
        // Inserir DISCIPLINA
        cadastraDisciplina(listas);
        break;

        case 2:
        // Exibe Todas as DISCIPLINAS
        exibeDisciplina(listas);
        break;

        case 3:
        // Inserir CURSO
        cadastraCurso(listas);
        break;

        case 4:
        // Exibir Todos os CURSOS
        exibeCurso(listas);
        break;

        case 5:
        // Inserir ALUNO em CURSO
        cadastraAlunoEmCurso(listas);
        break;

        case 6:
        // Exibir Todos os ALUNOS de CURSO especifico
        exibeAlunosEmCurso(listas);
        break;

        case 7:
        // Excluir ALUNO de CURSO
        // excluiAlunoEmCurso(listas);
        break;

        case 8:
        // Inserir HISTORICO para ALUNO
        cadastraHistorico(listas);
        break;

        case 9:
        // Exibir HISTORICO de ALUNO.
        exibeHistorico(listas);
        break;

        case 10:
        // Excluir HISTORICO de ALUNO
        // excluiHistorico(listas);
        break;
    default:
        printf("\nERRO: Opção invalida, tente novamente\n");
        break;
    }
    } while (op != 0);
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

    // insereCurso(lista, "ADMINISTRACAO");
    // insereCurso(lista, "ARQUITETURA");
    // insereCurso(lista, "SISTEMAS DE INFORMACAO");
    // exibeCurso(lista);

    // insereAlunoEmCurso(lista, "Luis");
    // insereAlunoEmCurso(lista, "Lucas");
    // insereAlunoEmCurso(lista, "Mephisto");
    // insereAlunoEmCurso(lista, "Soul");
    // insereAlunoEmCurso(lista, "Caio");
    // insereAlunoEmCurso(lista, "Bob o pato");
    // insereAlunoEmCurso(lista, "Sans");
    // exibeAlunosEmCurso(lista);

    // insereHistorico(lista, "Prog1", 10, 50);
    // insereHistorico(lista, "Math", 30, 100);
    // insereHistorico(lista, "ED", 20, 98);
    // insereHistorico(lista, "POO", 10, 50);
    exibeHistorico(lista);
}
//===================================================================
int main(){
    inicializa(&listas);
    realizaOpcaoDesejada(&listas);
    return 0;
}
