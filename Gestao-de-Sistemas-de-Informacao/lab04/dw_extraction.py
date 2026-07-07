# Data Warehouse - Extração, Transformação e Carga (ETL) dw_extraction.py
import pandas as pd

print("\n==============================")
print("ETAPA 1 - EXTRAÇÃO")
print("==============================")

# Interoperabilidade Técnica:
# Estamos lendo arquivos CSV de sistemas diferentes.

vendas = pd.read_csv("vendas.csv")
produtos = pd.read_csv("produtos.csv")

print("\n==============================")
print("ETAPA 2 - TRANSFORMAÇÃO")
print("==============================")

# ============================================================
# INTEROPERABILIDADE SEMÂNTICA
# O SKU é o elo de ligação entre sistemas que "falam línguas diferentes".
# Ele garante que estamos unindo o produto correto à venda correta.
# ============================================================

dw = pd.merge(vendas, produtos, on="sku")

print("\nTabela após Merge (Integração):")
print(dw.head())


# ============================================================
# REGRA DE NEGÓCIO - MÉTRICA DE FATURAMENTO
# ============================================================

dw["faturamento"] = dw["qtd"] * dw["preco"]

print("\nTabela com Faturamento Calculado:")
print(dw.head())


# ============================================================
# GOVERNANÇA - PADRONIZAÇÃO
# ============================================================

dw["nome"] = dw["nome"].str.upper()

print("\nTabela após Padronização (Nomes em MAIÚSCULO):")
print(dw.head())

print("\n==============================")
print("ETAPA 3 - CARGA")
print("==============================")

# Persistência do Data Warehouse
dw.to_csv("data_warehouse_final.csv", index=False)

print("Arquivo data_warehouse_final.csv criado com sucesso!")