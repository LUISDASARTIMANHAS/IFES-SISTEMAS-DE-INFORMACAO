#Faça um Programa que verifique se uma letra digitada é "F" ou "M". Conformealetra,escrever: F ­ Feminino, M ­ Masculino ou Sexo Inválido
abc = input("Insira seu sexo em letras (F,M) ")

if(abc == "F") or (abc == "f"):
    print("Sexo Indentificado como Feminino");
elif(abc == "M") or (abc == "m"):
    print("Sexo Indentificado como Masculino");
else:
    print("Sexo Invalido!");