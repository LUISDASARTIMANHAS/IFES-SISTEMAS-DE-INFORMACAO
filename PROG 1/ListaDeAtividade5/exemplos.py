import presets

def imprimir(vetor):
    i = 0
    while i < len(vetor):
        print("Nota %d = %.1f" % (i, vetor[i]))
        i = i + 1

def lerVetorNotas(vetNotas):
    stop = "N"
    while(stop == "N"):
        nota = presets.validNota()
        vetNotas.append(nota)
        stop = presets.stop()

# ----------------------FIM DAS FUNCTIONS---------------
def main():
    presets.head()

    meuVetor = [] 
    lerVetorNotas(meuVetor)
    imprimir(meuVetor)

    presets.copy()
main()