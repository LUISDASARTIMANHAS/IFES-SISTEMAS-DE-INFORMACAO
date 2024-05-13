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
	TIndividuo *fimLista;
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

// gera um numero aleatorio no intervalo n,
int aleatorio(int n){
    return (rand() % (n+1));
}

void printRel(TLista *L, string text){
	fprintf(L->fp,"%s",text);
}

// ============================= FIM DO BASE ======================
int menu(){
	int op;
	printf("\n\n\t\t====| MENU |=====\n\n");
	printf("\t0 - Sair (Encerrar a Aplicacao).\n\n");
	do {
		printf("Escolha sua opcao: ");
		scanf(" %d", &op);
	} while(op < 0 || op > 1);
	return op;
}

void exibeIndividuos(TLista *L) {
	TIndividuo *atual = L->populacao;
	int i = 1;
	int j;
	int bytes;

	printf("\n\t TABELA DE INDIVIDUOS:\n");
	while (atual != NULL) {
		// printf("| \t(%d) \t| numero = %d \t| endr = %p \t| err = %d \t| %d -> %d \t|\n", i, atual->numero, &atual, atual->erros,atual->numero,atual->prox->numero);
		printf("| \t(%d) ",i);
		printf("\t| numero = %d ",atual->numero);
		printf("\t| endr = %p ",&atual);
		printf("\t| err = %d ",atual->erros);
		if(atual->prox == NULL){
			printf("\t| %d -> NULL ",atual->numero);
		}else{
			printf("\t| %d -> %d ",atual->numero,atual->prox->numero);
		}
		printf("\t| genes = ");
		for (j = 0; j < MAX_Pesos; j++){
			printf("%.2f,",atual->genes[j]);
		}
		printf("\t|\n");
		atual = atual->prox;
		i++;
	}
	bytes = sizeof(TIndividuo) * i;
	printf("TAM %dMbytes\n", bytes/1024);
}

//==================== LOCALIZADORES ================
TIndividuo *localizaIndividuoFinal(TLista *lista){
	TIndividuo *fimLista;
	// TIndividuo *atual = lista->populacao;
	TIndividuo *atual = (TIndividuo *)malloc(sizeof(TIndividuo));
			
			while(atual->prox != NULL){
				atual = atual->prox;
			}//while
			
			fimLista = atual->prox;
			printf("\t| numero = %d ",fimLista->numero);
	return fimLista;
}

TIndividuo *localizaMelhorIndividuo(TLista *lista){
	TIndividuo *melhorIndv;
	TIndividuo *atual = lista->populacao;

			while(atual->prox != NULL){
				if (atual->erros < 1 ){
					melhorIndv = atual;
				}
				atual = atual->prox;
			}//while
	return melhorIndv;
}

TIndividuo *localizaPiorIndividuo(TLista *lista){
	TIndividuo *piorIndv;
	TIndividuo *atual = lista->populacao;

			while(atual->prox != NULL){
				if (atual->erros > 0){
					piorIndv = atual;
				}
				atual = atual->prox;
			}//while
	return piorIndv;
}

// ===========================================================
void geraTabela(FILE *arq, TIndividuo *indv){
		fprintf(arq,"\t| numero = %d ",indv->numero);
		fprintf(arq,"\t| endr = %p ",&indv);
		fprintf(arq,"\t| err = %d ",indv->erros);
		if(indv->prox == NULL){
			fprintf(arq,"\t| %d -> NULL ",indv->numero);
		}else{
			fprintf(arq,"\t| %d -> %d ",indv->numero,indv->prox->numero);
		}
		fprintf(arq,"\t|\n");
}

