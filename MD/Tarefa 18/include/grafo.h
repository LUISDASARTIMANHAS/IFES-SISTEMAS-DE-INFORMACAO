#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 50
#define TAM_NOME 50

/**
 * @brief Inicializa a matriz de adjacência e zera o contador de vértices (Exercício 1.1)[cite: 29].
 */
void inicializar_grafo();

/**
 * @brief Obtém o índice de um vértice pelo nome ou cadastra-o automaticamente se for novo.
 * @param nome Nome textual do vértice (ex: "col")
 * @return O índice inteiro do vértice ou -1 em caso de limite excedido.
 */
int obter_ou_cadastrar_vertice(const char *nome);

/**
 * @brief Adiciona uma aresta entre dois vértices pelos seus nomes (Exercício 1.1)[cite: 29].
 * @param nome_u Nome do vértice de origem
 * @param nome_v Nome do vértice de destino
 * @param direcionado 0 para não orientado, 1 para dígrafo
 */
void adicionar_aresta_por_nome(const char *nome_u, const char *nome_v, int direcionado);

/**
 * @brief Retorna o nome textual de um vértice a partir do seu índice numérico.
 * @param idx Índice do vértice
 * @return Ponteiro para a string com o nome
 */
const char* obter_nome_vertice(int idx);

/**
 * @brief Retorna o número total de vértices únicos descobertos dinamicamente.
 * @return Quantidade de vértices cadastrados.
 */
int total_vertices_atuais();

/**
 * @brief Calcula o grau de um vértice pelo seu nome em grafos não orientados (Exercício 1.2)[cite: 29].
 * @param nome Nome do vértice
 * @param n Número total de vértices
 * @return O grau do vértice
 */
int grau_vertice_por_nome(const char *nome, int n);

/**
 * @brief Calcula o grau de emissão (out-degree) pelo nome em dígrafos (Exercício 1.3)[cite: 29].
 */
int grau_emissao_por_nome(const char *nome, int n);

/**
 * @brief Calcula o grau de recepção (in-degree) pelo nome em dígrafos (Exercício 1.3)[cite: 29].
 */
int grau_recepcao_por_nome(const char *nome, int n);

/**
 * @brief Verifica se o grafo não orientado é regular (Exercício 1.4)[cite: 29].
 * @param n Número total de vértices
 * @return 1 se verdadeiro, 0 caso contrário.
 */
int eh_regular(int n);

/**
 * @brief Exibe a matriz de adjacência com os cabeçalhos nomeados[cite: 29].
 * @param n Número total de vértices
 */
void exibir_matriz(int n);

/**
 * @brief Desenha o mapa visual ASCII com os nomes reais das cidades[cite: 29].
 * @param n Número total de vértices
 * @param direcionado 0 para não orientado, 1 para direcionado
 */
void desenhar_grafo_ascii(int n, int direcionado);

#endif