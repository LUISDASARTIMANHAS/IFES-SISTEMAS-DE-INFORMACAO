# codigo_lab2_bam.py
import time

LIMITE_FORCA_NEWTONS = 15.0

def analisar_sessao(nome_sessao, fluxo_sensores):

    print("\n======================================")
    print(f"ANÁLISE DA SESSÃO: {nome_sessao}")
    print("======================================")

    historico_forcas = []
    espasmos_detectados = 0
    leituras_acima_limite = 0

    for leitura in fluxo_sensores:
        valor = leitura['valor']
        historico_forcas.append(valor)

        # Detecta espasmo
        if len(historico_forcas) > 1:
            if valor - historico_forcas[-2] > 5:
                espasmos_detectados += 1

        # Conta excesso de força
        if valor > LIMITE_FORCA_NEWTONS:
            leituras_acima_limite += 1

    # KPIs
    media_forca = sum(historico_forcas) / len(historico_forcas)
    pico_maximo = max(historico_forcas)
    percentual_excesso = (leituras_acima_limite / len(historico_forcas)) * 100

    # Índice simples de risco
    indice_risco = (espasmos_detectados * 2) + percentual_excesso

    print(f"Força Média: {media_forca:.2f} N")
    print(f"Pico Máximo: {pico_maximo:.2f} N")
    print(f"Espasmos Detectados: {espasmos_detectados}")
    print(f"% Leituras acima do limite: {percentual_excesso:.2f}%")
    print(f"Índice de Risco da Sessão: {indice_risco:.2f}")

    return {
        "media": media_forca,
        "pico": pico_maximo,
        "espasmos": espasmos_detectados,
        "percentual_excesso": percentual_excesso,
        "risco": indice_risco
    }


if __name__ == "__main__":

    # Sessão controlada
    sessao_normal = [
        {'valor': 2.0},
        {'valor': 4.0},
        {'valor': 6.0},
        {'valor': 5.0},
        {'valor': 7.0},
    ]

    # Sessão crítica
    sessao_critica = [
        {'valor': 2.0},
        {'valor': 8.0},   # espasmo
        {'valor': 16.0},  # excesso
        {'valor': 18.0},  # excesso
        {'valor': 9.0},
    ]

    resultado_normal = analisar_sessao("Sessão Controlada", sessao_normal)
    resultado_critica = analisar_sessao("Sessão Crítica", sessao_critica)

    print("\n======================================")
    print("COMPARAÇÃO FINAL")
    print("======================================")

    if resultado_critica["risco"] > resultado_normal["risco"]:
        print("Sessão Crítica apresentou maior risco clínico.")
    else:
        print("Sessão Controlada apresentou maior risco clínico.")