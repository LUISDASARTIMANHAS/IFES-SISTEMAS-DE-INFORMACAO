#include "functions.c"
#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES

int main(){
    head();
    int num = input();
    printf("numero %d", num);
    copy();
    return 0;
}