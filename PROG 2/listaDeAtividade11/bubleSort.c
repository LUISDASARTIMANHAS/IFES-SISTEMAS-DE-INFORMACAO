#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 8

int main(){
    head();
    // int data3[TAM] = {642, 207, 162, 954, 156, 472, 829, 398, 992, 241};
    int data2[TAM] = {16,5,24,30,1,9,17,2};
    // int data3[TAM] = {30,24,17,16,9,5,2,1};

    bubbleSort(data2,TAM);

    copy();
    return 0;
}
