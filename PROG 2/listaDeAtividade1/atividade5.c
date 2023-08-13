#include <stdlib.h>
#include <stdio.h>
// Desenvolva um programa em C que leia uma temperatura em graus centígrados e
// apresente a temperatura convertida em graus Fahrenheit. A fórmula de conversão é:
// F = (9 x C + 160) / 5
// Onde F é a temperatura em Fahrenheit e C é a temperatura em centígrados

int main(){
    int F,C;

    printf("Informe os graus centígrados (C): ");
    scanf("%d", &C);

    F = (9 * C + 160) / 5;

    printf("A conversao dos %d graus centígrados em Fahrenheit é de: %d\n", C, F);
    return 0;
}