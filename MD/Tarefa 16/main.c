#include <stdio.h>
#include "recursividade.h"
#include "utils.h"

int main() {
    printf("=== MENU DE EXERCICIOS DE RECURSIVIDADE (IFES) ===\n\n");

    // Exercício 1: Potenciação
    int base = ler_inteiro("--- Exercicio 1: Potenciação (x^y) ---\nDigite a base (x): ");
    int exp = ler_inteiro("Digite o expoente (y >= 0): ");
    printf("Resultado: potencia(%d, %d) = %d\n\n", base, exp, potencia(base, exp));

    // Exercício 2: Soma até N
    int n_soma = ler_inteiro("--- Exercicio 2: Soma dos Primeiros N Inteiros ---\nDigite um numero inteiro n (>= 1): ");
    printf("Resultado: soma_ate_n(%d) = %d\n\n", n_soma, soma_ate_n(n_soma));

    // Exercício 3: Contagem Regressiva
    int n_cont = ler_inteiro("--- Exercicio 3: Contagem Regressiva ---\nDigite um numero inteiro (>= 0): ");
    printf("Resultado da contagem: ");
    contagem_regressiva(n_cont);
    printf("\n");

    // Exercício 4: Fibonacci
    int n_fib = ler_inteiro("--- Exercicio 4: Sequencia de Fibonacci ---\nDigite o termo desejado n (>= 1): ");
    printf("Resultado: fibonacci(%d) = %d\n\n", n_fib, fibonacci(n_fib));

    // Exercício 5: Soma dos Dígitos
    int n_dig = ler_inteiro("--- Exercicio 5: Soma dos Digitos de um Numero ---\nDigite um numero inteiro positivo: ");
    printf("Resultado: soma_digitos(%d) = %d\n\n", n_dig, soma_digitos(n_dig));

    // Novo Exercício: Inverter Palavra
    char palavra[100];
    printf("--- Novo Exercicio: Inverter Palavra ---\n");
    ler_string("Digite uma palavra para inverter: ", palavra, sizeof(palavra));

    // Calcula o tamanho e inverte recursivamente
    int tam = tamanho_string(palavra, 0);
    if (tam > 0) {
        inverte_palavra(palavra, 0, tam - 1);
    }
    printf("Palavra invertida: %s\n\n", palavra);

    return 0;
}