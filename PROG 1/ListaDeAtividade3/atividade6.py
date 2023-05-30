# Ler dois números inteiros positivos e determinar o máximo divisor comum entre eles.
# DICA: Repita de 1 até chegar a um dos dois números lidos. A cada iteração verificar se esse contador divide os dois números. Se dividir, guarde ele em uma variável. Um número é divisível por outro se o resto da divisão for zero.

num = int(input("Insira um número: "));
rep = int(input("Repitir até?: "));
divisor = 2

while(num <= -1 ):
    print("O número não pode ser negativo");
    num = int(input("Insira um número: "));

while(rep <= -1 ):
    print("O número não pode ser negativo");
    rep = int(input("Repitir até?: "));


while(num != 0):
    resto = num % divisor
    num = resto
    print(resto);