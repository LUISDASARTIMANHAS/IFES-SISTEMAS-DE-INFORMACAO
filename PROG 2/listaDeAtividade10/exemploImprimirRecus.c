#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 10

int main(){
    head();
    char data[TAM] = {105,8,10,21,54,56,3,88,32,12};

    imprimirRecus(data,TAM);

    copy();
    return 0;
}