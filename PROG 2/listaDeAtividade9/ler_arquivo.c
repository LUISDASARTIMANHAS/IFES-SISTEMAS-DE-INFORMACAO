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

    int cod;
    char nome[100];
    float preco;
    int qtde;


    arquivo = abrirArquivo("../data/estoque.txt", "r");

    while ( ! feof(arquivo) ) { 
        fscanf(arquivo, "%d" , &cod);
        fscanf(arquivo, " %50[^\n]s" , nome);
        fscanf(arquivo, "%d" , &qtde);
        fscanf(arquivo, "%f" , &preco);

        printf("%3d|%-50s|%5d|%10.2f|\n", cod, nome, qtde, preco  );
    }

      
    return 0;
}