#include "grafos_ponderados.h"
#include <stdio.h>

/* Matriz de pesos W de acordo com o grafo de referência do laboratório[cite: 30] */
static int W[N][N] = {
    {0, 4, 2, 0, 0},
    {4, 0, 1, 5, 0},
    {2, 1, 0, 8, 10},
    {0, 5, 8, 0, 2},
    {0, 0, 10, 2, 0}
};

/* ==========================================
 * EXERCÍCIO 2.1: Consulta de Peso e Existência de Aresta
 * ========================================== */
int peso_aresta(int u, int v) {
    /* Valida se os índices estão fora do intervalo de 0 a 4[cite: 30] */
    if (u < 0 || u >= N || v < 0 || v >= N) {
        return -1;
    }
    /* 0 indica ausência de aresta na convenção adotada[cite: 30] */
    if (W[u][v] == 0) {
        return -1;
    }
    return W[u][v];
}

/* ==========================================
 * EXERCÍCIO 2.2: Listagem de Vizinhos e Pesos
 * ========================================== */
void listar_vizinhos(int v) {
    if (v < 0 || v >= N) {
        printf("Vertice invalido!\n");
        return;
    }
    
    printf("Vizinhos do vertice %c (indice %d): ", 'A' + v, v);
    int primeiro = 1;
    for (int j = 0; j < N; j++) {
        /* Exibe somente vizinhos com peso positivo[cite: 30] */
        if (W[v][j] > 0) {
            if (!primeiro) {
                printf(", ");
            }
            printf("%c (%d)", 'A' + j, W[v][j]);
            primeiro = 0;
        }
    }
    printf("\n");
}

/* ==========================================
 * EXERCÍCIO 2.3: Cálculo do Custo de um Caminho
 * ========================================== */
int custo_caminho(const int caminho[], int tamanho) {
    /* Retorna -1 se o caminho tiver menos de dois vértices[cite: 30] */
    if (tamanho < 2) {
        return -1;
    }
    
    int custo_total = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        int u = caminho[i];
        int v = caminho[i + 1];
        
        int peso = peso_aresta(u, v);
        if (peso == -1) {
            return -1; /* Índice inválido ou aresta inexistente[cite: 30] */
        }
        custo_total += peso;
    }
    return custo_total;
}

/* ==========================================
 * EXERCÍCIO 2.4: Comparação de Rotas Alternativas
 * ========================================== */
void comparar_rotas() {
    printf("\n--- EXERCICIO 2.4: COMPARACAO DE ROTAS ALTERNATIVAS ---\n");
    
    /* Rota 1: A -> B -> D -> E (índices 0, 1, 3, 4) */
    int rota1[] = {0, 1, 3, 4};
    int custo1 = custo_caminho(rota1, 4);
    printf("Rota 1 (A->B->D->E): Custo = %d\n", custo1);
    
    /* Rota 2: A -> C -> D -> E (índices 0, 2, 3, 4) */
    int rota2[] = {0, 2, 3, 4};
    int custo2 = custo_caminho(rota2, 4);
    printf("Rota 2 (A->C->D->E): Custo = %d\n", custo2);
    
    /* Rota 3: A -> C -> B -> D -> E (índices 0, 2, 1, 3, 4) */
    int rota3[] = {0, 2, 1, 3, 4};
    int custo3 = custo_caminho(rota3, 5);
    printf("Rota 3 (A->C->B->D->E): Custo = %d\n", custo3);
    
    printf("\nResultado esperado: custos 11, 12 e 10[cite: 30].\n");
    printf("Entre as rotas propostas, a menor e A->C->B->D->E, com custo %d[cite: 30].\n", custo3);
}

/* ==========================================
 * EXERCÍCIO 2.5: Menor Custo Direto entre Vizinhos
 * ========================================== */
int vizinho_mais_proximo(int v) {
    if (v < 0 || v >= N) {
        return -1;
    }
    
    int menor_peso = INF;
    int melhor_vizinho = -1;
    
    for (int j = 0; j < N; j++) {
        if (W[v][j] > 0) {
            if (W[v][j] < menor_peso) {
                menor_peso = W[v][j];
                melhor_vizinho = j;
            }
            /* Em caso de empate, o loop sequencial garante a escolha do menor índice[cite: 30] */
        }
    }
    
    if (melhor_vizinho != -1) {
        printf("Vizinho mais proximo de %c e %c (peso %d)\n", 'A' + v, 'A' + melhor_vizinho, menor_peso);
    } else {
        printf("O vertice %c nao possui vizinhos.\n", 'A' + v);
    }
    
    return melhor_vizinho;
}