import csv
import random

# quantidade de registros
qtd_produtos = 100
qtd_vendas = 100

# lista de nomes de produtos
nomes = [
    "Teclado", "Mouse", "Monitor", "Notebook", "Headset",
    "Webcam", "Mousepad", "SSD", "HD", "Memória RAM"
]

# gerar produtos.csv
with open("produtos.csv", "w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f)
    writer.writerow(["sku", "nome", "preco"])

    for i in range(1, qtd_produtos + 1):
        sku = f"P{i:03d}"
        nome = random.choice(nomes)
        preco = random.randint(50, 3000)
        writer.writerow([sku, nome, preco])

# gerar vendas.csv
with open("vendas.csv", "w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f)
    writer.writerow(["sku", "qtd"])

    for i in range(qtd_vendas):
        sku = f"P{random.randint(1, qtd_produtos):03d}"
        qtd = random.randint(1, 20)
        writer.writerow([sku, qtd])

print("Arquivos produtos.csv e vendas.csv gerados com sucesso!")