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


int main () {
    FILE * arquivo;
    int i;
    char codStr[TAM+1];
    dataProduto prod;

    arquivo = abrirArquivo("../data/estoque.bin", "wb");
    
    for (i=1; i <= 100; i++) {
        prod.cod = i;
        strcpy(prod.nome, "Produto ");
        itoa(prod.cod, codStr, 10);
        strcat(prod.nome, codStr );
        prod.preco = prod.cod * 2.1;
        prod.qtde = prod.cod * 10;

        fwrite(&prod,sizeof(dataProduto),1,arquivo);
        // fwrite(&cod,sizeof(int),1,arquivo);
        // fwrite(nome,TAM * sizeof(char),1,arquivo);
        // fwrite(&preco,sizeof(int),1,arquivo);
        // fwrite(&qtde,sizeof(int),1,arquivo);

    }
    
    fclose(arquivo);
    printf("FIM");
    return 0;
}