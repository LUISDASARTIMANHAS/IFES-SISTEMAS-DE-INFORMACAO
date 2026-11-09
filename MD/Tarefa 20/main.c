#include <stdio.h>
#include "grafos_ponderados.h"

int main() {
    printf("=== LABORATORIO 2: EXERCICIOS DE 2.1 A 2.5 (IFES) ===\n\n");

    /* Testes do Exercício 2.1 */
    printf("--- EXERCICIO 2.1: Consulta de Peso ---\n");
    printf("A->B (esperado 4): %d\n", peso_aresta(0, 1));
    printf("A->D (esperado -1): %d\n", peso_aresta(0, 3));
    printf("D->E (esperado 2): %d\n", peso_aresta(3, 4));
    printf("A->A (esperado -1): %d\n\n", peso_aresta(0, 0));

    /* Testes do Exercício 2.2 */
    printf("--- EXERCICIO 2.2: Listagem de Vizinhos ---\n");
    listar_vizinhos(2); // Vértice C (índice 2) -> Esperado: A (2), B (1), D (8) e E (10)[cite: 30]
    printf("\n");

    /* Testes do Exercício 2.3 */
    printf("--- EXERCICIO 2.3: Calculo de Custo de Caminho ---\n");
    int caminho1[] = {0, 1, 3, 4}; // A->B->D->E
    int caminho2[] = {0, 2, 3, 4}; // A->C->D->E
    int caminho3[] = {0, 3};       // A->D (inválido)
    
    printf("Custo A->B->D->E (esperado 11): %d\n", custo_caminho(caminho1, 4));
    printf("Custo A->C->D->E (esperado 12): %d\n", custo_caminho(caminho2, 4));
    printf("Custo A->D      (esperado -1): %d\n\n", custo_caminho(caminho3, 2));

    /* Execução do Exercício 2.4 */
    comparar_rotas();
    printf("\n");

    /* Testes do Exercício 2.5 */
    printf("--- EXERCICIO 2.5: Vizinho Mais Proximo ---\n");
    vizinho_mais_proximo(0); // Para A (índice 0) -> Retorna C (peso 2)[cite: 30]
    vizinho_mais_proximo(2); // Para C (índice 2) -> Retorna B (peso 1)[cite: 30]
    printf("\n");

    return 0;
}