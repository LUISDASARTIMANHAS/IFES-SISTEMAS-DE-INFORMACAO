# A sequência de Fibonacci é a seguinte: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ... 
# Sua regra de formação é simples: os dois primeiros elementos são 1; 
# a partir de então, cada elemento é a soma dos dois anteriores. 
# Faça um algoritmo que leia um número inteiro e calcule a sequência de Fibonacci. 
# Por exemplo, se o usuário informar o número 10, então mostrar os 10 primeiros números da sequência.
num = int(input("Insira um número: "));
while(num < 0):
    print('Número Inválido.')
    num = int(input("Insira um número: "));
repeat = num


while(repeat >= 10):

    repeat = repeat + 1