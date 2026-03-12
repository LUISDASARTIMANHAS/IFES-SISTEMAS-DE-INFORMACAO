# lab3/legacy_systems.py
from integrador_esb import IntegradorESB

# ============================================================
# LABORATÓRIO 3 - PARTE 1
# DESAFIO DAS ILHAS DE DADOS
# ============================================================

"""
Este script demonstra um problema clássico de integração:
Dois sistemas legados que utilizam estruturas de dados diferentes
e não conseguem se comunicar diretamente.

Aqui ocorre um problema de INTEROPERABILIDADE TÉCNICA,
pois os formatos das chaves são incompatíveis.
"""

# ------------------------------------------------------------
# Sistema A: Ilha de Dados de RH
# ------------------------------------------------------------
# Estrutura utilizada pelo setor de Recursos Humanos
funcionario_rh = {
    "id_func": 101,
    "nome_completo": "Eduardo Amaral",
    "salario_base": 5000.00,
}


# ------------------------------------------------------------
# Sistema B: Ilha de Dados Financeira
# ------------------------------------------------------------
# Este sistema espera campos com nomes diferentes:
# 'cod' e 'valor'
def processar_pagamento(dados_pagamento):
    """
    Sistema financeiro que processa pagamentos.
    Ele falha se as chaves esperadas não existirem.
    """
    try:
        print(
            f"Processando ID {dados_pagamento['cod']}: Valor R$ {dados_pagamento['valor']}"
        )
    except KeyError as e:
        print(f"ERRO DE INTEROPERABILIDADE: Chave não encontrada {e}")


# ------------------------------------------------------------
# Tentativa de integração direta (VAI FALHAR)
# ------------------------------------------------------------
if __name__ == "__main__":
    print("\nTentando integrar Sistema RH com Sistema Financeiro...\n")
    dados_convertidos = IntegradorESB.transformar_rh_para_financeiro(funcionario_rh)
    processar_pagamento(dados_convertidos)  # Agora funciona!
