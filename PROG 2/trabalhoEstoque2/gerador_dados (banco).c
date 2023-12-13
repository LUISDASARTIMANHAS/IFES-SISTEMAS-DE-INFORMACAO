#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_VETOR 100



struct Date{
    int dia;
    int mes;
    int ano;
};typedef struct Date Data;
struct ClassProduto{
    int cod;
    char nome[101];
    float prise;
    int quantidade;
    Data validade;
};typedef struct ClassProduto Produto;



int aleatorio(int n){
    return ( rand() % n) + 1;
}



FILE * abrirArquivo(char * nomeArq, char * modo) {
    // ABRIR o arquivo
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf("ERRO ao abrir o arquivo.");
        exit(-1);
    }
    return arq;
}

void gravarArquivo(FILE * arquivo, Produto * vet, int qtde) {

    fwrite( &qtde, sizeof(int), 1, arquivo  );
    fwrite( vet, sizeof(Produto), qtde, arquivo  );

}


void simularDados (Produto * vet, int * qtde ) {
    int i;
    char codStr[101];
    Produto temp;

    for (i=0; i < *qtde; i++) {
        // Simular os dados
        temp.cod = aleatorio(TAM_VETOR * 10);
        temp.prise = aleatorio(TAM_VETOR * 10);
        temp.quantidade = aleatorio(TAM_VETOR * 10);
        temp.validade.dia = aleatorio(30);
        temp.validade.mes = aleatorio(12);
        temp.validade.ano = aleatorio(30);

        itoa(temp.nome, codStr, 7);
        strcpy(temp.nome, "Produto ");
        strcat(temp.nome, codStr );

        vet[i] = temp;
    }
}

int main () {
    FILE * arquivo;
    Produto vetor[TAM_VETOR];
    int qtde = TAM_VETOR;

    // SEMENTE DOS NUMEROS ALEATÓRIOS. Usa a hora local
    srand( (unsigned) time(NULL) );

    simularDados(vetor, &qtde);

    arquivo = abrirArquivo("../data/database.bin", "wb");
    gravarArquivo(arquivo, vetor, qtde);
    fclose(arquivo);

    
    printf("FIM. Dados gerados com SUCESSO.");
    return 0;
}