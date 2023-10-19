#include <stdlib.h>
#include <stdio.h>
#include "functions.c"


int main(){
    FILE * file;
    char txt;
    file = lerArquivo("../data/atividade.txt");
    while(!feof(file)){
    fscanf(file,"%s",&txt);
    printf("%c",txt);
    }

    fclose(file);
    return 0;
}

// contar quantas vezes a palavra aparece no arquivo