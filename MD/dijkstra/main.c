#include <stdio.h>
#include "dijkstra.h"

int main(void) {
    const char rotulos[N] = {'A', 'B', 'C', 'D', 'E', 'F'};
    const char *arquivo_entrada = "grafo.txt";
    int W[N][N];
    int dist[N];
    int anterior[N];
    int origem = 0;  /* A */
    int destino = 5; /* F */

    if (!carregar_matriz_txt(arquivo_entrada, W)) {
        return 1;
    }

    dijkstra(W, origem, dist, anterior);

    printf("1. Caminho minimo: ");
    if (imprimir_caminho(anterior, origem, destino, rotulos) && dist[destino] < INF) {
        printf("2. Distancia percorrida: %d\n", dist[destino]);
    } else {
        printf("2. Distancia percorrida: INF\n");
    }

    return 0;
}