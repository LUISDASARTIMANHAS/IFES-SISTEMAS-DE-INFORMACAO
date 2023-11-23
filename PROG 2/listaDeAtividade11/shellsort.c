#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 10

int main(){
    head();
    // long int dataExtreme[1000] = {};
    // int data3[TAM] = {642, 207, 162, 954, 156, 472, 829, 398, 992, 241};
    int data2[TAM] = {41, 90, 4, 38, 67, 19, 57, 54, 44, 50};

    shellSort(data2,TAM);
    copy();
    return 0;
}
