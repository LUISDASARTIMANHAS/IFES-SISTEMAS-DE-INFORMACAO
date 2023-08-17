#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

// Crie um programa em C que leia a idade de uma pessoa e informe a sua classe eleitoral:
//  não eleitor (abaixo de 16 anos);
//  eleitor obrigatório (entre a faixa de 18 e menor de 65 anos);
//  eleitor facultativo (de 16 até 18 anos e maior de 65 anos, inclusive)

int main(){
    head();
    int idade;
    idade = validIdade();

    if (idade < 16){
        printf("Voce não é eleitor!");
    }
    else if ((idade <= 65) || ( idade >= 16 )){
        printf("Voce é um eleitor obrigatório!");
    }
    else if((idade > 16) && (idade < 18)){
        printf("Voce é eleitor facultativo!");
    }else{
        printf("Idade Invalida!");
    }

    copy();
    return 0;
}