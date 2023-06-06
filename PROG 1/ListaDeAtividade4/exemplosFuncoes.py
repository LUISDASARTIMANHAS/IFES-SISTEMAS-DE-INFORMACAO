import turtle

def lado():
    print("Desenhando lado...")
    cont = 1 
    while(cont <= 3):
        degrau()
        cont = cont + 1

def degrau():
    print("Desenhando degrau...")
    turtle.forward(50)
    turtle.right(90)
    turtle.forward(50)
    turtle.left(90)

# ----------Fim das funções-------

def main():
    cont = 1
    while(cont <= 4):
        lado()
        turtle.right(90)
        cont = cont + 1


main()