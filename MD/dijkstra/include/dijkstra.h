#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define N 6
#define INF 1000000000

/**
 * @brief Carrega uma matriz de adjacencia N x N a partir de um arquivo texto.
 *
 * @param nome_arquivo Caminho do arquivo .txt contendo os pesos da matriz.
 * @param W Matriz de destino onde os pesos lidos serao armazenados.
 * @return 1 se a leitura foi bem-sucedida, ou 0 em caso de erro.
 */
int carregar_matriz_txt(const char *nome_arquivo, int W[N][N]);

/**
 * @brief Seleciona o vertice aberto (nao visitado) com menor distancia finita.
 *
 * @param dist Vetor com as distancias minimas conhecidas a partir da origem.
 * @param visitado Vetor de estado dos vertices (0 = aberto, 1 = confirmado).
 * @return Indice do proximo vertice u ou -1 caso nao haja vertices alcancaveis.
 */
int proximo(int dist[N], int visitado[N]);

/**
 * @brief Executa o algoritmo de Dijkstra sobre uma matriz de adjacencia.
 *
 * @param W Matriz de adjacencia ponderada N x N (0 indica ausencia de aresta).
 * @param origem Indice do vertice inicial.
 * @param dist Vetor de saida com os menores custos a partir da origem.
 * @param anterior Vetor de saida com o predecessor de cada vertice (-1 se sem antecessor).
 */
void dijkstra(int W[N][N], int origem, int dist[N], int anterior[N]);

/**
 * @brief Imprime o caminho minimo no formato (A, C, B, D, E, F).
 *
 * @param anterior Vetor de predecessores calculado pelo Dijkstra.
 * @param origem Indice do vertice inicial.
 * @param destino Indice do vertice final.
 * @param rotulos Vetor com os rotulos dos vertices.
 * @return 1 se existe caminho da origem ao destino, ou 0 caso contrario.
 */
int imprimir_caminho(int anterior[N], int origem, int destino, const char rotulos[N]);

#endif