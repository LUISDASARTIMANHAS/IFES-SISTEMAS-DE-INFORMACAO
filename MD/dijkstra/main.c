#include <stdio.h>
#include "dijkstra.h"

int main(void) {
    const char *rotulos[N] = {
        "A",  "B",  "C",  "D",  "E",  "F",  "G",  "H",  "I",  "J",
        "K",  "L",  "M",  "N",  "O",  "P",  "Q",  "R",  "S",  "T",
        "U",  "V",  "W",  "X",  "Y",  "Z",  "AA", "AB", "AC", "AD",
        "AE", "AF", "AG", "AH", "AI", "AJ", "AK", "AL", "AM", "AN",
        "AO", "AP", "AQ", "AR", "AS", "AT", "AU", "AV", "AW", "AX",
        "AY", "AZ", "BA", "BB", "BC", "BD", "BE", "BF", "BG", "BH",
        "BI", "BJ", "BK", "BL", "BM", "BN", "BO", "BP", "BQ", "BR",
        "BS", "BT", "BU", "BV", "BW", "BX", "BY", "BZ", "CA", "CB",
        "CC", "CD", "CE", "CF", "CG", "CH", "CI", "CJ", "CK", "CL",
        "CM", "CN", "CO", "CP", "CQ", "CR", "CS", "CT", "CU", "CV"
    };
    const char *arquivo_entrada = "grafo.txt";
    int W[N][N];
    int dist[N];
    int anterior[N];
    int origem = 0;   /* A */
    int destino = 99; /* CV (ou 5 para F) */

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