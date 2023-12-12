#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"
#define MAXSPACE 1024

// deve possuir as seguintes operações:
//  Excluir: pedir o código do produto e excluir do vetor.
int main() {
	correct();
	head();
	Produto produtos[MAXSPACE];
	int tam = 0;
	int op;
	carregarDatabase(produtos,&tam);
	do {
		op = menu();
		switch ( op ) {
			case 0:
				// SAIR. NÃO PRECISA FAZER NADA
				gravarDatabase(produtos,tam);
				copy();
				break;
			case 1:
				// INSERIR
				inserir(produtos,&tam);
				break;
			case 2:
				// PESQUISAR POR CODIGO/MATRICULA
				pesqCod(produtos,tam);
				break;
			case 3:
				// PESQUISAR POR NOME
				pesqName(produtos,tam);
				break;
			case 4:
				// ATUALIZAR
				update(produtos,tam);
				break;
			case 5:
				// MAIOR
				finderMaior(produtos,tam);
				break;
			case 6:
				// EXCLUIR
				delete(produtos,&tam);
				break;
			case 7:
				// LISTAR
				list(produtos,tam);
				break;
			default:
				printf ("\n\nOpção inválida!\n\n");
		}
	} while (op != 0);
	return 0;
}