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


