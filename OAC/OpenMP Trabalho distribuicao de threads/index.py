#  tempo sem paralelo 11 segundos
import time
import functions

# Exemplo de uso
grafo = functions._Grafo()
# obstaculos = [(1, 3), (3, 1)]

parqueMapa = [(5, 0), (5, 2), (5, 4)]

def caminhoMapa(listaObstaculos, origem, destino):
    print("lista obstaculos = ", listaObstaculos)
    print("origem = ", origem)
    print("destino = ", destino)
    caminho = grafo.dijkstra(origem, destino)
    print(" ########  caminhoMapa  ########")
    print(caminho)
    print("################################")
    return caminho


inicio = time.time()
print(caminhoMapa([(2, 2), (3, 3)], (0, 4), (3, 2)))

capital_investido = functions.investimento(1, 20, 10000)
print("Capital Final: R$", capital_investido)
functions.valor_com_imposto(100000000)
print("Aumento:", functions.preco_com_imposto(functions.array))
functions.imprime_figura ()
functions.imagem_como_array_de_pixels ()
fim = time.time()
print("Tempo de Processamento:",fim - inicio,"segundos")