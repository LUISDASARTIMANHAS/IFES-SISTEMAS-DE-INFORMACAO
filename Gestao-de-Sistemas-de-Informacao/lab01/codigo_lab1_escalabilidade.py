# codigo_lab1_escalabilidade_mp.py
import time
import multiprocessing
from datetime import datetime
import random
from multiprocessing import Pool, cpu_count

NUM_CLIENTES = 4
LATENCIA = 0.1  # Alterar para 2 para o segundo teste
# LATENCIA = 2
# LATENCIA = 4

log_de_transacoes = []
lock = threading.Lock()

def processar_transacao(evento):
    global log_de_transacoes
    
    # Simula latência externa (rede/banco/API)
    time.sleep(LATENCIA)

    valor = random.randint(100, 3000)

    # Regra de desconto
    if valor > 1000:
        valor *= 0.85

    # Retorna apenas resultado mínimo (evita overhead)
    return valor


if __name__ == "__main__":

    inicio = time.time()

    # Número de processos = número de núcleos da CPU
    num_processos = cpu_count()

    with Pool(processes=num_processos) as pool:
        resultados = pool.map(processar_transacao, range(NUM_CLIENTES))

    fim = time.time()

    tempo_total = fim - inicio
    throughput = NUM_CLIENTES / tempo_total

    print("\n--- TESTE DE ESCALABILIDADE (Multiprocessing) ---")
    print(f"Núcleos utilizados: {num_processos}")
    print(f"Clientes processados: {NUM_CLIENTES}")
    print(f"Latência simulada: {LATENCIA} segundos")
    print(f"Tempo total: {tempo_total:.4f} segundos")
    print(f"Throughput: {throughput:.2f} transações/segundo")