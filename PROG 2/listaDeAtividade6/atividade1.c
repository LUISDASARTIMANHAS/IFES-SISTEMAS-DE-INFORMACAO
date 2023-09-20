#include "functions.c"
#include <stdlib.h>
#include <stdio.h>
#define TAM 100

// Implemente manualmente a função strlen, ou seja, uma função que conta a quantidade de caracteres de uma string (obviamente não é permitido o uso da função strlen da biblioteca
void strTam(char *str,int max){
    int pos = pesqStr(str,max, "\n");
    printf("\n posição: %d \n",pos);
}

int main(){
    correct();
    head();
    correct();
    char string[TAM];

    printf("\nInsira uma frase\n");
    inputStr(string,TAM);
    strTam(string,TAM);

    printf(string);
    copy();
    return 0;
}