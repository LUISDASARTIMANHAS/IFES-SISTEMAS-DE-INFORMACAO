// Feito por: Lucas Garcia E Luis Augusto
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#define _USE_MATH_DEFINES

void correct()
{
    SetConsoleOutputCP(65001);
}

/**
 * Calcula a raiz quadrada inteira de um número.
 *
 * Retorna o maior inteiro r tal que:
 * r² ≤ n
 *
 * @param n Número inteiro não negativo
 * @return Raiz quadrada inteira de n
 */
int raizInteira(int n)
{
    int r = 0;

    while ((r + 1) * (r + 1) <= n)
    {
        r++;
    }

    return r;
}

/**
 * Verifica se um número é primo.
 *
 * @param num Número inteiro a ser testado
 * @return 1 se for primo, 0 caso contrário
 */
int ehPrimo(int num)
{
    if (num <= 1)
        return 0;

    if (num == 2)
        return 1;

    if (num % 2 == 0)
    {
        printf("%d não é primo pois o resto da divisão por 2 é 0\n", num);
        return 0;
    }

    if (num % 3 == 0)
    {
        printf("%d não é primo pois o resto da divisão por 3 é 0\n", num);
        return 0;
    }

    /*
     * Calcula o limite superior usando a raiz quadrada:
     * d ≤ √num
     */
    int limite = raizInteira(num);

    // printf("Limite de teste (√%d) = %d\n", num, limite);

    for (int i = 5; i <= limite; i += 6)
    {
        // printf("Testando divisibilidade por %d\n", i);

        /*
         * Todo número primo maior que 3 pode ser escrito como:
         * 6k - 1 ou 6k + 1
         *
         * Como i avança de 6 em 6, testamos:
         * i     → forma 6k - 1
         * i + 2 → forma 6k + 1
         *
         * Isso elimina divisores múltiplos de 2 e 3,
         * reduzindo drasticamente o número de testes
         * sem perder correção matemática.
         */
        if (num % i == 0 || num % (i + 2) == 0)
        {
            printf("%d não é primo pois o resto da divisão por %d é 0\n", num, i);
            return 0;
        }
    }

    printf("%d é primo\n", num);
    return 1;
}

int acharProximoPrimo(int num)
{
    // Continuar incrementando até encontrar um número primo
    // while (num <= 2147483647)
    // {
    //     num++;
    // }
    while (!ehPrimo(num))
    {
        num++;
    }

    return num;
}

int main()
{
    correct();
    ehPrimo(137);
    // 9 não é primo pois o resto da divisão por 3 é 0
    ehPrimo(9);
    // 6 não é primo pois o resto da divisão por 2 é 0
    ehPrimo(6);
    // 1003542850 não é primo pois o resto da divisão por 2 é 0
    ehPrimo(1003542850);
    //     1003542851 é primo
    ehPrimo(1003542851);
    // 31677
    ehPrimo(1003542852);
    // 1003542852 não é primo pois o resto da divisão por 2 é 0
    printf("INICIANDO BUSCA\n");
    acharProximoPrimo(1003542854);

    return 0;
}

/*
========================================================
FÓRMULAS MATEMÁTICAS UTILIZADAS NO ALGORITMO (ATUALIZADAS)
========================================================

1) Definição de número primo
----------------------------------------
Um número n é primo se, e somente se:
n > 1  ∧  D(n) = {1, n}

onde D(n) é o conjunto de divisores positivos de n.

--------------------------------------------------------

2) Testes iniciais de eliminação
----------------------------------------
n = 2 ⇒ primo

n > 2 ∧ n mod 2 = 0 ⇒ não primo  
n > 3 ∧ n mod 3 = 0 ⇒ não primo

Esses testes eliminam todos os múltiplos de 2 e 3.

--------------------------------------------------------

3) Teste geral de divisibilidade
----------------------------------------
n é divisível por d ⇔ n mod d = 0

Logo:
n = d × k , com k ∈ ℕ
⇒ n não é primo

--------------------------------------------------------

4) Limite matemático para teste de primalidade
----------------------------------------
Se n é composto, então existe pelo menos
um divisor d tal que:

d ≤ √n

Prova:
Se n = a × b, então
a ≤ √n ou b ≤ √n.

--------------------------------------------------------

5) Implementação computacional da raiz
----------------------------------------
A raiz inteira é definida como:

r = ⌊ √n ⌋  tal que:
r² ≤ n < (r + 1)²

Esse valor define o limite superior do laço.

--------------------------------------------------------

6) Propriedade dos números primos maiores que 3
----------------------------------------
Todo número primo p > 3 pode ser escrito como:

p ≡ 6k − 1  ou  p ≡ 6k + 1

Ou seja:
p mod 6 ∈ {1, 5}

Números nas formas:
6k, 6k+2, 6k+3, 6k+4
são sempre múltiplos de 2 ou 3 e não são primos.

--------------------------------------------------------

7) Otimização do laço de verificação
----------------------------------------
O algoritmo testa apenas divisores da forma:

d = 6k − 1  e  d = 6k + 1

Implementado como:
i e (i + 2), com incremento i += 6

Isso reduz o número de divisões
sem alterar a corretude do algoritmo.

--------------------------------------------------------

8) Busca sequencial do próximo primo
----------------------------------------
n, n + 1, n + 2, ...

Base teórica:
Teorema de Euclides — existem infinitos números primos.

========================================================
*/

