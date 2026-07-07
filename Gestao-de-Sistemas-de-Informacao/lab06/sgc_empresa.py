"""Laboratorio 6 - Sistema de Gestao do Conhecimento (SGC).

Este modulo concentra as funcoes principais usadas pelos scripts e pelo notebook.
"""

from __future__ import annotations

import json
from pathlib import Path
from typing import Any


BASE_JSON = Path(__file__).with_name("base_conhecimento.json")


def carregar_base() -> list[dict[str, Any]]:
    """Retorna a base inicial com o conhecimento explicito ja codificado."""
    return [
        {
            "id": "K001",
            "categoria": "Infraestrutura",
            "titulo": "Lentidao ERP Segundas-feiras",
            "causa": "Conflito entre relatorio financeiro e backup_sync",
            "solucao": "Pausar 'Backup_Sync' no console, aguardar 5min e dar Resume.",
            "especialista": "Sr. Carlos (Senior)",
        }
    ]


def converter_tacito_para_explicito() -> dict[str, str]:
    """Estrutura o relato do especialista em formato de POP."""
    return {
        "titulo_problema": "Lentidao no ERP as segundas-feiras",
        "causa_raiz_identificada": (
            "Execucao simultanea do relatorio financeiro com o servico "
            "'Backup_Sync', causando competicao por recursos."
        ),
        "passo_a_passo_solucao": (
            "1. Abrir o console do servidor.\n"
            "2. Pausar o servico 'Backup_Sync'.\n"
            "3. Aguardar 5 minutos para aliviar o conflito.\n"
            "4. Executar o comando 'Resume' no servico.\n"
            "5. Validar se o ERP voltou ao desempenho normal."
        ),
        "indicador_erro_critico_fisico": (
            "Se a luz do rack estiver vermelha, o problema e fisico e o cabo deve ser trocado."
        ),
    }


def adicionar_conhecimento(
    base: list[dict[str, Any]],
    id_conhecimento: str,
    categoria: str,
    titulo: str,
    causa: str,
    solucao: str,
    especialista: str,
) -> dict[str, Any]:
    """Adiciona um conhecimento a base e retorna o registro criado."""
    registro = {
        "id": id_conhecimento,
        "categoria": categoria,
        "titulo": titulo,
        "causa": causa,
        "solucao": solucao,
        "especialista": especialista,
    }
    base.append(registro)
    return registro


def buscar_conhecimento(base: list[dict[str, Any]], termo: str) -> list[dict[str, Any]]:
    """Busca conhecimentos por titulo, causa ou solucao."""
    termo_normalizado = termo.lower()
    return [
        conhecimento
        for conhecimento in base
        if termo_normalizado in conhecimento["titulo"].lower()
        or termo_normalizado in conhecimento["causa"].lower()
        or termo_normalizado in conhecimento["solucao"].lower()
    ]


def diagnostico_servidor(temperatura: float) -> str:
    """Aplica um motor de regras simples sobre a temperatura do servidor."""
    if temperatura >= 37.0:
        return "CRITICO: Acionar manutencao (Regra K003)."
    if 35.0 <= temperatura < 37.0:
        return "ALERTA: Monitoramento intensivo necessario."
    return "NORMAL: Operacao estavel."


def salvar_base_json(base: list[dict[str, Any]], caminho: Path | None = None) -> Path:
    """Persiste a base de conhecimento em JSON."""
    destino = caminho or BASE_JSON
    destino.write_text(
        json.dumps(base, indent=2, ensure_ascii=False),
        encoding="utf-8",
    )
    return destino


def carregar_base_json(caminho: Path | None = None) -> list[dict[str, Any]]:
    """Carrega uma base persistida em JSON."""
    origem = caminho or BASE_JSON
    return json.loads(origem.read_text(encoding="utf-8"))


def montar_base_exemplo() -> list[dict[str, Any]]:
    """Cria a base completa usada nos exemplos do laboratorio."""
    base = carregar_base()
    adicionar_conhecimento(
        base=base,
        id_conhecimento="K002",
        categoria="Infraestrutura",
        titulo="Falha fisica no rack",
        causa="Luz vermelha no rack indica cabo defeituoso",
        solucao="Trocar o cabo de conexao e validar o status luminoso do rack.",
        especialista="Sr. Carlos (Senior)",
    )
    adicionar_conhecimento(
        base=base,
        id_conhecimento="K003",
        categoria="Monitoramento",
        titulo="Temperatura elevada do servidor",
        causa="Aumento de temperatura acima do padrao operacional",
        solucao="Aplicar o motor de regras conforme a faixa de temperatura.",
        especialista="Sistema especialista simples",
    )
    return base


if __name__ == "__main__":
    base = montar_base_exemplo()
    salvar_base_json(base)

    print("POP gerado a partir do conhecimento tacito:\n")
    for chave, valor in converter_tacito_para_explicito().items():
        print(f"{chave}:")
        print(valor)
        print()

    print("Resultados da busca por 'backup':")
    for item in buscar_conhecimento(base, "backup"):
        print(f"- {item['id']} | {item['titulo']}")

    print("\nDiagnostico para 36.5C:")
    print(diagnostico_servidor(36.5))
