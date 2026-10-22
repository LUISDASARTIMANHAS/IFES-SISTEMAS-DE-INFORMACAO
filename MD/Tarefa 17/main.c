#include <stdio.h>
#include "recursividade.h"
#include "utils.h"

int main() {
    printf("=== TAREFA 17: RECURSIVIDADE - IFES COLATINA ===\n\n");

    /* Exercício 1: Tamanho de String */
    char str1[100];
    ler_string("--- Exercicio 1: Tamanho de String ---\nDigite uma palavra: ", str1, sizeof(str1));
    printf("Resultado: tamstring(\"%s\") = %d\n\n", str1, tamstring(str1));

    /* Exercício 2: Contagem de Ocorrências de Caractere */
    char str2[100], caractere;
    printf("--- Exercicio 2: Ocorrencia de Caractere ---\n");
    ler_string("Digite uma palavra/frase: ", str2, sizeof(str2));
    printf("Digite o carater a ser contado: ");
    scanf(" %c", &caractere);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Resultado: caract('%c', \"%s\") = %d\n\n", caractere, str2, caract(caractere, str2));

    /* Exercício 3: Inversão de String */
    char str3[100];
    printf("--- Exercicio 3: Inversao de String (In Place) ---\n");
    ler_string("Digite uma palavra para inverter: ", str3, sizeof(str3));
    int len3 = tamstring(str3);
    if (len3 > 0) {
        inverte_string(str3, 0, len3 - 1);
    }
    printf("Resultado invertido: %s\n\n", str3);

    /* Exercício 4: Maior Elemento de um Vetor */
    printf("--- Exercicio 4: Maior Elemento de um Vetor ---\n");
    int vetor[] = {4, 12, 7, 9, 3};
    int n_vetor = 5;
    printf("Vetor padrão: {4, 12, 7, 9, 3} (Tamanho: %d)\n", n_vetor);
    printf("Resultado: maior_elemento = %d\n\n", maior_elemento(vetor, n_vetor));

    /* Exercício 5: Verificação de Palíndromo */
    char str5[100];
    printf("--- Exercicio 5: Verificacao de Palindromo ---\n");
    ler_string("Digite uma palavra/frase para testar: ", str5, sizeof(str5));
    int len5 = tamstring(str5);
    int palindromo = 0;
    if (len5 > 0) {
        palindromo = eh_palindromo(str5, 0, len5 - 1);
    }
    printf("Resultado: eh_palindromo = %d (%s)\n\n", palindromo, palindromo ? "Eh palindromo" : "Nao eh palindromo");

    /* Exercício 6: MDC de Euclides */
    printf("--- Exercicio 6: MDC (Algoritmo de Euclides) ---\n");
    int num_a = ler_inteiro("Digite o primeiro numero (a): ");
    int num_b = ler_inteiro("Digite o segundo numero (b): ");
    printf("Resultado: mdc(%d, %d) = %d\n\n", num_a, num_b, mdc(num_a, num_b));

    return 0;
}