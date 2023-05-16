quantidadeP1 = float(input("Insira a quantidade de produto a comprar: "))
preco = float(input("Insira o preço do produto: "))

total = quantidadeP1 * preco


if (total <= 100):
    des = total * (3/100)
    print("Voce recebeu um desconto de : %3")
elif (total <= 200):
    des = total * (5/100)
    print("Voce recebeu um desconto de : %5")
elif (total <= 300):
    des = total * (10/100)
    print("Voce recebeu um desconto de : %10")
else:
    des = total * (15/100)
    print("Voce recebeu um desconto de : %15")

total = total - des
print("O total da compra deu: %0.2f" % total)
