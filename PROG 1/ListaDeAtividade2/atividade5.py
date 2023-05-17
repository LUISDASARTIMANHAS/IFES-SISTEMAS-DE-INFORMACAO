numero1 = int(input("Insira um numero 1 "));
numero2 = int(input("Insira um numero 2 "));
numero3 = int(input("Insira um numero 3 "));

if((numero1 >= numero2) and (numero1 >= numero3)):
    ordem1 = numero1
    if((numero2 >= numero3)):
        ordem2 = numero2
        ordem3 = numero3
    else:
        ordem3 = numero2
        ordem2 = numero3
elif((numero2 >= numero1) and (numero2 >= numero3)): 
    ordem1 = numero2
    if((numero1 >= numero3)):
        ordem2 = numero1 
        ordem3 = numero3
    else:
        ordem3 = numero1
        ordem2 = numero3
else:
    ordem1 = numero3
    if((numero1 >= numero2)):
        ordem2 = numero1 
        ordem3 = numero2
    else:
        ordem3 = numero1
        ordem2 = numero2


print("A ordem vai ser: 1°%d" %ordem1);
print("                 2°%d"%ordem2);
print("                 3°%d"%ordem3);