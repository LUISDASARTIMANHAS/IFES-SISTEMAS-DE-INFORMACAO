#include "functions.c"
#include <stdlib.h>
#include <stdio.h>
// Faça um programa com funções em C que leia o preço de um produto qualquer (maior que zero) e a forma de pagamento (à vista ou à prazo, pode ser char ou int) e calcule o preço final desse produto da seguinte forma:
//  O preço do produto à vista tem desconto de 10%.
//  O preço do produto à prazo tem acréscimo de 10%.
// Depois, leia a quantidade (maior que zero) desse produto que será comprada e informe o valor total da compra.

int main(){
    head();
    int prc = validPreco();
    int formPay = menuPay();
    int des = prc * (100/10);

    if (formPay == 1){
        

    }
    else{
        
    }
    
    copy();
    return 0;
}
