# lab3/interop_semantica.py
# ============================================================
# LABORATÓRIO 3 - PARTE 4
# INTEROPERABILIDADE SEMÂNTICA
# ============================================================

"""
Problema:
O Sistema Internacional pode enviar temperatura em Fahrenheit.
O Sistema de Saúde trabalha apenas com Celsius.

Se enviarmos apenas o número, o significado pode ser interpretado errado.

Aqui ocorre INTEROPERABILIDADE SEMÂNTICA,
pois estamos traduzindo o SIGNIFICADO do dado.
"""

def tradutor_universal(valor, unidade_origem):
    """
    Converte temperatura para Celsius se necessário.
    Garante que o Sistema de Saúde sempre receba dados padronizados.
    """

    print("\n======================================")
    print(f"Dado recebido: {valor}°{unidade_origem}")
    print("======================================")

    if unidade_origem.upper() == "F":
        # Conversão de Fahrenheit para Celsius
        valor_convertido = (valor - 32) * 5/9
        print(f"Convertendo de Fahrenheit para Celsius...")
        print(f"Valor convertido: {valor_convertido:.2f}°C")
        return valor_convertido, "C"

    elif unidade_origem.upper() == "C":
        print("Nenhuma conversão necessária.")
        return valor, "C"

    else:
        raise ValueError("Unidade desconhecida! Use 'C' ou 'F'.")


# ------------------------------------------------------------
# Simulação de envio para Sistema de Saúde
# ------------------------------------------------------------
def enviar_para_sistema_saude(valor, unidade):
    print("\nEnviando para Sistema de Saúde...")
    print(f"Temperatura registrada: {valor:.2f}°{unidade}")
    print("Interoperabilidade semântica garantida.\n")


if __name__ == "__main__":

    # Cenário 1 — Dado já em Celsius
    valor1, unidade1 = tradutor_universal(37, "C")
    enviar_para_sistema_saude(valor1, unidade1)

    # Cenário 2 — Dado em Fahrenheit (precisa conversão)
    valor2, unidade2 = tradutor_universal(100, "F")
    enviar_para_sistema_saude(valor2, unidade2)