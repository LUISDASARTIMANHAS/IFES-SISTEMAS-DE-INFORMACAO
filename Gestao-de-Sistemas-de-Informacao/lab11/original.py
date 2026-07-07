import pandas as pd
import matplotlib.pyplot as plt

#
# ========================================================
# ====
# ATIVIDADE 1 — GERENCIAMENTO DE DISPONIBILIDADE (ITIL)
#
# ========================================================
# ====
# 1. Configuração do período analisado
minutos_no_mes = 43200  # 30 dias * 24 horas * 60 # minutos
# 2. Log simplificado de indisponibilidades dos serviços
dados_disponibilidade = {
    "servico": [
        "ERP",
        "Portal do Cliente",
        "Sistema de Pagamentos",
        "E-mail Corporativo",
    ],
    "tempo_indisponivel_min": [80, 250, 15, 420],
}
df_disp = pd.DataFrame(dados_disponibilidade)
# 3. Meta de disponibilidade definida no SLA
meta_disponibilidade = 99.5  # em %
# --- INÍCIO DA TAREFA DO ALUNO ---
# 4. Calcule a disponibilidade real (%) de cada serviço
df_disp["disponibilidade_pct"] = round(
    ((minutos_no_mes - df_disp["tempo_indisponivel_min"]) / minutos_no_mes) * 100, 3
)
# 5. Identifique as violações (serviços com disponibilidade abaixo da meta)
violacoes_disp = df_disp[df_disp["disponibilidade_pct"] < meta_disponibilidade]
# 6. Exiba o relatório de auditoria de disponibilidade
print("=== RELATÓRIO DE DISPONIBILIDADE — TECHSTORE S.A. ===")
print(df_disp)
print("\n" + "=" * 60)
print(f"VIOLAÇÕES DE DISPONIBILIDADE (Meta:{meta_disponibilidade}%)")
print("=" * 60)
if violacoes_disp.empty:
    print("Nenhuma violação detectada. Todos os serviços dentro da meta.")
else:
    print(violacoes_disp)
    print(f"\nTotal de serviços em não-conformidade: {len(violacoes_disp)}")
# 7 (Opcional). Gere um gráfico de barras com a disponibilidade por serviço
cores = [
    "red" if d < meta_disponibilidade else "steelblue"
    for d in df_disp["disponibilidade_pct"]
]
plt.figure(figsize=(9, 4))
plt.bar(df_disp["servico"], df_disp["disponibilidade_pct"], color=cores)
plt.axhline(
    y=meta_disponibilidade,
    color="orange",
    linestyle="--",
    label=f"Meta SLA ({meta_disponibilidade}%)",
)
plt.title("Disponibilidade Mensal dos Serviços — TechStore S.A.")
plt.xlabel("Serviço")
plt.ylabel("Disponibilidade (%)")
plt.ylim(98.5, 100.1)
plt.legend()
plt.tight_layout()
plt.show()
# --- FIM DA TAREFA DO ALUNO ---
