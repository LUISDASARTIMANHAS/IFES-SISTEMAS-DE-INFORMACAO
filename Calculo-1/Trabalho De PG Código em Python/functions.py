import numpy as np
import matplotlib.pyplot as plt
import subprocess
import sys
from colorama import init, Fore, Back, Style

# Inicializa o colorama para compatibilidade com Windows (muito importante no Windows)
init(autoreset=True)

# Definição das cores usando o colorama
CGREY = Fore.LIGHTBLACK_EX
ERROR = Fore.RED
OK = Fore.GREEN
ALERT = Fore.YELLOW
SYS = Fore.BLUE
CVIOLET2 = Fore.MAGENTA
CBEIGE2 = Fore.CYAN
STOPCOLOR = Fore.RESET

CGREYBG = Back.LIGHTBLACK_EX
CREDBG2 = Back.LIGHTRED_EX
CGREENBG2 = Back.LIGHTGREEN_EX
CYELLOWBG2 = Back.LIGHTYELLOW_EX
CBLUEBG2 = Back.LIGHTBLUE_EX
CVIOLETBG2 = Back.LIGHTMAGENTA_EX
CBEIGEBG2 = Back.LIGHTCYAN_EX
CWHITEBG2 = Back.LIGHTWHITE_EX

# Função de cabeçalho do programa
def head():
    clear()
    print("----------------------------------------------------")
    print(OK + "\t Progressão Geométrica (PG) - Analisador de Convergência")
    print("\t PRODUZIDO POR LUIS, THALES, ANTONIO" + STOPCOLOR)
    print("\t Iniciando programa....." + STOPCOLOR)
    print("----------------------------------------------------")


# Função para exibir dados
def data(line1, line2, line3, line4, dado1, dado2, dado3, dado4):
    print("-----------------------" + ALERT + "DADOS" + STOPCOLOR + "--------------------")
    print("\t %s : %s" % (line1, dado1))
    print("\t %s : %s" % (line2, dado2))
    print("\t %s : %s" % (line3, dado3))
    print("\t %s : %s" % (line4, dado4))
    print("----------------------------------------------------")


# Função para exibir os desenvolvedores
def copy():
    print("----------------------------------------------------")
    print(OK + "\t DEVS:")
    print("\t LUIS AUGUSTO.")
    print("\t THALES.")
    print("\t ANTONIO" + STOPCOLOR)
    print("----------------------------------------------------")


# Função para limpar a tela do terminal
def clear():
    print("\n" * 50)
    print("\t" + ALERT + "Console Limpo!" + STOPCOLOR)


def limite_termo(a, r):
    """
    Esta função calcula o limite do termo geral da Progressão Geométrica (PG)
    quando n tende ao infinito, ou seja, o comportamento do termo t_n para n muito grande.
    A fórmula do termo geral da PG é dada por: t_n = a * r^n
    """
    # Caso |r| < 1, os termos tendem a 0 conforme n cresce, logo o limite é 0
    if abs(r) < 1:
        return OK + "Limite do termo: 0" + STOPCOLOR
    
    # Se |r| == 1, o limite depende de r:
    # - Se r == 1, todos os termos serão iguais ao primeiro termo a, logo o limite é a.
    # - Se r == -1, a sequência oscila entre a e -a, não possui limite.
    elif abs(r) == 1:
        return ALERT + "Limite do termo: Oscilação entre a e -a (não tem limite)" + STOPCOLOR if r == -1 else OK + f"Limite do termo: {a}" + STOPCOLOR

    # Se |r| > 1, os termos da PG crescem sem limites, então não há limite finito.
    else:
        return ERROR + "Limite do termo: Sem limite finito (termos crescem indefinidamente)" + STOPCOLOR


def limite_soma(a, r):
    """
    Esta função calcula a soma infinita da PG, que é o limite da soma dos termos conforme n → ∞.
    A fórmula da soma infinita da PG é dada por: S = a / (1 - r), válida apenas para |r| < 1.
    """
    # Só existe soma infinita se |r| < 1
    if abs(r) < 1:
        return OK + f"Limite da soma infinita: {a / (1 - r)}" + STOPCOLOR
    return ERROR + "Limite da soma infinita: Soma infinita não existe (|r| >= 1)" + STOPCOLOR


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
    print(f"[{OK}plot_termos{STOPCOLOR}] Salvo: {nome}")  # Imprime uma mensagem indicando que o gráfico foi salvo


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
    print(f"[{OK}plot_somas{STOPCOLOR}] Salvo: {nome}")  # Imprime uma mensagem indicando que o gráfico foi salvo