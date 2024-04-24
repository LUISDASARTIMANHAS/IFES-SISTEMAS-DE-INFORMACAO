// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/*
  Rede Neural Artificial Evolutiva (RNA-E)
  
  Os pesos s�o atualizados a partir de um algoritmo
  gen�tico que busca minimizar os erros na fase de
  treinamento.
  
*/
// ============================= BASE ======================
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
// #include "utils.c"
// Defina constantes para as sequÃªncias de escape ANSI das cores

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

#define MAX_Entradas 2
#define MAX_Pesos 6

//===| Estrutura de Dados |==========================
typedef char string[60];

typedef struct tipoLicao {
	int p;  //proposi��o P
	int q;	//Proposi��o Q
	int resultadoEsperado; //Proposi��o Composta P "E" Q (A Classe)
	tipoLicao *prox;
}TLicao;

typedef struct tipoIndividuo {
	float genes[MAX_Pesos];
	int erros;
	int numero; //numero identificador
	tipoIndividuo  *prox;
}TIndividuo;

typedef struct tipoSinapse {
	int camada;
	int neuronio_origem;
	int neuronio_destino;
	float peso;
	tipoSinapse *prox;
}TSinapse;

typedef struct tipoNeuronio {
	int neuronio;
	float soma;
	float peso;
	tipoNeuronio *prox;
}TNeuronio;

typedef struct tipoLista{
	FILE *fp; //Arquivo de Sa�da (Relat�rio).
	string objetivo;
	TLicao *licoes; //Conjunto de li��es a serem aprendidas
	float entradas[MAX_Entradas];
	TNeuronio *neuronios;
	TSinapse *pesos;
	TIndividuo *populacao;
	TIndividuo *individuoAtual;
	int totalIndividuos;
	int Qtd_Populacao;
	int Qtd_Mutacoes_por_vez;
	int Total_geracoes;
	int geracao_atual;
	int Qtd_Geracoes_para_Mutacoes; 
	float sinapseThreshold;
	float learningRate;
}TLista;

// inputs personalizados e modificados EX: variavel = input();
float input(){
    float value;
    fflush(stdin);
    scanf("%f", &value);
    return value;
}

