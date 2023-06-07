import presets

g1 = presets.resGabarito()
g2 = presets.resGabarito()
g3 = presets.resGabarito()
g4 = presets.resGabarito()
g5 = presets.resGabarito()
g6 = presets.resGabarito()
g7 = presets.resGabarito()
g8 = presets.resGabarito()
g9 = presets.resGabarito()
g10 = presets.resGabarito()

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
    acertos = 0
    qtde = qtde + 1
    nome = input("Nome do aluno %d : " %qtde)
    q1 = presets.resProva()
    q2 = presets.resProva()
    q3 = presets.resProva()
    q4 = presets.resProva()
    q5 = presets.resProva()
    q6 = presets.resProva()
    q7 = presets.resProva()
    q8 = presets.resProva()
    q9 = presets.resProva()
    q10 = presets.resProva()

    #  QUESTÃO 1
    # -----------
    if q1 == g1:
        acertos = acertos + 1

    #  QUESTÃO 2
    # -----------
    if q2 == g2:
        acertos = acertos + 1

    #  QUESTÃO 3
    # -----------
    if q3 == g3:
        acertos = acertos + 1

    #  QUESTÃO 4
    # -----------
    if q4 == g4:
        acertos = acertos + 1

    #  QUESTÃO 5
    # -----------
    if q5 == g5:
        acertos = acertos + 1

    #  QUESTÃO 6
    # -----------
    if q6 == g6:
        acertos = acertos + 1

    #  QUESTÃO 7
    # -----------
    if q7 == g7:
        acertos = acertos + 1

    #  QUESTÃO 8
    # -----------
    if q8 == g8:
        acertos = acertos + 1

    #  QUESTÃO 9
    # -----------
    if q9 == g9:
        acertos = acertos + 1

    #  QUESTÃO 10
    # -----------
    if q10 == g10:
        acertos = acertos + 1

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
