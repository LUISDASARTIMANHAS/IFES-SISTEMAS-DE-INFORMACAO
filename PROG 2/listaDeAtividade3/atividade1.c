#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "functions.c"

// Construir um programa em C que leia dois números e efetue a adição. Caso o valor
// somado seja maior que 20, este deverá ser apresentado somando-se a ele mais 8. Caso o
// valor somado seja menor ou igual a 20, este deverá ser apresentado subtraindo-se 5.

int main(){
    head();
    int num = input();
    printf("numero %d", num);
    copy();
    return 0;
}



