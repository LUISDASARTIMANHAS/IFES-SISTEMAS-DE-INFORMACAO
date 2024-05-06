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
void promoveMutacoes(TLista *L);
void poda(TLista *L);
//===| Programa Principal |===========================
int main(){
    
    inicializa(&lista);
    treinamento(&lista);
}
//===| Funções |======================================
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
	
	L->fp = abrirArquivo("data/RNA_EVOLUTIVA_RELATORIO.TXT", "w");
    if(L->fp == NULL){
        printf("Reabrindo arquivo no local da execucao");
        L->fp = abrirArquivo("RNA_EVOLUTIVA_RELATORIO.TXT", "w");
    }
	
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
void geraIndividuos(TLista *L)
{
    TIndividuo *novo;
    int i, x;

    srand((unsigned)time(NULL));

    for (i = 0; i < L->Qtd_Populacao; i++)
    {
        novo = (TIndividuo *)malloc(sizeof(TIndividuo));

        novo->prox = NULL;
        novo->numero = i + 1; // Correção aqui
        novo->erros = -1;

        for (x = 0; x < MAX_Pesos; x++)
        {
            novo->genes[x] = rand() % 101;
            novo->genes[x] = novo->genes[x] / 100;
        } // for

        if (L->populacao == NULL)
        {
            L->populacao = novo;
        }
        else
        {
            TIndividuo *atual = L->populacao;

            while (atual->prox != NULL)
            {
                atual = atual->prox;
            } // while

            atual->prox = novo;
        } // if

        L->totalIndividuos++;
    } // for
}
//=====================================================
void geraLicoes(TLista *L){
    // TLicao *novo;
    // int p, q;

    insereLicao(L, 0, 0, 0);
    insereLicao(L, 0, 1, 0);
    insereLicao(L, 1, 0, 0);
    insereLicao(L, 1, 1, 1);
}
//=====================================================
void insereLicao(TLista *L, int p, int q, int resultado)
{
    TLicao *novo = (TLicao *)malloc(sizeof(TLicao));

    novo->prox = NULL;
    novo->p = p;
    novo->q = q;
    novo->resultadoEsperado = resultado;

    if (L->licoes == NULL)
    {
        L->licoes = novo;
    }
    else
    {
        TLicao *atual = L->licoes;

        while (atual->prox != NULL)
        {
            atual = atual->prox;
        } // while
        atual->prox = novo;
    } // if
}
//======================================================
void insereNeuronio(TLista *L, int neuronio)
{
    TNeuronio *novo = (TNeuronio *)malloc(sizeof(TNeuronio));
    novo->prox = NULL;
    novo->neuronio = neuronio;
    novo->peso = 0;
    novo->soma = 0;

    if (L->neuronios == NULL)
    {
        L->neuronios = novo;
    }
    else
    {
        TNeuronio *atual = L->neuronios;

        while (atual->prox != NULL)
        {
            atual = atual->prox;
        } // while
        atual->prox = novo;
    } // if
}
//======================================================
void estabelecendoSinapse(TLista *L, int neuronioDe, int neuronioAte, int camada)
{
    TSinapse *novo = (TSinapse *)malloc(sizeof(TSinapse));
    TSinapse *atual;

    novo->prox = NULL;
    novo->neuronio_origem = neuronioDe;
    novo->neuronio_destino = neuronioAte;
    novo->camada = camada;
    novo->peso = 0;

    if (L->pesos == NULL)
    {
        L->pesos = novo;
    }
    else
    {
        atual = L->pesos;

        while (atual->prox != NULL)
        {
            atual = atual->prox;
        } // while
        atual->prox = novo;
    } // if
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
	//for(i= 0; i < L->Total_geracoes; i++){
		cruzamento(L);
		printIndividuos(L);
		if((i % L->Qtd_Geracoes_para_Mutacoes) == 0){
			promoveMutacoes(L);
		}//if
		avaliacaoIndividuos(L);
		ordenamentoIndividuos(L);
		poda(L);
		printIndividuos(L);
	//}//for
	printf("Salvando dados...");
	fclose(L->fp);
	printf("Salvo com sucesso!");
}
//=============================================================
void inserirNoFim(TLista *lista, TIndividuo *filho) {
    // Acessar o último nó da lista
    TIndividuo *atual = lista->fimLista;
    printf("Chegou aqui1\n");
    // Atualizar o último nó da lista para o novo nó
    lista->fimLista = filho;
    printf("Chegou aqui2\n");
    // Se a lista estiver vazia, o novo individuo sera o primeiro
    if (atual == NULL) {
        lista->populacao = filho;
    } else {
        // O próximo nó do último nó da lista deve ser o novo nó
        atual->prox = filho;
    }
    // Incrementar o contador de elementos da lista
    lista->totalIndividuos++;
    printf("Chegou aqui3\n");
    // Imprimir uma mensagem de confirmação
    printf("Elemento inserido no fim da lista\n");
}
//=============================================================
void cruzamento(TLista *L){
    /*Essa funçao deve ler cada um dos individuos da lista e cruza-los, ou seja pegar metade
    dos genes de cada um dos pais selecionados e usar metade dos genes do primeiro individuo usado
    e depois usar a outra metade de genes tirados do segundo individuo selecionado, devem ser feitos 2 individuos
    novos de cada par de individuos selecionados da lista, esses individuos novos devem ser colocados em uma lista 
    auxiliar e apos isso devem ser alocados para a lista principal de forma que a lista principal tenha todos 
    os individuos interligados, no inicio os individuos originais e depois os individuos criados do cruzamento*/
    TIndividuo *pai1, *pai2, *filho1, *filho2;
    pai1 = L->populacao;
    pai2 = pai1->prox;
    int cont = L->totalIndividuos + 1;
    while (pai2!= NULL) { // Iterate until the end of the list
        printf("Cruzando individuo %d com %d\n", pai1->numero, pai2->numero);
        filho1 = (TIndividuo *)malloc(sizeof(TIndividuo));
        filho2 = (TIndividuo *)malloc(sizeof(TIndividuo));
        filho1->prox = NULL;
        filho2->prox = NULL;
        printf("Passou aqui1\n");
        int metade = MAX_Pesos / 2;
        for (int j = 0; j < metade; j++) {
            filho1->genes[j] = pai1->genes[j];
            filho2->genes[j] = pai2->genes[j];
        }
        for (int j = metade; j < MAX_Pesos; j++) {
            filho1->genes[j] = pai2->genes[j];
            filho2->genes[j] = pai1->genes[j];
        }
        printf("Passou aqui2\n");
        filho1->erros = -1;
        filho2->erros = -1;
        filho1->numero = cont;
        filho2->numero = cont+1;
        printf("Passou aqui3\n");
        cont = cont + 2;
        inserirNoFim(L, filho1);
        inserirNoFim(L, filho2);
        printf("Passou aqui4\n");
        if (pai1->prox == NULL) break; // Break the loop if at the end of the list
        pai1 = pai1->prox;
        pai2 = pai2->prox;
        printf("Passou aqui5\n");
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
                    printf("Cometeu erro\n");
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
void promoveMutacoes(TLista *L){
    
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
        while (atual != NULL && excedente > 0) {
            anterior = atual;
            atual = atual->prox;
            excedente--;
        }

        // Se houver algum nó anterior, significa que precisamos cortar a lista
        if (anterior != NULL) {
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
