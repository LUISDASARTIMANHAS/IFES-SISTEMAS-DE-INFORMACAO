import pandas as pd

# Simulação de Log de Incidentes (Prática ITIL)
dados = {
 'ticket_id': None,
 'prioridade': ['Alta', 'Baixa', 'Alta', 'Media'],
 'tempo_resolucao_horas': [1.5, 5.0, 3.2, 2.5] # Meta: 2.0h para Alta
}
df = pd.DataFrame(dados)
# Lógica de Auditoria de Governança (similar ao Lab de Auditoria)
violacoes = df[(df["prioridade"] == "Alta") & (df["tempo_resolucao_horas"] > 2.0)]
print("Relatório de Governança - Violações de SLA (Prioridade Alta):")
print(violacoes)
# Para ajudar na aula prática de Governança e Auditoria de SI, segue um script que gera um log de
# chamados aleatório mais robusto. Este log inclui variações de prioridade e tempos de resolução,
# permitindo que identifiquem múltiplas violações de SLA (Acordo de Nível de Serviço). O código
# abaixo utiliza a biblioteca random para criar 20 chamados fictícios da TechStore S.A., seguindo a
# lógica de auditoria solicitada:
# Python
import pandas as pd
import random

# Configuração para reprodutibilidade (opcional)
random.seed(42)
# 1. Criação do Log de Chamados Aleatório para os Alunos
n_chamados = 20
prioridades = ["Alta", "Media", "Baixa"]
dados_aleatorios = {
    "ticket_id": range(1001, 1001 + n_chamados),
    "prioridade": [random.choice(prioridades) for _ in range(n_chamados)],
    # Gera tempos entre 0.5h e 5.0h
    "tempo_resolucao_horas": [
        round(random.uniform(0.5, 5.0), 1) for _ in range(n_chamados)
    ],
}
df_log = pd.DataFrame(dados_aleatorios)
# --- INÍCIO DA TAREFA DO ALUNO ---
# 2. Lógica de Auditoria de Governança
# Meta definida no SLA da TechStore S.A.: Prioridade Alta deve ser resolvida em
# até 2h.
meta_sla_alta = 2.0
violacoes = df_log[
    (df_log["prioridade"] == "Alta") & (df_log["tempo_resolucao_horas"] > meta_sla_alta)
]
# 3. Exibição dos Resultados (Relatório de Auditoria)
print("=== LOG COMPLETO DE INCIDENTES (TECHSTORE S.A.) ===")
print(df_log)
print("\n" + "=" * 50)
print("RELATÓRIO DE GOVERNANÇA - VIOLAÇÕES DE SLA")
print(f"Critério: Prioridade Alta > {meta_sla_alta} horas")
print("=" * 50)
if violacoes.empty:
    print("Nenhuma violação de conformidade detectada.")
else:
    print(violacoes)
    print(f"\nTotal de não-conformidades encontradas: {len(violacoes)}")
# --- FIM DA TAREFA DO ALUNO ---
