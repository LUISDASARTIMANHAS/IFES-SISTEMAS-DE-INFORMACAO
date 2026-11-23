#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define MAX_N 100
#define INF 1000000000

/**
 * @brief Detecta automaticamente o tamanho (qtd x qtd) e carrega a matriz de pesos do arquivo.
 *
 * @param nome_arquivo Caminho do arquivo .txt contendo os pesos da matriz.
 * @param W Matriz de destino com capacidade MAX_N x MAX_N.
 * @param qtd Ponteiro de saida que recebe a quantidade de vertices detectada (1..MAX_N).
 * @return 1 se a leitura foi bem-sucedida, ou 0 em caso de erro.
 */
int carregar_matriz_txt(const char *nome_arquivo, int W[MAX_N][MAX_N], int *qtd);

/**
 * @brief Seleciona o vertice aberto (nao visitado) com menor distancia finita.
 *
 * @param dist Vetor com as distancias minimas conhecidas a partir da origem.
 * @param visitado Vetor de estado dos vertices (0 = aberto, 1 = confirmado).
 * @param qtd Quantidade de vertices ativos no grafo.
 * @return Indice do proximo vertice u ou -1 caso nao haja vertices alcancaveis.
 */
int proximo(const int dist[MAX_N], const int visitado[MAX_N], int qtd);

/**
 * @brief Executa o algoritmo de Dijkstra com opcao de exibir cada passo no console.
 *
 * @param W Matriz de adjacencia ponderada MAX_N x MAX_N (0 indica ausencia de aresta).
 * @param qtd Quantidade de vertices ativos no grafo.
 * @param origem Indice do vertice inicial.
 * @param dist Vetor de saida com os menores custos a partir da origem.
 * @param anterior Vetor de saida com o predecessor de cada vertice (-1 se sem antecessor).
 * @param rotulos Vetor com os rotulos em string dos vertices.
 * @param mostrar_passos 1 para imprimir o rastreamento, 0 para execucao silenciosa.
 */
void dijkstra(int W[MAX_N][MAX_N], int qtd, int origem, int dist[MAX_N],
              int anterior[MAX_N], const char *const rotulos[MAX_N], int mostrar_passos);

/**
 * @brief Imprime o caminho minimo no formato (A, C, B, D, E, F).
 *
 * @param anterior Vetor de predecessores calculado pelo Dijkstra.
 * @param origem Indice do vertice inicial.
 * @param destino Indice do vertice final.
 * @param qtd Quantidade de vertices ativos no grafo.
 * @param rotulos Vetor com os rotulos em string dos vertices.
 * @return 1 se existe caminho da origem ao destino, ou 0 caso contrario.
 */
int imprimir_caminho(const int anterior[MAX_N], int origem, int destino,
                     int qtd, const char *const rotulos[MAX_N]);

#endif