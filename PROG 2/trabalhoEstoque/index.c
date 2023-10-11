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
	Produto produtos[MAXSPACE];
	int op;
	do {
		op = menu();
		switch ( op ) {
			case 0:
				// SAIR. NÃO PRECISA FAZER NADA
				copy();
				break;
			case 1:
				// INSERIR
				inserir();
				break;
			case 2:
				// PESQUISAR POR CODIGO/MATRICULA
				pesqCod();
				break;
			case 3:
				// PESQUISAR POR NOME
				pesqName();
				break;
			case 4:
				// ATUALIZAR
				update();
				break;
			case 5:
				// MAIOR
				finderMaior();
				break;
			case 6:
				// EXCLUIR
				delete();
				break;
			case 7:
				// LISTAR
				list();
				break;
			default:
				printf ("\n\nOpção inválida!\n\n");
		}
	} while (op != 0);
	
	return 0;
}

// deve possuir as seguintes operações:
//  Inserir produto: ler todos os dados de Data e Produto e inserir no vetor. Não deixar inserir código de produto repetido.
//  Pesquisar por código: pedir o código do produto e pesquisar no vetor, imprimindo todos os dados de Produto e Data.
//  Pesquisar por nome: pedir o nome do produto e pesquisar no vetor, imprimindo todos os dados de Produto e Data.
//  Atualizar preço: pedir o código do produto e a porcentagem de aumento ou
// desconto. Pesquisar o código do produto no vetor e aplicar o aumento ou desconto no preço.
//  Maior preço: pesquisar qual é o produto com maior preço e mostrar todos os dados de Produto e Data.
//  Excluir: pedir o código do produto e excluir do vetor.
//  Listar: mostrar todas os produtos e seu respectivo preço.