#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

// Implemente um programa em C que dada a idade de uma pessoa, determine sua
// classificação segundo as informações:
//  maior de idade;
//  menor de idade;
//  pessoa idosa (idade superior ou igual a 65 anos)

int main(){
    head();
    int idade;
    idade = validIdade();

    if (idade < 18){
        printf("Voce é menor de idade");
    }
    else if (idade >= 65){
        printf("Voce é uma pessoa idosa");
    }
    else if(idade > 18){
        printf("Voce é maior de idade");
    }else{
        printf("Idade Invalida!");
    }

    copy();
    return 0;
}