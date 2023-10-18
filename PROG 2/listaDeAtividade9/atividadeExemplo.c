#include <stdlib.h>
#include <stdio.h>
#include "functions.c"


int main(){
    FILE * file;
    char txt[1024];
    file = abrirArquivo("../data/atividade.txt","r");
    fscanf(file,"%s",&txt);


    fclose(file);
    return 0;
}

// contar quantas vezes a palavra aparece no arquivo