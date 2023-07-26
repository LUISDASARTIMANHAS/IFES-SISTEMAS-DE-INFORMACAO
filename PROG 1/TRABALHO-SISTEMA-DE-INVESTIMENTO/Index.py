import functions
functions.head()
###### PRINCIPAL ##########
def main():
    op = 1
    DBCod = []
    DBInvest =[]

    while(op != 0):
        op = functions.menu()
        if (op == 0):
            functions.copy()
        elif (op == 1):
            print("\n\nINSERIR\n\n")
            functions.inserir(DBCod,DBInvest)
        elif (op == 2):
            print("\n\nPESQUISAR\n\n")
            pos = functions.pesq(DBCod)
            if(pos >= 0):
                print("Código do investimento: %d" %DBCod[pos])
                print("Valor do investimento: %d" %DBInvest[pos])
            # Imprimir os dados se encontrar
        elif (op == 3):
            print("\n\n Rendimento \n\n")
            functions.rendimento(DBCod,DBInvest)
        elif (op == 4):
            print("\n\nMAIOR\n\n")
            functions.maior(DBCod,DBInvest)
        elif (op == 5):
            print("\n\nEXCLUIR\n\n")
            functions.pesqEDel(DBCod,DBInvest)
        elif(op == 6):
            print("\n\nLISTAR\n\n")
            functions.listar(DBCod,DBInvest)
        else:
            print("Opção inválida!")
main()