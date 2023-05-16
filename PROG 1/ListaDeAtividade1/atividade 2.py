nome = input("Digite seu nome: ")
nota1 = float(input("Nota 1: "))
nota2 = float(input("Nota 2: "))
nota3 = float(input("Nota 3: "))
nota4 = float(input("Nota 4: "))

sumMedia = nota1 + nota2 + nota3 + nota4
media = sumMedia/4

print("Seu nome é: %s" %nome)
print("Sua media de notas é: %0.2f" %media)
