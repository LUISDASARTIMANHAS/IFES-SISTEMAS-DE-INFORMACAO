#include <stdlib.h>
#include <stdio.h>
#include "functions.c"


int main(){
    head();
    int data[10] = {10, 20, 30,40, 50, 60, 70, 80, 90, 100};
    int *p;
    p = data;

    copy();
    return 0;
}
