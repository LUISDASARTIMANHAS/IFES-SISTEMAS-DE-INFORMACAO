#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

struct Produto{
    int cod;
    char nome[TAM+1];
    float preco;
    int qtde;
};
typedef struct Produto dataProduto;

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
void gravarArquivo(FILE * arquivo, dataProduto *vetProd, int qtde){
    fwrite(&qtde,sizeof(int),1,arquivo);
    fwrite(vetProd,sizeof(dataProduto),qtde,arquivo);
}
void simularDados(dataProduto * vetProd, int *qtde){
    int i;
    char codStr[TAM+1];
    dataProduto prod;
    *qtde = 389;
    for (i=0; i <= *qtde; i++) {
        prod.cod = i;
        strcpy(prod.nome, "Produto ");
        itoa(prod.cod, codStr, 10);
        strcat(prod.nome, codStr );
        prod.preco = prod.cod * 2.1;
        prod.qtde = prod.cod * 10;
        vetProd[i] = prod;
    }
}

int main () {
    FILE * arquivo;
    dataProduto vetProd[1000];
    int qtde = 100;
    simularDados(vetProd, &qtde);
    
    arquivo = abrirArquivo("../data/estoque.bin", "wb");
    gravarArquivo(arquivo, vetProd, &qtde);
    fclose(arquivo);

    printf("FIM");
    return 0;
}