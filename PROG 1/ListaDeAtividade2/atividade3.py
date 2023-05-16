# Faça um programa para a leitura de duas notas parciais de um aluno. 
nota1 = int(input("Insira uma nota parcial "));
nota2 = int(input("Insira a segunda nota parcial "));

# O programa deve calcular a média alcançada por aluno e apresentar a mensagem: ­ ­
notaMedia = (nota1 + nota2) / 2;

    # "Aprovado com Distinção", se a média for igual a dez.
if(notaMedia == 10):
    msm = "Aprovado com Distinção";
    #  "Aprovado", se a média alcançada for maior ou igual a sete;
elif( notaMedia >= 7):
    msm = "Aprovado";
else:
    # "Reprovado", se a média for menor do que sete; ­
    msm = "Reprovado";

print("Sua nota foi %d. Por tanto voce foi %s" %(notaMedia,msm));