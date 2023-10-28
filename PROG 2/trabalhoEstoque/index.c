#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"
#define MAXSPACE 1024

// OBS: Reutilize a função pesquisar por código. Ela será utilizada pelas funções inserir, aumentar preço, aplicar desconto e excluir.
// Para isso seu sistema deve possuir o seguinte menu:
// SISTEMA DE ESTOQUE
// 1 – Inserir produto
// 2 – Pesquisar por código
// 3 – Pesquisar por nome
// 4 – Atualizar preço
// 5 – Maior preço
// 6 – Excluir
// 7 - Listar
// 0 – Sair
// Escolha sua opção:
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

// deve possuir as seguintes operações:
//  Atualizar preço: pedir o código do produto e a porcentagem de aumento ou
// desconto. Pesquisar o código do produto no vetor e aplicar o aumento ou desconto no preço.
//  Excluir: pedir o código do produto e excluir do vetor.