#include "grafo.h"
#include <stdio.h>
#include <string.h>

static int matriz_adj[MAX_VERTICES][MAX_VERTICES];
static char nomes_vertices[MAX_VERTICES][TAM_NOME];
static int total_cadastrados = 0;

void inicializar_grafo() {
    total_cadastrados = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        nomes_vertices[i][0] = '\0';
        for (int j = 0; j < MAX_VERTICES; j++) {
            matriz_adj[i][j] = 0;
        }
    }
}

int obter_ou_cadastrar_vertice(const char *nome) {
    for (int i = 0; i < total_cadastrados; i++) {
        if (strcmp(nomes_vertices[i], nome) == 0) {
            return i;
        }
    }
    if (total_cadastrados < MAX_VERTICES) {
        strncpy(nomes_vertices[total_cadastrados], nome, TAM_NOME - 1);
        nomes_vertices[total_cadastrados][TAM_NOME - 1] = '\0';
        return total_cadastrados++;
    }
    return -1;
}

const char* obter_nome_vertice(int idx) {
    if (idx >= 0 && idx < total_cadastrados) {
        return nomes_vertices[idx];
    }
    return "Desconhecido";
}

int total_vertices_atuais() {
    return total_cadastrados;
}

void adicionar_aresta_por_nome(const char *nome_u, const char *nome_v, int direcionado) {
    int u = obter_ou_cadastrar_vertice(nome_u);
    int v = obter_ou_cadastrar_vertice(nome_v);

    if (u != -1 && v != -1) {
        matriz_adj[u][v] = 1;
        if (!direcionado) {
            matriz_adj[v][u] = 1; /* Tratamento de simetria para grafos não orientados[cite: 29] */
        }
    }
}

static int grau_vertice_idx(int v, int n) {
    int grau = 0;
    if (v < 0 || v >= n) return 0;
    for (int j = 0; j < n; j++) {
        grau += matriz_adj[v][j];
    }
    return grau;
}

int grau_vertice_por_nome(const char *nome, int n) {
    int v = obter_ou_cadastrar_vertice(nome);
    return grau_vertice_idx(v, n);
}

int grau_emissao_por_nome(const char *nome, int n) {
    return grau_vertice_por_nome(nome, n);
}

int grau_recepcao_por_nome(const char *nome, int n) {
    int v = obter_ou_cadastrar_vertice(nome);
    if (v == -1) return 0;
    
    int grau = 0;
    for (int i = 0; i < n; i++) {
        grau += matriz_adj[i][v];
    }
    return grau;
}

int eh_regular(int n) {
    if (n <= 0) return 0;
    int grau_referencia = grau_vertice_idx(0, n);
    for (int i = 1; i < n; i++) {
        if (grau_vertice_idx(i, n) != grau_referencia) {
            return 0;
        }
    }
    return 1;
}

void exibir_matriz(int n) {
    printf("\nMatriz de Adjacencia (%d x %d):\n", n, n);
    printf("         ");
    for (int j = 0; j < n; j++) {
        printf("[%s] ", obter_nome_vertice(j));
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("[%s]\t", obter_nome_vertice(i));
        for (int j = 0; j < n; j++) {
            printf("  %d   ", matriz_adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void desenhar_grafo_ascii(int n, int direcionado) {
    printf("\n========================================\n");
    printf("      MAPA VISUAL DO GRAFO (ASCII)      \n");
    printf("========================================\n");
    
    int tem_arestas = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz_adj[i][j] == 1) {
                if (!direcionado && i > j) continue;
                
                tem_arestas = 1;
                const char *nome_u = obter_nome_vertice(i);
                const char *nome_v = obter_nome_vertice(j);

                if (direcionado) {
                    printf("  (%s) ----> (%s)\n", nome_u, nome_v);
                } else {
                    printf("  (%s) <---> (%s)\n", nome_u, nome_v);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (grau_vertice_idx(i, n) == 0 && grau_recepcao_por_nome(obter_nome_vertice(i), n) == 0) {
            printf("  (%s) [ISOLADO / SEM CONEXOES]\n", obter_nome_vertice(i));
        }
    }

    if (!tem_arestas) {
        printf("  [Nenhuma aresta cadastrada no grafo]\n");
    }
    printf("========================================\n\n");
}