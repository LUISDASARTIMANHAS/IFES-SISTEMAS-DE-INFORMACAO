#ifndef VETOR_DISTANCIAS_H
#define VETOR_DISTANCIAS_H

#define N 5
#define INF 1000000000 /* Valor sentinela para distância desconhecida */

/**
 * @brief EXERCÍCIO 3.1: Inicializa o vetor de distâncias com INF e define dist[origem] = 0.
 */
void inicializar_dist(int origem, int dist[]);

/**
 * @brief EXERCÍCIO 3.1: Exibe cada vértice (A até E) e sua distância, formatando INF adequadamente.
 */
void imprimir_dist(const int dist[]);

/**
 * @brief EXERCÍCIO 3.2: Preenche as distâncias diretas consultando os vizinhos da origem na matriz W.
 */
void carregar_vizinhos_origem(int origem, int dist[]);

/**
 * @brief EXERCÍCIO 3.3: Retorna o índice do vértice com menor distância (exceto origem), ou -1[cite: 32].
 */
int menor_distancia(int origem, const int dist[]);

/**
 * @brief EXERCÍCIO 3.4: Testa e aplica um atalho (relaxamento de aresta), retornando 1 se atualizou ou 0[cite: 32].
 */
int testar_atalho(int u, int v, int dist[]);

#endif