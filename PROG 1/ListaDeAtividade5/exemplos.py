import presets

def imprimir(vetor):
    i = 0
    while i < len(vetor):
        print("Nota %d = %.1f" % (i, vetor[i]))
        i = i + 1

def lerVetorNotas(vetNotas):
    stoper = presets.validNota()

    while(stoper != 0):
        vetNotas.append(nota)
        nota = presets.validNota()
        stoper = nota

# ----------------------FIM DAS FUNCTIONS---------------
def main():
    presets.head()

    meuVetor = [] 
    lerVetorNotas(meuVetor)
    imprimir(meuVetor)

    presets.copy()
main()