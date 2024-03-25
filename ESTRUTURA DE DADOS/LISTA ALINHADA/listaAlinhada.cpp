#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
TLista lista;

void insereAtor(TLista *DB, string nome){
    TAtor *novo = (TAtor *)malloc(sizeof(TAtor));
    TAtor *atual = DB->inicioA;
    TAtor *anterior = NULL;
    int inseriu = 0;
    

    novo->prox = NULL;
    strcpy(novo->nome,nome);
    printf("\nINSERINDO ATOR: %s...",nome);

    if(DB->inicioA == NULL){
        DB->inicioA = novo;
        DB->fimA = novo;
    }else{
        while(atual != NULL){
            if (strcmp(atual->nome,novo->nome) > 0)	{
                inseriu = 1;
                if(atual == DB->inicioA)	{
                    novo->prox = atual;
                    DB->inicioA = novo;	
                } else {
                    novo->prox = anterior->prox;
                    anterior->prox = novo;
                }
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }
        
        if(!inseriu){
            DB->fimA->prox = novo;
            DB->fimA = novo;
        }
    }
}

void insereFilme(TLista *DB, string titulo, int ano){
    TFilme *novo = (TFilme *)malloc(sizeof(TFilme));
    TFilme *atual = DB->inicioF;
    TFilme *anterior = NULL;
    int inseriu = 0;

    novo->ante = NULL;
    novo->prox = NULL;
    novo->elenco = NULL;
    novo->anoProducao = ano;
    strcpy(novo->titulo,titulo);
    printf("\nINSERINDO FILME: %s...",titulo);

    if(DB->inicioF == NULL){
        DB->inicioF = novo;
        DB->fimF = novo;
    }else{
        inseriu = 0;
        anterior = atual->ante;
        while(atual != NULL){
            if (strcmp(atual->titulo,novo->titulo) > 0)	{
                inseriu = 1;
                novo->prox = atual;
                atual->ante = novo;

                if(anterior == NULL){
                    DB->inicioF = novo;	
                } else {
                    anterior->prox = novo;
                    novo->ante = anterior;
                }
                break;
            }
            atual = atual->prox;
        }
        
        if(!inseriu){
            DB->fimF->prox = novo;
            novo->ante = DB->fimF;
            DB->fimF = novo;
        }
    }
}

void cadastraAtor(TLista *DB){
    string nome;

    printf("\n\n\t=====| INSERE ATOR|=====\n\n");
    printf("\tInforme o nome do ator: ");
    fflush(stdin);
    inputS(nome);

    insereAtor(DB, nome);
}

void cadastraFilme(TLista *DB){
    string titulo;
    int ano;


    printf("\n\n\t=====| CADASTRO DE FILMES |=====\n\n");
    printf("\tTITULO: ");
    fflush(stdin);
    inputS(titulo);

    printf("\n\n\tANO DE PRODUÇÃO: ");
    fflush(stdin);
    ano = input();

    insereFilme(DB, titulo, ano);
}

void exibeAtores(TLista *DB){
	TAtor *atual = DB->inicioA;
	int cont = 0;
	
	printf("\n\n");
	printf("+----------------------------------------------------+\n");
	while (atual != NULL)	{
		printf("\t(%d) - %s.\n", ++cont, atual->nome);
		atual = atual->prox;
	}//while
	printf("+----------------------------------------------------+\n\n\n");
}

void exibeFilmes(TLista *DB){
	TFilme *atual = DB->inicioF;
    TElenco *cursor;
    TAtor *ator;
	int cont = 0;
	
	printf("\n\n");
	printf("+----------------------------------------------------+\n");
	while (atual != NULL)	{
		printf("\t(%d) - %s [%d].\n", ++cont, atual->titulo, atual->anoProducao);
        if (atual->elenco !=NULL){
            printf("\n");
            cursor = atual->elenco;
            while (cursor != NULL){

                printf("\t\t%s\n",cursor->ator->nome);
                cursor = cursor->prox;
            }
            
        }
        
		atual = atual->prox;
	}//while
	printf("+----------------------------------------------------+\n\n\n");
}

// ====================================== FIM DA BASE ============================

void inicializa(TLista *DB){
    head();
    DB->inicioF = NULL;
    DB->inicioA = NULL;
    DB->fimF = NULL;
    DB->fimA = NULL;

    insereAtor(DB,"Tobey Maguire");
	insereAtor(DB,"Christen Dusten");
	insereAtor(DB,"Charlton Heston");
	insereAtor(DB,"Sofia Loren");
	insereAtor(DB,"Kirk Douglas");
	insereAtor(DB,"Michael Douglas");
	insereAtor(DB,"Mira Sorvino");
	insereAtor(DB,"Tom Cruise");
	insereAtor(DB,"Jennifer Connelly");
	insereAtor(DB,"Kelly McGillis");
	insereAtor(DB,"Kathleen Turner");
	insereAtor(DB,"Danny DeVito");
	insereAtor(DB,"Sylvester Stallone");
	insereAtor(DB,"Talia Shire");
	insereAtor(DB,"Hayley Atwell");
	insereAtor(DB,"Chris Evans");
	insereAtor(DB,"Sebastian Stan");
	insereAtor(DB,"Sidney Potier");
	insereAtor(DB,"Charlie Chaplin");
	insereAtor(DB,"Paulette Goddard");
	insereAtor(DB,"Bruce Willis");
	insereAtor(DB,"Cybill Shepherd");

    insereFilme(DB, "O Garoto",1921);
    insereFilme(DB, "Tempos Modernos",1936);
    insereFilme(DB, "To Sir With Love",1967);
    insereFilme(DB, "Aladin",1997);
    insereFilme(DB, "Et",1982);
    insereFilme(DB, "The Wo",2024);

    exibeAtores(DB);
    exibeFilmes(DB);
    copy();
}

int main(){
    inicializa(&lista);
    return 0;
}