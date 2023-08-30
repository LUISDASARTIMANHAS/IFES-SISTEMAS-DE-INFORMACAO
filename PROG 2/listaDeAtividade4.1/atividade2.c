#include "functions.c"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
// Faça um programa com funções em C que leia o preço de um produto qualquer (maior que zero) e a forma de pagamento (à vista ou à prazo, pode ser char ou int) e calcule o preço final desse produto da seguinte forma:
//  O preço do produto à vista tem desconto de 10%.
//  O preço do produto à prazo tem acréscimo de 10%.
// Depois, leia a quantidade (maior que zero) desse produto que será comprada e informe o valor total da compra.


int main(){
    head();
    correct();
    float prc = validPreco();
    float qtd = validQTD();
    float formPay = menuPay();
    float total = prc*qtd;
    float des = total * 0.10;
    

    if (formPay == 1){
    total = total - des;
    }else{
    total = total + des;
    }

    printf("\n--------\n");
    printf("Preço: %0.2f\n", prc);
    printf("Quantidade: %0.2f\n", qtd);
    printf("Desconto: %0.2f\n", des);
    printf("Total: %0.2f\n", total);
    printf("\n--------\n");

    copy();
    return 0;
}
