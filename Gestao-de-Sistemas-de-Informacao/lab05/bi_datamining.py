# ============================================================
# LABORATÓRIO 5 - BI e Data Mining
# ============================================================

import pandas as pd

print("\n====================================")
print("PARTE 0 - CARGA DE DADOS")
print("====================================")

# Interoperabilidade Técnica ocorre aqui:
# Leitura do arquivo CSV padronizado
df = pd.read_csv("base_vendas_transacional_300.csv")

# Normaliza a data mantendo apenas os 4 ultimos digitos do ano.
partes_data = df["Data"].astype(str).str.split("/", expand=True)
df["Data"] = pd.to_datetime(
    partes_data[0] + "/" + partes_data[1] + "/" + partes_data[2].str[-4:],
    format="%d/%m/%Y",
    errors="coerce"
)

if df["Data"].isna().any():
    raise ValueError("Existem datas invalidas na base apos a normalizacao.")

print("\nEstrutura da Base:")
print(df.head())

print("\nTotal de Registros:", len(df))
