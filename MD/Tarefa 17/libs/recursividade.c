#include "recursividade.h"
#include <stdio.h>

/* ==========================================
 * EXERCÍCIO 1: Tamanho de uma String (tamstring)
 * ========================================== */
int tamstring(char s[]) {
    /* 1. Caso Base: o carater terminador nulo '\0' marca o fim da string */
    if (s[0] == '\0') {
        return 0;
    }
    /* 2. Passo Recursivo: 1 mais o tamanho do restante da string */
    return 1 + tamstring(s + 1);
}

/* ==========================================
 * EXERCÍCIO 2: Contagem de Ocorrências (caract)
 * ========================================== */
int caract(char c, char s[]) {
    /* 1. Caso Base: fim da string alcançado */
    if (s[0] == '\0') {
        return 0;
    }
    int match = (s[0] == c) ? 1 : 0;
    
    /* 2. Passo Recursivo: soma o match atual com a contagem no restante */
    return match + caract(c, s + 1);
}

/* ==========================================
 * EXERCÍCIO 3: Inversão de String (inverte_string)
 * ========================================== */
void inverte_string(char s[], int inicio, int fim) {
    /* 1. Caso Base: os índices cruzam-se ou encontram-se no centro */
    if (inicio >= fim) {
        return;
    }
    
    char temp = s[inicio];
    s[inicio] = s[fim];
    s[fim] = temp;
    
    /* 2. Passo Recursivo: aproxima os extremos em direção ao centro */
    inverte_string(s, inicio + 1, fim - 1);
}

/* ==========================================
 * EXERCÍCIO 4: Maior Elemento de um Vetor (maior_elemento)
 * ========================================== */
int maior_elemento(int v[], int n) {
    /* 1. Caso Base: vetor de tamanho 1 (n >= 1) */
    if (n == 1) {
        return v[0];
    }
    
    /* 2. Passo Recursivo: obtém o maior elemento no restante do vetor */
    int maior_restante = maior_elemento(v + 1, n - 1);
    
    return (v[0] > maior_restante) ? v[0] : maior_restante;
}

/* ==========================================
 * EXERCÍCIO 5: Verificação de Palíndromo (eh_palindromo)
 * ========================================== */
int eh_palindromo(char s[], int inicio, int fim) {
    /* 1. Caso Base 1: os ponteiros cruzam-se ou coincidem */
    if (inicio >= fim) {
        return 1;
    }
    if (s[inicio] == ' ') {
        return eh_palindromo(s, inicio + 1, fim);
    }
    if (s[fim] == ' ') {
        return eh_palindromo(s, inicio, fim - 1);
    }
    /* Caso Base 2: carateres diferentes nas pontas */
    if (s[inicio] != s[fim]) {
        return 0;
    }
    
    /* 2. Passo Recursivo: avança ambos os limites para o interior */
    return eh_palindromo(s, inicio + 1, fim - 1);
}

/* ==========================================
 * EXERCÍCIO 6: Máximo Divisor Comum - MDC (mdc)
 * ========================================== */
int mdc(int a, int b) {
    /* 1. Caso Base: mdc(a, 0) = a */
    if (b == 0) {
        return a;
    }
    
    /* 2. Passo Recursivo: mdc(b, a % b) */
    return mdc(b, a % b);
}