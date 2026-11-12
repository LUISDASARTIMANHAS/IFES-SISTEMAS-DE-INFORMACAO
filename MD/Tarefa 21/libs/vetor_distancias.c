#include "vetor_distancias.h"
#include <stdio.h>

/* Matriz de pesos W de acordo com o grafo de referência do laboratório[cite: 32] */
static int W[N][N] = {
    {0, 4, 2, 0, 0},
    {4, 0, 1, 5, 0},
    {2, 1, 0, 8, 10},
    {0, 5, 8, 0, 2},
    {0, 0, 10, 2, 0}
};

/* ==========================================
 * EXERCÍCIO 3.1: Inicializar e Imprimir o Vetor de Distâncias
 * ========================================== */
void inicializar_dist(int origem, int dist[]) {
    for (int i = 0; i < N; i++) {
        dist[i] = INF; /* Preenche todas as posições com "infinito"[cite: 32] */
    }
    if (origem >= 0 && origem < N) {
        dist[origem] = 0; /* Distância da origem para ela mesma é 0[cite: 32] */
    }
}

void imprimir_dist(const int dist[]) {
    for (int i = 0; i < N; i++) {
        printf("%c: ", 'A' + i);
        if (dist[i] == INF) {
            printf("INF");
        } else {
            printf("%d", dist[i]);
        }
        if (i < N - 1) {
            printf(" | ");
        }
    }
    printf("\n");
}

/* ==========================================
 * EXERCÍCIO 3.2: Preencher Distâncias Diretas a partir da Origem
 * ========================================== */
void carregar_vizinhos_origem(int origem, int dist[]) {
    if (origem < 0 || origem >= N) return;
    
    /* Percorre a linha da origem na matriz W[cite: 32] */
    for (int v = 0; v < N; v++) {
        /* Onde houver peso positivo (vizinho direto), copia o custo para dist[v][cite: 32] */
        if (W[origem][v] > 0) {
            dist[v] = W[origem][v];
        }
    }
}

/* ==========================================
 * EXERCÍCIO 3.3: Encontrar o Vértice com Menor Distância (Exceto a Origem)
 * ========================================== */
int menor_distancia(int origem, const int dist[]) {
    int menor_val = INF;
    int melhor_vertice = -1;
    
    for (int v = 0; v < N; v++) {
        /* Ignora a própria origem e verifica se a distância é menor que INF[cite: 32] */
        if (v != origem && dist[v] < INF) {
            if (dist[v] < menor_val) {
                menor_val = dist[v];
                melhor_vertice = v;
            }
        }
    }
    return melhor_vertice;
}

/* ==========================================
 * EXERCÍCIO 3.4: Testar um Atalho (Atualização Simples de Distância)
 * ========================================== */
int testar_atalho(int u, int v, int dist[]) {
    /* Valida índices */
    if (u < 0 || u >= N || v < 0 || v >= N) return 0;
    
    /* Verifica se existe aresta entre u e v, se dist[u] é alcançável e se o atalho é menor[cite: 32] */
    if (W[u][v] > 0 && dist[u] < INF && (dist[u] + W[u][v] < dist[v])) {
        dist[v] = dist[u] + W[u][v]; /* Atualiza a distância[cite: 32] */
        return 1; /* Houve melhoria[cite: 32] */
    }
    
    return 0; /* Caso contrário, inalterado[cite: 32] */
}