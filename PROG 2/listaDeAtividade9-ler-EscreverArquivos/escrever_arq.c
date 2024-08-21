#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

    arquivo = abrirArquivo("../data/estoque.txt", "w");
    
    for (i=1; i <= 100; i++) {
        cod = i;
        strcpy(nome, "Produto ");
        itoa(cod, codStr, 10);
        strcat(nome, codStr );
        preco = cod * 2.1;
        qtde = cod * 10;

        fprintf(arquivo, "\n%3d %-50s %5d %10.2f", cod, nome, qtde, preco  );
    }
    
    fclose(arquivo);
    printf("FIM");
    return 0;
}