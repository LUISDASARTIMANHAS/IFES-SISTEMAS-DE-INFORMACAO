#ifndef RECURSIVIDADE_H
#define RECURSIVIDADE_H

/**
 * EXERCÍCIO 1: Potenciação Inteira Exponencial (x^y)
 */
int potencia(int x, int y);

/**
 * EXERCÍCIO 2: Soma dos Primeiros N Inteiros Consecutivos
 */
int soma_ate_n(int n);

/**
 * EXERCÍCIO 3: Contagem Regressiva com Efeito Colateral
 */
void contagem_regressiva(int n);

/**
 * EXERCÍCIO 4: Sequência de Fibonacci
 */
int fibonacci(int n);

/**
 * EXERCÍCIO 5: Soma dos Dígitos de um Número Decimal
 */
int soma_digitos(int n);

/**
 * NOVO EXERCÍCIO: Calcula o tamanho de uma string recursivamente
 */
int tamanho_string(char *str, int index);

/**
 * NOVO EXERCÍCIO: Inverte uma palavra/string recursivamente
 */
void inverte_palavra(char *str, int inicio, int fim);

#endif