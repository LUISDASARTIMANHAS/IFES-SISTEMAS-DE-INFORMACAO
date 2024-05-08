#include <iostream>
/*
    Rede Neural Artificial Evolutiva (RNA-E)
    Os pesos são atualizados a partir de um algoritmo genético que busca minimizar os erros na fase de treinamento.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Entradas 2
#define MAX_Pesos 6

//===| Estrutura de Dados |==========================
typedef char string[60];

typedef struct tipoLicao
{
    int p;                 // proposição P
    int q;                 // Proposição Q
    int resultadoEsperado; // Proposição Composta P "E" Q (A Classe)
    tipoLicao *prox;
} TLicao;

typedef struct tipoIndividuo
{
    float genes[MAX_Pesos];
    int erros;
    int numero; // numero identificador
    tipoIndividuo *prox;
} TIndividuo;

typedef struct tipoSinapse
{
    int camada;
    int neuronio_origem;
    int neuronio_destino;
    float peso;
    tipoSinapse *prox;
} TSinapse;

typedef struct tipoNeuronio
{
    int neuronio;
    float soma;
    float peso;
    tipoNeuronio *prox;
} TNeuronio;

typedef struct tipoLista
{
    FILE *fp; // Arquivo de Saída (Relatório).
    string objetivo;
    TLicao *licoes; // Conjunto de lições a serem aprendidas
    float entradas[MAX_Entradas];
    TNeuronio *neuronios;
    TSinapse *pesos;
    TIndividuo *populacao;
    TIndividuo *fimLista;
    TIndividuo *individuoAtual;
    int totalIndividuos;
    int Qtd_Populacao;
    int Qtd_Mutacoes_por_vez;
    int Total_geracoes;
    int geracao_atual;
    int Qtd_Geracoes_para_Mutacoes;
    float sinapseThreshold;
    float learningRate;
} TLista;

TLista lista;

//====| Assinatura de Funções |=======================+
void inicializa(TLista *L);
void geraIndividuos(TLista *L);
void geraLicoes(TLista *L);
void insereLicao(TLista *L, int p, int q, int resultado);
void insereNeuronio(TLista *L, int neuronio);
void estabelecendoSinapse(TLista *L, int neuronioDe, int neuronioAte, int camada);
void treinamento(TLista *L);
void cruzamento(TLista *L);
void avaliacaoIndividuos(TLista *L);
void ordenamentoIndividuos(TLista *L);
void promoveMutacoes(TLista *L,float learningRate);
void poda(TLista *L);
//===| Programa Principal |===========================
int main(){
    inicializa(&lista);
    treinamento(&lista);
}
//===| Funções |======================================
void exibeIndividuos(TLista *L) {
	TIndividuo *atual = L->populacao;
	int i = 1;
	int j;
	int bytes;

	printf("\n\t TABELA DE INDIVIDUOS:\n");
	fprintf(L->fp,"\n\t TABELA DE INDIVIDUOS:\n");
	while (atual != NULL) {
		// printf("| \t(%d) \t| numero = %d \t| endr = %p \t| err = %d \t| %d -> %d \t|\n", i, atual->numero, &atual, atual->erros,atual->numero,atual->prox->numero);
		printf("| \t(%d) ",i);
		printf("\t| numero = %d ",atual->numero);
		printf("\t| endr = %p ",&atual);
		printf("\t| err = %d ",atual->erros);
		if(atual->prox == NULL){
			printf("\t| %d -> NULL ",atual->numero);
		}else{
			printf("\t| %d -> %d ",atual->numero,atual->prox->numero);
		}
		printf("\t| genes = ");
		for (j = 0; j < MAX_Pesos; j++){
			printf("%.2f,",atual->genes[j]);
		}
		printf("\t|\n");

		fprintf(L->fp,"| \t(%d) \t| number = %d \t| address = %p \t| errors = %d \t|\n", i, atual->numero, &atual, atual->erros);
		i++;
		atual = atual->prox;
	}
	bytes = sizeof(TIndividuo) * i;
	printf("TAM %dMbytes\n", bytes/1024);
	fprintf(L->fp,"TAM %dMbytes\n", bytes/1024);
}

FILE * abrirArquivo(char * nomeArq, char * modo) {
    // ABRIR o arquivo
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf("\n\n\t ERRO ao abrir o arquivo. \n\n");
        return NULL;
    }
    return arq;
}

void inicializa(TLista *L){
	int i;
	
	L->licoes = NULL;
	L->populacao = NULL;
	L->individuoAtual = NULL;
	L->totalIndividuos = 0;
	
	for(i=0; i < MAX_Entradas; i++){
		L->entradas[i] = 0;
	}//for
	
	L->neuronios = NULL;
	L->pesos = NULL;
	
	printf("\t\t=====| REDE NEURAL ARTIFICIAL EVOLUTIVA |=====");
	printf("\n\n\t\t=====| Configuracao da RNA |=====\n\n");
	printf("\tInforme o TAMANHO da POPULACAO (em termos de individuos):\n");
	printf("\t\tSugestao: 300 individuos.\n\t\tValor: ");
	scanf("%d", &L->Qtd_Populacao);
	
	geraIndividuos(L);
	
	printf("\n\n\tInforme a QUANTIDADE de GERACOES maxima:");
	printf("\n\tSugestao: 100 geracoes no total.\n\tValor: ");
	scanf("%d", &L->Total_geracoes);
	
	L->geracao_atual = 0;
	
	printf("\n\n\tInforme o INTERVALO de GERACOES para a ocorrencia de MUTACOES:");
	printf("\n\tSugestao: 5 (a cada 5 geracoes devem ocorrer mutacoes).\n\tValor: ");
	scanf("%d", &L->Qtd_Geracoes_para_Mutacoes);
	
	printf("\n\n\tInforme a QUANTIDADE de MUTACOES que devem ocorrer POR VEZ:");
	printf("\n\tSugestao: 3 mutacoes por intervalo.\n\tValor: ");
	scanf("%d", &L->Qtd_Mutacoes_por_vez);
	
	printf("\n\nSINAPSE THRESHOLD (Limiar das Conexoes entre Neuronios):\n");
	printf("Define a intensidade do sinal que sensibiliza cada neuronio.\n\n");
	printf("\tInforme o SINAPSE THRESHOLD:\n\tSugestao: 0.60\n\tValor: ");
	scanf("%f",&L->sinapseThreshold);
	
	printf("\n\nLEARNING RATE (Taxa de Aprendizado): variacao dos pesos em cada ajuste (Aprendizado).\n");
	printf("\n\tLEARNING RATE:\n\tSugestao: 0.20\n\tValor: ");
	scanf("%f",&L->learningRate);
	
	strcpy(L->objetivo,"Aprendizado da Funcao Logica P E Q");
	
	printf("\n\n\tDefinindo as LICOES a serem aprendidas pela Rede Neural Artificial.\n\n");
	geraLicoes(L);
	
	printf("\n\n\tDefinindo os NEURONIOS que compoem a REDE NEURAL ARTIFICIAL.");
	insereNeuronio(L,1);
	insereNeuronio(L, 2);
	insereNeuronio(L, 3);
	insereNeuronio(L, 4);
	insereNeuronio(L, 5);
	
	printf("\n\n\tEstabelecendo as CONEXOES (Sinapses) entre os NEURONIOS.");
	estabelecendoSinapse(L,1,3,0);
	estabelecendoSinapse(L,1,4,0);
	estabelecendoSinapse(L,2,3,0);
	estabelecendoSinapse(L,2,4,0);
	estabelecendoSinapse(L,3,5, 1);
	estabelecendoSinapse(L,4,5, 1);
	
	L->fp = fopen("RNA_EVOLUTIVA_RELATORIO.TXT","w");
	
	fprintf(L->fp,"\n\t\t=====| REDE NEURAL ARTIFICIAL EVOLUTIVA |=====\n\n");
	fprintf(L->fp,"\tOBJETIVO: %s.\n\n\tLicoes:\n", L->objetivo);
	fprintf(L->fp,"\t LICAO    P    Q  (Resultado Esperado)\n");
	fprintf(L->fp,"\t+------+----+----+---------------------+\n");
	
	TLicao *licao = L->licoes;
	int cont = 0;
	while(licao != NULL){
		fprintf(L->fp,"\t(%d) - %d   %d   %d\n", ++cont, licao->p, licao->q, licao->resultadoEsperado);
		licao = licao->prox;
	}//while
	
	fprintf(L->fp,"\n\n");
	fprintf(L->fp,"\tLearning Rate: %.2f\n", L->learningRate);
	fprintf(L->fp,"\tSinapse Threshold: %.2f\n", L->sinapseThreshold);
	fprintf(L->fp,"\tPopulacao MAXIMA: %d.\n", L->Qtd_Populacao);
	fprintf(L->fp,"\t%d MUTACOES a cada sequencia de %d GERACOES.\n", L->Qtd_Mutacoes_por_vez, L->Qtd_Geracoes_para_Mutacoes);
	fprintf(L->fp,"\tTOTAL de GERACOES: %d.\n\n\n", L->Total_geracoes);
	
	printf("\n\n\tConfiguracao FINALIZADA!!!\n\n");
	
}

//====================================================
void geraIndividuos(TLista *L){
	TIndividuo *novo;
	int i, x;
	
    srand( (unsigned)time(NULL) );
    
    for(i= 0; i < L->Qtd_Populacao; i++){
    	novo = (TIndividuo *)malloc(sizeof(TIndividuo));
		
		novo->prox = NULL;
		novo->numero = i+1;		
		novo->erros = -1;
		
		for(x=0; x < MAX_Pesos; x++){
			novo->genes[x] = rand() % 101;
			novo->genes[x] = novo->genes[x] / 100;
		}//for
		
		if(L->populacao == NULL){
			L->populacao = novo;
		} else {
			TIndividuo *atual = L->populacao;
			
			while(atual->prox != NULL){
				atual = atual->prox;
			}//while
			
			atual->prox = novo;
		}//if
		
		L->totalIndividuos++;
	}//for
}
//=====================================================
void geraLicoes(TLista *L){
	TLicao *novo;
	int p,q;
	
	insereLicao(L, 0, 0, 0);
	insereLicao(L, 0, 1, 0);
	insereLicao(L, 1, 0, 0);
	insereLicao(L, 1, 1, 1);

}
//=====================================================
void insereLicao(TLista *L, int p, int q, int resultado){
	TLicao *novo = (TLicao *)malloc(sizeof(TLicao));
	
	novo->prox = NULL;
	novo->p = p;
	novo->q = q;
	novo->resultadoEsperado = resultado;
	
	if(L->licoes == NULL){
		L->licoes = novo;
	} else {
		TLicao *atual = L->licoes;
		
		while(atual->prox != NULL){
			atual = atual->prox;			
		}//while
		atual->prox = novo;
	}//if
}
//======================================================
void insereNeuronio(TLista *L, int neuronio){
	TNeuronio *novo = (TNeuronio *)malloc(sizeof(TNeuronio));
	novo->prox = NULL;
	novo->neuronio = neuronio;
	novo->peso = 0;
	novo->soma = 0;
	
	if(L->neuronios == NULL){
		L->neuronios = novo;
	} else {
		TNeuronio *atual = L->neuronios;
		
		while(atual->prox != NULL){
			atual = atual->prox;
		}//while
		atual->prox = novo;
	}//if
}
//======================================================
void estabelecendoSinapse(TLista *L,int neuronioDe, int neuronioAte, int camada){
	TSinapse *novo = (TSinapse *)malloc(sizeof(TSinapse));
	TSinapse *atual;
	
	novo->prox = NULL;
	novo->neuronio_origem = neuronioDe;
	novo->neuronio_destino = neuronioAte;
	novo->camada = camada;
	novo->peso = 0;
	
	if(L->pesos == NULL){
		L->pesos = novo;
	} else {
		atual = L->pesos;
		
		while(atual->prox != NULL){
			atual = atual->prox;
		}//while
		atual->prox = novo;
	}//if
}
//=============================================================
int contaIndividuos(TLista *lista){
    TIndividuo *atual = (TIndividuo *)malloc(sizeof(TIndividuo));
    atual = lista->populacao;
    int cont = 0;
    while (atual != NULL){
        atual = atual->prox;
        cont++;
    }
    printf("O numero de individuos e: %d\n", cont);
    return cont;
}
//=============================================================
void descobreFimLista(TLista *L){
    TIndividuo *atual = (TIndividuo *)malloc(sizeof(TIndividuo));
    atual = L->populacao;
    while (atual->prox != NULL){
        atual = atual->prox;
    }
    L->fimLista = atual;
}
//=============================================================
void printIndividuos(TLista *L) {
    TIndividuo *atual = L->populacao;
    int i = 1;
    printf("Lista de individuos:\n");
    while (atual!= NULL) {
        printf("Individuo %d:\n", i);
        printf("  Numero: %d\n", atual->numero);
        printf("  Endereco de memoria: %p\n", (void *)atual);
        printf("  Genes: ");
        for (int j = 0; j < MAX_Pesos; j++) {
            printf("%.2f ", atual->genes[j]);
        }
        printf("\n");
        printf("  Erros: %d\n", atual->erros);
        if (atual->prox!= NULL) {
            printf("  Proximo individuo: %p\n", (void *)atual->prox);
        } else {
            printf("  Proximo individuo: NULL\n");
        }
        printf("\n");
        atual = atual->prox;
        i++;
    }
}
//=============================================================
void treinamento(TLista *L){
	printf("\n\n\t\t=====| INICIADO TREINAMENTO |=====\n\n");
	fprintf(L->fp,"\n\n\tINICIO DO TREINAMENTO: ");
	//ponteiro para a struct que armazena data e hora:
	struct tm *data_hora_atual;
	//vari?vel do tipo time_t para armazenar o tempo em segundos.
	time_t segundos;
	//Obetendo o tempo em segundos.
	time(&segundos);
	//Para converter de segundos para o tempo local
	//utilizamos a fun??o localtime().
	data_hora_atual = localtime(&segundos);
	
	fprintf(L->fp,"Dia: %d", data_hora_atual->tm_mday);
	fprintf(L->fp,"   Mes: %d", data_hora_atual->tm_mon+1);
	fprintf(L->fp,"   Ano: %d\n\n", data_hora_atual->tm_year+1900);
	
	fprintf(L->fp,"Dia da Semana: %d.\n", data_hora_atual->tm_wday);
	
	fprintf(L->fp,"%d", data_hora_atual->tm_hour);
	fprintf(L->fp,":%d", data_hora_atual->tm_min);
	fprintf(L->fp,":%d.\n\n", data_hora_atual->tm_sec);
	
	int i;
	for(i= 0; i < L->Total_geracoes; i++){
		cruzamento(L);
        //contaIndividuos(L);
		if((i % L->Qtd_Geracoes_para_Mutacoes) == 0){
			promoveMutacoes(L,L->learningRate);
		}//if
		avaliacaoIndividuos(L);
		ordenamentoIndividuos(L);
		poda(L);
        //contaIndividuos(L);
        exibeIndividuos(L);
	}//for
	printf("Salvando dados...");
	fclose(L->fp);
	printf("Salvo com sucesso!");
}
//=============================================================
void inserirNoFimAux(TLista *L, TIndividuo *individuo) {
    if (L->populacao == NULL) { // Se a lista estiver vazia
        L->populacao = individuo;
        L->totalIndividuos++;
        return;
    }
    TIndividuo *aux = L->populacao;
    while (aux->prox != NULL) { // Percorre até o último elemento da lista
        aux = aux->prox;
    }
    aux->prox = individuo; // Adiciona o novo indivíduo ao final da lista
    L->totalIndividuos++;
}

void inserirNoFim(TLista *L, TIndividuo *individuo) {
    TIndividuo *clone = (TIndividuo *)malloc(sizeof(TIndividuo)); // Clonar o indivíduo
    memcpy(clone, individuo, sizeof(TIndividuo));
    clone->prox = NULL;
    inserirNoFimAux(L, clone);
}

//==============================================================
float randomFloat(float min, float max) {
    float scale = rand() / (float) RAND_MAX; 
    return min + scale * ( max - min ); 
}

void promoveMutacoes(TLista *L, float learningRate) {
    // Verificar se a lista está vazia
    if (L->populacao == NULL) {
        printf("Lista de individuos vazia.\n");
        return;
    }

    // Escolher um indivíduo aleatório
    int index = rand() % L->totalIndividuos;
    TIndividuo *individuo = L->populacao;

    // Percorrer até o índice do indivíduo escolhido
    for (int i = 0; i < index; i++) {
        individuo = individuo->prox;
    }

    // Escolher um gene aleatório
    int geneIndex = rand() % MAX_Pesos;

    // Escolher aleatoriamente se a mutação será para cima ou para baixo
    int upOrDown = rand() % 2; // 0 para baixo, 1 para cima

    // Aplicar a mutação
    if (upOrDown == 0) {
        individuo->genes[geneIndex] -= learningRate; // Diminuir do valor do gene
    } else {
        individuo->genes[geneIndex] += learningRate; // Somar ao valor do gene
    }

    //printf("Mutacao promovida com sucesso.\n");
}
//=============================================================
void cruzamento(TLista *L) {
    TIndividuo *pai1, *pai2, *filho1, *filho2;
    pai1 = L->populacao;
    pai2 = pai1->prox;
    int cont = L->totalIndividuos + 1;
    int individuosCruzados = 0; 
    int totalPais = L->totalIndividuos;

    while (individuosCruzados < totalPais / 2) { // cruzar até a metade dos pais
        //printf("Cruzando individuo %d com %d\n", pai1->numero, pai2->numero);
        filho1 = (TIndividuo *)malloc(sizeof(TIndividuo));
        filho2 = (TIndividuo *)malloc(sizeof(TIndividuo));
        filho1->prox = NULL;
        filho2->prox = NULL;
        int metade = MAX_Pesos / 2;
        for (int j = 0; j < metade; j++) {
            filho1->genes[j] = pai1->genes[j];
            filho2->genes[j] = pai2->genes[j];
        }
        for (int j = metade; j < MAX_Pesos; j++) {
            filho1->genes[j] = pai2->genes[j];
            filho2->genes[j] = pai1->genes[j];
        }
        filho1->erros = -1;
        filho2->erros = -1;
        filho1->numero = cont;
        filho2->numero = cont + 1;
        cont = cont + 2;
        inserirNoFimAux(L, filho1);
        inserirNoFimAux(L, filho2);
        individuosCruzados += 1;
        
        // Avançar para os próximos pais, garantindo que não ultrapassemos o final da lista
        if (pai1->prox != NULL) {
            pai1 = pai1->prox;
        }
        if (pai2->prox != NULL) {
            pai2 = pai2->prox;
        }
    }
}
//==============================================================
void avaliacaoIndividuos(TLista *L) {
    TIndividuo *atual = L->populacao;
    
    while (atual != NULL) {
        if (atual->erros == -1) {
            atual->erros = 0;
            TLicao *licaoAtual = L->licoes; // Corrigido aqui
            
            while (licaoAtual != NULL) {
                float n3, soma3, n1, n2;
                float peso13 = atual->genes[0];
                float peso23 = atual->genes[2];
                n1 = licaoAtual->p; // Corrigido aqui
                n2 = licaoAtual->q; // Corrigido aqui
                soma3 = (n1 * peso13) + (n2 * peso23);
                
                if (soma3 >= L->sinapseThreshold) {
                    n3 = 1;
                } else {
                    n3 = 0;
                }
                
                float n4, soma4;
                float peso14 = atual->genes[1];
                float peso24 = atual->genes[3];
                soma4 = (n2 * peso14) + (n3 * peso24);
                
                if (soma4 >= L->sinapseThreshold) {
                    n4 = 1;
                } else {
                    n4 = 0;
                }
                
                float n5, soma5;
                float peso15 = atual->genes[4];
                float peso25 = atual->genes[5];
                soma5 = (n3 * peso15) + (n4 * peso25);
                
                if (soma5 >= L->sinapseThreshold) {
                    n5 = 1;
                } else {
                    n5 = 0;
                }
                
                if (licaoAtual->resultadoEsperado != n5) { // Corrigido aqui
                    //printf("Cometeu erro\n");
                    atual->erros++;
                }
                
                licaoAtual = licaoAtual->prox;
            }
        }
        
        atual = atual->prox;
    }
}
//==============================================================
void ordenamentoIndividuos(TLista *L){
    TIndividuo *atual, *anterior, *temp;
    int trocou;

    // Se a lista estiver vazia ou tiver apenas um elemento, não há nada a ordenar
    if (L->populacao == NULL || L->populacao->prox == NULL) {
        return;
    }

    do {
        trocou = 0;
        atual = L->populacao;
        anterior = NULL;

        while (atual->prox != NULL) {
            // Se o número de erros do próximo indivíduo for maior que o atual, troque-os de lugar
            if (atual->erros > atual->prox->erros) {
                temp = atual->prox;
                atual->prox = atual->prox->prox;
                temp->prox = atual;

                if (anterior != NULL) {
                    anterior->prox = temp;
                } else {
                    // Se anterior for NULL, significa que estamos trocando o primeiro elemento da lista
                    L->populacao = temp;
                }

                anterior = temp;
                trocou = 1;
            } else {
                anterior = atual;
                atual = atual->prox;
            }
        }
    } while (trocou);
}
//==============================================================
void poda(TLista *L){
	// Verificar se o número total de indivíduos na lista é maior do que o máximo permitido
    if (L->totalIndividuos > L->Qtd_Populacao) {
        // Calcular quantos indivíduos excedentes precisam ser removidos
        int excedente = L->totalIndividuos - L->Qtd_Populacao;

        // Remover os indivíduos excedentes
        TIndividuo *atual = L->populacao;
        TIndividuo *anterior = NULL;

        // Avançar até o último indivíduo da lista
        while (atual!= NULL && excedente > 0) {
            anterior = atual;
            atual = atual->prox;
            excedente--;
        }

        // Se houver algum nó anterior, significa que precisamos cortar a lista
        if (anterior!= NULL) {
            // Atualizar o ponteiro para o último nó da lista
            L->fimLista = anterior;

            // Definir o próximo nó após o último nó como NULL
            anterior->prox = NULL;

            // Atualizar o número total de indivíduos na lista
            L->totalIndividuos = L->Qtd_Populacao;
        } else {
            // Se não houver nenhum nó anterior, significa que a lista inteira deve ser removida
            L->populacao = NULL;
            L->fimLista = NULL;
            L->totalIndividuos = 0;
        }
    }
}
//==============================================================
