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
    char nome[100], codStr[10];
    float preco;
    int qtde;

    arquivo = abrirArquivo("../data/estoque.bin", "rb");
    
    for (i=1; i <= 100; i++) {
        
        fread(&cod,sizeof(int),1,arquivo);
        fread(nome,sizeof(char)*50,1,arquivo);
        fread(&preco,sizeof(int),1,arquivo);
        fread(&qtde,sizeof(int),1,arquivo);
        printf("%3d|%-50s|%5d|%10.2f|\n", cod, nome, qtde, preco  );
    }
    
    fclose(arquivo);
    printf("FIM");
    return 0;
}