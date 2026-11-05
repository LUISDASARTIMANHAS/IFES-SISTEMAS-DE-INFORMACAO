#include "utils.h"
#include <stdio.h>
#include <string.h>

int ler_inteiro(const char *mensagem) {
    int valor;
    printf("%s", mensagem);
    scanf("%d", &valor);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    return valor;
}

void ler_string(const char *mensagem, char *dest, int tamanho) {
    printf("%s", mensagem);
    fgets(dest, tamanho, stdin);
    
    size_t len = strlen(dest);
    if (len > 0 && dest[len - 1] == '\n') {
        dest[len - 1] = '\0';
    }
}