import presets

gab = []
presets.lerArrayGab(gab)


# Fim da leitura do gabarito
# ------------------------
qtde = 0       # qtde de alunos
maior = 0      # maior nota
menor = 500    # menor nota
somaNotas = 0  # somar todas as notas, para depois calcular a media
acertos = 0    # acertos de cada aluno
nomeMaior = "" # nome do aluno com a maior nota
nomeMenor = "" # nome do aluno com a menor nota

continuar = "S"
while continuar == "S":
    res = []
    acertos = presets.lerArrayGabOrRes(res)
    qtde = qtde + 1
    nome = input("Nome do aluno %d : " %qtde)
    

    presets.comparar(gab,res)

    # Informações desse aluno
    print("Você teve %d acertos." %acertos)

    # Calcular maior nota
    if acertos > maior:
        maior = acertos
        nomeMaior = nome

    # Calcular menor nota
    if acertos < menor:
        menor = acertos
        nomeMenor = nome

    # Somar as notas
    somaNotas = somaNotas + acertos
        
    # CONTINUAR
    continuar = input("Desejar continuar (S ou N)? ")
    continuar = continuar.upper()


# Imprimir o resultado final
media = somaNotas / qtde

print("Qtde de alunos = %d" %qtde)
print("A maior nota (%d acertos) foi do aluno = %s" %(maior, nomeMaior))
print("A menor nota (%d acertos) foi do aluno = %s" %(menor, nomeMenor))
print("Média dos acertos = %.1f" %media)