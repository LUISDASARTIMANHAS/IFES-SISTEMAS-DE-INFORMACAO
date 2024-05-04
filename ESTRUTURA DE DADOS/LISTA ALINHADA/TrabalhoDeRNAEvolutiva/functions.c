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

FILE * abrirArquivo(char * nomeArq, char * modo) {
    // ABRIR o arquivo
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf("\n\n\t ERRO ao abrir o arquivo. \n\n");
        return NULL;
    }
    return arq;
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

void printIndividuos(TLista *L) {
    TIndividuo *atual = L->populacao;
    int i = 1;

    printf("\n\t TABELA DE INDIVIDUOS:\n");
    fprintf(L->fp,"\n\t TABELA DE INDIVIDUOS:\n");
    printf("| \t=========================================================== \t|\n");
    fprintf(L->fp,"| \t=========================================================== \t|\n");
    while (atual!= NULL) {
        printf("| \t(%d) \t| number = %d \t| address = %p \t| errors = %d \t|\n", i, atual->numero, &atual, atual->erros);
        atual = atual->prox;
        // fprintf(L->fp,"| \t(%d) \t| number = %d \t| address = %p \t| errors = %d \t|\n", i, atual->numero, &atual, atual->erros);
        i++;
    }
    printf("| \t=========================================================== \t|\n");
    fprintf(L->fp,"| \t=========================================================== \t|\n");
}

//==================== LOCALIZADORES ================
TIndividuo *localizaIndividuoProx(TLista *lista){
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

// ====================CRUZAMENTO====================

void insere(TLista *lista, TIndividuo *filho){
    int inseriu = 0;
    if (lista->populacao == NULL){
        //Lista encontra-se vazia.
        //Inserir o primeiro e unico elemento da lista ate agora
        lista->populacao = filho;
        lista->populacao->prox = NULL;
        lista->totalIndividuos = 1;
        inseriu = 1;
    }else{
        //Lista ja possui pelo menos 1 elemento
        TIndividuo *atual = lista->populacao;
        TIndividuo *anterior = NULL;
        while (atual != NULL){
            if (atual->numero > filho->numero){
                if (atual == lista->populacao){
                    // Inserir novo no inicio da lista
                    filho->prox = atual;
                    lista->populacao = filho;
                }else{
                    //Inserir novo no meio da lista
                    filho->prox = atual;
                    anterior->prox = filho;
                }
                inseriu = 1;
                lista->totalIndividuos++;
                break;
            }
            anterior = atual;
            atual = atual->prox; //move para o próximo elemento
        }
        if (!inseriu){
            //Inserir elemento no fim da lista
            lista->populacao->prox = filho;
            lista->populacao = filho;
            lista->totalIndividuos++;
        }
        lista->totalIndividuos++;
    }
}
void cruzamento(TLista *L){
	/*Essa funçao deve ler cada um dos individuos da lista e cruza-los, ou seja pegar metade
    dos genes de cada um dos pais selecionados e usar metade dos genes do primeiro individuo usado
    e depois usar a outra metade de genes tirados do segundo individuo selecionado, devem ser feitos 2 individuos
    novos de cada par de individuos selecionados da lista, esses individuos novos devem ser colocados em uma lista 
    auxiliar e apos isso devem ser alocados para a lista principal de forma que a lista principal tenha todos 
    os individuos interligados, no inicio os individuos originais e depois os individuos criados do cruzamento*/
    TIndividuo *pai1, *pai2, *filho1, *filho2;
    pai1 = L->populacao;
    pai2 = pai1->prox;
    while (pai2 != NULL) {
        printf("Cruzando individuo %d com %d\n", pai1->numero, pai2->numero);

        filho1 = (TIndividuo *)malloc(sizeof(TIndividuo));
        filho2 = (TIndividuo *)malloc(sizeof(TIndividuo));
        int metade = MAX_Pesos / 2;
        for (int j = 0; j < metade; j++) {
            filho1->genes[j] = pai1->genes[j];
            filho2->genes[j] = pai2->genes[j];
        }
        for (int j = metade; j < MAX_Pesos; j++) {
            filho1->genes[j] = pai2->genes[j];
            filho2->genes[j] = pai1->genes[j];
        }
        filho1->erros = -1;
        filho2->erros = -1;
        filho1->prox = NULL;
        filho2->prox = NULL;
        insere(L, filho1);
        insere(L, filho2);
        pai1 = pai2;
        pai2 = pai2->prox;
    }
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

float verificar(float n1, float soma, float sinapseThreshold){
	if(soma >= sinapseThreshold){
		n1 = 1;
	}else{
		n1 = 0;
	}
	return n1;
}

void avaliacaoIndividuos(TLista *L){
	/*
	Avalia o grau de adapta��o de cada indiv�duo ao ambiente
	em termos de quantidade de erros cometidos nas li��es da 
	RNA. O objetivo � MINIMIZAR esses ERROS at� ZERO.
	*/
	TIndividuo *atual = (TIndividuo *)malloc(sizeof(TIndividuo));
    TLicao *licaoAtual = (TLicao *)malloc(sizeof(TLicao));
    atual = L->populacao;
    while (atual != NULL){
        if (atual->erros == -1){
            atual->erros = 0;
            licaoAtual = L->licoes;
            while(licaoAtual != NULL){
				float sinapseThreshold = L->sinapseThreshold;
                float n3,soma3,n1,n2;
                float peso13 = atual->genes[0];
                float peso23 = atual->genes[2];

				float n4,soma4;
                float peso14 = atual->genes[1];
                float peso24 = atual->genes[3];

				float n5, soma5;
                float peso15 = atual->genes[4];
                float peso25 = atual->genes[5];

                n1 = L->licoes->p;
                n2 = L->licoes->q;
                soma3 = calcSomaPeso(n1,n2,peso13,peso23);
				n3 = verificar(n3,soma3,sinapseThreshold);

                soma4 = calcSomaPeso(n2,n3,peso14,peso24);
				n4 = verificar(n4,soma4,sinapseThreshold);

                soma5 = calcSomaPeso(n3,n4,peso15,peso25);
				n5 = verificar(n5,soma5,sinapseThreshold);

                if (L->licoes->resultadoEsperado != n5){
                    printf("Cometeu erro\n");
                    atual->erros++;
                }
                licaoAtual = licaoAtual->prox;
            }
        }
        atual = atual->prox;
    }
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