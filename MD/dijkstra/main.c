#include <stdio.h>
#include <time.h>
#include "dijkstra.h"

int main(void) {
    const char *rotulos[MAX_N] = {
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
    int W[MAX_N][MAX_N];
    int dist[MAX_N];
    int anterior[MAX_N];
    int qtd = 0;
    int origem = 0;
    int destino;
    int iteracoes = 1000;
    int k;

    clock_t inicio_leitura;
    clock_t fim_leitura;
    clock_t inicio_algo;
    clock_t fim_algo;
    double tempo_leitura_ms;
    double tempo_total_ms;
    double tempo_medio_us;

    /* 1. Detecta tamanho e le a matriz do arquivo */
    inicio_leitura = clock();
    if (!carregar_matriz_txt(arquivo_entrada, W, &qtd)) {
        return 1;
    }
    fim_leitura = clock();
    tempo_leitura_ms = ((double)(fim_leitura - inicio_leitura) / CLOCKS_PER_SEC) * 1000.0;

    destino = qtd - 1;

    /* 2. Benchmark silencioso */
    inicio_algo = clock();
    for (k = 0; k < iteracoes; k++) {
        dijkstra(W, qtd, origem, dist, anterior, rotulos, 0);
    }
    fim_algo = clock();
    tempo_total_ms = ((double)(fim_algo - inicio_algo) / CLOCKS_PER_SEC) * 1000.0;
    tempo_medio_us = (tempo_total_ms / iteracoes) * 1000.0;

    /* 3. Execucao visivel mostrando cada passo e relaxamento */
    printf("=== RASTREAMENTO DO ALGORITMO (%d cidades) ===\n", qtd);
    dijkstra(W, qtd, origem, dist, anterior, rotulos, 1);

    printf("\n=== RESULTADO FINAL ===\n");
    printf("1. Caminho minimo: ");
    fflush(stdout);
    if (imprimir_caminho(anterior, origem, destino, qtd, rotulos) && dist[destino] < INF) {
        printf("2. Distancia percorrida: %d\n", dist[destino]);
    } else {
        printf("2. Distancia percorrida: INF\n");
    }

    printf("\n=== METRICAS DE TEMPO (%d cidades) ===\n", qtd);
    printf("Leitura do arquivo: %.3f ms\n", tempo_leitura_ms);
    printf("Dijkstra (%d execucoes): %.3f ms total\n", iteracoes, tempo_total_ms);
    printf("Tempo medio por execucao: %.3f us (microssegundos)\n", tempo_medio_us);

    return 0;
}