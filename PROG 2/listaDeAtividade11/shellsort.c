#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 5

int main(){
    head();
    // long int dataExtreme[1000] = {};
    // int data3[TAM] = {642, 207, 162, 954, 156, 472, 829, 398, 992, 241};
    int data2[TAM] = {9,7,2,4,3,5,9,2,3};

    shellSort(data2,TAM);
    copy();
    return 0;
}
