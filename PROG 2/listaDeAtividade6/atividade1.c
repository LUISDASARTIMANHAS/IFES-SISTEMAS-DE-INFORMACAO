#include "functions.c"
#include <stdlib.h>
#include <stdio.h>

// Implemente manualmente a função strlen, ou seja, uma função que conta a quantidade de caracteres de uma string (obviamente não é permitido o uso da função strlen da biblioteca
void strTam(char *str,int max){
    int pos = pesqStr(str,max, "\n");
    printf("\n posição: %d \n",pos);
}

int main(){
    correct();
    head();
    correct();
    char *string;
    int maxSpace;
    autoAlocarMEMStr(&string,&maxSpace);

    printf("\nInsira uma frase\n");
    inputStr(string,maxSpace);
    strTam(string,maxSpace);

    printf(string);
    copy();
    return 0;
}