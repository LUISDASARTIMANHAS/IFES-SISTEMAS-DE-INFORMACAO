// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/* 
  Tarefa Avaliativa (Semana 08).
  implementaÃ§Ã£o de uma lista encadeada aninhada.

*/
#include <windows.h>
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
        excluiAlunoEmCurso(listas);
        break;

        case 8:
        // Inserir HISTORICO para ALUNO
        cadastraHistorico(listas);
        break;

        case 9:
        // Exibir HISTORICO de ALUNO.
        exibeHistoricoAluno(listas);
        break;

        case 10:
        // Excluir HISTORICO de ALUNO
        excluiHistorico(listas);
        break;
    default:
        printf("\nSaindo do programa e encerrando a aplicacao\n");
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
    insereDisciplina(lista, "Mecatronica: Como ter seus robôs ajudantes",45);
    insereDisciplina(lista, "Quimica e engenharia da petrophisto",20);
    insereDisciplina(lista, "Energia Sustentável aplicada na prática e consumo adequado",20);
    insereDisciplina(lista, "Terapia de Grupo para Jogadores de Factorio: Lidando com a Síndrome do só Mais um Minuto",100);
    insereDisciplina(lista, "Manobra de veículos",15);
    insereDisciplina(lista, "Logística interna: Organizações de inventário",10);
    insereDisciplina(lista, "Perfeccionismo Aplicado A Engenharia: Como Gastar 10 Horas Para Ajustar Um Transportador",60);
    insereDisciplina(lista, "As leis da cimetria aplicadas na prática",60);

    insereCurso(lista, "ADMINISTRACAO");
    insereCurso(lista, "ARQUITETURA");
    insereCurso(lista, "SISTEMAS DE INFORMACAO");
    insereCurso(lista, "Factoriologia: Curso Avançado em Engenharia de Precisão e Perfeccionismo");

    insereAlunoEmCurso(lista, "SISTEMAS DE INFORMACAO", "Luis", 'M');
    insereAlunoEmCurso(lista, "SISTEMAS DE INFORMACAO", "Lucas", 'M');
    insereAlunoEmCurso(lista, "Factoriologia: Curso Avançado em Engenharia de PrecisÃ£o e Perfeccionismo", "Mephisto", 'M');
    insereAlunoEmCurso(lista, "Factoriologia: Curso Avançado em Engenharia de PrecisÃ£o e Perfeccionismo", "Soul", 'M');
    insereAlunoEmCurso(lista, "Factoriologia: Curso Avançado em Engenharia de PrecisÃ£o e Perfeccionismo", "Caio", 'M');
    insereAlunoEmCurso(lista, "Factoriologia: Curso Avançado em Engenharia de PrecisÃ£o e Perfeccionismo", "Bob o pato", 'M');
    insereAlunoEmCurso(lista, "Factoriologia: Curso Avançado em Engenharia de PrecisÃ£o e Perfeccionismo", "Sans", 'M');
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
}
//===================================================================
int main(){
	SetConsoleOutputCP(65001);
    inicializa(&listas);
    realizaOpcaoDesejada(&listas);
    return 0;
}
