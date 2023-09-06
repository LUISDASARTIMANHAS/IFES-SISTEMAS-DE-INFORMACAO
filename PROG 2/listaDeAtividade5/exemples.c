#include "functions.c"
#include <stdlib.h>
#include <stdio.h>
#define MAX 500
int qtde;

int main(){
    head();
    int data[MAX];
    int qtdData = 0;
    saveArray(&qtdData,data,12);
    saveArray(&qtdData,data,15);
    saveArray(&qtdData,data,5);

    imprimirArray(data,qtdData);
    copy();
    return 0;
}