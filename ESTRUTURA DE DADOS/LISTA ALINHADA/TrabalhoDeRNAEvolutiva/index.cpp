// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
/*
  Rede Neural Artificial Evolutiva (RNA-E)
  
  Os pesos s�o atualizados a partir de um algoritmo
  gen�tico que busca minimizar os erros na fase de
  treinamento.
  
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

TLista listas;


//===| Fun��es |======================================
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
	
	// L->fp = fopen("RNA_EVOLUTIVA_RELATORIO.TXT","w");
    L->fp = fopen("../data/RNA_EVOLUTIVA_RELATORIO.TXT","w");
	
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


//===| Programa Principal |===========================
int main(){
	inicializa(&listas);
	treinamento(&listas);
}