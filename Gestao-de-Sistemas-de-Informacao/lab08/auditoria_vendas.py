"""Laboratorio 8 - Auditoria de Sistemas.

Script principal para auditar a base ``log_vendas.csv`` e gerar evidencias
textuais e graficas para o relatorio em notebook/PDF.
"""

from __future__ import annotations

import os
from pathlib import Path


BASE_DIR = Path(__file__).resolve().parent
os.environ.setdefault("MPLCONFIGDIR", str(BASE_DIR / ".matplotlib"))

import matplotlib.pyplot as plt
import pandas as pd


ARQUIVO_CSV = BASE_DIR / "log_vendas.csv"
PASTA_SAIDA = BASE_DIR / "saidas"


def carregar_base(caminho_csv: Path) -> pd.DataFrame:
    """Carrega a base original e adiciona a coluna numerica derivada."""
    df = pd.read_csv(caminho_csv)
    df["valor_numerico"] = pd.to_numeric(df["valor"], errors="coerce")
    return df


def identificar_falhas_nulos(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna registros cujo campo ``valor`` esta vazio."""
    return df[df["valor"].isna()].copy()


def identificar_falhas_negativos(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna registros com valor monetario menor que zero."""
    return df[df["valor_numerico"] < 0].copy()


def identificar_duplicidades(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna transacoes com o mesmo ID repetido."""
    mascara = df["id_transacao"].duplicated(keep=False)
    return df[mascara].sort_values("id_transacao").copy()


def identificar_valores_invalidos(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna valores nao vazios que nao puderam ser convertidos em numero."""
    mascara = df["valor"].notna() & df["valor_numerico"].isna()
    return df[mascara].copy()


def contar_valores_nao_numericos(df: pd.DataFrame) -> int:
    """Soma registros com ``valor`` vazio ou invalido para conversao numerica."""
    return len(identificar_falhas_nulos(df)) + len(identificar_valores_invalidos(df))


def identificar_campos_obrigatorios_ausentes(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna registros com cliente ou metodo de pagamento ausentes."""
    mascara = df["cliente"].isna() | df["metodo_pagamento"].isna()
    return df[mascara].copy()


def montar_resumo_principal(df: pd.DataFrame) -> pd.DataFrame:
    """Monta o resumo exigido pelo roteiro do laboratorio."""
    resumo = {
        "Nulos": len(identificar_falhas_nulos(df)),
        "Invalidos": len(identificar_valores_invalidos(df)),
        "Negativos": len(identificar_falhas_negativos(df)),
        "Duplicados": len(identificar_duplicidades(df)),
    }
    return pd.DataFrame(
        {"categoria": list(resumo.keys()), "quantidade": list(resumo.values())}
    )


def montar_resumo_complementar(df: pd.DataFrame) -> pd.DataFrame:
    """Consolida problemas adicionais encontrados na base."""
    resumo = {
        "Cliente ausente": int(df["cliente"].isna().sum()),
        "Metodo ausente": int(df["metodo_pagamento"].isna().sum()),
    }
    return pd.DataFrame(
        {"categoria": list(resumo.keys()), "quantidade": list(resumo.values())}
    )


def gerar_grafico(resumo: pd.DataFrame, caminho_saida: Path) -> Path:
    """Gera o grafico de barras principal da auditoria."""
    plt.style.use("ggplot")
    fig, ax = plt.subplots(figsize=(10, 5))
    cores = ["#1f77b4", "#ff7f0e", "#d62728", "#2ca02c"]
    barras = ax.bar(
        resumo["categoria"],
        resumo["quantidade"],
        color=cores[: len(resumo)],
    )
    ax.set_title("Auditoria do Sistema de Vendas - Ocorrencias por Categoria")
    ax.set_xlabel("Categoria de erro")
    ax.set_ylabel("Quantidade de registros")
    ax.set_ylim(0, max(resumo["quantidade"].max(), 1) + 12)
    ax.tick_params(axis="x", labelrotation=10)

    for barra in barras:
        altura = int(barra.get_height())
        ax.text(
            barra.get_x() + barra.get_width() / 2,
            altura + 0.6,
            str(altura),
            ha="center",
            va="bottom",
            fontsize=10,
            fontweight="bold",
        )

    fig.tight_layout()
    caminho_saida.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(caminho_saida, dpi=150, bbox_inches="tight")
    plt.close(fig)
    return caminho_saida


def salvar_evidencias(df: pd.DataFrame, pasta_saida: Path) -> dict[str, Path]:
    """Salva os recortes usados na auditoria para consulta posterior."""
    pasta_saida.mkdir(parents=True, exist_ok=True)

    arquivos = {
        "falhas_nulos": pasta_saida / "falhas_valor_nulo.csv",
        "falhas_negativos": pasta_saida / "falhas_valor_negativo.csv",
        "falhas_duplicados": pasta_saida / "falhas_id_duplicado.csv",
        "falhas_invalidos": pasta_saida / "falhas_valor_invalido.csv",
        "falhas_campos_obrigatorios": pasta_saida / "falhas_campos_obrigatorios.csv",
        "resumo_principal": pasta_saida / "resumo_principal.csv",
        "resumo_complementar": pasta_saida / "resumo_complementar.csv",
    }

    identificar_falhas_nulos(df).to_csv(arquivos["falhas_nulos"], index=False)
    identificar_falhas_negativos(df).to_csv(arquivos["falhas_negativos"], index=False)
    identificar_duplicidades(df).to_csv(arquivos["falhas_duplicados"], index=False)
    identificar_valores_invalidos(df).to_csv(arquivos["falhas_invalidos"], index=False)
    identificar_campos_obrigatorios_ausentes(df).to_csv(
        arquivos["falhas_campos_obrigatorios"], index=False
    )
    montar_resumo_principal(df).to_csv(arquivos["resumo_principal"], index=False)
    montar_resumo_complementar(df).to_csv(arquivos["resumo_complementar"], index=False)

    return arquivos


def gerar_relatorio_gerencial(
    resumo_principal: pd.DataFrame, resumo_complementar: pd.DataFrame
) -> str:
    """Produz um parecer curto para ser usado na conclusao do notebook."""
    descricao_principal = {
        "Nulos": "registros com valor nulo",
        "Invalidos": "registros com valor invalido",
        "Negativos": "registros com valor negativo",
        "Duplicados": "IDs de transacao duplicados",
    }
    descricao_complementar = {
        "Cliente ausente": "cliente ausente",
        "Metodo ausente": "metodo de pagamento ausente",
    }
    problema_principal = resumo_principal.sort_values(
        "quantidade", ascending=False
    ).iloc[0]
    problema_complementar = resumo_complementar.sort_values(
        "quantidade", ascending=False
    ).iloc[0]
    valores_nao_numericos = int(
        resumo_principal.loc[
            resumo_principal["categoria"].isin(["Nulos", "Invalidos"]), "quantidade"
        ].sum()
    )
    problema_principal_texto = descricao_principal.get(
        problema_principal["categoria"], problema_principal["categoria"].lower()
    )
    problema_complementar_texto = descricao_complementar.get(
        problema_complementar["categoria"], problema_complementar["categoria"].lower()
    )

    return (
        "O problema mais critico do sistema, considerando as validacoes exigidas "
        f"no roteiro, sao os {problema_principal_texto} "
        f"({int(problema_principal['quantidade'])} ocorrencias). Somando nulos e "
        f"invalidos, ha {valores_nao_numericos} registros cujo campo valor nao se "
        "tornou numerico. Como achado complementar, a base tambem possui "
        f"{int(problema_complementar['quantidade'])} ocorrencias de "
        f"{problema_complementar_texto}, o que indica ausencia de validacao de "
        "entrada no cadastro de vendas. A recomendacao para a TI e "
        "implantar validacoes obrigatorias no momento da gravacao, bloquear "
        "valores negativos e textos no campo valor, registrar logs de erro e criar "
        "rotinas periodicas de auditoria automatizada."
    )


def executar_auditoria(caminho_csv: Path = ARQUIVO_CSV, pasta_saida: Path = PASTA_SAIDA) -> dict:
    """Executa o fluxo completo da auditoria e devolve os artefatos principais."""
    df = carregar_base(caminho_csv)
    resumo_principal = montar_resumo_principal(df)
    resumo_complementar = montar_resumo_complementar(df)
    grafico = gerar_grafico(resumo_principal, pasta_saida / "grafico_auditoria.png")
    arquivos = salvar_evidencias(df, pasta_saida)

    return {
        "df": df,
        "resumo_principal": resumo_principal,
        "resumo_complementar": resumo_complementar,
        "valores_nao_numericos": contar_valores_nao_numericos(df),
        "grafico": grafico,
        "arquivos": arquivos,
        "relatorio_gerencial": gerar_relatorio_gerencial(
            resumo_principal, resumo_complementar
        ),
    }


def main() -> None:
    """Ponto de entrada em linha de comando."""
    resultado = executar_auditoria()
    df = resultado["df"]
    resumo_principal = resultado["resumo_principal"]
    resumo_complementar = resultado["resumo_complementar"]

    print("=" * 60)
    print("LABORATORIO 8 - AUDITORIA DE SISTEMAS")
    print("=" * 60)
    print(f"Arquivo analisado: {ARQUIVO_CSV.name}")
    print(f"Total de registros: {len(df)}")
    print()
    print("Resumo principal:")
    print(resumo_principal.to_string(index=False))
    print()
    print("Resumo complementar:")
    print(resumo_complementar.to_string(index=False))
    print()
    print(
        "Total de valores nao numericos (nulos + invalidos):",
        resultado["valores_nao_numericos"],
    )
    print()
    print("Exemplo de falhas de valor nulo:")
    print(identificar_falhas_nulos(df).head(5).to_string(index=False))
    print()
    print("Exemplo de falhas de valor negativo:")
    print(identificar_falhas_negativos(df).head(5).to_string(index=False))
    print()
    print("Exemplo de valores invalidos no campo valor:")
    print(identificar_valores_invalidos(df).head(5).to_string(index=False))
    print()
    print("Relatorio gerencial:")
    print(resultado["relatorio_gerencial"])
    print()
    print(f"Grafico salvo em: {resultado['grafico']}")
    print(f"Evidencias salvas em: {PASTA_SAIDA}")


if __name__ == "__main__":
    main()
