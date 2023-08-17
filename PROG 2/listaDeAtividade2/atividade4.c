#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

// Implemente um programa em C que leia um número e informe se ele é divisível por 10, por 5 ou por 2 ou se não é divisível por nenhum deles.

int main(){
    head();
    int num;
    num = validNum();

    if (num % 10 == 0){
        printf("%d é divisível por 10", num);
    }
    else if (num % 5 == 0){
        printf("%d é divisível por 5", num);
    }
    else if (num % 2 == 0){
        printf("%d é divisível por 2", num);
    }
    else{
        printf("%d não é divisível por nenhum deles.", num);
    }

    copy();
    return 0;
}