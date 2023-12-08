#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 5

int main(){
    head();
    // int data3[TAM] = {642, 207, 162, 954, 156, 472, 829, 398, 992, 241};

    int data2[5] =  {3,7,1,1,2};

    heapSort(data2,5);

    copy();
    return 0;
}
