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
        printf("INDISPONIVEL!");
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
        printf("INDISPONIVEL!");
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
    insereDisciplina(lista, "A historia do captalismo conforme o shopping",30);
    insereDisciplina(lista, "Como matar bitters de maneira eficiente ",30);
    insereDisciplina(lista, "Principios do Mainbus",60);
    insereDisciplina(lista, "Principios do Mainbus",60);
    insereDisciplina(lista, "Mecatrônica: Como ter seus robôs ajudantes",45);
    insereDisciplina(lista, "Quimica e engenharia da petrophisto",20);
    insereDisciplina(lista, "Mecatrônica: Como ter seus robôs ajudantes",45);
    insereDisciplina(lista, "Energia sustentável aplicada na prática e consumo adequado",20);
    insereDisciplina(lista, "Terapia de Grupo para Jogadores de Factorio: Lidando com a Síndrome do 'Só Mais um Minuto",100);
    insereDisciplina(lista, "Manobra de veículos",15);
    insereDisciplina(lista, "Logística interna: Organização de inventário",10);
    insereDisciplina(lista, "Perfeccionismo Aplicado à Engenharia: Como Gastar 10 Horas Para Ajustar Um Transportador",60);
    insereDisciplina(lista, "As leis da cimetria aplicadas na prática",60);
    exibeDisciplina(lista);

    // insereCurso(lista, "ADMINISTRACAO");
    // insereCurso(lista, "ARQUITETURA");
    // insereCurso(lista, "SISTEMAS DE INFORMACAO");
    // insereCurso(lista, "Factoriologia: Curso Avançado em Engenharia de Precisão e Perfeccionismo");
    exibeCurso(lista);

    // insereAlunoEmCurso(lista, "Luis");
    // insereAlunoEmCurso(lista, "Lucas");
    // insereAlunoEmCurso(lista, "Mephisto");
    // insereAlunoEmCurso(lista, "Soul");
    // insereAlunoEmCurso(lista, "Caio");
    // insereAlunoEmCurso(lista, "Bob o pato");
    // insereAlunoEmCurso(lista, "Sans");
    exibeAlunosEmCurso(lista);

    // insereHistorico(lista, "Prog1", 10, 50);
    // insereHistorico(lista, "Math", 30, 100);
    // insereHistorico(lista, "ED", 20, 98);
    // insereHistorico(lista, "POO", 10, 50);
    // exibeHistorico(lista);
}
//===================================================================
int main(){
    inicializa(&listas);
    realizaOpcaoDesejada(&listas);
    return 0;
}
