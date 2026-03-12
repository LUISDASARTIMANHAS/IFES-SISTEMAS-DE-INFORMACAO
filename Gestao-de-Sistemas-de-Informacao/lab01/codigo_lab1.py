# codigo_lab1.py
import time
from datetime import datetime

# Simulação de Banco de Dados de Eventos (BAM)
log_de_transacoes = []

def processar_transacao(evento):
    global log_de_transacoes
    agora = datetime.now().strftime("%H:%M:%S")

    print(f"\n[{agora}] NOVO EVENTO: Cliente {evento['cliente']} | Valor: R${evento['valor']}")

    # --- DESAFIO 1: REGRA DE NEGÓCIO ---
    if evento['valor'] > 1000:
        evento['valor'] *= 0.85
        print(f" [AUTOMAÇÃO]: Regra de Grande Valor aplicada. Novo valor: R${evento['valor']:.2f}")

    # --- DESAFIO 2: CEP - DETECÇÃO DE FRAUDE ---
    compras_anteriores = [
        t for t in log_de_transacoes
        if t['cliente'] == evento['cliente']
    ]

    if len(compras_anteriores) >= 2:
        print(f" [ALERTA CEP]: Padrão suspeito! Cliente {evento['cliente']} com múltiplas transações rápidas.")

    # Armazena o evento no log (Resiliência)
    log_de_transacoes.append(evento)


# --- FLUXO DE EVENTOS (FORA DA FUNÇÃO!) ---
fluxo_entrada = [
    {'cliente': 'Alice', 'valor': 1200.00},
    {'cliente': 'Bob', 'valor': 150.00},
    {'cliente': 'Alice', 'valor': 500.00},
    {'cliente': 'Alice', 'valor': 200.00},  # Terceiro evento da Alice
]

for transacao in fluxo_entrada:
    processar_transacao(transacao)
    time.sleep(0.1)