/* Lista Encadeada Aninhada 20/03/2024 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[40];

typedef struct tipoAtor {
	string nome;
	tipoAtor *prox;	
}TAtor;

typedef struct tipoElenco {
	TAtor *ator;
	tipoElenco *prox;
}TElenco;

typedef struct tipoFilme {
	string titulo;
	int anoProducao;
	tipoFilme *ante, *prox;
	TElenco *elenco;
}TFilme;

typedef struct tipoLista {
	TFilme *inicioF;
	TFilme *fimF;
	TAtor *inicioA;
	TAtor *fimA;
}TLista;

TLista listas;

void inicializa(TLista *L);
void insereAtor(TLista *L, string nome);
void cadastraAtor(TLista *L);
void exibeAtores(TLista *L);


int main(){
	inicializa(&listas);
	
}
//=================================================================
void inicializa(TLista *L){
	L->inicioF = NULL;
	L->inicioA = NULL;
	L->fimF = NULL;
	L->fimA = NULL;
	
	insereAtor(L,"Tobey Maguire");
	insereAtor(L,"Christen Dusten");
	insereAtor(L,"Charlton Heston");
	insereAtor(L,"Sofia Loren");
	insereAtor(L,"Kirk Douglas");
	insereAtor(L,"Michael Douglas");
	insereAtor(L,"Mira Sorvino");
	insereAtor(L,"Tom Cruise");
	insereAtor(L,"Jennifer Connelly");
	insereAtor(L,"Kelly McGillis");
	insereAtor(L,"Kathleen Turner");
	insereAtor(L,"Danny DeVito");
	insereAtor(L,"Sylvester Stallone");
	insereAtor(L,"Talia Shire");
	insereAtor(L,"Hayley Atwell");
	insereAtor(L,"Chris Evans");
	insereAtor(L,"Sebastian Stan");
	insereAtor(L,"Sidney Potier");
	insereAtor(L,"Charlie Chaplin");
	insereAtor(L,"Paulette Goddard");
	insereAtor(L,"Bruce Willis");
	insereAtor(L,"Cybill Shepherd");
	exibeAtores(L);
	
}
//=================================================================
void insereAtor(TLista *L, string nome){
	TAtor *novo	= (TAtor *)malloc(sizeof(TAtor));
	int flag = 0;
	
	novo->prox = NULL;
	strcpy(novo->nome, nome);
	
	if(L->inicioA == NULL){
		//Lista de Atores encontra-se vazia
		L->inicioA = novo;
		L->fimA = novo;
	} else {
		TAtor *atual = L->inicioA;
		TAtor *anterior = NULL;
		
		while(atual != NULL){
			if (strcmp(atual->nome,novo->nome) > 0)	{
				//Momento de inserir na lista.
				flag = 1;
				if(atual == L->inicioA)	{
					//insere NOVO como primeiro da Lista...
					novo->prox = atual;
					L->inicioA = novo;	
				} else {
					//insere NOVO antes do ATUAL (no MEIO da LISTA)
					novo->prox = anterior->prox;
					anterior->prox = novo;
				}//if
				break;
			}//if
		    anterior = atual;
			atual = atual->prox;
		}//while
		
		if(!flag){
			//Insere NOVO no FIM da LISTA.
			L->fimA->prox = novo;
			L->fimA = novo;
		}//if
	}//if
}
//=================================================================
void cadastraAtor(TLista *L){
	string nome;
	
	printf("\n\n\t\t=====| INSERE ATOR |=====\n\n");
	printf("\tInforme NOME de novo ATOR: ");
	fflush(stdin);
	gets(nome);
	
	insereAtor(L, nome);
}
//=================================================================
void exibeAtores(TLista *L){
	TAtor *atual = L->inicioA;
	int cont = 0;
	
	printf("\n\n");
	printf("+----------------------------------------------------+\n");
	while (atual != NULL)	{
		printf("\t(%d) - %s.\n", ++cont, atual->nome);
		atual = atual->prox;
	}//while
	printf("+----------------------------------------------------+\n\n\n");
	system("PAUSE");
}
//=========================================================================

