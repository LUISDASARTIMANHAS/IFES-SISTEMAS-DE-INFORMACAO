#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
// #define TAM 5

int main(){
    head();
    // int data3[TAM] = {642, 207, 162, 954, 156, 472, 829, 398, 992, 241};
    int data1[5] =   {9,7,2,4,3};
    int data2[5] =  {3,7,1,1,2};
    int data3[6] =  {1,2,3,8,9,1};
    int data4[9] = {15, 2, 24, 56, 7, 37, 3, 88, 45};
    int data5[10] = {80, 67,13, 9, 55, 5, 2, 51, 1, 23};

    heapSort(data1,5);
    heapSort(data2,5);
    heapSort(data3,6);
    heapSort(data4,9);
    heapSort(data5,10);

    copy();
    return 0;
}
