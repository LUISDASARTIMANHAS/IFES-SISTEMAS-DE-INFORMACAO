#include "recursividade.h"
#include <stdio.h>

/**
 * EXERCÍCIO 1: Potenciação Inteira Exponencial (x^y)
 */
int potencia(int x, int y) {
    // 1. Caso Base: qualquer número elevado a 0 é 1
    if (y == 0) {
        return 1;
    }
    // 2. Passo Recursivo: x^y = x * x^(y-1)
    return x * potencia(x, y - 1);
}

/**
 * EXERCÍCIO 2: Soma dos Primeiros N Inteiros Consecutivos
 */
int soma_ate_n(int n) {
    // 1. Caso Base: S(1) = 1
    if (n <= 1) {
        return 1;
    }
    // 2. Passo Recursivo: S(n) = n + S(n-1)
    return n + soma_ate_n(n - 1);
}

/**
 * EXERCÍCIO 3: Contagem Regressiva com Efeito Colateral
 */
void contagem_regressiva(int n) {
    // 1. Caso Base: atingiu o zero, imprime o zero e a mensagem de decolagem
    if (n == 0) {
        printf("0, Decolagem!\n");
        return;
    }
    // 2. Passo Recursivo: imprime o número atual e chama a função para n - 1
    printf("%d, ", n);
    contagem_regressiva(n - 1);
}

/**
 * EXERCÍCIO 4: Sequência de Fibonacci (Recorrência de 2ª Ordem)
 */
int fibonacci(int n) {
    // 1. Caso Base: F(1) = 1 e F(2) = 1
    if (n == 1 || n == 2) {
        return 1;
    }
    // 2. Passo Recursivo: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * EXERCÍCIO 5: Soma dos Dígitos de um Número Decimal
 */
int soma_digitos(int n) {
    // 1. Caso Base: se n for 0, a soma dos dígitos restantes é 0
    if (n == 0) {
        return 0;
    }
    // 2. Passo Recursivo: pega o último dígito (n % 10) e soma com o restante (n / 10)
    return (n % 10) + soma_digitos(n / 10);
}

/**
 * NOVO EXERCÍCIO: Função auxiliar recursiva para calcular o tamanho da string
 */
int tamanho_string(char *str, int index) {
    // 1. Caso Base: chegou ao fim da string '\0' ou quebra de linha '\n'
    if (str[index] == '\0' || str[index] == '\n') {
        return 0;
    }
    // 2. Passo Recursivo: 1 + tamanho do restante da string
    return 1 + tamanho_string(str, index + 1);
}

/**
 * NOVO EXERCÍCIO: Inverter uma palavra de forma recursiva
 */
void inverte_palavra(char *str, int inicio, int fim) {
    // 1. Caso Base: os ponteiros se cruzam ou se encontram no meio
    if (inicio >= fim) {
        return;
    }
    // Passo Intermediário / Troca: troca os caracteres das pontas
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    
    // 2. Passo Recursivo: chama para os caracteres internos (aproximando do centro)
    inverte_palavra(str, inicio + 1, fim - 1);
}