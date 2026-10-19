#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Lê um número inteiro do usuário exibindo uma mensagem personalizada.
 *        Também limpa o buffer do teclado para evitar conflitos com leituras futuras.
 * @param mensagem A string com a instrução para o usuário.
 * @return O valor inteiro digitado.
 */
int ler_inteiro(const char *mensagem);

/**
 * @brief Lê uma string/palavra do usuário com segurança.
 * @param mensagem A string com a instrução para o usuário.
 * @param dest Ponteiro para o array onde a palavra será armazenada.
 * @param tamanho O tamanho máximo do buffer.
 */
void ler_string(const char *mensagem, char *dest, int tamanho);

#endif