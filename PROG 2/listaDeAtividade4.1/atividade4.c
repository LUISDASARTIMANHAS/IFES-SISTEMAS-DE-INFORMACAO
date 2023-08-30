#include "functions.c"
#include <stdlib.h>
#include <stdio.h>
// SEMENTE DOS NUMEROS ALEATÓRIOS. Usa a hora local
#include <time.h> // Para os números aleatórios

// Jogo de Craps. Faça um programa que implemente um jogo de Craps. O jogador lança um par de dados, obtendo a soma entre 2 e 12. Se na primeira jogada tirar 7 ou 11, você ganhou. Se você tirar 2, 3 ou 12 na primeira jogada, isto é chamado de "craps" e você perdeu. Se na primeira jogada você somou 4, 5, 6, 8, 9 ou 10, este é seu "Ponto". Seu objetivo agora é continuar jogando os dados até tirar este número novamente. Você perde, no entanto, se tirar um 7 antes de tirar este “Ponto” novamente

// A função lancarDado() abaixo retorna um número aleatório entre 1 e 6 e
// simula o lançamento de um dado.
// A função jogarDados() simula uma jogada com os dois dados e retorna a
// soma.

int main(){
    head();
    srand( (unsigned)time(NULL) );
    
    
    
    copy();
    return 0;
}

