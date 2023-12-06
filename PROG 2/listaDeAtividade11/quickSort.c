#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 8


int main(){
    head();
    int data2[TAM] = {16,5,24,30,1,9,17,2};
    // int data3[TAM] = {30,24,17,16,9,5,2,1};
    printf("\n ANTES: \n");
    imprimirArray(data2,TAM);

    quickSort(data2,0,TAM-1);

    printf("\n DEPOIS: \n");
    imprimirArray(data2,TAM);

    copy();
    return 0;
}
