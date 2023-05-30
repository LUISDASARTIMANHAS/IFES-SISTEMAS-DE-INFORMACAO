popA = 80000
taxaA = 0.03
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
print("Cresc. Anual A: %d" %cresAnuA);
print("População B: %d" %popB);
print("Cresc. Anual B: %d" %cresAnuB);