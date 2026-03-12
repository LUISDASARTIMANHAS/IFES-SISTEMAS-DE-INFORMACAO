# codigo_lab1_latencia.py
import time
from datetime import datetime

log_de_transacoes = []

def processar_transacao(evento):
    global log_de_transacoes
    agora = datetime.now().strftime("%H:%M:%S")

    print(f"\n[{agora}] NOVO EVENTO: Cliente {evento['cliente']} | Valor: R${evento['valor']}")

    if evento['valor'] > 1000:
        evento['valor'] *= 0.85
        print(f" [AUTOMAÇÃO]: Regra de Grande Valor aplicada. Novo valor: R${evento['valor']:.2f}")

    compras_anteriores = [
        t for t in log_de_transacoes
        if t['cliente'] == evento['cliente']
    ]

    if len(compras_anteriores) >= 2:
        print(f" [ALERTA CEP]: Padrão suspeito! Cliente {evento['cliente']} com múltiplas transações rápidas.")

    log_de_transacoes.append(evento)


fluxo_entrada = [
    {'cliente': 'Alice', 'valor': 1200.00},
    {'cliente': 'Bob', 'valor': 150.00},
    {'cliente': 'Alice', 'valor': 500.00},
    {'cliente': 'Alice', 'valor': 200.00},
]

# ⏱ Marca início
inicio = time.time()

for transacao in fluxo_entrada:
    processar_transacao(transacao)
    time.sleep(0.1)  # Latência reduzida

# ⏱ Marca fim
fim = time.time()

tempo_total = fim - inicio
tempo_medio = tempo_total / len(fluxo_entrada)

print("\n--- MÉTRICAS DE EXECUÇÃO ---")
print(f"Tempo total de execução: {tempo_total:.4f} segundos")
print(f"Tempo médio por evento: {tempo_medio:.4f} segundos")