# -*- coding: utf-8 -*-


import numpy as np
import matplotlib.pyplot as plt


def soma_pg_infinita(a1, q):
    """
    Calcula o limite da soma de uma PG infinita.
    |q| < 1 para existir o limite.
    """
    if abs(q) >= 1:
        raise ValueError("A soma infinita não converge para |q| >= 1.")
   
    return a1 / (1 - q)


def soma_pg_n_termos(a1, q, n):
    """
    Soma dos n primeiros termos da PG.
    """
    return a1 * (1 - q**n) / (1 - q)


def gerar_pg(a1, q, n):
    """
    Gera os n primeiros termos da PG.
    """
    return [a1 * q**i for i in range(n)]


# Dados do problema
a1 = 1000
q = 0.8
n_termos = 50  # Número de termos a serem calculados


# Cálculo da soma infinita usando limite
soma_infinita = soma_pg_infinita(a1, q)


# Gerar os termos da PG
termos_pg = gerar_pg(a1, q, n_termos)


# Comparação gerando valores aproximados para n crescente
print("Aproximação da soma conforme n aumenta:")
for n in [5, 10, 20, 50, 100]:
    print("n={}: {:.2f}".format(n, soma_pg_n_termos(a1, q, n)))


print("\nLimite da soma infinita da PG:")
print("S∞ = {:.2f}".format(soma_infinita))


# Plotar os termos da PG
plt.figure(figsize=(8, 6))
plt.plot(termos_pg, marker='o', color='b', label="Termos da PG", linestyle='-', markersize=6)
plt.axhline(y=soma_infinita, color='r', linestyle='--', label="Limite S∞ = {:.2f}".format(soma_infinita))


# Configurações do gráfico
plt.title("Progressão Geométrica com Limite", fontsize=14)
plt.xlabel("Número de Termos (n)", fontsize=12)
plt.ylabel("Valor dos Termos da PG", fontsize=12)
plt.legend(loc="best")
plt.grid(True)
plt.tight_layout()


# Mostrar o gráfico
plt.show()