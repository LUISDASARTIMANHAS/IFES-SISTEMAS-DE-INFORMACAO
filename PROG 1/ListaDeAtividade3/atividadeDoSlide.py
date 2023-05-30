# Leia o preço de um produto e a quantidade vendida. 
# Verifique se os valores são válidos e calcule o valor total da compra. 
# Se for maior que R$ 100,00, então conceder um desconto de 5%

preco = float(input("Insira o preço de um produto: "));
qtd = int(input("Insira a quantidade vendida: "));
total = preco * qtd

while(preco <= 0):
    print("Preço invalido.");
    preco = float(input("Insira o preço de um produto: "));

while(qtd <= 0):
    print("Quantidade invalida.");
    qtd = int(input("Insira a quantidade vendida: "));

if(total > 100):
    des = total * (5/100);
    total = total - des;

print("O preço total deu: %0.2d" %total)