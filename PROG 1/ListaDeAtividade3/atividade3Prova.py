n = int(input("Numero: "))
cont = 2
m = 3
soma = 0

while(cont < n):
    termo = cont/m
    soma = soma + termo

    cont = cont + 1
    m = m + 2

print(soma)