// Desenvolvido por LUIS AUGUSTO DE SOUZA 
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

void CLIinserirNovaMatricula(TLista *L, int valor){
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
				if(atual->valor == novo->valor){
					printf(RED "\nMatricula %d Já Existe!",valor,RESET);
					return;
				}
				if(anterior == NULL){
					//Inserir novo antes do primeiro da primeiro da lista.
					novo->prox = atual;
					L->inicio = novo;
				}else{
					//inserir no meio da lista
					novo->prox = atual;
					anterior->prox = novo;
				}
				printf(GREEN "\nMatricula %d Inserida com sucesso!",valor,RESET);
				inseriu = 1;
				L->total++;
				break;
			}
			anterior = atual;
			atual = atual->prox; //move para o pr�ximo Matrícula
		}//while
	}//if
	if(!inseriu){
		printf(GREEN "\nMatricula %d Inserida com sucesso no fim da lista!",valor,RESET);
		// insere o Matrícula no fim da lista
		L->fim->prox = novo;
		L->fim = novo;
		L->total++;
	}
}

void LerArquivodeDados(TLista *L){
	int matricula;
	FILE *arquivo = lerArq("../lista_matricula.txt");

	while ( ! feof(arquivo) ) {
        fscanf(arquivo, "%d" , &matricula);
		CLIinserirNovaMatricula(L,matricula);
    }
}

void inserirNovaMatricula(TLista *L){
	int valor;
	printf(YELLOW "\n\t Insira o número de matrícula: ",RESET);
	valor = input();
	CLIinserirNovaMatricula(L,valor);
}

void imprimirMatricula(TLista L){
	TElemento *atual = L.inicio;
	int count = 0;

	printf("\n\t\t===| EXIBE LISTA COMPLETA |===\n");
	while(atual != NULL){
		printf(BLUE "\n\t(%d) - %d.",++count, atual->valor,RESET);
		atual = atual->prox;
	}
	printf("\n\n");
}

void totalDeMatriculas(TLista L){
	TElemento *atual = L.inicio;
	int count = 0;

	printf(BLUE "\n\t\t=====| Total de Matrículas |=====\n",RESET);
	while(atual != NULL){
		count++;
		atual = atual->prox;
	}
	printf(BLUE "\n TOTAL de Matrículas: %d",count,RESET);
	printf("\n\n");
}

void pesquisarMatricula(TLista L){
	TElemento *atual = L.inicio;
	int count = 0;
	int valor;

	printf(YELLOW "\n\tInsira o número da matrícula que deseja pesquisar: ",RESET);
	valor = input();

	while(atual != NULL){
		if(valor == atual->valor){
			printf("(%d) - %d.",++count, atual->valor);
		}
		atual = atual->prox;
	}
	if(atual == NULL){
		printf(RED "\n Matrícula %d Não foi encontrada!\n",valor, RESET);
	}
	printf("\n");
}
//===============================================
void CLIremoverMatricula(TLista *L, int valor){
	TElemento *atual = L->inicio;
	TElemento *anterior = NULL;

	while(atual != NULL){
		if(atual->valor == valor){
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
			printf(RED "\n Matrícula %d Foi EXCLUIDA com sucesso!\n",valor, RESET);
			free(atual);
			L->total--;
			break;
		}
		anterior = atual;
		atual = atual->prox;
	}
	if(atual == NULL){
		printf(RED "\n Matrícula %d Não foi encontrada!\n",valor, RESET);
	}
}

void removerMatricula(TLista *L){
	int valor;
	printf(YELLOW "\n\t Insira o número da matrícula que deseja remover: ",RESET);
	valor = input();
	CLIremoverMatricula(L,valor);
}

int menu() {
    correct();
	int op;
	// system("@cls||clear");  // LIMPA A TELA
	printf(BLUE "\n\t\t =====| SISTEMA DE MATRICULA |=====\t\t\n" RESET);
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
				LerArquivodeDados(&lista);
				break;
			case 2:
				// Inserir Nova Matrícula
				inserirNovaMatricula(&lista);
				break;
			case 3:
				// Remover Matrícula
				removerMatricula(&lista);
				break;
			case 4:
				// Pesquisar Matrícula
				pesquisarMatricula(lista);
				break;
			case 5:
				// total De Matriculas
				totalDeMatriculas(lista);
				break;
			case 6:
				// imprimir Matricula
				imprimirMatricula(lista);
				break;
			default:
				printf ("\n\nOpção inválida!\n\n");
		}
	} while (op != 0);
	return 0;
}