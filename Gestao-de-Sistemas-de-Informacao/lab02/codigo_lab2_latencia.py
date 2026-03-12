# codigo_lab2_latencia.py
import time

LIMITE_FORCA_NEWTONS = 15.0
FORCA_APLICADA = 16.0  # Já acima do limite

def simular_sistema(latencia_processamento):
    print("\n======================================")
    print(f"Simulando latência de {latencia_processamento} segundos")
    print("======================================")

    inicio = time.time()

    # Motor começa aplicando força perigosa
    print(f"Força aplicada: {FORCA_APLICADA}N (ACIMA DO LIMITE!)")

    # Sistema demora para processar
    time.sleep(latencia_processamento)

    # Sistema finalmente reage
    if FORCA_APLICADA > LIMITE_FORCA_NEWTONS:
        print("ALERTA: Limite excedido!")
        print("AÇÃO: Parada de emergência executada.")

    fim = time.time()

    tempo_exposicao = fim - inicio
    excesso_forca = FORCA_APLICADA - LIMITE_FORCA_NEWTONS
    dano_simulado = excesso_forca * tempo_exposicao

    print(f"Tempo até reação: {tempo_exposicao:.2f} segundos")
    print(f"Exposição acumulada acima do limite: {dano_simulado:.2f} N·s")

    return tempo_exposicao, dano_simulado


if __name__ == "__main__":

    # Cenário 1: Sistema rápido (0.1s)
    simular_sistema(0.1)

    # Cenário 2: Sistema lento (2s)
    simular_sistema(2)