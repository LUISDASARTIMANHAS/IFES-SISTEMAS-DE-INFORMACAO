// Desenvolvido por Lucas Garcia de Souza & LUIS AUGUSTO DE SOUZA 
#include "TabelaHash.h"

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

int mod(int x, int y){
	return x%y;
}

int calculaNumPrimoProx(int num){
	int fatorPrimo = 1;
	while (num%fatorPrimo != 0){

		fatorPrimo = fatorPrimo + 2;
	}
	return fatorPrimo;
}

int pesq(int matricula, TLista L){
	mod(matricula, L.tamTabelaHash);
}

FILE * lerArq(char *nomeArq, char * modo){
    FILE * arq;
    arq = fopen(nomeArq,modo);
    if(arq == NULL){
        printf("\n ERRO: Erro ao carregar o arquivo!");
        exit(-1);
    }
	printf("\n INFO: Arquivo %s carregado com sucesso! \n",nomeArq);
    return arq;
}

void escreverArq(FILE *arq, int matricula, string nome){
	fprintf(arq, "\n%3d", matricula);
}

void salvarAqr(TLista L){
	FILE *arq = lerArq("../data/nomes_matriculas.txt","w");
	FILE *backupArq = lerArq("../data/backup.txt","w");
	TElemento *atual = L.inicio;

	printf("\n Salvando...\n");
	while(atual != NULL){
		escreverArq(arq,atual->valor, atual->nome);
		escreverArq(backupArq,atual->valor, atual->nome);
		atual = atual->prox;
	}

	fclose(arq);
	printf("\n Autosave Completo!\n");
}


int switchMenuHash(){
    int op;
	int fatorTamanhoTabelaHash;
    do{
        op = menuHash();
        switch (op){
        case 1:
            // Inserir Nova Matrícula
            fatorTamanhoTabelaHash = 100;
            break;
        case 2:
            // Remover Matrícula
            fatorTamanhoTabelaHash = 120;
            break;
        case 3:
            // Pesquisar Matrícula
            fatorTamanhoTabelaHash = 150;
            break;
        default:
            printf("\n\nOpção inválida!\n\n");
        }
    } while (op != 0);
	return fatorTamanhoTabelaHash;
}

void inicializa(TLista *L){
	int fatorTamanhoTabelaHash = switchMenuHash();
	int tamBaseDados = calculaBaseDados();
	L->inicio = NULL;
	L->fim = NULL;
	L->total = 0;
	L->tamTabelaHash = fatorTamanhoTabelaHash * tamBaseDados;
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
	string nome;
	FILE *arquivo = lerArq("../data/nomes_matriculas.txt","r");

	while ( ! feof(arquivo) ) {
		fscanf(arquivo, "%s" , &nome);
        fscanf(arquivo, "%d" , &matricula);
		CLIinserirNovaMatricula(L,matricula);
    }
	fclose(arquivo);
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
	printf("1 - Inserir Nova Matrícula\n");
	printf(RED "2 - Remover Matrícula\n");
	printf(GREEN"3 - Pesquisar Matrícula\n");
	printf("4 - Total de Matrículas\n");
	printf("5 - Imprimir Matrículas\n" RESET);
	printf(RED "0 - Sair\n" RESET);
	do {
		printf(YELLOW "Escolha sua opção: " RESET);
		scanf(" %d", &op);
	} while(op < 0 || op > 6);
	return op;
}

int menuHash() {
    correct();
	int op;
	// system("@cls||clear");  // LIMPA A TELA
	printf(BLUE "\n\t\t =====| Escolher Tamanho do Vetor Hash |=====\t\t\n" RESET);
	printf(GREEN"1 - 100%%\n");
	printf("2 - 120%%\n");
	printf("3 - 150%%\n");
	do {
		printf(YELLOW "Escolha sua opção: " RESET);
		scanf(" %d", &op);
	} while(op < 0 || op > 3);
	return op;
}

int main(){
	inicializa(&lista);
	correct();
	int op;

    // LerArquivodeDados(&lista);
    do{
        op = menuHash();
        switch (op){
        case 1:
            // Inserir Nova Matrícula
            fatorTamanhoTabelaHash = 100;
            break;
        case 2:
            // Remover Matrícula
            fatorTamanhoTabelaHash = 120;
            break;
        case 3:
            // Pesquisar Matrícula
            fatorTamanhoTabelaHash = 150;
            break;
        default:
            printf("\n\nOpção inválida!\n\n");
        }
    } while (op != 0);

    return 0;
}
