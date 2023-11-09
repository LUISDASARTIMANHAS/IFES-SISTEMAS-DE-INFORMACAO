#include <stdlib.h>
#include <stdio.h>
#include "functions.c"


int main(){
    head();
    int valor;
    int num = 48;
    valor = seqFibonacci(num);

    printf("\n Valor do termo: %d",valor);

    copy();
    return 0;
}