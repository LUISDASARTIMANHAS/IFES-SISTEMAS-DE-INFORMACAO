#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

struct Produto {
    int codigo;
    char nome[TAM+1];
    float preco;
    int qtde;
};
typedef struct Produto Produto;


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
    Produto prod;


    arquivo = abrirArquivo("../data/estoque.bin", "wb");

    for (i=1; i <= 100; i++) {
        // Simular os dados
        prod.codigo = i;
        strcpy(prod.nome, "Produto ");
        itoa(prod.codigo, codStr, 10);
        strcat(prod.nome, codStr );
        prod.preco = prod.codigo * 2.1;
        prod.qtde = prod.codigo * 10;
        
        // FIM da simulação

        fwrite(&prod, sizeof(Produto), 1, arquivo );

        /*
        fwrite(&cod,  sizeof(int), 1, arquivo  );
        fwrite(nome,  TAM * sizeof(char), 1, arquivo  );
        fwrite(&qtde,  sizeof(int), 1, arquivo  );
        fwrite(&preco,  sizeof(float), 1, arquivo  );
        */
    }


    fclose(arquivo);
    printf("FIM");
    return 0;
}