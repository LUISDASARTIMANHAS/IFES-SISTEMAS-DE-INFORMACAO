#include "functions.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    head();
    int num = input();
    printf("numero %d", num);
    copy();
    return 0;
}
