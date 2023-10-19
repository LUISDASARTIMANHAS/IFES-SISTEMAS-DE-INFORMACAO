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

void gravarArquivo(FILE * arquivo, Produto * vetProd, int qtde) {

    fwrite( &qtde, sizeof(int), 1, arquivo  );
    fwrite( vetProd, sizeof(Produto), qtde, arquivo  );

}

void listar(Produto * vetProd, int qtde) {
    int i;
    for( i=0; i < qtde; i++) {
        printf("%3d|%-50s|%5d|%10.2f|\n", vetProd[i].codigo, vetProd[i].nome, 
                    vetProd[i].qtde , vetProd[i].preco  );
    }
}

void simularDados (Produto * vetProd, int * qtde ) {
    int i;
    char codStr[TAM+1];
    Produto prod;

    *qtde = 389;
    for (i=0; i < *qtde; i++) {
        // Simular os dados
        prod.codigo = i+1;
        strcpy(prod.nome, "Produto ");
        itoa(prod.codigo, codStr, 10);
        strcat(prod.nome, codStr );
        prod.preco = prod.codigo * 2.1;
        prod.qtde = prod.codigo * 10;

        vetProd[i] = prod;
    }
    
 }

int main () {
    FILE * arquivo; 
    Produto vetProd[1000];
    int qtde = 0;

    simularDados(vetProd, &qtde);

    arquivo = abrirArquivo("../data/estoque.bin", "wb");    
    gravarArquivo(arquivo, vetProd, qtde);
    fclose(arquivo);

    
    printf("FIM");
    return 0;
}