import random

CGREY    = '\33[90m'
ERROR    = '\33[91m'
OK  = '\33[92m'
ALERT = '\33[93m'
SYS   = '\33[94m'
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

def login() :
    DBAdmin = "admin"
    DBSenha = "admin"
    user = validUser()
    senha = validSenha()

    while(user != DBAdmin) or (senha != DBSenha):
        print(ERROR+"\n Usuário ou senha inválidos."+STOPCOLOR)
        user = validUser()
        senha = validSenha()
    print(OK+"Bem Vindo %s" %DBAdmin +STOPCOLOR)



def menu() :
    op =""
    while op.isdigit() == False or int(op) < 0 or int(op) > 6:
        print("\n")
        print(ALERT+"SISTEMA DE INVESTIMENTO:")
        print(SYS+"1-Inserir")
        print("2-Pesquisar")
        print("3-Atualizar")
        print("4-Maior")
        print(ERROR+"5-Excluir")
        print(SYS+"6-Listar")
        print(ERROR+"0-Sair")
        op = input(SYS+"Escolha sua opção: "+STOPCOLOR)
    return int(op)


def validNota():
    nota = float(input("Insira uma Nota: "))
    while(nota < 0) or ( nota > 10):
        print("Nota Invalida!")
        nota = float(input("Insira uma Nota: "))
    return nota

def validCod():
    cod = input("Insira o código do investimento: ");
    codTam = len(cod)

    while(codTam <= 0 ):
        print(ERROR+"O código do investimento não pode ser menor do que 0 caracteres"+STOPCOLOR);
        cod = input("Insira o código do investimento: ");
        codTam = len(cod)
    return int(cod)

def validUser():
    user = input(SYS +"Insira seu usuario: "+STOPCOLOR);
    nTam = len(user)
    
    while(nTam <= 4 ):
        print(ERROR+"O nome não pode ser menor do que 5 caracteres"+STOPCOLOR);
        user = input(SYS +"Insira seu usuario: "+STOPCOLOR);
        nTam = len(user)
    return user

def validSenha():
    senha = input(SYS +"Insira Sua senha: "+STOPCOLOR);

    while (len(senha) < 4):
        print(ERROR+"A senha não pode ser menor do que 5 caracteres"+STOPCOLOR);
        senha = input(SYS +"Insira Sua senha: "+STOPCOLOR);
    return senha

def fatorial(num):
    fat = 1

    while num > 1:
        fat = fat * num
        num = num - 1
    
    return fat

def validNum():
    num = int(input("Insira um número: "));
    
    while(num <= 0 ):
        print("O Número não pode ser menor do que 0!");
        num = int(input("Insira um número: "));
    return num

def validTaxa():
    tax = int(input(SYS+"Insira a taxa de rendimento: "+STOPCOLOR));

    while(tax <= 0 ) or (tax > 100):
        print(ERROR+"A taxa não pode ser menor do que 0 ou maior que 100!"+STOPCOLOR);
        tax = int(input(SYS+"Insira a taxa de rendimento: "+STOPCOLOR));
    porcent = (tax/100)
    print(porcent)
    return porcent

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
    while i < len(data):
        if data[i] == cod:
            print(OK+"O código do investimento procurado foi encontrado!"+STOPCOLOR)
            return i;
        else:
            print(SYS+"SISTEMA: PROCURANDO..."+STOPCOLOR)
            i = i + 1
    print(ERROR+"O código do investimento não foi encontado!"+STOPCOLOR)
    return -1

def pesqEDel(data,dataInv):
    pos = pesq(data)
    if(pos >= 0):
        print(OK+
              "O Investimento: %d. Foi deletado com Sucesso." %data[pos]
              +STOPCOLOR)
        del(data[pos])
        del(dataInv[pos])
    else:
        print(ERROR+"Não foi possível deletar os dados a pesquisa não retornou."+STOPCOLOR)

def listar(data,dataInv):
    print( SYS + "\t +-------------------------+")
    print(       "\t || informações           || Valor"+STOPCOLOR)
    for i, DBCod in enumerate(data):
        DBInv = dataInv[i]
        print(   "\t +-------------------------+")
        print(OK+"\t || Código do investimento || %.2d" %DBCod)
        print(   "\t || Valor do Investimento  || %0.2f" %DBInv + STOPCOLOR)
    print(       "\t +-------------------------+")

def rendimento(data,dataInv):
    pos = pesq(data)
    taxaRend = validTaxa()
    DBCod = data[pos]
    DBInv = dataInv[pos]
    dataInv[pos] = taxaRend * DBInv
    print(OK+
          "O rendimento de %f foi aplicado no valor do investimento!" %taxaRend
          +STOPCOLOR)
    listar(DBCod,DBInv)