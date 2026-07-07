import pandas as pd
import random

# ====================================================
# ATIVIDADE 2 — IDENTIFICAÇÃO DE PROBLEMAS (ITIL)
# ====================================================
random.seed(99)
# 1. Partindo de um novo log de incidentes com serviço associado
n_incidentes = 30
prioridades = ["Alta", "Media", "Baixa"]
severidades = [1, 2, 3, 4]
servicos = ["ERP", "Portal do Cliente", "Sistema de Pagamentos", "E-mail Corporativo"]
dados_incidentes2 = {
    "ticket_id": range(5001, 5001 + n_incidentes),
    "servico": [random.choice(servicos) for _ in range(n_incidentes)],
    "prioridade": [random.choice(prioridades) for _ in range(n_incidentes)],
    "severidade": [random.choice(severidades) for _ in range(n_incidentes)],
}
df_incidentes = pd.DataFrame(dados_incidentes2)
# --- INÍCIO DA TAREFA DO ALUNO ---
print("=== LOG DE INCIDENTES POR SERVIÇO — TECHSTORE S.A. ===")
print(df_incidentes)
# 2. Filtrar apenas incidentes de Prioridade Alta
incidentes_alta = df_incidentes[df_incidentes["prioridade"] == "Alta"]
# 3. Contar quantos incidentes de Prioridade Alta houve por serviço
contagem_alta_por_servico = incidentes_alta.groupby("servico")["ticket_id"].count()
print("\n=== CONTAGEM DE INCIDENTES DE PRIORIDADE ALTA POR SERVIÇO ===")
print(contagem_alta_por_servico)
# 4. Definir threshold para abrir Problema (por exemplo, 3 incidentes Alta)
limite_problema = 3
# 5. Criar uma tabela de "Problemas" para serviços que atingirem o limite
# Dica: selecione apenas serviços com contagem >= limite_problema
servicos_com_problema = contagem_alta_por_servico[
    contagem_alta_por_servico >= limite_problema
]
df_problemas = pd.DataFrame(
    {
        "servico": servicos_com_problema.index,
        "qtd_incidentes_alta": servicos_com_problema.values,
        "status_problema": ["Aberto"] * len(servicos_com_problema),
    }
)
print("\n" + "=" * 70)
print("REGISTROS DE PROBLEMAS ABERTOS (SERVIÇOS COM INCIDENTES ALTA RECORRENTES)")
print("=" * 70)
if df_problemas.empty:
    print("Nenhum Problema aberto. Nenhum serviço atingiu o limite de recorrência.")
else:
    print(df_problemas)
# --- FIM DA TAREFA DO ALUNO ---
