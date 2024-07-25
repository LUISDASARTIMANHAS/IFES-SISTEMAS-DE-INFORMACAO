import time
import numpy as np
from numba import njit
from PIL import Image, ImageFilter
import matplotlib.pyplot as plt
from matplotlib import pyplot as plt
import matplotlib.image as mpimg
import seaborn as sns

imagem_1 = Image.open ("/home/maker/Documentos/Eduardo/Ifes/OAC/Programas/creation.jpg")
# Carrega a imagem como um array de pixels
data = mpimg.imread("/home/maker/Documentos/Eduardo/Ifes/OAC/Programas/japanese.png")
imagem_2 = Image.open ("/home/maker/Documentos/Eduardo/Ifes/OAC/Programas/japanese.png")

def imprime_figura ():
    
    # Sumarizando detalhes sobre a imagem
    # Modo da imagem
    print(imagem_1.mode)
    # Formato da imagem
    print(imagem_1.format)
    # Tamanho da imagem (largura, altura)
    print(imagem_1.size)

    # Apresentando a imagem
    imagem_1.show()


def imagem_como_array_de_pixels ():
    
    # Imprime os arrays de dados
    print(data)
    # Imprime o tipo 
    print(type(data))

    # Dados sobre o array de pixels
    # Tipo de dados
    print(data.dtype)
    # Dimensão de dados
    print(data.shape)

    # Apresenta o array de pixels como uma imagem
    #lum_img = data[:, :, 0]
    #imgplot = plt.imshow(lum_img, cmap='twilight')
    #plt.axis('off')
    #plt.show()


def filtro_gaussian_blur ():
    # Cria uma imagem cortada
    cropped = imagem_2.crop((55, 60, 320, 400))
    # Aplica o GaussianBlur
    img_filter = cropped.filter(ImageFilter.GaussianBlur(1.3))
    # Mostra a imagem
    img_filter.show()
    
def grafico_de_calor_de_uma_matriz ():
    
    #Cria uma matriz de dados 
    dados = np.random.rand(200, 200)
    #Utiliza a função “imshow” para exibir o gráfico de calor 
    plt.imshow(dados, cmap="hot")
    #Adiciona uma barra de cores à visualização
    plt.colorbar()
    
def visualização_mapa_de_densidade ():
    #Carregua um conjunto de dados adequado para a visualização
    dados = sns.load_dataset("iris")
    #Utilize a função “imshow” para exibir o mapa de densidade
    sns.kdeplot(dados["sepal_width"], dados["sepal_length"], cmap="viridis", shade=True)


array = np.random.randint(1000, 10000, 10000000)
def preco_com_imposto(lista):
    aumento_total = 0
    for item in lista:
        if item > 5000:
            valor = item * 1.1
        else:
            valor = item
        aumento_total += valor - item
    return aumento_total



def valor_com_imposto(qtde):
    for i in range(qtde):
        novo_valor = qtde * 1.1


def investimento (juros_ao_mes, anos, capital_inicial):
    capital = 0
    meses = anos * 12
    juros = (1 + (juros_ao_mes/100))
    for i in range (meses):
       capital = capital + capital_inicial
       capital = (capital * juros)
    return capital


