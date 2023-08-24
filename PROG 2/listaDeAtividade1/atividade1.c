#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "functions.c"

// Uma P.A. (progressão aritmética) fica determinada pela sua razão (r) e pelo primeiro
// termo(a1). Faça um programa em linguagem C, que seja capaz de determinar qualquer
// termo de uma P.A., dada a razão, o primeiro termo e a quantidade de termos.
// an = a1 + (n-1) x r

int main(){
    int an, r, a1, n;

    printf("Informe o primeiro termo (a1): ");
    scanf("%d", &a1);
    printf("Informe a razão (r): ");
    scanf("%d", &r);
    printf("Informe a quantidade de termos (n): ");
    scanf("%d", &n);

    an = a1 + (n - 1) * r;

    printf("O %d e o termo da P.A. é: %d\n", n, an);
    return 0;
}