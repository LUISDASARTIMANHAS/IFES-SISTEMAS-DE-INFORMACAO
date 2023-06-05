# Ler dois números inteiros positivos e determinar o máximo divisor comum entre eles.
# DICA: Repita de 1 até chegar a um dos dois números lidos. A cada iteração verificar se esse contador divide os dois números. Se dividir, guarde ele em uma variável. Um número é divisível por outro se o resto da divisão for zero.

num = int(input("Insira um número: "));
num2 = int(input("Insira o segundo número: "));
divisor = 2
cont = 1

while(num <= -1 ):
    print("O número não pode ser negativo");
    num = int(input("Insira um número: "));

while(num2 <= -1 ):
    print("O número não pode ser negativo");
    rep = int(input("Insira o segundo número: "));

while(divisor < num) and (divisor < num2):
    restoNum = num % divisor
    restoNum2 = num2 % divisor
    if(restoNum == 0) and (restoNum2 == 0):
        mdc = divisor
    divisor = divisor + 1