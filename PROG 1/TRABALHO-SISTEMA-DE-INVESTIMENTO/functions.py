import random

CGREY    = '\33[90m'
ERROR    = '\33[91m'
OK  = '\33[92m'
ALERT = '\33[93m'
CBLUE2   = '\33[94m'
CVIOLET2 = '\33[95m'
CBEIGE2  = '\33[96m'
STOPCOLOR  = '\33[97m'

CGREYBG    = '\33[100m'
CREDBG2    = '\33[101m'
CGREENBG2  = '\33[102m'
CYELLOWBG2 = '\33[103m'
CBLUEBG2   = '\33[104m'
CVIOLETBG2 = '\33[105m'
CBEIGEBG2  = '\33[106m'
CWHITEBG2  = '\33[107m'

def head():
    clear()
    print("----------------------------------------------------")
    print(OK+"\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A")
    print("\t Iniciando programa....."+STOPCOLOR)
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
    print(OK+"\t DEVS:")
    print("\t LUIS_DAS_ARTIMANHAS.")
    print("\t PINGOBRAS S.A"+STOPCOLOR)
    print("----------------------------------------------------")

def clear():
    print("\n" * 50) 
    print("\t Console Limpo!") 

def menu() :
    op =""
    while op.isdigit() == False or int(op) < 0 or int(op) > 6:
        print(ALERT+"SISTEMA DE INVESTIMENTO:")
        print(CBLUE2+"1-Inserir")
        print("2-Pesquisar")
        print("3-Atualizar")
        print("4-Maior")
        print(ERROR+"5-Excluir")
        print(CBLUE2+"6-Listar")
        print(ERROR+"0-Sair")
        op = input(CBLUE2+"Escolha sua opção: "+STOPCOLOR)
    return int(op)


def validNota():
    nota = float(input("Insira uma Nota: "))
    while(nota < 0) or ( nota > 10):
        print("Nota Invalida!")
        nota = float(input("Insira uma Nota: "))
    return nota

def validCod():
    cod = input("Insira o codigo do investimento: ");
    codTam = len(cod)

    while(codTam <= 0 ):
        print(ERROR+"O codigo do investimento não pode ser menor do que 0 caracteres"+STOPCOLOR);
        cod = input("Insira o codigo do investimento: ");
        codTam = len(cod)
    return int(cod)

def validUser():
    user = input("Insira seu usuario: ");
    nTam = len(user)
    
    while(nTam <= 3 ):
        print("O nome não pode ser menor do que 6 caracteres");
        user = input("Insira seu usuario: ");
        nTam = len(user)
    return user

def fatorial(num):
    fat = 1

    while num > 1:
        fat = fat * num
        num = num - 1
    
    return fat

def imprimirArray(placeholder,data):
    i = 0
    while i < len(data):
        print("%s %d: %.1f" % (placeholder,i, data[i]))
        i = i + 1

def validNum():
    num = int(input("Insira um número: "));
    
    while(num <= 0 ):
        print("O Número não pode ser menor do que 0!");
        num = int(input("Insira um número: "));
    return num

def validTaxa():
    tax = int(input("Insira a taxa: "));
    
    while(tax <= 0 ) or (tax >=100):
        print("A taxa não pode ser menor do que 0 ou maior que 100!");
        tax = int(input("Insira a taxa: "));
    return tax

def lancarDado():
    return random.randint(1,6)

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

def gerarNumAleatorio(min,max):
    return random.randint(min,max)

def searchParImpVetor(vetor,vetorPar,vetorImp):
    i = 0
    while i < len(vetor):
        resto  = vetor[i] % 2
        if(resto == 0):
            vetorPar.append(vetor[i])
        else:
            vetorImp.append(vetor[i])
        i = i + 1

def pesq(data):
    cod = validCod()
    i = 0
    while i < len(data) :
        if data[i] == cod:
            return i;
        else:
            i = i + 1
    print(ERROR+"O codigo do investimento não foi encontado!"+STOPCOLOR)
    return -1

def pesqEDel(data):
    pos = pesq(data)
    DBCod= data[pos]
    if(pos >= 0):
        print(OK+"O Investimento: %d. Foi deletado com Sucesso." %DBCod + STOPCOLOR)
        del(DBCod)
    else:
        print(ERROR+"Não foi possível deletar os dados a pesquisa não retornou."+STOPCOLOR)