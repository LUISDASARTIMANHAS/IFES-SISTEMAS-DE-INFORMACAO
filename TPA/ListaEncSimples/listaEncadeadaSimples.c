#include "listaEncadeadaSimples.h"

TLista lista;


void correct(){
    SetConsoleOutputCP(65001);
}

// inputs personalizados e modificados
float input(){
    float value;
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
void inputS(char destino[]){
    scanf(" %100[^\n]s", destino);
}

FILE * lerArq(char *nomeArq){
    FILE * arq;
    arq = fopen(nomeArq,"r");
    if(arq == NULL){
        printf("\n ERRO: Erro ao carregar o arquivo!");
        exit(-1);
    }
	printf("\n INFO: Arquivo %s carregado com sucesso! \n",nomeArq);
    return arq;
}

void inicializa(TLista *L){
	L->inicio = NULL;
	L->fim = NULL;
	L->total = 0;
}

void LerArquivodeDados(TLista *L){
	int matricula;
	FILE *arquivo = lerArq("../lista_matricula.txt");

	while ( ! feof(arquivo) ) {
        fscanf(arquivo, "%d" , &matricula);
		inserirNovaMatricula(L,matricula);
    }
}

void inserirNovaMatricula(TLista *L,int valor){
	int inseriu = 0;
	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	
	novo->valor = valor;
	novo->prox = NULL;
	
	if(L->inicio == NULL){
		//Lista encontra-se vazia.
		L->inicio = novo;
		L->fim = novo;
		L->total = 1;
		inseriu = 1;
	} else {
		//Lista possui pelo menos um Matrícula.
		TElemento *atual = L->inicio;
		TElemento *anterior = NULL;
		
		while(atual != NULL){
			if(atual->valor >= novo->valor)	{
				if(anterior == NULL){
					//Inserir novo antes do primeiro da primeiro da lista.
					novo->prox = atual;
					L->inicio = novo;
				}else{
					//inserir no meio da lista
					novo->prox = atual;
					anterior->prox = novo;
				}
				inseriu = 1;
				L->total++;
				break;
			}
			anterior = atual;
			atual = atual->prox; //move para o pr�ximo Matrícula
		}//while
	}//if
	if(!inseriu){
		// insere o Matrícula no fim da lista
		L->fim->prox = novo;
		L->fim = novo;
		L->total++;
	}
}

void imprimirMatricula(TLista L){
	TElemento *atual = L.inicio;
	int count = 0;

	printf("\n\t\t===| EXIBE LISTA COMPLETA |===\n");
	while(atual != NULL){
		printf("(%d) - %d.\n",++count, atual->valor);
		atual = atual->prox;
	}
	printf("\n\n");
}

void totalDeMatriculas(TLista L){
	TElemento *atual = L.inicio;
	int count = 0;

	printf("\n\t\t===| 5. Total de Matrículas |===\n");
	while(atual != NULL){
		printf("(%d) - %d.\n",++count, atual->valor);
		atual = atual->prox;
	}
	printf("\n\n");
}

void pesquisarMatricula(TLista L,int valor){
	TElemento *atual = L.inicio;
	int count = 0;

	printf("\n\t\t===| EXIBE LISTA COMPLETA |===\n");
	while(atual != NULL){
		printf("(%d) - %d.\n",++count, atual->valor);
		atual = atual->prox;
	}
	printf("\n\n");
}
//===============================================

void removerMatricula(TLista *L, int valor){
	TElemento *atual = L->inicio;
	TElemento *anterior = NULL;
	int count = 0;

	while(atual != NULL){
		if(count == 0){
			printf("\n\t\tExcluino o Matrícula %d ...\n", atual->valor);
			count++;
		}
		if(atual->valor == valor){
			printf("\n\t\tEncontrado Matrícula a ser EXCLUIDO!\n");
			if(L->inicio == L->fim){
				L->inicio = NULL;
				L->fim = NULL;
			}else if(atual == L->inicio){
				L->inicio = atual->prox;
			}else if(atual == L->fim){
				L->fim = anterior;
				L->fim->prox = NULL;
			}else{
				anterior->prox = atual->prox;
			}
			free(atual);
			L->total--;
			break;
		}
		anterior = atual;
		atual = atual->prox;
	}
}

int menu() {
    correct();
	int op;
	// system("@cls||clear");  // LIMPA A TELA
	printf(BLUE "\n\t\t SISTEMA DE ESTOQUE \t\t\n" RESET);
	printf(GREEN "1 - Ler Arquivo de Dados\n");
	printf("2 - Inserir Nova Matrícula\n");
	printf(RED "3 - Remover Matrícula\n");
	printf(GREEN"4 - Pesquisar Matrícula\n");
	printf("5 - Total de Matrículas\n");
	printf("6 - Imprimir Matrículas\n" RESET);
	printf(RED "0 - Sair\n" RESET);
	do {
		printf(YELLOW "Escolha sua opção: " RESET);
		scanf(" %d", &op);
	} while(op < 0 || op > 6);
	return op;
}

int main(){
	inicializa(&lista);
	correct();
	int op;
	do {
		op = menu();
		switch ( op ) {
			case 0:
				// SAIR. NÃO PRECISA FAZER NADA
				EXIT_SUCCESS;
				break;
			case 1:
				// Ler Arquivo de Dados
				break;
			case 2:
				// Inserir Nova Matrícula
				break;
			case 3:
				// Remover Matrícula
				break;
			case 4:
				// Pesquisar Matrícula
				break;
			case 5:
				// MAIOR
				break;
			case 6:
				// EXCLUIR
				break;
			default:
				printf ("\n\nOpção inválida!\n\n");
		}
	} while (op != 0);
	return 0;
}
