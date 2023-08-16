#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "functions.c"

// Construir um programa em C que leia dois números e efetue a adição. Caso o valor
// somado seja maior que 20, este deverá ser apresentado somando-se a ele mais 8. Caso o
// valor somado seja menor ou igual a 20, este deverá ser apresentado subtraindo-se 5.

int main(){
    copy();
    int num = input("text");
    printf("numero %d", num);
    return 0;
}



int somar(int num1, int num2){
    int total = num1 + num2;
    
    return total;
}

// int main(){
//     int v, raizV;
//     printf("Informe a raiz (v): ");
//     scanf("%d", &v);
    
//     raizV = ;

//     printf("A raiz de %d é: %d\n", v,raizV);
//     return 0;
// }