"""Laboratorio 9 - Auditoria avancada de seguranca e acesso.

Script principal para cruzar logs de autenticacao com a base de RH,
identificar anomalias de acesso e gerar artefatos para o relatorio final.
"""

from __future__ import annotations

import os
from pathlib import Path
from typing import Any


BASE_DIR = Path(__file__).resolve().parent
os.environ.setdefault("MPLCONFIGDIR", str(BASE_DIR / ".matplotlib"))

import matplotlib.pyplot as plt
import pandas as pd
from matplotlib.ticker import MaxNLocator


ARQUIVO_LOGS = BASE_DIR / "log_acessos_200_registros.csv"
ARQUIVO_RH = BASE_DIR / "usuarios_ativos_200_registros.csv"
PASTA_SAIDA = BASE_DIR / "saidas"

CATEGORIAS_CLASSIFICACAO = [
    "Acessos Autorizados",
    "Violacoes de Horario",
    "Usuarios Inexistentes/Inativos",
]


def carregar_logs(caminho_csv: Path) -> pd.DataFrame:
    """Carrega os logs e converte a data para ``datetime``."""
    df = pd.read_csv(caminho_csv)
    df["data_hora"] = pd.to_datetime(df["data_hora"])
    return df


def carregar_base_rh(caminho_csv: Path) -> pd.DataFrame:
    """Carrega a base de usuarios do RH."""
    return pd.read_csv(caminho_csv)


def cruzar_bases(logs: pd.DataFrame, rh: pd.DataFrame) -> pd.DataFrame:
    """Cruza logs com RH e adiciona flags operacionais para a auditoria."""
    df = logs.merge(rh, on="usuario", how="left", indicator=True)

    df["usuario_encontrado_rh"] = df["_merge"].eq("both")
    df["usuario_ativo"] = df["status_contrato"].eq("Ativo")
    df["fora_horario"] = (df["data_hora"].dt.hour < 8) | (
        df["data_hora"].dt.hour >= 18
    )
    df["ip_externo"] = ~df["ip_origem"].fillna("").astype(str).str.startswith("192.168")
    df = df.drop(columns=["_merge"])
    return df


