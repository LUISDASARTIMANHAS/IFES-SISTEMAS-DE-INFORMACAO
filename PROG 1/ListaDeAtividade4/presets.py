def head():
    print("----------------------------------------------------")
    print("\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A")
    print("\t Iniciando programa.....")
    print("----------------------------------------------------")

def data(dado,user,dado2,senha):
    print("-----------------------DADOS--------------------")
    print("\t %s : %s" %(dado,user))
    print("\t %s : %s" %(dado2,senha))
    print("----------------------------------------------------")

def copy():
    print("----------------------------------------------------")
    print("\t DEVS:")
    print("\t LUIS_DAS_ARTIMANHAS.")
    print("\t PINGOBRAS S.A")
    print("----------------------------------------------------")

def validNota():
    nota = input("Insira uma Nota: ")
    while(nota < 0) or ( nota > 10):
        print("Nota Invalida!")
        nota = input("Insira uma Nota: ")
    return nota

def validNome():
    nome = input("Insira seu nome: ");
    nTam = len(nome)

    while(nTam <= 3 ):
        print("O nome não pode ser menor do que 3 caracteres");
        nome = input("Insira seu nome: ");
        nTam = len(nome)
    return nome

def validUser():
    user = input("Insira seu usuario: ");
    nTam = len(user)
    
    while(nTam <= 3 ):
        print("O nome não pode ser menor do que 6 caracteres");
        user = input("Insira seu usuario: ");
        nTam = len(user)
    return user

def validIdade():
    idade = int(input("Insira sua idade: "));
    while(idade <= 0) or (idade >= 50):
        print("Idade invalida.");
        idade = int(input("Insira sua idade: "));
    return idade

def validSalario():
    salario = int(input("Insira seu salario: "));
    while(salario < 0):
        print("Salario invalido.")
        salario = input("Insira Seu salario: ");
    return salario

def validSexo():
    sx = input("Insira seu sexo(F/M): ").upper();
    while (sx != "F") and (sx != "M"):
        print("Sexo invalido.")
        sx = input("Insira seu sexo(F/M): ").upper();
    return sx

def validUF():
    uf = input("Insira seu Estado Civil: ").upper();
    while (uf != "S") and (uf != "C") and (uf != "V") and (uf != "D"):
        print("Sexo invalido.")
        uf = input("Insira seu Estado Civil: ").upper();
    return uf

def validSenha():
    senha = input("Insira Sua senha: ");

    while (len(senha) < 6):
        print("A senha não pode ser menor do que 6 caracteres");
        senha = input("Insira Sua senha: ");
    return senha

def fatorial(num):
    fat = 1

    while num > 1:
        fat = fat * num
        num = num - 1
    
    return fat

def media3(nota1,nota2,nota3):
    soma = nota1 + nota2 + nota3
    media = soma / 3
    return media

def resultadoNota(media):
    if(media >= 7):
        txt = "APROVADO"
    elif(media < 6):
        txt = "REPROVADO"
    else:
        txt = "PROVA FINAL"
    return txt

def resGabarito():
    g = input("Gabarito da questão: ").upper()

    while g != "A" and g != "B" and g != "C" and g != "D" and g != "E":
        g = input("Questão: ").upper()
    
    return g

def resProva():
    q1 = input("Questão: ").upper()

    while q1 != "A" and q1 != "B" and q1 != "C" and q1 != "D" and q1 != "E":
        q1 = input("Questão: ").upper()
    
    return q1