class _Grafo:
    def __init__(self):
        self.vertices = {}
        self.adicionar_aresta((0, 4), (0, 3))
        self.adicionar_aresta((0, 4), (1, 4))

        self.adicionar_aresta((0, 3), (0, 4))
        self.adicionar_aresta((0, 3), (1, 3))
        self.adicionar_aresta((0, 3), (0, 2))

        self.adicionar_aresta((0, 2), (0, 1))
        self.adicionar_aresta((0, 2), (0, 3))

        self.adicionar_aresta((0, 1), (0, 0))
        self.adicionar_aresta((0, 1), (0, 2))
        self.adicionar_aresta((0, 1), (1, 1))

        self.adicionar_aresta((1, 1), (1, 0))
        self.adicionar_aresta((1, 1), (0, 1))
        self.adicionar_aresta((1, 1), (1, 2))
        self.adicionar_aresta((1, 1), (2, 1))


        self.adicionar_aresta((1, 3), (0, 3))
        self.adicionar_aresta((1, 3), (1, 2))
        self.adicionar_aresta((1, 3), (1, 4))
        self.adicionar_aresta((1, 3), (2, 3))

        self.adicionar_aresta((2, 0), (1, 0))
        self.adicionar_aresta((2, 0), (2, 1))

        self.adicionar_aresta((2, 1), (1, 1))
        self.adicionar_aresta((2, 1), (3, 1))
        self.adicionar_aresta((2, 1), (2, 2))
        self.adicionar_aresta((2, 1), (2, 0))

        self.adicionar_aresta((2, 2), (2, 1))
        self.adicionar_aresta((2, 2), (2, 3))
        self.adicionar_aresta((2, 2), (3, 2))

        self.adicionar_aresta((2, 3), (1, 3))
        self.adicionar_aresta((2, 3), (2, 2))
        self.adicionar_aresta((2, 3), (2, 4))
        self.adicionar_aresta((2, 3), (3, 3))

        self.adicionar_aresta((2, 4), (3, 4))
        self.adicionar_aresta((2, 4), (2, 3))

        self.adicionar_aresta((3, 1), (3, 0))
        self.adicionar_aresta((3, 1), (2, 1))
        self.adicionar_aresta((3, 1), (4, 1))

        self.adicionar_aresta((3, 3), (3, 4))
        self.adicionar_aresta((3, 3), (2, 3))
        self.adicionar_aresta((3, 3), (4, 3))

        self.adicionar_aresta((4, 0), (3, 0))
        self.adicionar_aresta((4, 0), (5, 0))
        self.adicionar_aresta((4, 0), (4, 1))

        self.adicionar_aresta((4, 1), (3, 1))
        self.adicionar_aresta((4, 1), (4, 2))
        self.adicionar_aresta((4, 1), (4, 0))

        self.adicionar_aresta((4, 2), (3, 2))
        self.adicionar_aresta((4, 2), (5, 2))
        self.adicionar_aresta((4, 2), (4, 1))
        self.adicionar_aresta((4, 2), (4, 3))

        self.adicionar_aresta((4, 3), (4, 2))
        self.adicionar_aresta((4, 3), (3, 3))
        self.adicionar_aresta((4, 3), (4, 4))

        self.adicionar_aresta((4, 4), (4, 3))
        self.adicionar_aresta((4, 4), (5, 4))

    def remover_no(self, no):
        if no in self.vertices:
            # Remova todas as arestas conectadas a este nó
            for vertice in self.vertices:
                if no in self.vertices[vertice]:
                    del self.vertices[vertice][no]
            # Remova o nó
            del self.vertices[no]
        else:
            print(f"O nó {no} não existe no grafo.")

    def remover_aresta(self, origem, destino):
        if origem in self.vertices and destino in self.vertices:
            if destino in self.vertices[origem]:
                del self.vertices[origem][destino]
        else:
            print(f"Aresta entre {origem} e {destino} não existe no grafo.")

    def adicionar_vertice(self, coordenada):
        self.vertices[coordenada] = {}
            
    def adicionar_aresta(self, origem, destino):
        if origem not in self.vertices:
            self.adicionar_vertice(origem)
        if destino not in self.vertices:
            self.adicionar_vertice(destino)
            
        # Calcula a distância Euclidiana entre as coordenadas
        x1, y1 = origem
        x2, y2 = destino
        distancia = ((x1 - x2)**2 + (y1 - y2)**2) ** 0.5
        
        self.vertices[origem][destino] = distancia

    def dijkstra(self, origem, destino):
        vertices = self.vertices
        distancias = {vertice: float('infinity') for vertice in vertices}
        distancias[origem] = 0
        antecessores = {vertice: None for vertice in vertices}
        vertices_nao_visitados = list(vertices.keys())

        while vertices_nao_visitados:
            # Encontrar o vértice com a menor distância na lista de não visitados
            vertice_atual = None
            for vertice in vertices_nao_visitados:
                if vertice_atual is None or distancias[vertice] < distancias[vertice_atual]:
                    vertice_atual = vertice

            if vertice_atual == destino:
                # Construir o caminho a partir dos antecessores e retorná-lo
                caminho = []
                while vertice_atual is not None:
                    caminho.insert(0, vertice_atual)
                    vertice_atual = antecessores[vertice_atual]
                return caminho

            vertices_nao_visitados.remove(vertice_atual)

            # Atualizar as distâncias para os vizinhos do vértice atual
            for vizinho, peso in vertices[vertice_atual].items():
                nova_distancia = distancias[vertice_atual] + peso
                if nova_distancia < distancias[vizinho]:
                    distancias[vizinho] = nova_distancia
                    antecessores[vizinho] = vertice_atual

        # Se o destino não foi alcançado, retornar um caminho vazio
        return None



# Exemplo de uso
grafo = _Grafo()
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

capital_investido = investimento(1, 20, 10000)
print("Capital Final: R$", capital_investido)
valor_com_imposto(100000000)
print("Aumento:", preco_com_imposto(array))
imprime_figura ()
imagem_como_array_de_pixels ()
#filtro_gaussian_blur ()
#grafico_de_calor_de_uma_matriz ()
#visualização_mapa_de_densidade ()
fim = time.time()
print("Tempo de Processamento:",fim - inicio,"segundos")