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

void carregarArquivo(FILE * arquivo, Produto * vetProd, int *qtde) {

    fread( qtde, sizeof(int), 1, arquivo  );
    fread( vetProd, sizeof(Produto), *qtde, arquivo  );
    

}

void listar(Produto * vetProd, int qtde) {
    int i;
    for( i=0; i < qtde; i++) {
        printf("%3d|%-50s|%5d|%10.2f|\n", vetProd[i].codigo, vetProd[i].nome, vetProd[i].qtde , vetProd[i].preco  );
    }
}


int main () {
    FILE * arquivo; 
    Produto vetProd[1000];
    int qtde = 0;

    arquivo = abrirArquivo("../data/estoque.bin", "rb");    
    carregarArquivo(arquivo, vetProd, &qtde);
    fclose(arquivo);

    listar(vetProd, qtde);
    

    
    printf("FIM");
    return 0;
}