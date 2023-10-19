#include <stdlib.h>
#include <stdio.h>
#include "functions.c"


int main(){
    head();
    int cont = 0;
    char txt[100];
    FILE * file;

    file = lerArquivo("../data/atividade.txt");
    lerPalavra(txt);
    cont = contarPalavras(file,txt);
    printf("A palavra ");

    while(!feof(file)){
    fscanf(file,"%s",&txt);
    printf("%c",txt);
    }

    fclose(file);
    copy();
    return 0;
}

// contar quantas vezes a palavra aparece no arquivo

// if(dtrcmo(palavra, palavraAq) == 0 ){

// }