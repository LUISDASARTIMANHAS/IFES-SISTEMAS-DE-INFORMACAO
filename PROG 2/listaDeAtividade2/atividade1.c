#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "functions.c"

// Construir um programa em C que leia dois números e efetue a adição.
//  Caso o valor somado seja maior que 20, este deverá ser apresentado somando-se a ele mais 8.
// Caso o valor somado seja menor ou igual a 20, este deverá ser apresentado subtraindo-se 5.

int main(){
    head();
    int num,num2,soma;

    printf("Insira um número: ");
    num = input();

    printf("Insira um número: ");
    num2 = input();

    soma = somar(num,num2);
    if(soma >= 20){
        soma = somar(soma,8);
    }else{
        soma = diminuir(soma,5);
    }

    printf("Total: %d", soma);
    copy();
    return 0;
}
