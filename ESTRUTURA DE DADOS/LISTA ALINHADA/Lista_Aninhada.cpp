/* 
   Lista Encadeada Aninhada 25/03/2024.
 */
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
void insereAtor(TLista *L, const string nome);
void cadastraAtor(TLista *L);
void exibeAtores(TLista *L);
int menu();
void cadastraFilme(TLista *L);
void insereFilme(TLista *L, string titulo, int ano);
void exibeFilmes(TLista L);
void defineElenco(TLista *L);
TFilme *localizaFilme(TLista *L, string titulo);
TAtor *localizaAtor(TLista *L, string nome);
void relacionarFilmeAtor(TFilme *f, TAtor *a);
void criaElenco(TLista *L, string titulo, string nomeAtor);

int main(){
	int opcao;
	
	inicializa(&listas);
	
	do{
		opcao = menu();
		
		switch(opcao)	{
			case 1: cadastraAtor(&listas); break;
			case 2: exibeAtores(&listas); break;
			case 3: cadastraFilme(&listas); break;
			case 4: exibeFilmes(listas); break;
			case 5: defineElenco(&listas); break;
		}//switch case
		
	}while(opcao != 0);
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
	insereAtor(L,"Sophia Loren");
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
	insereAtor(L,"Genevieve Page");
	insereAtor(L,"Roy Scheider");
	insereAtor(L,"Richard Dreyfuss");
	insereAtor(L,"Edna Purviance");
	insereAtor(L,"Jackie Coogan");
	insereAtor(L,"Lulu");
	insereAtor(L,"Judy Geeson");
	
	insereFilme(L,"O Garoto", 1921);
	insereFilme(L,"Tempos Modernos", 1936);
	insereFilme(L,"SPARTACUS", 1958);
	insereFilme(L,"El Cid", 1961);
	insereFilme(L,"To Sir With Love", 1967);
	insereFilme(L,"Tubarao", 1976);
	insereFilme(L,"O Poderoso Chefao", 1972);
	insereFilme(L,"A Joia do NILO", 1986);
	insereFilme(L,"Moonlighting", 1985);
	insereFilme(L,"Tudo por uma Esmeralda", 1985);
	
	criaElenco(L,"El Cid","Charlton Heston");
	criaElenco(L,"El Cid","Sophia Loren");
	criaElenco(L,"El Cid","Genevieve Page");
	criaElenco(L,"Tubarao","Roy Scheider");
	criaElenco(L,"Tubarao","Richard Dreyfuss");
	criaElenco(L,"A Joia do NILO","Michael Douglas");
	criaElenco(L,"A Joia do NILO","Kathleen Turner");
	criaElenco(L,"A Joia do NILO","Danny DeVito");
	criaElenco(L,"O Garoto","Charlie Chaplin");
	criaElenco(L,"O Garoto","Edna Purviance");
	criaElenco(L,"O Garoto","Jackie Coogan");
	criaElenco(L,"To Sir With Love","Sidney Potier");
	criaElenco(L,"To Sir With Love", "Judy Geeson");
	criaElenco(L,"To Sir With Love", "Lulu");
	criaElenco(L,"Moonlighting", "Cybill Shepherd");
	criaElenco(L,"Moonlighting", "Bruce Willis");
	criaElenco(L,"Tudo por uma Esmeralda", "Michael Douglas");
	criaElenco(L,"Tudo por uma Esmeralda", "Kathleen Turner");
	criaElenco(L,"Tempos Modernos", "Charlie Chaplin");
	criaElenco(L,"Tempos Modernos", "Paulette Goddard");
	
}
//=================================================================
void insereAtor(TLista *L, const string nome){
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
int menu(){
	int opcao;
	
	system("CLS");
	printf("\n\n\t\t==========| MENU |==========\n\n");
	printf("\t0 - SAIR (Encerrar Aplicacao).\n\n");
	printf("\t1 - Cadastrar Atores.\n");
	printf("\t2 - Exibir Atores.\n");
	printf("\t3 - Cadastrar Filmes.\n");
	printf("\t4 - Exibir Filmes.\n");
	printf("\t5 - Define Elenco de Filme.\n");
	
	printf("\n\tInforme OPCAO desejada: ");
	fflush(stdin);
	scanf("%d", &opcao);
	
	if((opcao < 0) || (opcao > 5)){
		printf("\n\n\tERRO: Opcao invalida!\nTente outra vez!\n\n");
		system("PAUSE");
	}
	return opcao;
}
//=========================================================================
void cadastraFilme(TLista *L){
	string titulo;
	int anoProducao;
	
	printf("\n\n\t\t=====| CADASTRO DE FILMES |=====\n\n");
	printf("\tTITULO: ");
	fflush(stdin);
	gets(titulo);
	printf("\n\n\tANO DE PRODUCAO: ");
	fflush(stdin);
	scanf("%d",&anoProducao);
	
	insereFilme(L, titulo, anoProducao);
}
//========================================================================
void insereFilme(TLista *L, string titulo, int ano){
	TFilme *novo = (TFilme *)malloc(sizeof(TFilme));
	TFilme *anterior, *atual;
	int flag;
	
	novo->prox = NULL;
	novo->ante = NULL;
	novo->elenco = NULL;
	strcpy(novo->titulo, titulo);
	novo->anoProducao = ano;
	
	if(L->inicioF == NULL){
		//Inserção em Lista VAZIA.
		L->inicioF = novo;
		L->fimF = novo;
	} else {
		//A Lista possui pelo menos um Filme.
		atual = L->inicioF;
		flag = 0;
		
		while(atual != NULL){
			if(strcmp(atual->titulo, novo->titulo) > 0){
				//Encontrada posição de inserção na Lista...
				anterior = atual->ante;
				flag = 1;
				
				novo->prox = atual;
				atual->ante = novo;
				
				if(anterior == NULL){
					//insere NOVO antes do PRIMEIRO Filme da Lista.	
					L->inicioF = novo;	
				} else {
					//insere NOVO no MEIO da Lista.
					anterior->prox = novo;
					novo->ante = anterior;
				}//if
				break;
			}//if
			atual = atual->prox;	
		}//while
		
		if(!flag){
			//Insere após o ÚLTIMO Filme da Lista.
			L->fimF->prox = novo;
			novo->ante = L->fimF;
			L->fimF = novo;
		}//if
		
	}//if
}
//========================================================================
void exibeFilmes(TLista L){
	int cont = 0;
	TFilme *atual = L.inicioF;
	TElenco *cursor;
	
	printf("\n\n\t\t=====| EXIBIR TODOS OS FLMES |=====\n\n");
	while(atual != NULL){
		printf("\n\t(%d) - %s [%d].\n", ++cont, atual->titulo, atual->anoProducao);
		if(atual->elenco != NULL) printf("\n");
		cursor = atual->elenco;
		while(cursor != NULL){
			printf("\t\t%s\n", cursor->ator->nome);
			cursor = cursor->prox;
		}//while
		atual = atual->prox;
	}//while
	printf("\n\n");
	system("PAUSE");
}
//=======================================================================
void defineElenco(TLista *L){
	TFilme *f;
	TAtor *a;
	string titulo;
	string nome;
	
	printf("\n\n\t\t======| DEFINE ELENCO DE FILME |======\n\n");
	printf("\tInforme TITULO de FILME: ");
	fflush(stdin);
	gets(titulo);
	
	f = localizaFilme(L, titulo);
	
	if(f == NULL){
		printf("\n\n\tERRO: filme NAO encontrado.\n\tTITULO: %s.\n\n",f->titulo);
		system("PAUSE");
	} else {
    	printf("\n\n\tInforme NOME de ATOR: ");
	    fflush(stdin);
	    gets(nome);
			
	    a = localizaAtor(L, nome);
		if(a == NULL){
			printf("\n\n\tERRO: ator NAO encontrado!\n\tNOME: %s.\n\n", a->nome);
			system("PAUSE");
		} else {
			
		}//if
	}//if
	
}
//=======================================================================
TFilme *localizaFilme(TLista *L, string titulo){
	TFilme *atual = L->inicioF;
	
	while (atual != NULL){
		if(strcmp(atual->titulo, titulo) == 0){
			break;
		}//if
		atual = atual->prox;
	}//while
	return atual;
}
//=======================================================================
TAtor *localizaAtor(TLista *L, string nome){
	TAtor *atual = L->inicioA;
	
	while(atual != NULL)	{
		if(strcmp(atual->nome, nome) == 0) {
			break;
		}//if
		atual = atual->prox;
	}//while
	return atual;
}
//=======================================================================
void relacionarFilmeAtor(TFilme *f, TAtor *a){
	TElenco *novo = (TElenco *)malloc(sizeof(TElenco));
	
	novo->prox = NULL;
	novo->ator = a;
	
	if(f->elenco != NULL){
	   TElenco *atual = f->elenco;
	   while(atual->prox != NULL){
			atual = atual->prox;
       }//while
	   atual->prox = novo;		
	} else {
	   f->elenco = novo;
	}//if
}
//=======================================================================
void criaElenco(TLista *L, string titulo, string nomeAtor){
	TFilme *f = localizaFilme(L,titulo);
	if(f != NULL){
		TAtor *a = localizaAtor(L, nomeAtor);
		
		if(a != NULL)	{
			relacionarFilmeAtor(f,a);
		}//if
	}//if	
}
//=======================================================================

