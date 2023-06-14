# Faça um programa com uma função chamada somaImposto. A função possui dois parâmetros formais: taxaImposto, que é a quantia de imposto sobre vendas expressa em porcentagem; e valorCusto, que é o custo de um item antes do imposto. A função retorna o valor de custo acrescentado com o imposto sobre vendas.
import presets

def main():
    presets.head()
    Imposto = presets.validTaxa()
    Custo = presets.validMoeda()
    presets.somaImposto(Imposto,Custo)
    presets.copy()

main()