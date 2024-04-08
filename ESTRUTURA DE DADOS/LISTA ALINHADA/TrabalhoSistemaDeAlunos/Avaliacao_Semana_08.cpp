/* 
  Tarefa Avaliativa (Semana 08).
  implementação de uma lista encadeada aninhada.
  
*/
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
}TLista;

TLista listas;


int main(){
	
}
//===================================================================
int menu(){
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
}
