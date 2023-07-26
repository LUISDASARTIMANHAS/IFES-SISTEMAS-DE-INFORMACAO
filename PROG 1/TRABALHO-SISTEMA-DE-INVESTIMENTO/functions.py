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


def menu() :
    op =""
    while op.isdigit() == False or int(op) < 0 or int(op) > 6:
        print("\n")
        print(ALERT+"SISTEMA DE INVESTIMENTO:")
        print(SYS+"1-Inserir")
        print("2-Pesquisar")
        print("3-Aplicar Rendimento")
        print("4-Maior Investimento")
        print(ERROR+"5-Excluir")
        print(SYS+"6-Listar")
        print(ERROR+"0-Sair")
        op = input(SYS+"Escolha sua opção: "+STOPCOLOR)
    return int(op)

# leituras
def validCod():
    cod = input("Insira o código do investimento: ");
    codTam = len(cod)

    while(codTam <= 0 ):
        print(ERROR+"O código do investimento não pode ser menor do que 0 caracteres"+STOPCOLOR);
        cod = input("Insira o código do investimento: ");
        codTam = len(cod)
    return int(cod)

def validInv():
    inv = input("Insira o investimento (R$ 100): ");
    invTam = len(inv)

    while(invTam <= 0 ):
        print(ERROR+"O investimento não pode ser menor do que R$ 0"+STOPCOLOR);
        inv = input("Insira o investimento (R$ 100): ");
        invTam = len(inv)
    return float(inv)

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
# fim das leituras


# funções
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
    print(ERROR+"O código do investimento não esta repetido e não foi encontado!"+STOPCOLOR)
    return -1

def inserir(data,dataInv):
    cod = validCod()
    investimento = validInv()
    print(SYS+"SISTEMA: CONFIRME O CÓDIGO PARA CONTINUAR"+STOPCOLOR)
    pos = pesq(data)

    if(pos == -1):
        data.append(cod)
        dataInv.append(investimento)
    else:
        print(ERROR + "O novo investimento não pode ser inserido!")
        print("O código do investimento não pode ser repetido"+ STOPCOLOR)
        inserir(data,dataInv)
    print(OK + "Novo investimento inserido com sucesso!" + STOPCOLOR)

def rendimento(data,dataInv):
    pos = pesq(data)
    if(pos >=0 ):
        taxa = validTaxa()
        DBInv = dataInv[pos]
        taxaRend = taxa * DBInv
        total = DBInv + taxaRend
        dataInv[pos] = total
        print(OK+
              "O rendimento de R$ %f foi aplicado no valor do investimento!" %taxaRend
             +STOPCOLOR);
    else:
        print(ERROR+ "Não foi possivel aplicar o rendimento" +STOPCOLOR)

def maior(data,dataInv):
    i = 0
    tam = len(dataInv)
    if(tam >= 1):
        maior = dataInv[i]
        for i, DBInv in enumerate(dataInv):
            if (DBInv >= maior):
                maior = DBInv
                cod = data[i]
            else:
                print(SYS+"SISTEMA: PROCURANDO..."+STOPCOLOR)
                i = i + 1
        print(   "\t +------------------------------+")
        print(OK+"\t || Código do investimento      || %.2d" %cod)
        print(   "\t || Maior Valor de Investimento || R$ %0.2f" %maior + STOPCOLOR)
        print(   "\t +------------------------------+")
    else:
        print(ERROR+
              "O banco de dados esta vazio, insira algo primeiro"
              +STOPCOLOR)

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
        print(   "\t || Valor do Investimento  || R$ %0.2f" %DBInv + STOPCOLOR)
    print(       "\t +-------------------------+")
