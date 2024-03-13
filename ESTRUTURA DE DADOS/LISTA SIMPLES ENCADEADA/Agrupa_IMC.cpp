#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

typedef char string[40];

typedef struct tipoElemento {
	float idade;
	float altura;
	float peso;
	float imc;
	string nome;
	int grupo;
	int centroide;
	tipoElemento *prox;	
}TElemento;

typedef struct tipoLista {
	TElemento *inicio;
	TElemento *fim;
	int total;
	int k;
}TLista;

TLista lista;

void inicializa(TLista *L);
void insere(TLista *L, float idade, float altura, float peso, string nome);
void exibe(TLista L);
void escolheCentroides(TLista *L);

int main(){
	inicializa(&lista);
	exibe(lista);
	escolheCentroides(&lista);
	exibe(lista);
}
//=============================================
void inicializa(TLista *L){
	L->inicio = NULL;
	L->fim = NULL;
	L->total = 0;
	
	printf("\n\n\tInforme quantidade de Grupos: ");
	scanf("%d", &L->k);
	
	insere(L,23,1.8,81,"Pedro");
	insere(L,21,1.76,67,"Anna");
	insere(L,21,1.72,61,"Cinthia");
	insere(L,17,1.72,72,"Jose");
	insere(L,35,1.77,96,"Silvano");
	insere(L,28,1.68,69,"Evelyn");
	insere(L,56,1.77,94,"Asdrubal");
	insere(L,35,1.75,85,"Jambira");
	insere(L,20,1.65,100,"Desiderio");
	insere(L,46,1.82,102,"Ramiro");
	insere(L,38,1.70,65,"Paula");
	insere(L,39,1.65,68,"Claudia");
	insere(L,18,1.66,65,"Sofia");
	insere(L,58,1.86,99,"Astolfo");
	insere(L,52,1.80,120,"Demostenes");
	insere(L,18,1.72,72,"Josefino");
	
	
}
//==============================================
void insere(TLista *L, float idade, float altura, float peso, string nome){
	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	
	novo->idade = idade;
	novo->grupo = -1;
	novo->altura = altura;
	novo->peso = peso;
	novo->imc = (peso /(altura * altura));
	novo->prox = NULL;
	strcpy(novo->nome, nome);
	novo->centroide = 0;
	
	if(L->inicio == NULL)	{
		//Lista Vazia
		L->inicio = novo;
		L->fim = novo;
	}else {
		//Lista Possui pelo menos 1 elemento...
		TElemento *atual = L->inicio;
		TElemento *anterior = NULL;
		int inserido = 0;
		
		while(atual != NULL){
			if(strcmp(atual->nome, novo->nome)== 1){
				
				if(atual == L->inicio){
					//Inserir novo no in�cio da Lista.
					novo->prox = atual;
					L->inicio = novo;	
				} else {
					//Inserir novo no meio da lista.
					novo->prox = atual;
					anterior->prox = novo;
				}
				
				inserido = 1;
				break; //interrompe o while...
			}//if
			anterior = atual;
			atual = atual->prox;
			
		}//while
		
		if(!inserido){
			//Insere novo ao final da lista...
			L->fim->prox = novo;
			L->fim = novo;	
		}//if
		
		L->total++;
	}//if
	
}
//===================================================================
void exibe(TLista L){
	TElemento *atual = L.inicio;
	int cont = 0;
	
	printf("\n\n\t\t=====| EXIBE ELEMENTOS |=====\n\n");
	
	while(atual != NULL){
		if(atual->grupo == -1){
			printf("\t(%d) - %s : %.2f ... SEM GRUPO.\n", ++cont, atual->nome, atual->imc);	
		} else {
			printf("\t(%d) - %s : %.2f ... GRUPO: %d\n", ++cont, atual->nome, atual->imc, atual->grupo);
		}//if
		
		atual = atual->prox;
	}//while
	
	printf("\n\n");
	system("PAUSE");
}
//============================================================================
void escolheCentroides(TLista *L){
   //Fun��o que escolhe randomicamente um centroide para cada grupo.
   //O usu�rio-final define a quantidade de grupos existentes (k) durante a execu��o
   //do programa.
   //Esta fun��o sorteia um TElemento para Centr�ide de cada grupo.
   
  int grupo = L->k;
  int posicao = 0;
  int pos;
  
  TElemento *atual;
  
  while(grupo > 0){
	posicao = rand() % 20;
	
	atual = L->inicio;
	pos = 0;
	while(atual != NULL){
		if(pos == posicao){
			//Encontrado TElemento a ser Transformado em Centr�ide	...
			if(atual->centroide == 0){
				
			
			    atual->centroide = 1;
			    atual->grupo = grupo;
			
		    	printf("\n\n\tEscolhido CENTROIDE do GRUPO %d: %s ...",grupo, atual->nome);
		    	break;
		    	
	    	} else {
				pos--;
    		}//if
		}//if
		
		if(atual == L->fim){
			atual = L->inicio;
		} else {
			atual = atual->prox;
		}//if
		pos++;
	}//while
	grupo--;
  }//while
  
  printf("\n\n Processo de escolha dos CENTROIDES concluido!\n\n");
  system("PAUSE");

}
//============================================================================
void distribuiElementos(TLista *L){
	TElemento *atual, *centroide, *menorDist;
	// float X = raizQuadrada(IDADEs - IDADEn) + raizQuadrada(ALTURAs - ALTURAn) + raizQuadrada(PESOs - PESOn)
	// float distância = raizQuadrada(x);
	float menor, temp;
	atual = L->inicio;


	//Esta fun��o percorre a Lista com todos os TElementos.
	//Cada TElemento encontrado que N�O seja um CENTR�IDE deve ter a sua dist�ncia euclidiana
	//calculada em rela��o a todos os CENTR�IDES existentes.
	//Esse TElemento dever� pertecer ao mesmo GRUPO do CENTR�IDE menos distante dele.
	
	while(atual != NULL){
		if(atual->centroide){
			centroide = L->inicio;
		}

		atual = atual->prox;
	}
}
//============================================================================
void ordenaPorGrupo(TLista *L){
//Reordena os elementos da Lista por GRUPO. Ao final do processo os ELementos da Lista
//que pertencerem ao mesmo grupo dever�o estar agrupados de maneira contigua.
	
	
}
//============================================================================

float raizQuadrada(float num){
	#include <math.h>
	float res = sqrt(num);
	return res;
}