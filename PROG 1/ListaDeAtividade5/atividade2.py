# Utilize a função acima para gerar 50 números aleatórios entre 1 e 100 (min=1 e max=100) e armazene em um vetor. Faça outra função que percorra esse vetor e coloque os números pares em um vetor chamado pares e os números ímpares em outro vetor chamado ímpares (essa função receberá três vetores como parâmetros: o principal com todos os números, o vetor de pares e o vetor de ímpares). Imprima os três vetores.
# DICA: Você só precisará de uma função imprimir. Chame ela três vezes, uma vez para cada vetor.

import presets
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