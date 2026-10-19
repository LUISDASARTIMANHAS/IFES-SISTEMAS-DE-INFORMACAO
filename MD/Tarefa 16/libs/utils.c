#include "utils.h"
#include <stdio.h>
#include <string.h>

int ler_inteiro(const char *mensagem) {
    int valor;
    printf("%s", mensagem);
    scanf("%d", &valor);
    
    // Limpa o '\n' deixado pelo scanf no buffer do teclado
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    return valor;
}

void ler_string(const char *mensagem, char *dest, int tamanho) {
    printf("%s", mensagem);
    fgets(dest, tamanho, stdin);
    
    // Remove a quebra de linha (\n) capturada pelo fgets no final da string
    size_t len = strlen(dest);
    if (len > 0 && dest[len - 1] == '\n') {
        dest[len - 1] = '\0';
    }
}