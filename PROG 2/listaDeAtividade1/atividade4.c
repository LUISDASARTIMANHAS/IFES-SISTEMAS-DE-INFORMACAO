#include <stdlib.h>
#include <stdio.h>
// Em épocas de pouco dinheiro, os comerciantes estão procurando aumentar suas
// vendas oferecendo desconto. Faça um programa em C que possa entrar com o valor de um produto e imprima o novo valor tendo em vista que o desconto foi de 9%. Além disso, imprima o valor do desconto;

int main(){
    float valorProduto, desconto, total,taxa;

    printf("Digite o valor do produto: ");
    scanf("%f", &valorProduto);
    printf("Digite o valor do desconto (50): ");
    scanf("%f", &taxa);

    taxa = taxa/100;
    desconto = valorProduto * taxa;
    total = valorProduto - desconto;

    printf("O total com desconto foi de: R$%.2f\n", total);
    printf("Valor do desconto doi de: R$%.2f\n", desconto);
    return 0;

}