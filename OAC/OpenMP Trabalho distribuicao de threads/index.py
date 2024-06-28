import time
from numba import jit, njit

@njit
def valor_com_imposto(qtde):
    for i in range(qtde):
        novo_valor = qtde * 1.1

inicio = time.time()
valor_com_imposto(1000000000)
fim = time.time()
print(fim - inicio)