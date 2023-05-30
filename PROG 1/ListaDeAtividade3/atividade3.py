cont = 0
somaNt = 0
maiorNota = 0
menorNota = 0
meiaNt = 0
nome = input("Insira seu nome: ");
nTam = len(nome)

while(nTam <= 0 ):
    print("O nome não pode ser menor do que 0 caracteres");
    nome = input("Insira seu nome: ");
    nTam = len(nome)

while(cont <= 2):
    nota = int(input("Insira uma nota: "));
    while(nota <= 0):
        print("Nota invalida.");
        nota = int(input("Insira uma nota: "));
    
    if(nota > maiorNota):
        maiorNota = nota
    if(nota > maiorNota):
        menorNota = nota
    if(nota > maiorNota) and (nota < menorNota):
        meiaNt = nota
    
    somaNt = somaNt + nota
    cont = cont + 1

media = somaNt / 3

if(media >= 7):
    txt = "APROVADO"
elif(media < 6):
    txt = "REPROVADO"
else:
    txt = "PROVA FINAL"

print("----------DADOS------------")
print("Situação: %s" %txt)
print("Maior Nota: %d" %maiorNota)
print("Segunda Maior Nota: %d" %meiaNt)
print("Menor Nota: %d" %menorNota)