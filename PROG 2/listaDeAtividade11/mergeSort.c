#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 5

int main(){
    head();
    // int data3[TAM] = {642, 207, 162, 954, 156, 472, 829, 398, 992, 241};

    int data2[TAM] =  {3,7,1,1,2};

    mergeSort(data2,0,TAM-1);
    imprimirArray(data2,TAM);

    copy();
    return 0;
}