def identificar_contas_orfas(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna acessos de usuarios que nao aparecem na base do RH."""
    return df[~df["usuario_encontrado_rh"]].copy()


def identificar_usuarios_inativos_ou_bloqueados(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna acessos de usuarios que existem no RH, mas nao estao ativos."""
    mascara = df["usuario_encontrado_rh"] & (~df["usuario_ativo"])
    return df[mascara].copy()


def identificar_acessos_irregulares_rh(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna acessos de usuarios ausentes no RH ou sem status ativo."""
    mascara = (~df["usuario_encontrado_rh"]) | (~df["usuario_ativo"])
    return df[mascara].copy()


def identificar_acessos_sucesso_irregulares_rh(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna acessos com sucesso por usuarios ausentes/inativos no RH."""
    mascara = df["status"].eq("Sucesso") & (
        (~df["usuario_encontrado_rh"]) | (~df["usuario_ativo"])
    )
    return df[mascara].copy()


def identificar_fora_horario(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna todos os acessos registrados fora do horario comercial."""
    return df[df["fora_horario"]].copy()


def identificar_ips_externos_sucesso(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna acessos bem-sucedidos originados fora da faixa interna."""
    mascara = df["status"].eq("Sucesso") & df["ip_externo"]
    return df[mascara].copy()


def identificar_acessos_autorizados(df: pd.DataFrame) -> pd.DataFrame:
    """Retorna acessos bem-sucedidos por usuarios ativos e em horario comercial."""
    mascara = df["status"].eq("Sucesso") & df["usuario_ativo"] & (~df["fora_horario"])
    return df[mascara].copy()


def classificar_acessos_sucesso(df: pd.DataFrame) -> pd.DataFrame:
    """Classifica cada acesso bem-sucedido em uma categoria exclusiva."""
    sucessos = df[df["status"].eq("Sucesso")].copy()
    sucessos["classificacao"] = "Usuarios Inexistentes/Inativos"

    mascara_ativos = sucessos["usuario_ativo"]
    sucessos.loc[
        mascara_ativos & (~sucessos["fora_horario"]), "classificacao"
    ] = "Acessos Autorizados"
    sucessos.loc[
        mascara_ativos & sucessos["fora_horario"], "classificacao"
    ] = "Violacoes de Horario"
    return sucessos


def montar_resumo_classificacao(df: pd.DataFrame) -> pd.DataFrame:
    """Resume a classificacao exclusiva usada no grafico de pizza."""
    classificados = classificar_acessos_sucesso(df)
    contagens = (
        classificados["classificacao"]
        .value_counts()
        .reindex(CATEGORIAS_CLASSIFICACAO, fill_value=0)
    )
    return pd.DataFrame(
        {"categoria": list(contagens.index), "quantidade": list(contagens.values)}
    )


def montar_resumo_incidentes(df: pd.DataFrame) -> pd.DataFrame:
    """Resume os principais incidentes apurados na auditoria."""
    resumo = {
        "Contas Orfas": len(identificar_contas_orfas(df)),
        "Usuarios Inativos/Bloqueados": len(identificar_usuarios_inativos_ou_bloqueados(df)),
        "Acessos Fora do Horario": len(identificar_fora_horario(df)),
        "IPs Externos com Sucesso": len(identificar_ips_externos_sucesso(df)),
        "Acessos Autorizados": len(identificar_acessos_autorizados(df)),
    }
    return pd.DataFrame(
        {"categoria": list(resumo.keys()), "quantidade": list(resumo.values())}
    )


def montar_ranking_usuarios_risco(df: pd.DataFrame) -> pd.DataFrame:
    """Consolida indicadores por usuario para priorizacao operacional."""
    base = (
        df.assign(
            sucesso=df["status"].eq("Sucesso").astype(int),
            sucesso_fora_horario=(
                df["status"].eq("Sucesso") & df["fora_horario"]
            ).astype(int),
            sucesso_ip_externo=(
                df["status"].eq("Sucesso") & df["ip_externo"]
            ).astype(int),
        )
        .groupby("usuario", as_index=False)[
            ["sucesso", "sucesso_fora_horario", "sucesso_ip_externo"]
        ]
        .sum()
        .sort_values(
            ["sucesso_fora_horario", "sucesso_ip_externo", "sucesso"],
            ascending=False,
        )
    )
    return base


def _autopct_com_absoluto(valores: list[int]):
    total = max(sum(valores), 1)

    def formatador(pct: float) -> str:
        absoluto = int(round((pct / 100.0) * total))
        if absoluto == 0:
            return ""
        return f"{pct:.1f}%\n({absoluto})"

    return formatador


def _montar_resumo_numerico_pizza(resumo_classificacao: pd.DataFrame) -> str:
    """Monta um quadro textual com contagens e percentuais da pizza."""
    total = max(int(resumo_classificacao["quantidade"].sum()), 1)
    linhas = ["Resumo numerico"]

    for linha in resumo_classificacao.itertuples(index=False):
        percentual = (int(linha.quantidade) / total) * 100
        linhas.append(
            f"{linha.categoria}: {int(linha.quantidade)} ({percentual:.1f}%)"
        )

    return "\n".join(linhas)


def gerar_dashboard_visual(
    resumo_classificacao: pd.DataFrame,
    resumo_incidentes: pd.DataFrame,
    caminho_saida: Path,
    total_acessos: int | None = None,
) -> Path:
    """Gera um dashboard simples com pizza e barras."""
    fig, axes = plt.subplots(1, 2, figsize=(16, 7))

    total_acessos = total_acessos or 0
    resumo_pizza = resumo_classificacao[
        resumo_classificacao["quantidade"] > 0
    ].copy()
    total_sucessos = int(resumo_classificacao["quantidade"].sum())

    if resumo_pizza.empty:
        resumo_pizza = pd.DataFrame(
            {"categoria": ["Sem acessos com sucesso"], "quantidade": [1]}
        )

    valores_pizza = resumo_pizza["quantidade"].tolist()
    cores_pizza = ["#2f7ed8", "#f45b5b", "#f7a35c"]
    wedges, _, autotextos = axes[0].pie(
        valores_pizza,
        autopct=_autopct_com_absoluto(valores_pizza),
        startangle=90,
        colors=cores_pizza[: len(valores_pizza)],
        pctdistance=0.72,
        wedgeprops={"width": 0.58, "edgecolor": "white"},
        textprops={"fontsize": 11, "fontweight": "bold"},
    )
    axes[0].set_title("Classificacao dos acessos com sucesso")
    axes[0].text(
        0,
        0,
        f"{total_sucessos}\nacessos\ncom sucesso",
        ha="center",
        va="center",
        fontsize=12,
        fontweight="bold",
    )
    axes[0].text(
        1.02,
        0.5,
        _montar_resumo_numerico_pizza(resumo_classificacao),
        transform=axes[0].transAxes,
        ha="left",
        va="center",
        fontsize=10.5,
        bbox={"boxstyle": "round,pad=0.5", "facecolor": "#f7f7f7", "edgecolor": "#cfcfcf"},
    )

    for texto in autotextos:
        if texto.get_text():
            texto.set_color("#111111")

    resumo_barras = resumo_incidentes[
        resumo_incidentes["categoria"].isin(
            ["Contas Orfas", "Acessos Fora do Horario", "IPs Externos com Sucesso"]
        )
    ]
    categorias_exibicao = [
        "Contas\nOrfas",
        "Acessos fora\ndo horario",
        "IPs externos\ncom sucesso",
    ]
    barras = axes[1].bar(
        categorias_exibicao,
        resumo_barras["quantidade"],
        color=["#7cb5ec", "#434348", "#90ed7d"],
    )
    axes[1].set_title("Incidentes criticos identificados")
    axes[1].set_ylabel("Quantidade de acessos")
    axes[1].tick_params(axis="x", rotation=0, labelsize=11)
    axes[1].set_ylim(0, max(resumo_barras["quantidade"].max(), 1) + 15)
    axes[1].yaxis.set_major_locator(MaxNLocator(integer=True))
    axes[1].grid(axis="y", linestyle="--", alpha=0.3)
    axes[1].set_axisbelow(True)
    axes[1].text(
        0.98,
        0.96,
        f"Base analisada: {total_acessos} acessos",
        transform=axes[1].transAxes,
        ha="right",
        va="top",
        fontsize=10,
        bbox={"boxstyle": "round,pad=0.35", "facecolor": "#f7f7f7", "edgecolor": "#cfcfcf"},
    )

    for barra in barras:
        altura = int(barra.get_height())
        percentual = (altura / total_acessos * 100) if total_acessos else 0
        axes[1].text(
            barra.get_x() + barra.get_width() / 2,
            altura + 1,
            f"{altura}\n{percentual:.1f}%",
            ha="center",
            va="bottom",
            fontsize=10,
            fontweight="bold",
        )

    fig.suptitle("Laboratorio 9 - Dashboard de riscos de seguranca", fontsize=14)
    fig.subplots_adjust(wspace=0.42)
    fig.tight_layout()
    caminho_saida.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(caminho_saida, dpi=150, bbox_inches="tight")
    plt.close(fig)
    return caminho_saida


def salvar_evidencias(df: pd.DataFrame, pasta_saida: Path) -> dict[str, Path]:
    """Salva recortes e resumos usados no relatorio."""
    pasta_saida.mkdir(parents=True, exist_ok=True)
    arquivos = {
        "contas_orfas": pasta_saida / "acessos_contas_orfas.csv",
        "usuarios_irregulares_rh": pasta_saida / "acessos_usuarios_irregulares_rh.csv",
        "fora_horario": pasta_saida / "acessos_fora_horario.csv",
        "ips_externos_sucesso": pasta_saida / "acessos_ips_externos_sucesso.csv",
        "resumo_classificacao": pasta_saida / "resumo_classificacao.csv",
        "resumo_incidentes": pasta_saida / "resumo_incidentes.csv",
        "ranking_usuarios": pasta_saida / "ranking_usuarios_risco.csv",
    }

    identificar_contas_orfas(df).to_csv(arquivos["contas_orfas"], index=False)
    identificar_acessos_irregulares_rh(df).to_csv(
        arquivos["usuarios_irregulares_rh"], index=False
    )
    identificar_fora_horario(df).to_csv(arquivos["fora_horario"], index=False)
    identificar_ips_externos_sucesso(df).to_csv(
        arquivos["ips_externos_sucesso"], index=False
    )
    montar_resumo_classificacao(df).to_csv(
        arquivos["resumo_classificacao"], index=False
    )
    montar_resumo_incidentes(df).to_csv(arquivos["resumo_incidentes"], index=False)
    montar_ranking_usuarios_risco(df).to_csv(arquivos["ranking_usuarios"], index=False)
    return arquivos


def gerar_analise_critica(df: pd.DataFrame) -> str:
    """Responde a pergunta critica exigida no roteiro."""
    total_sucesso_irregular = len(identificar_acessos_sucesso_irregulares_rh(df))
    return (
        "A presenca de acessos com sucesso de usuarios fora da base do RH indica "
        "uma falha especifica no processo de offboarding e deprovisionamento de "
        "contas no IAM. Em termos praticos, a empresa nao esta reconciliando "
        "corretamente os eventos de desligamento do RH com a revogacao de acesso "
        "nos sistemas, o que mantem credenciais obsoletas ativas. Nesta base, "
        f"isso aparece em {total_sucesso_irregular} acessos com sucesso por "
        "usuarios sem correspondencia valida no cadastro de pessoal."
    )


def gerar_sugestao_controle(df: pd.DataFrame) -> str:
    """Descreve como um dashboard em tempo real pode mitigar os riscos."""
    total_fora_horario = len(identificar_fora_horario(df))
    total_ips_externos = len(identificar_ips_externos_sucesso(df))
    total_orfas = len(identificar_contas_orfas(df))
    return (
        "Um dashboard de BI em tempo real mitigaria esses riscos ao cruzar "
        "continuamente eventos de login com a base do RH e ao disparar alertas "
        "automaticos para tres sinais criticos: contas orfas, acessos fora do "
        "horario e IPs externos com sucesso. Nesta auditoria, o painel precisaria "
        f"destacar {total_orfas} acessos sem correspondencia no RH, "
        f"{total_fora_horario} acessos fora do horario comercial e "
        f"{total_ips_externos} acessos externos com sucesso, permitindo bloqueio "
        "preventivo, abertura de incidente e acompanhamento da equipe de seguranca "
        "quase em tempo real."
    )


def executar_auditoria(
    caminho_logs: Path = ARQUIVO_LOGS,
    caminho_rh: Path = ARQUIVO_RH,
    pasta_saida: Path = PASTA_SAIDA,
) -> dict[str, Any]:
    """Executa o fluxo completo da auditoria."""
    if not caminho_logs.exists():
        raise FileNotFoundError(f"Arquivo de logs nao encontrado: {caminho_logs}")
    if not caminho_rh.exists():
        raise FileNotFoundError(f"Arquivo de RH nao encontrado: {caminho_rh}")
    logs = carregar_logs(caminho_logs)
    rh = carregar_base_rh(caminho_rh)
    cruzado = cruzar_bases(logs, rh)
    resumo_classificacao = montar_resumo_classificacao(cruzado)
    resumo_incidentes = montar_resumo_incidentes(cruzado)
    dashboard = gerar_dashboard_visual(
        resumo_classificacao,
        resumo_incidentes,
        pasta_saida / "dashboard_riscos.png",
        total_acessos=len(cruzado),
    )
    arquivos = salvar_evidencias(cruzado, pasta_saida)

    return {
        "logs": logs,
        "rh": rh,
        "cruzado": cruzado,
        "resumo_classificacao": resumo_classificacao,
        "resumo_incidentes": resumo_incidentes,
        "dashboard": dashboard,
        "arquivos": arquivos,
        "analise_critica": gerar_analise_critica(cruzado),
        "sugestao_controle": gerar_sugestao_controle(cruzado),
    }


def main() -> None:
    """Ponto de entrada do script em linha de comando."""
    resultado = executar_auditoria()
    cruzado = resultado["cruzado"]
    resumo_classificacao = resultado["resumo_classificacao"]
    resumo_incidentes = resultado["resumo_incidentes"]

    print("=" * 64)
    print("LABORATORIO 9 - AUDITORIA AVANCADA DE SEGURANCA E ACESSO")
    print("=" * 64)
    print(f"Arquivo de logs: {ARQUIVO_LOGS.name}")
    print(f"Arquivo do RH:   {ARQUIVO_RH.name}")
    print(f"Total de acessos analisados: {len(cruzado)}")
    print(f"Usuarios distintos no log: {cruzado['usuario'].nunique()}")
    print()
    print("Resumo de classificacao dos acessos com sucesso:")
    print(resumo_classificacao.to_string(index=False))
    print()
    print("Resumo consolidado de incidentes:")
    print(resumo_incidentes.to_string(index=False))
    print()
    print("Amostra - contas orfas:")
    print(identificar_contas_orfas(cruzado).head(5).to_string(index=False))
    print()
    print("Amostra - acessos fora do horario:")
    print(identificar_fora_horario(cruzado).head(5).to_string(index=False))
    print()
    print("Amostra - IPs externos com sucesso:")
    print(identificar_ips_externos_sucesso(cruzado).head(5).to_string(index=False))
    print()
    print("Analise critica:")
    print(resultado["analise_critica"])
    print()
    print("Sugestao de controle:")
    print(resultado["sugestao_controle"])
    print()
    print(f"Dashboard salvo em: {resultado['dashboard']}")
    print(f"Evidencias salvas em: {PASTA_SAIDA}")


if __name__ == "__main__":
    main()
