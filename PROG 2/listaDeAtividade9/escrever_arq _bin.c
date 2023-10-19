#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

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
    int i, cod;
    char nome[TAM+1], codStr[TAM+1];
    float preco;
    int qtde;

    arquivo = abrirArquivo("../data/estoque.bin", "wb");
    
    for (i=1; i <= 100; i++) {
        cod = i;
        strcpy(nome, "Produto ");
        itoa(cod, codStr, 10);
        strcat(nome, codStr );
        preco = cod * 2.1;
        qtde = cod * 10;

        fwrite(&cod,sizeof(int),1,arquivo);
        fwrite(nome,TAM * sizeof(char),1,arquivo);
        fwrite(&preco,sizeof(int),1,arquivo);
        fwrite(&qtde,sizeof(int),1,arquivo);

    }
    
    fclose(arquivo);
    printf("FIM");
    return 0;
}