#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 10

int main(){
    head();
    // int data3[TAM] = {642, 207, 162, 954, 156, 472, 829, 398, 992, 241};
    int data2[TAM] = {41, 90, 4, 38, 67, 19, 57, 54, 44, 50};

    insertionSort(data2,TAM);

    copy();
    return 0;
}
