#include <stdio.h>
#include "dijkstra.h"

int carregar_matriz_txt(const char *nome_arquivo, int W[N][N]) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    int i;
    int j;

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo da matriz");
        return 0;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (fscanf(arquivo, "%d", &W[i][j]) != 1) {
                fprintf(stderr, "Erro ao ler elemento [%d][%d] em '%s'.\n", i, j, nome_arquivo);
                fclose(arquivo);
                return 0;
            }
        }
    }

    fclose(arquivo);
    return 1;
}

int proximo(int dist[N], int visitado[N]) {
    int u = -1;
    int i;

    for (i = 0; i < N; i++) {
        if (!visitado[i] && dist[i] < INF &&
            (u == -1 || dist[i] < dist[u])) {
            u = i;
        }
    }
    return u;
}

void dijkstra(int W[N][N], int origem, int dist[N], int anterior[N],
              const char *rotulos[N], int mostrar_passos) {
    int visitado[N] = {0};
    int i;
    int passo;

    for (i = 0; i < N; i++) {
        dist[i] = INF;
        anterior[i] = -1;
    }
    dist[origem] = 0;

    for (passo = 0; passo < N; passo++) {
        int u = proximo(dist, visitado);
        int v;

        if (u == -1) {
            break;
        }
        visitado[u] = 1;

        if (mostrar_passos) {
            printf("[Passo %d] Fechando vertice %s (dist = %d)\n",
                   passo + 1, rotulos[u], dist[u]);
        }

        for (v = 0; v < N; v++) {
            /* Relaxamento: verifica se passar por u reduz o custo ate v */
            if (!visitado[v] && W[u][v] > 0 &&
                dist[u] + W[u][v] < dist[v]) {
                int dist_antiga = dist[v];
                dist[v] = dist[u] + W[u][v];
                anterior[v] = u;

                if (mostrar_passos) {
                    if (dist_antiga >= INF) {
                        printf("   -> Relaxou %s -> %s: INF -> %d\n",
                               rotulos[u], rotulos[v], dist[v]);
                    } else {
                        printf("   -> Relaxou %s -> %s: %d -> %d\n",
                               rotulos[u], rotulos[v], dist_antiga, dist[v]);
                    }
                }
            }
        }
    }
}

int imprimir_caminho(int anterior[N], int origem, int destino, const char *rotulos[N]) {
    int caminho[N];
    int tamanho = 0;
    int atual = destino;
    int i;

    while (atual != -1) {
        caminho[tamanho++] = atual;
        if (atual == origem) {
            break;
        }
        atual = anterior[atual];
    }

    if (tamanho == 0 || caminho[tamanho - 1] != origem) {
        printf("Sem caminho\n");
        return 0;
    }

    printf("(");
    for (i = tamanho - 1; i >= 0; i--) {
        printf("%s", rotulos[caminho[i]]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf(")\n");
    return 1;
}