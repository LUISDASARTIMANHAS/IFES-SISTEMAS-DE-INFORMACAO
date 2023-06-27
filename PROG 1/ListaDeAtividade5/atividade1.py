import presets

# ===========FIM DAS FUNCOES========================
def main():
    presets.head()
    vetorNum = []
    vetorPar = []
    vetorImp = []
    presets.gerarNumQtd(50,1,100,vetorNum)
    #     Faça outra função para percorrer esse vetor e contar a quantidade de números pares e ímpares que foram gerados. Mostre na tela
    presets.searchParImpVetor(vetorNum,vetorPar,vetorImp)
    presets.imprimirArray("Esse e o DATABASE na linha ",vetorNum)
    presets.imprimirArray("Esse e o vetor Par na linha ",vetorPar)
    presets.imprimirArray("Esse e o vetor Impar na linha ",vetorImp)
    presets.copy()

main()