float inputBoleano(){
    int value;
    do{
    	fflush(stdin);
    	scanf("%d", &value);
	}while(value != 1 && value != 0);
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



//==================== LOCALIZADORES ================
TIndividuo *localizaIndividuoProx(TLista *lista, string nomeAluno, string nomeCurso){
    TIndividuo *individuo;

	while (individuo != NULL){
		if(individuo->numero){
			break;
		}//if
		individuo = individuo->prox;
	}//while
	return individuo;
}
//====================================================
void geraIndividuos(TLista *L){
	TIndividuo *novo;
	int i, x;
	
    srand( (unsigned)time(NULL) );
    
    for(i= 0; i < L->Qtd_Populacao; i++){
    	novo = (TIndividuo *)malloc(sizeof(TIndividuo));
		
		novo->prox = NULL;
		novo->numero = i+1;		
		novo->erros = -1;
		
		for(x=0; x < MAX_Pesos; x++){
			novo->genes[x] = rand() % 101;
			novo->genes[x] = novo->genes[x] / 100;
		}//for
		
		if(L->populacao == NULL){
			L->populacao = novo;
		} else {
			TIndividuo *atual = L->populacao;
			
			while(atual->prox != NULL){
				atual = atual->prox;
			}//while
			
			atual->prox = novo;
		}//if
		
		L->totalIndividuos++;
	}//for
}
//=====================================================
void insereLicao(TLista *L, int p, int q, int resultado){
	TLicao *novo = (TLicao *)malloc(sizeof(TLicao));
	
	novo->prox = NULL;
	novo->p = p;
	novo->q = q;
	novo->resultadoEsperado = resultado;
	
	if(L->licoes == NULL){
		L->licoes = novo;
	} else {
		TLicao *atual = L->licoes;
		
		while(atual->prox != NULL){
			atual = atual->prox;			
		}//while
		atual->prox = novo;
	}//if
}
//=====================================================
void geraLicoes(TLista *L){
	TLicao *novo;
	int p,q;
	
	insereLicao(L, 0, 0, 0);
	insereLicao(L, 0, 1, 0);
	insereLicao(L, 1, 0, 0);
	insereLicao(L, 1, 1, 1);

}
//======================================================
void insereNeuronio(TLista *L, int neuronio){
	TNeuronio *novo = (TNeuronio *)malloc(sizeof(TNeuronio));
	novo->prox = NULL;
	novo->neuronio = neuronio;
	novo->peso = 0;
	novo->soma = 0;
	
	if(L->neuronios == NULL){
		L->neuronios = novo;
	} else {
		TNeuronio *atual = L->neuronios;
		
		while(atual->prox != NULL){
			atual = atual->prox;
		}//while
		atual->prox = novo;
	}//if
}
//======================================================
void estabelecendoSinapse(TLista *L,int neuronioDe, int neuronioAte, int camada){
	TSinapse *novo = (TSinapse *)malloc(sizeof(TSinapse));
	TSinapse *atual;
	
	novo->prox = NULL;
	novo->neuronio_origem = neuronioDe;
	novo->neuronio_destino = neuronioAte;
	novo->camada = camada;
	novo->peso = 0;
	
	if(L->pesos == NULL){
		L->pesos = novo;
	} else {
		atual = L->pesos;
		
		while(atual->prox != NULL){
			atual = atual->prox;
		}//while
		atual->prox = novo;
	}//if
}
//=============================================================
void cruzamento(TLista *L){
	/* Fun��o respons�vel pelo cruzamento de individuos.
	   Cada casal (selecionado por proximidade) gera dois
	   descendentes. E cada descendente herda segmentos
	   do c�digo gen�tico de seus pais.
	*/
	// TIndividuo *filhote1 = (TIndividuo *)malloc(sizeof(TIndividuo));
	// TIndividuo *filhote2 = (TIndividuo *)malloc(sizeof(TIndividuo));

	// filhote1->prox = NULL;
	// filhote1->erros = -1;
	// filhote1->genes;
	// filhote1->numero = 0;

	// filhote2->prox = NULL;
	// filhote2->erros = -1;
	// filhote2->genes;
	// filhote2->numero = 0;

	// for (int iFilhos = 0, iPaes = 0; iPaes < iPaes.genes; iPaes++,iFilhos++) {
	//     if(iPaes <= 2){
	//         filhote1[iFilhos] = pai[iPaes];
	//         filhote2[iFilhos] = mae[iPaes];
	//     }else{
	//         filhote1[iFilhos] = mae[iPaes];
	//         filhote2[iFilhos] = pai[iPaes];
	//     }
	// }
	
	
	// if(L->neuronios == NULL){
	// 	L->neuronios = novo;
	// } else {
	// 	TNeuronio *atual = L->neuronios;
		
	// 	while(atual->prox != NULL){
	// 		atual = atual->prox;
	// 	}//while
	// 	atual->prox = novo;
	// }//if
}
//==============================================================
void promoveMutacoes(TLista *L){
	/* Altera o c�digo gen�tico de um n�mero espec�fico
	   de indiv�duos (= L->Qtd_Mutacoes_por_vez). */
	   
		// escolha ramdomica do individuo
		// escolha ramdomica do gene 
		//  escolha ramdomica do sentido para cima(+)
		//  para baix (-)
		// [0.8, 0.7, 0.3, 0.6, 0.5, 0.4]

		//  mudanca pra cima 
		// gene 2 e igual a posicao do vetor [2]
		// taxa de aprendizado 0.2

	  	//[0.8, 0.7, 0.3 + 0.2 , 0.6, 0.5, 0.4] 
		//[0.8, 0.7, 0.5 , 0.6, 0.5, 0.4] 
		// total de erros volta a ser -1
	   
}

//=============================================================
float calcSomaPeso(float n1, float n2, float peso1, float peso2){
	float soma;

	soma  = n1 * peso1 + n2 * peso2;
	return soma;
}

void verificar(TIndividuo *indv, float n1, float n5, float soma, float sinapseThreshold, float resultadoEsperado){
	if(soma >= sinapseThreshold){
		n1 = 1;
	}else{
		n1 = 0;
	}
	if(resultadoEsperado == n5){
			indv->erros++;
	}
}

void avaliacaoIndividuos(TLista *L){
	/*
	Avalia o grau de adapta��o de cada indiv�duo ao ambiente
	em termos de quantidade de erros cometidos nas li��es da 
	RNA. O objetivo � MINIMIZAR esses ERROS at� ZERO.
	*/
	// TIndividuo *indv = indv->prox;
	// float n1,n2,n3,n4,n5; 
	// float peso13,peso21;
	// float soma3;
	// peso13 = indv[0];
	// peso21 = indv[2];
	// n1 = licao.p;
	// n2 = licao.p;
	// soma3 = calcSomaPeso(n1,n2,peso13,peso23);
	// verificar();
}


//a sacada do menos 1 so vai ler o individuo que estão no total de erros

//==============================================================
void ordenamentoIndividuos(TLista *L){
	/* Reordena os indiv�duos por ordem ascendente de erros:
	   os indiv�duos que cometeram menos erros dever�o permanecer
	   no in�cio da Lista e os que cometeram mais erros dever�o 
	   ficar no final da mesma Lista. */
	   
}
//==============================================================
void poda(TLista *L){
	/* Elimina os indiv�duos menos aptos (que est�o no
	   fim da Lista) at� que a popula��o volte ao seu
	   Limite estabelecido na configura��o inicial 
	   (L->Qtd_Populacao). */

	//    while ( L->Qtd_Populacao =< 0){
	// 	/* code */
	//    }
	   
	   
}
//=============================================================
void treinamento(TLista *L){
	printf("\n\n\t\t=====| INICIADO TREINAMENTO |=====\n\n");
	fprintf(L->fp,"\n\n\tINICIO DO TREINAMENTO: ");
	//ponteiro para a struct que armazena data e hora:
	struct tm *data_hora_atual;
	//vari�vel do tipo time_t para armazenar o tempo em segundos.
	time_t segundos;
	//Obetendo o tempo em segundos.
	time(&segundos);
	//Para converter de segundos para o tempo local
	//utilizamos a fun��o localtime().
	data_hora_atual = localtime(&segundos);
	
	fprintf(L->fp,"Dia: %d", data_hora_atual->tm_mday);
	fprintf(L->fp,"   Mes: %d", data_hora_atual->tm_mon+1);
	fprintf(L->fp,"   Ano: %d\n\n", data_hora_atual->tm_year+1900);
	
	fprintf(L->fp,"Dia da Semana: %d.\n", data_hora_atual->tm_wday);
	
	fprintf(L->fp,"%d", data_hora_atual->tm_hour);
	fprintf(L->fp,":%d", data_hora_atual->tm_min);
	fprintf(L->fp,":%d.\n\n", data_hora_atual->tm_sec);
	
	int i;
	for(i= 0; i < L->Total_geracoes; i++){
		cruzamento(L);
		
		if((i % L->Qtd_Geracoes_para_Mutacoes) == 0){
			promoveMutacoes(L);
		}//if
		
		avaliacaoIndividuos(L);
		
		ordenamentoIndividuos(L);
		
		poda(L);
		
	}//for
	
}
