import math
import numpy as np
import matplotlib.pyplot as plt


def limite_termo(a, r):
    if abs(r) < 1:
        return 0
    elif abs(r) == 1:
        return a if r == 1 else None
    else:
        return None


def limite_soma(a, r):
    if abs(r) < 1:
        return a / (1 - r)
    return None


def termos_pg(a, r, n=50):
    return a * (r ** np.arange(n))


def somas_parciais(termos):
    return np.cumsum(termos)


def testar_convergencia(a, r, n=50):
    if abs(r) < 1:
        t = a * (r ** n)
        return True, t
    return False, None


def plot_termos(a, r, termos):
    plt.figure()
    plt.plot(termos, marker='o')
    plt.title(f"Termos da PG (a={a}, r={r})")
    plt.xlabel("n")
    plt.ylabel("t_n")
    nome = f"termos_a{a}_r{r}.png"
    plt.savefig(nome)
    plt.close()
    print(f"[plot_termos] Salvo: {nome}")


def plot_somas(a, r, somas):
    plt.figure()
    plt.plot(somas, marker='o')
    plt.title(f"Somas Parciais da PG (a={a}, r={r})")
    plt.xlabel("n")
    plt.ylabel("S_n")
    nome = f"somas_a{a}_r{r}.png"
    plt.savefig(nome)
    plt.close()
    print(f"[plot_somas] Salvo: {nome}")


amostras = [
    (2, 0.5),
    (1, 0.9),
    (3, -0.5),
    (5, 1),
    (1, -1),
    (1, 1.5)
]


for a, r in amostras:
    t_lim = limite_termo(a, r)
    S_lim = limite_soma(a, r)
    termos = termos_pg(a, r)
    somas = somas_parciais(termos)
    converg, aprox = testar_convergencia(a, r)


    print("------------------------------------------------------------")
    print(f"a={a}, r={r}")
    print(f"Limite do termo: {t_lim}")
    print(f"Limite da soma infinita: {S_lim}")
    print(f"Converge: {converg}, último termo: {aprox}")


    plot_termos(a, r, termos)
    plot_somas(a, r, somas)


print("Pronto.")
