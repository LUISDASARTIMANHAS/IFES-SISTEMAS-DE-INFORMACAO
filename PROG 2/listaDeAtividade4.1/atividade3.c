#include "functions.c"
#include <stdlib.h>
#include <stdio.h>

// O programa abaixo calcula a área das figuras geométricas retângulo e círculo. Implemente as
// funções que estão faltando e complete o programa principal abaixo para que ele execute corretamente.
//  A área do retângulo é: base * altura
//  A área do círculo é: PI * raio2
// (Para pegar o valor de PI, use: M_PI)
//  O tamanho de cada informação (base, altura e raio) deve ser maior que zero.
//  A opção a ser lida deve ser 0, 1 e 2.

int main(){
    head();
    correct();
    
    int opcao;
    do {
    opcao = lerOpcaoCalc();
    switch (opcao) {
    case 1:
        printf("\n\tÁREA DO RETÂNGULO\n");
        float areaR = calcArRetangulo();
        printf("A ÁREA DO RETÂNGULO e: %0.2f",areaR);
        break;
    case 2:
        printf("\n\tÁREA DO CÍRCULO\n");
        float areaC = calcArCirculo();
        printf("A ÁREA DO CÍRCULO e: %0.2f",areaC);
        break;
    }
    } while ( opcao > 0);

    copy();
    return 0;
}