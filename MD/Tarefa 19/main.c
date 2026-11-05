#include <stdio.h>
#include "grafo.h"
#include "utils.h"

int main() {
    printf("=== LABORATORIO DE GRAFOS - IFES COLATINA ===\n\n");

    int tipo = ler_inteiro("O grafo e direcionado? (0 - Nao, 1 - Sim): ");
    int num_arestas = ler_inteiro("Quantas arestas (ruas) deseja adicionar? ");

    inicializar_grafo();

    char u[TAM_NOME], v[TAM_NOME];
    for (int k = 0; k < num_arestas; k++) {
        printf("\nAresta %d:\n", k + 1);
        ler_string("  Vertice (Cidade) origem (u): ", u, sizeof(u));
        ler_string("  Vertice (Cidade) destino (v): ", v, sizeof(v));
        adicionar_aresta_por_nome(u, v, tipo);
    }

    /* Descobre automaticamente o número total de vértices únicos cadastrados */
    int n = total_vertices_atuais();
    printf("\n[INFO] Total de cidades unicas cadastradas: %d\n", n);

    /* Exibe o desenho e a matriz nomeada corretamente com todas as cidades */
    desenhar_grafo_ascii(n, tipo);
    exibir_matriz(n);

    /* Testando graus */
    char vertice_consulta[TAM_NOME];
    ler_string("Digite o nome de um vertice para consultar os graus: ", vertice_consulta, sizeof(vertice_consulta));
    
    if (tipo == 0) {
        printf("Ex 1.2 - Grau do vertice '%s': %d\n\n", vertice_consulta, grau_vertice_por_nome(vertice_consulta, n));
    } else {
        printf("Ex 1.3 - Grau de emissao (saida) de '%s': %d\n", vertice_consulta, grau_emissao_por_nome(vertice_consulta, n));
        printf("Ex 1.3 - Grau de recepcao (chegada) de '%s': %d\n\n", vertice_consulta, grau_recepcao_por_nome(vertice_consulta, n));
    }

    /* Verificação de Regularidade[cite: 29] */
    int regular = eh_regular(n);
    printf("Ex 1.4 - O grafo e regular? %s (%d)\n", regular ? "Sim" : "Nao", regular);

    return 0;
}