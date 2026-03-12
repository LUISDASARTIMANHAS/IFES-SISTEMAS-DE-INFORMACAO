# gsi/lab2/codigo_lab2.py
import time
from datetime import datetime

# Limites de Segurança (Regras de Negócio Médicas)
LIMITE_FORCA_NEWTONS = 15.0
historico_sensores = []

def processar_sensor_luva(leitura):
    global historico_sensores
    agora = datetime.now().strftime("%H:%M:%S.%f")[:-3]

    print(f"\n[{agora}] SENSOR: {leitura['sensor']} | Força: {leitura['valor']}N")

    # --- REGRA DE NEGÓCIO: PROTEÇÃO TECIDUAL ---
    if leitura['valor'] > LIMITE_FORCA_NEWTONS:
        print(f" [ALERTA DE SEGURANÇA]: Limite de {LIMITE_FORCA_NEWTONS}N excedido!")
        print(" > AÇÃO: Aliviando tensão dos motores imediatamente.")
        return "PARADA_EMERGENCIA"

    # --- CEP: DETECÇÃO DE ESPASMO ---
    historico_sensores.append(leitura)

    if len(historico_sensores) > 1:
        delta_forca = leitura['valor'] - historico_sensores[-2]['valor']
        if delta_forca > 5.0:
            print(" [ALERTA CEP]: Espasmo muscular detectado (Subida brusca de força)!")
            print(" > AÇÃO: Bloqueando movimento e notificando fisioterapeuta.")
            return "BLOQUEIO_POR_ESPASMO"

    print(" [STATUS]: Movimento seguro. Motores operando normalmente.")
    return "OK"


# --- SIMULAÇÃO DE FLUXO DE SENSORES ---
if __name__ == "__main__":

    fluxo_sensores = [
        {'sensor': 'Indicador', 'valor': 2.0},
        {'sensor': 'Indicador', 'valor': 4.5},
        {'sensor': 'Indicador', 'valor': 10.2},  # Espasmo
        {'sensor': 'Indicador', 'valor': 16.0},  # Limite excedido
    ]

    for dado in fluxo_sensores:
        status = processar_sensor_luva(dado)

        if status != "OK":
            print(f"--- SISTEMA TRAVADO PARA SEGURANÇA: {status} ---")
            break

        time.sleep(0.5)  # Latência do sensor