import random
from typing import Sequence

def head():
    print("----------------------------------------------------")
    print("\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A")
    print("\t Iniciando programa.....")
    print("----------------------------------------------------")

def data(line1,line2,line3,line4,dado1,dado2,dado3,dado4):
    print("-----------------------DADOS--------------------")
    print("\t %s : %s" %(line1,dado1))
    print("\t %s : %s" %(line2,dado2))
    print("\t %s : %s" %(line3,dado3))
    print("\t %s : %s" %(line4,dado4))
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

def resGabarito(numQ):
    g = input("Gabarito da questão %d: "%numQ).upper()

    while g != "A" and g != "B" and g != "C" and g != "D" and g != "E":
        g = input("Questão %d: " %numQ).upper()
    
    return g

def resProva(numRes):
    q1 = input("Questão %d: " %numRes).upper()

    while (q1 != "A") and (q1 != "B") and (q1 != "C") and (q1 != "D") and (q1 != "E"):
        q1 = input("Questão %d: " %numRes).upper()
    
    return q1

def validNum():
    num = int(input("Insira um número: "));
    
    while(num <= 0 ):
        print("O Número não pode ser menor do que 0!");
        num = int(input("Insira um número: "));
    return num

def validQtdProdutos():
    qtd = int(input("Insira a quantidade de produtos: "));
    
    while(qtd <= 0 ):
        print("A quantidade não pode ser menor do que 0!");
        qtd = int(input("Insira a quantidade de produtos: "));
    return qtd

def validTaxa():
    tax = int(input("Insira a taxa: "));
    
    while(tax <= 0 ) or (tax >=100):
        print("A taxa não pode ser menor do que 0 ou maior que 100!");
        tax = int(input("Insira a taxa: "));
    return tax

def validImc(imc):
    if(imc < 18.5):
        categoria = "Abaixo do peso"
    elif(imc < 25):
        categoria = "Peso normal"
    elif(imc < 30):
        categoria = "Sobrepeso"
    elif(imc < 35):
        categoria = "Obeso leve"
    elif(imc < 40):
        categoria = "Obeso moderado"
    elif(imc > 40):
        categoria = "Obeso mórbido"
    else:
        categoria = "IMC Invalido!"
    return categoria

def lancarDado():
    return random.randint(1,6)

def jogarDados():
    input("Pressione ENTER para lançar os dados.")
    d1 = lancarDado()
    d2 = lancarDado()
    soma = d1 + d2
    print("Dado 1: %d" %d1)
    print("Dado 2: %d" %d2)
    print("SOMA: %d" %soma)
    print("---------------------")
    return soma

def validPeso():
    peso = int(input("Insira seu Peso: "));
    
    while(peso <= 0 ) or( peso >= 400):
        print("Seu Peso não pode ser menor do que 0 ou maior que 400KG!");
        peso = int(input("Insira seu Peso: "));
    return peso

def validAltura():
    alt = float(input("Insira sua Altura: "));
    
    while(alt <= 0 ) or(alt >= 3):
        print("Sua Altura não pode ser menor do que 0M ou maior que 3M!");
        alt = float(input("Insira sua Altura: "));
    return alt

def sequencia(stop):
    seq = 1
    while(seq <= stop):
        print(seq, end=" ")
        seq = seq + 1
    return True

def imprimirLinha(numLinha):
    cont = 0
    while(cont <= numLinha):
        print(numLinha, end=" ")
        cont = cont+1

def saldoSys(saldo,value):
    saldo = saldo + (value)
    print("Saldo Atual: %d" %saldo)
    return saldo

def somaImposto(imposto,valorCusto):
    porcentImposto = imposto/100
    taxa = valorCusto * porcentImposto
    total = valorCusto + taxa
    print("-----------------------DADOS--------------------")
    print("\t Valor do produto: %s" %valorCusto)
    print("\t Imposto: %s" %imposto)
    print("\t Taxa: %s" %taxa)
    print("\t Total a pagar: %s" %total)
    print("------------------------------------------------")

def continuarJogando(ponto):
    soma = jogarDados()
    if():
        stop = True
        return
    else:
        stop = True
        return stop


def primeiraJogada():
    soma = jogarDados()
    if():
        return True
    elif():
        return False
    else:
        continuarJogando(soma)

