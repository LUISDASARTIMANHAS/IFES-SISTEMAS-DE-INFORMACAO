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

    if(DB->inicioA == NULL){
        DB->inicioA = novo;
        DB->fimA = novo;
    }else{
        while (atual != NULL){
            if (strcmp(atual->nome,novo->nome) > 0){
                inseriu = 1;
                novo->prox = atual;
                DB->inicioA = novo;
            }else{
                novo->prox = anterior->prox;
                anterior->prox = novo;
            }
        anterior = atual;
        atual = atual->prox;   
        }
        if (!inseriu){
            DB->fimA->prox = novo;
            DB->fimA = novo;
        } 
    }
}

void cadastraAtor(TLista *DB){
    string nome;

    printf("\n\n\t=====| INSERE ATOR|=====\n\n");
    printf("\tInforme o nome do ator: ");
    fflush(stdin);
    inputS(nome);
}

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

// ====================================== FIM DA BASE ============================

void inicializa(TLista *DB){
    DB->inicioF = NULL;
    DB->inicioA = NULL;
    DB->fimF = NULL;
    DB->fimA = NULL;

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
}

int main(){
    inicializa(&lista);
    return 0;
}