// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
// chave e a matricula (K)
// mod e o resto da divisão
// M e o tamanho do vetor
#include <TabelaHash.h>
void inicializa(){
	printf("\n\n\t\t=====| Tabela Hash |=====\n");
    
}

//===| Programa Principal |===========================
int main(){
	SetConsoleOutputCP(65001);
	inicializa();
	int op;
	do {
		op = menu();
		switch ( op ) {
			case 0:
				// SAIR. NÃO PRECISA FAZER NADA
				salvarAqr(lista);
				break;
			case 1:
				// Inserir Nova Matrícula
				inserirNovaMatricula(&lista);
				break;
			case 2:
				// Remover Matrícula
				removerMatricula(&lista);
				break;
			case 3:
				// Pesquisar Matrícula
				pesquisarMatricula(lista);
				break;
			case 4:
				// total De Matriculas
				totalDeMatriculas(lista);
				break;
			case 5:
				// imprimir Matricula
				imprimirMatricula(lista);
				break;
			default:
				printf ("\n\nOpção inválida!\n\n");
		}
	} while (op != 0);
	return 0; 
}