void geraRelatorio(TLista *L){
	TIndividuo *melhorIndv = localizaMelhorIndividuo(L);
	TIndividuo *piorIndv = localizaPiorIndividuo(L);
	FILE *rel = L->fp;
	int totalDeGeracoes = L->Total_geracoes;
	int totalDeindv = L->totalIndividuos;
	int bytes = sizeof(TIndividuo) * totalDeindv * totalDeGeracoes;

	fprintf(rel,"\n\t TABELA DE INDIVIDUOS:\n");
	fprintf(rel,"\n\t Melhor Individuo:\n");
	geraTabela(rel,melhorIndv);
	fprintf(rel,"\n\t Pior Individuo:\n");
	geraTabela(rel,piorIndv);
	fprintf(rel,"TAM %dMbytes\n", bytes/1024);
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
void inserirNoFimAux(TLista *L, TIndividuo *individuo) {
    if (L->populacao == NULL) { // Se a lista estiver vazia
        L->populacao = individuo;
        L->totalIndividuos++;
        return;
    }
    TIndividuo *aux = L->populacao;
    while (aux->prox != NULL) { // Percorre até o último elemento da lista
        aux = aux->prox;
    }
    aux->prox = individuo; // Adiciona o novo indivíduo ao final da lista
    L->totalIndividuos++;
}

void inserirNoFim(TLista *L, TIndividuo *individuo) {
    TIndividuo *clone = (TIndividuo *)malloc(sizeof(TIndividuo)); // Clonar o indivíduo
    memcpy(clone, individuo, sizeof(TIndividuo));
    clone->prox = NULL;
    inserirNoFimAux(L, clone);
}

void geraFilhos(TLista *L, TIndividuo *pai,TIndividuo *mae){
	int iFilhos,iPaes;
	TIndividuo *filho1 = (TIndividuo *)malloc(sizeof(TIndividuo));
	TIndividuo *filho2 = (TIndividuo *)malloc(sizeof(TIndividuo));

	L->totalIndividuos = L->totalIndividuos + 1;
	filho1->numero = L->totalIndividuos;
	L->totalIndividuos = L->totalIndividuos + 1;
	filho2->numero = L->totalIndividuos;
	filho1->erros = -1;
	filho2->erros = -1;
	filho1->prox = NULL;
	filho2->prox = NULL;
	for (iFilhos = 0, iPaes = 0; iPaes < MAX_Pesos; iPaes++,iFilhos++) {
		if(iPaes <= 2){
			filho1->genes[iFilhos] = pai->genes[iPaes];
			filho2->genes[iFilhos] = mae->genes[iPaes];
		}else{
			filho1->genes[iFilhos] = mae->genes[iPaes];
			filho2->genes[iFilhos] = pai->genes[iPaes];
		}
	}
	inserirNoFim(L, filho1);
	inserirNoFim(L, filho2);
}

void cruzamento(TLista *L){
	/*Essa funçao deve ler cada um dos individuos da lista e cruza-los, ou seja pegar metade
	dos genes de cada um dos pais selecionados e usar metade dos genes do primeiro individuo usado
	e depois usar a outra metade de genes tirados do segundo individuo selecionado, devem ser feitos 2 individuos
	novos de cada par de individuos selecionados da lista, esses individuos novos devem ser colocados em uma lista 
	auxiliar e apos isso devem ser alocados para a lista principal de forma que a lista principal tenha todos 
	os individuos interligados, no inicio os individuos originais e depois os individuos criados do cruzamento*/
	TIndividuo *pai1 = L->populacao;
	TIndividuo *pai2 = pai1->prox;
	int individuosCruzados = 0;
    int totalPais = L->totalIndividuos;

	while (individuosCruzados < totalPais / 2) {
		printf("Cruzando individuo %d com %d\n", pai1->numero, pai2->numero);

		geraFilhos(L, pai1,pai2);
		individuosCruzados += 1;
        
        // Avançar para os próximos pais, garantindo que não ultrapassemos o final da lista
        if (pai1->prox != NULL) {
            pai1 = pai1->prox;
        }
        if (pai2->prox != NULL) {
            pai2 = pai2->prox;
        }
	}
}
//==============================================================
void promoveMutacoes(TLista *L){
	/* Altera o c�digo gen�tico de um n�mero espec�fico
	de indiv�duos (= L->Qtd_Mutacoes_por_vez). */
	// Verificar se a lista está vazia
    if (L->populacao == NULL) {
        printf("Lista de individuos vazia.\n");
        return;
    }

    // Escolher um indivíduo aleatório
    int index = rand() % L->totalIndividuos;
    TIndividuo *individuo = L->populacao;

    // Percorrer até o índice do indivíduo escolhido
    for (int i = 0; i < index; i++) {
        individuo = individuo->prox;
    }

    // Escolher um gene aleatório
    int geneIndex = rand() % MAX_Pesos;

    // Escolher aleatoriamente se a mutação será para cima ou para baixo
    int upOrDown = rand() % 2; // 0 para baixo, 1 para cima

    // Aplicar a mutação
    if (upOrDown == 0) {
        individuo->genes[geneIndex] -= L->learningRate; // Diminuir do valor do gene
    } else {
        individuo->genes[geneIndex] += L->learningRate; // Somar ao valor do gene
    }

    printf("Mutacao promovida com sucesso.\n");
}

//=============================================================
float calcSomaPeso(float n1, float n2, float peso1, float peso2){
	float soma;

	soma  =(n1 * peso1) + (n2 * peso2);
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

	printf("AVALIANDO INDIVIDUOS...");
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

				n1 = licaoAtual->p;
				n2 = licaoAtual->q;
				soma3 = calcSomaPeso(n1,n2,peso13,peso23);
				n3 = verificar(n3,soma3,sinapseThreshold);

				soma4 = calcSomaPeso(n2,n3,peso14,peso24);
				n4 = verificar(n4,soma4,sinapseThreshold);

				soma5 = calcSomaPeso(n3,n4,peso15,peso25);
				n5 = verificar(n5,soma5,sinapseThreshold);

				if (licaoAtual->resultadoEsperado != n5){
					printf("Cometeu erro\n");
					atual->erros++;
				}
				licaoAtual = licaoAtual->prox;
			}
		}
		atual = atual->prox;
	}
}

