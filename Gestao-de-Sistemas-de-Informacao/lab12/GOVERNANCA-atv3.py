import pandas as pd

# ====================================================
# ATIVIDADE 3 — PAINEL DE GOVERNANÇA (RESUMO)
# ====================================================
# Supõe que df_incidentes e df_problemas já existam na memória
# Se não existirem, rode antes a Atividade 2.
# --- INÍCIO DA TAREFA DO ALUNO ---
# 1. Contagem total de incidentes por serviço
total_incidentes_por_servico = df_incidentes.groupby("servico")["ticket_id"].count()
# 2. Contagem de incidentes de Prioridade Alta por serviço
incidentes_alta = df_incidentes[df_incidentes["prioridade"] == "Alta"]
incidentes_alta_por_servico = incidentes_alta.groupby("servico")["ticket_id"].count()
# 3. Montar um DataFrame de painel unificando essas informações
painel = pd.DataFrame(
    {
        "total_incidentes": total_incidentes_por_servico,
        "incidentes_prioridade_alta": incidentes_alta_por_servico,
    }
)
# Preencher com 0 onde não houver incidentes Alta
painel["incidentes_prioridade_alta"] = (
    painel["incidentes_prioridade_alta"].fillna(0).astype(int)
)
# 4. Adicionar coluna indicando se há Problema aberto para o serviço
painel["problema_aberto"] = painel.index.isin(df_problemas["servico"]).astype(int)
print("=== PAINEL DE GOVERNANÇA — INCIDENTES, PRIORIDADE ALTA E PROBLEMAS ===")
print(painel)
# 5. Calcular taxa de serviços com Problema aberto
qtd_servicos = len(painel)
qtd_com_problema = painel["problema_aberto"].sum()
taxa_servicos_com_problema = round((qtd_com_problema / qtd_servicos) * 100, 1)
print("\nResumo:")
print(f"Total de serviços monitorados: {qtd_servicos}")
print(f"Serviços com Problema aberto: {qtd_com_problema}")
print(f"Taxa de serviços com Problema aberto: {taxa_servicos_com_problema}%")
# --- FIM DA TAREFA DO ALUNO ---
