# lab3/padronizacao_eping.py
# ============================================================
# LABORATÓRIO 3 - PARTE 5
# GOVERNANÇA E PADRONIZAÇÃO (ePING)
# ============================================================

"""
Problema:
O Ministério da Fazenda usa CPF com pontos e traços.
O Ministério da Saúde exige CPF apenas numérico.

Sem padronização, os sistemas não conseguem cruzar dados.

Aqui ocorre INTEROPERABILIDADE ORGANIZACIONAL,
pois estamos aplicando um contrato institucional de dados.
"""

import re


def normalizar_cadastro(dados_origem):
    """
    Gateway de Integração (ESB Governamental).
    Garante que os dados sigam o contrato organizacional.
    """

    print("\n======================================")
    print("DADOS ORIGINAIS RECEBIDOS")
    print("======================================")
    print(dados_origem)

    # Remover caracteres especiais do CPF
    cpf_limpo = re.sub(r'\D', '', dados_origem["cpf"])

    # Nome em maiúsculas (padrão de sistemas legados)
    nome_padronizado = dados_origem["nome"].upper()

    dados_padronizados = {
        "cpf": cpf_limpo,
        "nome": nome_padronizado,
        "origem_validada": True
    }

    print("\n======================================")
    print("DADOS PADRONIZADOS (CONTRATO ePING)")
    print("======================================")
    print(dados_padronizados)

    return dados_padronizados


# ------------------------------------------------------------
# Simulação de integração entre Ministérios
# ------------------------------------------------------------
if __name__ == "__main__":

    # Dados vindos da Fazenda
    dados_fazenda = {
        "cpf": "123.456.789-00",
        "nome": "Eduardo Amaral"
    }

    dados_normalizados = normalizar_cadastro(dados_fazenda)