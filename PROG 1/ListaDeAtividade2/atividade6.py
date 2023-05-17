tipoComb = input("Insira o tipo de combustível vendido.(A-alcool, G-Gasolina)").upper()
litrosSell = float(input("Insira a quantidade de combustível vendidos.(1)"))

if (tipoComb == "G"):
    total = litrosSell * 3.90
    if (litrosSell <= 20):
        des = total * (4/100)
    else:
        des = total * (6/100)
elif (tipoComb == "A"):
    total = litrosSell * 3.20
    if (litrosSell <= 20):
        des = total * (3/100)
    else:
        des = total * (5/100)
else:
    print("<Erro> <Tipo> LOG: Nenhum combustivel definito!")
total = total - des

print("Tipo De Combustivel: %s" % tipoComb)
print("Quantidade comprada: %0.2f" % litrosSell)
print("Desconto: %0.2f" % des)
print("Parabens o valor total do seu combustivel foi: %0.2f" % total)
