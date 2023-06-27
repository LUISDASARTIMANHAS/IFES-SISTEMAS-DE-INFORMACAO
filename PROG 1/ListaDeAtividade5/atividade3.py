import presets

# Faça um programa que gere dois vetores com 20 números aleatórios em cada (utilize a função implementada nos exercícios anteriores). Faça uma função que gere um terceiro vetor de 40 elementos, cujos valores deverão ser compostos pelos elementos intercalados dos dois outros vetores (essa função receberá os três vetores como parâmetros). Imprima os três vetores (faça somente uma função imprimir e chame-a três vezes).
def main():
    presets.head()
    vetorLeft = []
    vetorRight = []
    vetorCenter = []

    presets.gerarNumQtd(20,1,100,vetorLeft)
    presets.gerarNumQtd(20,1,100,vetorRight)
    presets.intercalarVetor(vetorLeft,vetorRight,vetorCenter)

    presets.imprimirArray("Esse e o vetor Esquerdo na linha ",vetorLeft)
    presets.imprimirArray("Esse e o vetor Direito na linha ",vetorRight)
    presets.imprimirArray("Esse e o vetor Total na linha ",vetorCenter)
    presets.copy()

main()