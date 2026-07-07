"""
Monitor de SLA - TechStore S.A.
Disciplina: Gestão de Sistemas de Informação
Tema: Governança de TI / ITIL

Audita chamados de suporte técnico verificando conformidade com o SLA.
"""

import random
import sys
import matplotlib.pyplot as plt
import pandas as pd
sys.stdout.reconfigure(encoding='utf-8')

# ---------------------------------------------------------------------------
# Constantes
# ---------------------------------------------------------------------------

RANDOM_SEED: int = 42
N_CHAMADOS: int = 20
ID_INICIAL: int = 1001
META_SLA_ALTA: float = 2.0      # horas — definida no SLA da TechStore S.A.
META_SLA_MEDIA: float = 8.0     # horas
META_SLA_BAIXA: float = 24.0    # horas

PRIORIDADES: list[str] = ["Alta", "Media", "Baixa"]

METAS_POR_PRIORIDADE: dict[str, float] = {
    "Alta":  META_SLA_ALTA,
    "Media": META_SLA_MEDIA,
    "Baixa": META_SLA_BAIXA,
}

CORES_PRIORIDADE: dict[str, str] = {
    "Alta":  "#e74c3c",
    "Media": "#f39c12",
    "Baixa": "#2ecc71",
}


# ---------------------------------------------------------------------------
# Geração de dados
# ---------------------------------------------------------------------------

def gerar_log_chamados(n: int, seed: int = RANDOM_SEED) -> pd.DataFrame:
    """
    Gera um DataFrame com chamados fictícios de suporte técnico.

    @param n    Quantidade de chamados a gerar.
    @param seed Semente para reprodutibilidade.
    @return     DataFrame com colunas: ticket_id, prioridade,
                tempo_resolucao_horas.
    """
    random.seed(seed)

    dados = {
        "ticket_id": range(ID_INICIAL, ID_INICIAL + n),
        "prioridade": [random.choice(PRIORIDADES) for _ in range(n)],
        "tempo_resolucao_horas": [
            round(random.uniform(0.5, 5.0), 1) for _ in range(n)
        ],
    }

    return pd.DataFrame(dados)


# ---------------------------------------------------------------------------
# Auditoria
# ---------------------------------------------------------------------------

def auditar_sla(df: pd.DataFrame) -> pd.DataFrame:
    """
    Identifica registros que violam a meta de SLA para cada prioridade.

    @param df DataFrame com colunas ticket_id, prioridade e
              tempo_resolucao_horas.
    @return   DataFrame contendo apenas os chamados em não-conformidade,
              acrescido das colunas 'meta_horas' e 'excesso_horas'.
    """
    df = df.copy()
    df["meta_horas"] = df["prioridade"].map(METAS_POR_PRIORIDADE)
    df["excesso_horas"] = (df["tempo_resolucao_horas"] - df["meta_horas"]).round(1)

    violacoes = df[df["tempo_resolucao_horas"] > df["meta_horas"]].copy()
    return violacoes


def exibir_relatorio(df_log: pd.DataFrame, violacoes: pd.DataFrame) -> None:
    """
    Imprime o relatório de auditoria no terminal.

    @param df_log    DataFrame completo de chamados.
    @param violacoes DataFrame filtrado com as não-conformidades.
    @return None
    """
    separador = "=" * 55

    print(separador)
    print("  LOG COMPLETO DE INCIDENTES — TECHSTORE S.A.")
    print(separador)
    print(df_log.to_string(index=False))

    print(f"\n{separador}")
    print("  RELATÓRIO DE GOVERNANÇA — VIOLAÇÕES DE SLA")
    print(separador)
    print("  Metas definidas no SLA:")
    for prioridade, meta in METAS_POR_PRIORIDADE.items():
        print(f"    • {prioridade:<6} → até {meta:.0f}h")
    print(separador)

    if violacoes.empty:
        print("  ✔  Nenhuma violação de conformidade detectada.")
    else:
        print(violacoes[
            ["ticket_id", "prioridade", "tempo_resolucao_horas",
             "meta_horas", "excesso_horas"]
        ].to_string(index=False))
        print(f"\n  Total de não-conformidades: {len(violacoes)}")
        taxa = len(violacoes) / len(df_log) * 100
        print(f"  Taxa de violação geral:     {taxa:.1f}%")

    print(separador)


# ---------------------------------------------------------------------------
# Visualização
# ---------------------------------------------------------------------------

def gerar_graficos(df_log: pd.DataFrame, violacoes: pd.DataFrame) -> None:
    """
    Gera dois gráficos: dispersão dos tempos por chamado e
    comparativo de conformidade x violação por prioridade.

    @param df_log    DataFrame completo de chamados.
    @param violacoes DataFrame das não-conformidades.
    @return None
    """
    fig, axes = plt.subplots(1, 2, figsize=(13, 5))
    fig.suptitle("Monitor de SLA — TechStore S.A.", fontsize=14, fontweight="bold")

    # --- Gráfico 1: tempo de resolução por chamado, colorido por prioridade ---
    ax1 = axes[0]
    for prioridade in PRIORIDADES:
        subset = df_log[df_log["prioridade"] == prioridade]
        ax1.scatter(
            subset["ticket_id"],
            subset["tempo_resolucao_horas"],
            label=prioridade,
            color=CORES_PRIORIDADE[prioridade],
            zorder=3,
            s=60,
        )

    # Linha de meta SLA (Alta) — foco da atividade
    ax1.axhline(
        META_SLA_ALTA,
        color=CORES_PRIORIDADE["Alta"],
        linestyle="--",
        linewidth=1.2,
        label=f"Meta Alta ({META_SLA_ALTA}h)",
    )

    ax1.set_title("Tempo de Resolução por Chamado")
    ax1.set_xlabel("Ticket ID")
    ax1.set_ylabel("Horas")
    ax1.legend(fontsize=8)
    ax1.grid(True, linestyle="--", alpha=0.5)

    # --- Gráfico 2: conformidade x violação por prioridade (barras empilhadas) ---
    ax2 = axes[1]
    resumo: dict[str, dict[str, int]] = {}

    for prioridade in PRIORIDADES:
        total = len(df_log[df_log["prioridade"] == prioridade])
        viol = len(violacoes[violacoes["prioridade"] == prioridade])
        resumo[prioridade] = {"Conformes": total - viol, "Violações": viol}

    labels = list(resumo.keys())
    conformes = [resumo[p]["Conformes"] for p in labels]
    violados = [resumo[p]["Violações"] for p in labels]

    x = range(len(labels))
    ax2.bar(x, conformes, label="Conformes", color="#27ae60")
    ax2.bar(x, violados, bottom=conformes, label="Violações", color="#c0392b")

    ax2.set_xticks(list(x))
    ax2.set_xticklabels(labels)
    ax2.set_title("Conformidade por Prioridade")
    ax2.set_ylabel("Qtd. de Chamados")
    ax2.legend(fontsize=8)
    ax2.grid(axis="y", linestyle="--", alpha=0.5)

    plt.tight_layout()
    plt.savefig("relatorio_sla.png", dpi=150)
    plt.show()
    print("\n  Gráfico salvo em: relatorio_sla.png")


# ---------------------------------------------------------------------------
# Ponto de entrada
# ---------------------------------------------------------------------------

def main() -> None:
    """Fluxo principal: gerar dados → auditar → reportar → visualizar."""
    df_log = gerar_log_chamados(N_CHAMADOS)
    violacoes = auditar_sla(df_log)
    exibir_relatorio(df_log, violacoes)
    gerar_graficos(df_log, violacoes)


if __name__ == "__main__":
    main()