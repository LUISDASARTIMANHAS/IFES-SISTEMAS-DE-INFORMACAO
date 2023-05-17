nota1 = int(input("Insira uma nota parcial "));
nota2 = int(input("Insira a segunda nota parcial "));

notaMedia = (nota1 + nota2) / 2;

if(notaMedia == 10):
    msm = "Aprovado com Distinção";
elif( notaMedia >= 7):
    msm = "Aprovado";
else:
    msm = "Reprovado";

print("Sua nota foi %d. Por tanto voce foi %s" %(notaMedia,msm));