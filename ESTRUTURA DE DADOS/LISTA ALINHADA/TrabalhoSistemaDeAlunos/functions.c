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


// void insereAtor(TLista *DB, string nome){
//     TAtor *novo = (TAtor *)malloc(sizeof(TAtor));
//     TAtor *atual = DB->inicioA;
//     TAtor *anterior = NULL;
//     int inseriu = 0;
    

//     novo->prox = NULL;
//     strcpy(novo->nome,nome);
//     printf("\nINSERINDO ATOR: %s...",nome);

//     if(DB->inicioA == NULL){
//         DB->inicioA = novo;
//         DB->fimA = novo;
//     }else{
//         while(atual != NULL){
//             if (strcmp(atual->nome,novo->nome) > 0)	{
//                 inseriu = 1;
//                 if(atual == DB->inicioA)	{
//                     novo->prox = atual;
//                     DB->inicioA = novo;	
//                 } else {
//                     novo->prox = anterior->prox;
//                     anterior->prox = novo;
//                 }
//                 break;
//             }
//             anterior = atual;
//             atual = atual->prox;
//         }
        
//         if(!inseriu){
//             DB->fimA->prox = novo;
//             DB->fimA = novo;
//         }
//     }
// }

// void insereFilme(TLista *DB, string titulo, int ano){
//     TFilme *novo = (TFilme *)malloc(sizeof(TFilme));
//     TFilme *atual = DB->inicioF;
//     TFilme *anterior = NULL;
//     int inseriu = 0;

//     novo->ante = NULL;
//     novo->prox = NULL;
//     novo->elenco = NULL;
//     novo->anoProducao = ano;
//     strcpy(novo->titulo,titulo);
//     printf("\nINSERINDO FILME: %s...",titulo);

//     if(DB->inicioF == NULL){
//         DB->inicioF = novo;
//         DB->fimF = novo;
//     }else{
//         inseriu = 0;
//         anterior = atual->ante;
//         while(atual != NULL){
//             if (strcmp(atual->titulo,novo->titulo) > 0)	{
//                 inseriu = 1;
//                 novo->prox = atual;
//                 atual->ante = novo;

//                 if(anterior == NULL){
//                     DB->inicioF = novo;	
//                 } else {
//                     anterior->prox = novo;
//                     novo->ante = anterior;
//                 }
//                 break;
//             }
//             atual = atual->prox;
//         }
        
//         if(!inseriu){
//             DB->fimF->prox = novo;
//             novo->ante = DB->fimF;
//             DB->fimF = novo;
//         }
//     }
// }

// void cadastraAtor(TLista *DB){
//     string nome;

//     printf("\n\n\t=====| INSERE ATOR|=====\n\n");
//     printf("\tInforme o nome do ator: ");
//     fflush(stdin);
//     inputS(nome);

//     insereAtor(DB, nome);
// }

// void cadastraFilme(TLista *DB){
//     string titulo;
//     int ano;


//     printf("\n\n\t=====| CADASTRO DE FILMES |=====\n\n");
//     printf(YELLOW"\tTITULO: ");
//     fflush(stdin);
//     inputS(titulo);

//     printf("\n\n\tANO DE PRODUÇÃO: "RESET);
//     fflush(stdin);
//     ano = input();

//     insereFilme(DB, titulo, ano);
// }

// void exibeAtores(TLista *DB){
// 	TAtor *atual = DB->inicioA;
// 	int cont = 0;
	
// 	printf("\n\n");
// 	printf("+----------------------------------------------------+\n");
// 	while (atual != NULL)	{
// 		printf("\t(%d) - %s.\n", ++cont, atual->nome);
// 		atual = atual->prox;
// 	}//while
// 	printf("+----------------------------------------------------+\n\n\n");
// }

// void exibeFilmes(TLista *DB){
// 	TFilme *atual = DB->inicioF;
//     TElenco *cursor;
//     TAtor *ator;
// 	int cont = 0;
	
// 	printf("\n\n");
// 	printf(BLUE"+----------------------------------------------------+\n");
// 	while (atual != NULL)	{
// 		printf("\t(%d) - %s [%d].\n", ++cont, atual->titulo, atual->anoProducao);
//         if (atual->elenco !=NULL){
//             printf("\n");
//             cursor = atual->elenco;
//             while (cursor != NULL){

//                 printf("\t\t%s\n",cursor->ator->nome);
//                 cursor = cursor->prox;
//             }
            
//         }
        
// 		atual = atual->prox;
// 	}//while
// 	printf("+----------------------------------------------------+\n\n\n"RESET);
// }

// TFilme *localizaFilme(TLista *DB, string titulo){
// 	TFilme *atual = DB->inicioF;
	
// 	while (atual != NULL){
// 		if(strcmp(atual->titulo, titulo) == 0){
// 			break;
// 		}//if
// 		atual = atual->prox;
// 	}//while
// 	return atual;
// }

// TAtor *localizaAtor(TLista *DB, string nome){
// 	TAtor *atual = DB->inicioA;
	
// 	while(atual != NULL)	{
// 		if(strcmp(atual->nome, nome) == 0) {
// 			break;
// 		}//if
// 		atual = atual->prox;
// 	}//while
// 	return atual;
// }

// void relacionarFilmeAtor(TFilme *filme, TAtor *a){
// 	TElenco *novo = (TElenco *)malloc(sizeof(TElenco));
	
// 	novo->prox = NULL;
// 	novo->ator = a;
	
// 	if(filme->elenco != NULL){
// 	   TElenco *atual = filme->elenco;
// 	   while(atual->prox != NULL){
// 			atual = atual->prox;
//        }//while
// 	   atual->prox = novo;		
// 	} else {
// 	   filme->elenco = novo;
// 	}//if
// }

// void criaElenco(TLista *DB, string titulo, string nomeAtor){
// 	TFilme *f = localizaFilme(DB,titulo);
// 	if(f != NULL){
// 		TAtor *a = localizaAtor(DB, nomeAtor);
		
// 		if(a != NULL)	{
// 			relacionarFilmeAtor(f,a);
// 		}//if
// 	}//if	
// }