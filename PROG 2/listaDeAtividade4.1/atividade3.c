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
    
    int opcao;
    do {
    opcao = lerOpcao();
    switch (opcao) {
    case 1:
    printf("\n\tÁREA DO RETÂNGULO\n");
    // Ler os dados para calcular a área do RETANGULO
    // Chamar a função para calcular a área do RETANGULO
    // Mostrar o resultado
    break;
    case 2:
    printf("\n\tÁREA DO CÍRCULO\n");
    // Ler os dados para calcular a área do CIRCULO
    // Chamar a função para calcular a área do CIRCULO
    // Mostrar o resultado
    break;
    }
    } while ( opcao > 0);

    copy();
    return 0;
}


int main() {
    
    return 0;
}