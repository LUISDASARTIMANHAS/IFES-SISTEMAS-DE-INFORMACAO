import pandas as pd

print("\n==============================")
print("ETAPA 1 - EXTRAÇÃO")
print("==============================")

# Interoperabilidade Técnica:
# Estamos lendo arquivos CSV de sistemas diferentes.

vendas = pd.read_csv("vendas.csv")
produtos = pd.read_csv("produtos.csv")

print("\nTabela Vendas:")
print(vendas)

print("\nTabela Produtos:")
print(produtos)