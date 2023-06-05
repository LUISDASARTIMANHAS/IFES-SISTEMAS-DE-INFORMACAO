a = int(input("Numero 1: "))
b = int(input("Numero 2: "))
cont = 0

while(cont < 5):
    if(cont%2 == 0):
        c = b - a
    else:
l    a = b
    b = c
    cont = cont + 1
    print(c)
