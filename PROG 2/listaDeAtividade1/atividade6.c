#include <stdlib.h>
#include <stdio.h>
// Desenvolva um programa em C que leia uma temperatura em fahrenheit e
// apresente a temperatura convertida em graus Fahrenheit. A fórmula de conversão é:
// F = (9 x C + 160) / 5
// Onde F é a temperatura em Fahrenheit e C é a temperatura em centígrados
// Faça agora o contrário, de Fahrenheit para Celsius.

int main(){
    int F,C;

    printf("Informe os Fahrenheit (F): ");
    scanf("%d", &F);

    C = (C - 32) * (5/9);

    printf("A conversao dos %d Fahrenheit em graus centígrados é de: %d\n", F, C);
    return 0;
}