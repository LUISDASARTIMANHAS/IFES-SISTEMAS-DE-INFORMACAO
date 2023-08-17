#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

// Dados três valores A, B e C, construa um programa em C que imprima os valores de forma descendente (do maior para o menor).

int main(){
    head();
    int a,b,c,ordem1,ordem2,ordem3;
    a=10;
    b=32;
    c=16;

    if((a >= b) || (a >= c)){
        ordem1 = a;
        if((b >= c)){
            ordem2 = b;
            ordem3 = c;
        }else{
            ordem3 = b;
            ordem2 = c;
        }
    }else if((b >= a) || (b >= c)){
        ordem1 = b;
        if((a >= c)){
            ordem2 = a;
            ordem3 = c;
        }else{
            ordem3 = a;
            ordem2 = c;
        }
    }else{
        ordem1 = c;
        if((a >= b)){
            ordem2 = a;
            ordem3 = b;
        }else{
            ordem3 = a;
            ordem2 = b;
        }
    }
    printf("A ordem vai ser: \n");
    printf("1-%d \n", ordem1);
    printf("2-%d \n", ordem2);
    printf("3-%d \n", ordem3);

    copy();
    return 0;
}