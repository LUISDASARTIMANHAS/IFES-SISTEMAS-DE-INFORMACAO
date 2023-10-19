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
    Produto prod;

    arquivo = abrirArquivo("../data/estoque.bin", "rb");

    fread(&prod,  sizeof(Produto), 1, arquivo  );
    while ( ! feof(arquivo) ) {
        
        printf("%3d|%-50s|%5d|%10.2f|\n", prod.codigo, prod.nome, prod.qtde , prod.preco  );
        fread(&prod,  sizeof(Produto), 1, arquivo  );

        /*

        fread(&cod,  sizeof(int), 1, arquivo  );        
        if ( ! feof(arquivo) ) {
            fread(nome,  TAM * sizeof(char), 1, arquivo  );
            fread(&qtde,  sizeof(int), 1, arquivo  );
            fread(&preco,  sizeof(float), 1, arquivo  );
            
            printf("%3d|%-50s|%5d|%10.2f|\n", cod, nome, qtde , preco  );
        }
        */
    }

    
    fclose(arquivo);
    printf("FIM");
    return 0;
}