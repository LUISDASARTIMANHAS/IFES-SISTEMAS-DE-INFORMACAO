#include <stdio.h>
#include "vetor_distancias.h"

int main() {
    printf("=== LABORATORIO 3: VETOR DE DISTANCIAS E ATALHOS (IFES) ===\n\n");

    int dist[N];

    /* Testes do Exercício 3.1 */
    printf("--- EXERCICIO 3.1: Inicializar e Imprimir Distancias ---\n");
    inicializar_dist(0, dist); // Origem A (índice 0)
    printf("Saida obtida: ");
    imprimir_dist(dist);
    printf("Saida esperada: A: 0 | B: INF | C: INF | D: INF | E: INF\n\n");

    /* Testes do Exercício 3.2 */
    printf("--- EXERCICIO 3.2: Carregar Vizinhos Diretos da Origem ---\n");
    inicializar_dist(0, dist);
    carregar_vizinhos_origem(0, dist);
    printf("Saida obtida: ");
    imprimir_dist(dist);
    printf("Saida esperada: A: 0 | B: 4 | C: 2 | D: INF | E: INF\n\n");

    /* Testes do Exercício 3.3 */
    printf("--- EXERCICIO 3.3: Encontrar Menor Distancia (Exceto Origem) ---\n");
    // Cenário 1: dist = {0, 4, 2, INF, INF}
    int m1 = menor_distancia(0, dist);
    printf("Menor distancia (Cenario 1) -> Indice: %d (Vertice %c, Distancia: %d)\n", 
           m1, 'A' + m1, dist[m1]);

    // Cenário 2: dist inicializada apenas com origem
    int dist_vazia[N];
    inicializar_dist(0, dist_vazia);
    int m2 = menor_distancia(0, dist_vazia);
    printf("Menor distancia (Cenario 2 - Vazio) -> Retorno: %d (Esperado: -1)\n\n", m2);

    /* Testes do Exercício 3.4 */
    printf("--- EXERCICIO 3.4: Testar um Atalho (Relaxamento) ---\n");
    // Estado atual do vetor após 3.2: dist = {0, 4, 2, INF, INF}
    printf("Estado inicial antes do atalho: ");
    imprimir_dist(dist);

    // Teste 1: u = 2 (C), v = 1 (B) -> Caminho A->C->B (2 + 1 = 3 < 4)[cite: 32]
    int res1 = testar_atalho(2, 1, dist);
    printf("Teste 1 (Atalho C -> B): Retorno = %d (Esperado: 1)\n", res1);
    printf("Vetor atualizado: ");
    imprimir_dist(dist);

    // Teste 2: u = 2 (C), v = 0 (A) -> Caminho A->C->A (2 + 2 = 4 nao e menor que dist[0] = 0)[cite: 32]
    int res2 = testar_atalho(2, 0, dist);
    printf("Teste 2 (Atalho C -> A): Retorno = %d (Esperado: 0)\n", res2);
    printf("Vetor final: ");
    imprimir_dist(dist);

    return 0;
}