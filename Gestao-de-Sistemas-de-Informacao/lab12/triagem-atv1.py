import pandas as pd
import random

# ====================================================
# ATIVIDADE 1 — TRIAGEM COM PRIORIDADE E SEVERIDADE
# ====================================================
random.seed(42)
# 1. Geração de log fictício de incidentes
n_incidentes = 25
prioridades = ["Alta", "Media", "Baixa"]
severidades = [1, 2, 3, 4]  # 1 = mais grave, 4 = menos grave
dados_incidentes = {
    "ticket_id": range(4001, 4001 + n_incidentes),
    "prioridade": [random.choice(prioridades) for _ in range(n_incidentes)],
    "severidade": [random.choice(severidades) for _ in range(n_incidentes)],
    # tempo de resolução entre 0.5h e 5h
    "tempo_resolucao_horas": [
        round(random.uniform(0.5, 5.0), 2) for _ in range(n_incidentes)
    ],
}
df_triagem = pd.DataFrame(dados_incidentes)
# Meta de SLA para prioridade Alta
meta_sla_alta = 2.0  # horas


# --- INÍCIO DA TAREFA DO ALUNO ---
# 2. Criar uma nova coluna 'fila_destino' com base em Prioridade e Severidade
# Regra:
# - Se prioridade = 'Alta' e severidade em {1,2} -> 'N2'
# - Caso contrário -> 'N1'
def decidir_fila(prioridade, severidade):
    # Substitua o 'pass' pela lógica condicional descrita acima
    pass


df_triagem["fila_destino"] = df_triagem.apply(
    lambda linha: decidir_fila(linha["prioridade"], linha["severidade"]), axis=1
)
# 3. Identificar violações de SLA para chamados de Prioridade Alta
# Critério: tempo_resolucao_horas > meta_sla_alta
violacoes_sla_alta = df_triagem[
    (df_triagem["prioridade"] == "Alta")
    & (df_triagem["tempo_resolucao_horas"] > meta_sla_alta)
]
# 4. Exibir relatório de triagem e violações
print(
    "=== LOG DE INCIDENTES - TRIAGEM POR PRIORIDADE E SEVERIDADE (TECHSTORE S.A.) ==="
)
print(df_triagem)
print("\n" + "=" * 70)
print("RELATÓRIO DE GOVERNANÇA - VIOLAÇÕES DE SLA (PRIORIDADE ALTA)")
print(f"Critério: tempo_resolucao_horas > {meta_sla_alta} horas")
print("=" * 70)
if violacoes_sla_alta.empty:
    print("Nenhuma violação de SLA para incidentes de prioridade Alta.")
else:
    print(violacoes_sla_alta)
    print(f"\nTotal de violações de SLA (Alta): {len(violacoes_sla_alta)}")
# --- FIM DA TAREFA DO ALUNO ---
