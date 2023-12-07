#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 9


int main(){
    head();
    int data2[TAM] = {16,5,24,30,1,9,17,2};
    // int data3[TAM] = {30,24,17,16,9,5,2,1};

    selectSort(data2,TAM);
    imprimirArray(data2,TAM);

    copy();
    return 0;
}