//==============================================================
void ordenamentoIndividuos(TLista *L){
	/* Reordena os indiv�duos por ordem ascendente de erros: 
	os indiv�duos que cometeram menos erros dever�o permanecer no in�cio da Lista e os que cometeram mais erros dever�o ficar no final da mesma Lista. */
	TIndividuo *atual, *anterior, *temp;
    int trocou;

    // Se a lista estiver vazia ou tiver apenas um elemento, não há nada a ordenar
    if (L->populacao == NULL || L->populacao->prox == NULL) {
        return;
    }

    do {
        trocou = 0;
        atual = L->populacao;
        anterior = NULL;

        while (atual->prox != NULL) {
            // Se o número de erros do próximo indivíduo for maior que o atual, troque-os de lugar
            if (atual->erros > atual->prox->erros) {
                temp = atual->prox;
                atual->prox = atual->prox->prox;
                temp->prox = atual;

                if (anterior != NULL) {
                    anterior->prox = temp;
                } else {
                    // Se anterior for NULL, significa que estamos trocando o primeiro elemento da lista
                    L->populacao = temp;
                }

                anterior = temp;
                trocou = 1;
            } else {
                anterior = atual;
                atual = atual->prox;
            }
        }
    } while (trocou);
}
//==============================================================
void poda(TLista *L){
	/* Elimina os indiv�duos menos aptos (que est�o no
	   fim da Lista) at� que a popula��o volte ao seu
	   Limite estabelecido na configura��o inicial 
	   (L->Qtd_Populacao). */

	if (L->totalIndividuos > L->Qtd_Populacao) {
        // Calcular quantos indivíduos excedentes precisam ser removidos
        int excedente = L->totalIndividuos - L->Qtd_Populacao;

        // Remover os indivíduos excedentes
        TIndividuo *atual = L->populacao;
        TIndividuo *anterior = NULL;

        // Avançar até o último indivíduo da lista
        while (atual!= NULL && excedente > 0) {
            anterior = atual;
            atual = atual->prox;
            excedente--;
        }

        // Se houver algum nó anterior, significa que precisamos cortar a lista
        if (anterior!= NULL) {
            // Atualizar o ponteiro para o último nó da lista
            L->fimLista = anterior;

            // Definir o próximo nó após o último nó como NULL
            anterior->prox = NULL;

            // Atualizar o número total de indivíduos na lista
            L->totalIndividuos = L->Qtd_Populacao;
        } else {
            // Se não houver nenhum nó anterior, significa que a lista inteira deve ser removida
            L->populacao = NULL;
            L->fimLista = NULL;
            L->totalIndividuos = 0;
        }
    }
	exibeIndividuos(L);
}