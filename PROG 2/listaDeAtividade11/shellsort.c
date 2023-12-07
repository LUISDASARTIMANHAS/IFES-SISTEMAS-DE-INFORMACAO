#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define TAM 9

int main(){
    head();
    int data2[TAM] = {9,7,2,4,3,5,9,2,3};
    shellSort(data2,TAM-1);
    copy();
    return 0;
}
