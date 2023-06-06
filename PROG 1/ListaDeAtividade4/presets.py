def head():
    print("----------------------------------------------------")
    print("\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A")
    print("\t Iniciando programa.....")
    print("----------------------------------------------------")

def copy():
    print("----------------------------------------------------")
    print("\t DESENVOLVEDORES:")
    print("\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A")
    print("----------------------------------------------------")

def validNota():
    n = input("Insira uma Nota: ")
    while(n < 0) or ( n > 10):
        print("Nota Invalido!")
        n = input("Insira uma Nota: ")
    return n