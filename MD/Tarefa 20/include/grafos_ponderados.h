#ifndef GRAFOS_PONDERADOS_H
#define GRAFOS_PONDERADOS_H

#define N 5
#define INF 1000000000 /* Valor sentinela para 'infinito' */

/**
 * @brief EXERCÍCIO 2.1: Retorna o peso de uma aresta existente ou -1 caso não exista ou índices sejam inválidos.
 */
int peso_aresta(int u, int v);

/**
 * @brief EXERCÍCIO 2.2: Percorre a linha do vértice v e exibe seus vizinhos com peso positivo e custos[cite: 30].
 */
void listar_vizinhos(int v);

/**
 * @brief EXERCÍCIO 2.3: Calcula o custo total de um caminho baseado na sequência de índices de vértices[cite: 30].
 */
int custo_caminho(const int caminho[], int tamanho);

/**
 * @brief EXERCÍCIO 2.4: Compara as rotas alternativas propostas, exibe os custos e identifica a menor[cite: 30].
 */
void comparar_rotas();

/**
 * @brief EXERCÍCIO 2.5: Retorna o índice do vizinho ligado diretamente a v pela aresta de menor peso[cite: 30].
 */
int vizinho_mais_proximo(int v);

#endif