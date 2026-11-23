#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

int carregar_matriz_txt(const char *nome_arquivo, int W[MAX_N][MAX_N], int *qtd) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    char linha[4096];
    int n = 0;
    int i;
    int j;

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo da matriz");
        return 0;
    }

    /* Le a primeira linha nao vazia para descobrir quantas colunas/cidades existem */
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *ptr = linha;
        int offset = 0;
        int valor;
        int cols = 0;

        while (sscanf(ptr, "%d%n", &valor, &offset) == 1) {
            if (cols >= MAX_N) {
                fprintf(stderr, "Erro: matriz excede o limite de %d cidades.\n", MAX_N);
                fclose(arquivo);
                return 0;
            }
            W[0][cols++] = valor;
            ptr += offset;
        }

        if (cols > 0) {
            n = cols;
            break;
        }
    }

    if (n <= 0) {
        fprintf(stderr, "Erro: arquivo '%s' vazio ou sem matriz valida.\n", nome_arquivo);
        fclose(arquivo);
        return 0;
    }

    /* Le o restante das linhas (1..n-1) respeitando a dimensao n detectada */
    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (fscanf(arquivo, "%d", &W[i][j]) != 1) {
                fprintf(stderr, "Erro ao ler elemento [%d][%d] em '%s' (esperado %dx%d).\n",
                        i, j, nome_arquivo, n, n);
                fclose(arquivo);
                return 0;
            }
        }
    }

    fclose(arquivo);
    *qtd = n;
    return 1;
}

int proximo(const int dist[MAX_N], const int visitado[MAX_N], int qtd) {
    int u = -1;
    int i;

    for (i = 0; i < qtd; i++) {
        if (!visitado[i] && dist[i] < INF &&
            (u == -1 || dist[i] < dist[u])) {
            u = i;
        }
    }
    return u;
}

void dijkstra(int W[MAX_N][MAX_N], int qtd, int origem, int dist[MAX_N],
              int anterior[MAX_N], const char *const rotulos[MAX_N], int mostrar_passos) {
    int visitado[MAX_N] = {0};
    int i;
    int passo;

    for (i = 0; i < qtd; i++) {
        dist[i] = INF;
        anterior[i] = -1;
    }
    dist[origem] = 0;

    for (passo = 0; passo < qtd; passo++) {
        int u = proximo(dist, visitado, qtd);
        int v;

        if (u == -1) {
            break;
        }
        visitado[u] = 1;

        if (mostrar_passos) {
            printf("[Passo %d] Fechando vertice %s (dist = %d)\n",
                   passo + 1, rotulos[u], dist[u]);
        }

        for (v = 0; v < qtd; v++) {
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

int imprimir_caminho(const int anterior[MAX_N], int origem, int destino,
                     int qtd, const char *const rotulos[MAX_N]) {
    int caminho[MAX_N];
    int tamanho = 0;
    int atual = destino;
    int passos = 0;
    int i;

    if (origem < 0 || origem >= qtd || destino < 0 || destino >= qtd) {
        printf("Indice de origem ou destino fora do intervalo (0..%d)\n", qtd - 1);
        return 0;
    }

    while (atual != -1 && passos < qtd) {
        if (atual < 0 || atual >= qtd) {
            printf("Erro: indice de predecessor invalido (%d)\n", atual);
            return 0;
        }
        caminho[tamanho++] = atual;
        if (atual == origem) {
            break;
        }
        atual = anterior[atual];
        passos++;
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