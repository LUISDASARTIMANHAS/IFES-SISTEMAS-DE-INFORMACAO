aluno = input("Insira seu nome")
nota1 = int(input("Insira a nota 1 "))
nota2 = int(input("Insira a nota 2 "))
nota3 = int(input("Insira a nota 3 "))
nota4 = int(input("Insira a nota 4 "))
nota5 = int(input("Insira a nota 5 "))
maxNota = nota1
minNota = nota1

if(nota1 > maxNota):
    maxNota = nota1
elif(nota1 < minNota):
    minNota = nota1

if(nota2 > maxNota):
    maxNota = nota2
elif(nota2 < minNota):
    minNota = nota2

if(nota3 > maxNota):
    maxNota = nota3
elif(nota3 < minNota):
    minNota = nota3

if(nota4 > maxNota):
    maxNota = nota4
elif(nota4 < minNota):
    minNota = nota4

if(nota5 > maxNota):
    maxNota = nota5
elif(nota5 < minNota):
    minNota = nota5

media = (nota1+nota2+nota3+nota4+nota5 - maxNota - minNota) / 3

print("%s Teve a média %0.2f" %(aluno,media));
print("A Maior nota foi %0.2f" %maxNota);
print("A Menor nota foi %0.2f" %minNota);