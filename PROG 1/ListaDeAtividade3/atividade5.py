# Faça um programa que calcule e
#  escreva o número de anos necessários para que a 
# população do país A ultrapasse ou iguale a população do país B, mantidas as taxas de crescimento.

# # Supondo que a população de um país A seja 80000 habitantes com uma taxa anual de crescimento de 3%
popA = 80000
taxaA = 0.03

# a população de B seja 200.000 habitantes com uma taxa de crescimento de 1.5%. 
popB = 200000
taxaB = 0.015
anos = 0

while(popA <= popB ):
    cresAnuA = popA * taxaA
    cresAnuB = popB * taxaB
    popA = popA + cresAnuA
    popB = popB + cresAnuB
    anos = anos + 1
print("-----------DADOS--------");
print("Cilcos de Anos: %d" %anos);
print("População A: %d" %popA);
print("População B: %d" %popB);