# Importação das bibliotecas necessárias
import numpy as np                   # numpy é utilizado para operações matemáticas eficientes com arrays (como somas, potências e sequências)
import matplotlib.pyplot as plt      # matplotlib é usado para plotar gráficos e visualizar os termos e somas da Progressão Geométrica


# Função que calcula o limite do termo geral da PG quando n → ∞
def limite_termo(a, r):
    """
    Esta função calcula o limite do termo geral da Progressão Geométrica (PG)
    quando n tende ao infinito, ou seja, o comportamento do termo t_n para n muito grande.
    A fórmula do termo geral da PG é dada por: t_n = a * r^n
    """

    # Caso |r| < 1, os termos tendem a 0 conforme n cresce, logo o limite é 0
    if abs(r) < 1:
        return 0
    
    # Se |r| == 1, o limite depende de r:
    # - Se r == 1, todos os termos serão iguais ao primeiro termo a, logo o limite é a.
    # - Se r == -1, a sequência oscila entre a e -a, não possui limite.
    elif abs(r) == 1:
        return a if r == 1 else None  # Retorna a apenas se r for 1. Caso contrário, retorna None, pois não há limite.

    # Se |r| > 1, os termos da PG crescem sem limites, então não há limite finito.
    else:
        return None


# Função que calcula a soma infinita da PG, se ela convergir
def limite_soma(a, r):
    """
    Esta função calcula a soma infinita da PG, que é o limite da soma dos termos conforme n → ∞.
    A fórmula da soma infinita da PG é dada por: S = a / (1 - r), válida apenas para |r| < 1.
    """
    # Só existe soma infinita se |r| < 1
    if abs(r) < 1:
        return a / (1 - r)  # Fórmula da soma infinita da PG
    return None  # Se |r| >= 1, a soma não existe


# Função que gera os primeiros n termos da PG
def termos_pg(a, r, n=50):
    """
    Gera os primeiros n termos da Progressão Geométrica (PG) usando a fórmula t_n = a * r^n.
    """
    # np.arange(n) cria um array de números inteiros de 0 até n-1, e então gera os termos
    return a * (r ** np.arange(n))


# Função que calcula as somas parciais dos termos da PG
def somas_parciais(termos):
    """
    Calcula as somas parciais dos primeiros n termos da PG, ou seja:
    S_n = t_1 + t_2 + ... + t_n, para n variando de 1 até n.
    """
    return np.cumsum(termos)  # np.cumsum retorna a soma acumulada dos termos, ou seja, soma parcial até o termo n.


# Função que testa se a PG converge (|r| < 1)
def testar_convergencia(a, r, n=50):
    """
    Verifica se a Progressão Geométrica (PG) converge para um valor finito.
    Uma PG converge se |r| < 1. Se a PG converge, retorna True e o valor do termo aproximado para n grande.
    """
    # Se |r| < 1, a PG converge, então calculamos o valor do termo para n grande.
    if abs(r) < 1:
        t = a * (r ** n)  # Calcula o valor do último termo aproximado.
        return True, t   # Retorna True indicando que a PG converge, e o valor do último termo.
    return False, None  # Caso contrário, a PG não converge


# Função que gera o gráfico dos termos da PG
def plot_termos(a, r, termos):
    """
    Gera um gráfico para visualizar como os termos da PG se comportam.
    Este gráfico mostra os termos t_1, t_2, ..., t_n da Progressão Geométrica.
    """
    plt.figure()  # Cria uma nova figura para o gráfico
    plt.plot(termos, marker='o')  # Plota os termos com marcadores circulares
    plt.title(f"Termos da PG (a={a}, r={r})")  # Define o título do gráfico com os valores de a e r
    plt.xlabel("n")  # Rótulo do eixo x (índice dos termos)
    plt.ylabel("t_n")  # Rótulo do eixo y (valor dos termos t_n)
    nome = f"termos_a{a}_r{r}.png"  # Nome do arquivo para salvar o gráfico
    plt.savefig(nome)  # Salva o gráfico como um arquivo PNG
    plt.close()  # Fecha a figura para liberar memória
    print(f"[plot_termos] Salvo: {nome}")  # Imprime uma mensagem indicando que o gráfico foi salvo


# Função que gera o gráfico das somas parciais da PG
def plot_somas(a, r, somas):
    """
    Gera um gráfico para visualizar como as somas parciais da PG se comportam.
    Este gráfico mostra a soma acumulada dos termos S_1, S_2, ..., S_n.
    """
    plt.figure()  # Cria uma nova figura para o gráfico
    plt.plot(somas, marker='o')  # Plota as somas parciais com marcadores circulares
    plt.title(f"Somas Parciais da PG (a={a}, r={r})")  # Define o título do gráfico com os valores de a e r
    plt.xlabel("n")  # Rótulo do eixo x (índice dos termos)
    plt.ylabel("S_n")  # Rótulo do eixo y (valor das somas S_n)
    nome = f"somas_a{a}_r{r}.png"  # Nome do arquivo para salvar o gráfico
    plt.savefig(nome)  # Salva o gráfico como um arquivo PNG
    plt.close()  # Fecha a figura para liberar memória
    print(f"[plot_somas] Salvo: {nome}")  # Imprime uma mensagem indicando que o gráfico foi salvo


# Lista com amostras de PGs para testar diferentes comportamentos
amostras = [
    (2, 0.5),   # PG convergente com razão menor que 1
    (1, 0.9),   # PG convergente com razão menor que 1
    (3, -0.5),  # PG convergente, mas com termos alternando entre positivo e negativo
    (5, 1),     # PG constante (não converge), r == 1
    (1, -1),    # PG divergente, os termos oscilam entre 1 e -1
    (1, 1.5)    # PG divergente, com termos crescendo sem limites
]


# Loop principal que executa todos os cálculos para cada PG
for a, r in amostras:
    t_lim = limite_termo(a, r)           # Calcula o limite do termo geral
    S_lim = limite_soma(a, r)            # Calcula o limite da soma infinita, se ela existir
    termos = termos_pg(a, r)             # Gera os primeiros termos da PG
    somas = somas_parciais(termos)       # Calcula as somas parciais dos primeiros n termos
    converg, aprox = testar_convergencia(a, r)   # Testa se a PG converge e retorna o valor do termo aproximado


    # Exibe os resultados no console
    print("------------------------------------------------------------")
    print(f"a={a}, r={r}")  # Imprime os valores de a e r da PG
    print(f"Limite do termo: {t_lim}")  # Imprime o limite do termo geral
    print(f"Limite da soma infinita: {S_lim}")  # Imprime o limite da soma infinita (se existir)
    print(f"Converge: {converg}, último termo: {aprox}")  # Exibe se a PG converge e o valor aproximado do último termo


    # Gera e salva os gráficos dos termos e das somas parciais
    plot_termos(a, r, termos)  # Plota e salva o gráfico dos termos
    plot_somas(a, r, somas)    # Plota e salva o gráfico das somas parciais


# Mensagem final indicando que o código terminou de executar
print("Pronto.")
