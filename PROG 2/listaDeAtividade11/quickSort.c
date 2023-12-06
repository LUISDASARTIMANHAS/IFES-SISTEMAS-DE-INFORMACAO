#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 9


int main(){
    head();
    int data2[TAM] = {15, 2, 24, 56, 7, 37, 3, 88, 45};
    // int data3[TAM] = {30,24,17,16,9,5,2,1};
    printf("\n ANTES: \n");
    imprimirArray(data2,TAM);

    quickSort(data2,0,TAM-1);

    printf("\n DEPOIS: \n");
    imprimirArray(data2,TAM);

    copy();
    return 0;
}
