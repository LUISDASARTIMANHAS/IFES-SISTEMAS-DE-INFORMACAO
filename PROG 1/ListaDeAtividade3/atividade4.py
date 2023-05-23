#start
pares = 0
impares = 0
Spares = 0
Simpares = 0
maiorNum = 0
menorNum = 2023
#start

numero = int(input("Digite um número:"));
while(numero > 1000):
    print("Número inválido!");
    numero = int(input("Número:"));


while(numero > 0):

    if(numero > maiorNum):
        maiorNum = numero
    
    if(numero < menorNum):
        menorNum = numero

    numero = int(input("Digite um número:"));
    while(numero > 1000):
        print("Número inválido!");
        numero = int(input("Número:"));
    
    if(numero%2 == 0):
        pares = pares + 1
        Spares = Spares + numero
    else:
        impares = impares + 1
        Simpares = Simpares + numero


    



mediaPares = Spares / pares
mediaImpares = Simpares / impares
total = Spares + Simpares

print("resultados:")
print("pares: %d" %pares)
print("Impares: %d" %impares)
print("Media dos pares: %d" %mediaPares)
print("Media dos Impares: %d" %mediaImpares)
print("Soma Total: %d" %total)
print("Menor Número: %d" %menorNum)
print("Maior Número: %d" %maiorNum)
