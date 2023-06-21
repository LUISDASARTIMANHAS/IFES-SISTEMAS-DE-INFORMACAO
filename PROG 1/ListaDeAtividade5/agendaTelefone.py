import presets

def imprimirArray(data1,data2):
    i = 0
    while(i < len(data1)):
        letra = input("Insira a primeira letra para buscar: ")
        if(data1[i] == letra):
            print("Nome: %s" %data1[i])
            print("Telefone: %s" %data2[i])
        else:
            print("Não Encontrado!")
        i = i + 1

def validTell():
    tell = input("Insira seu número de telefone: ");
    tellTam = len(tell)
    while(tellTam <= 0) or (tellTam > 10):
        print("O Telefone não pode ser menor do que 0!");
        tell = input("Insira seu número de telefone: ");
    return tell

def validNome():
    nome = input("Insira seu nome: ");
    nTam = len(nome)

    while(nTam <= 3 ):
        print("O nome não pode ser menor do que 3 caracteres");
        nome = input("Insira seu nome: ");
        nTam = len(nome)
    return nome

def lerArrayAgenda(DBnome,DBtel):
    # while():
        nome = validNome()
        tell = validTell()
        DBnome.append(nome)
        DBtel.append(tell)
        print(DBnome[0])



#------------- FIM DAS FUNCOES
def main():
    DBnome =["luis","Arthur","Jean"]
    DBtel = ["123456789","987654321","654321987"]
    lerArrayAgenda(DBnome,DBtel)
    imprimirArray(DBnome,DBtel)



main()