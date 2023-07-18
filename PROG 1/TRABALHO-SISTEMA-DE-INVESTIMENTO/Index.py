import functions
functions.head()
###### PRINCIPAL ##########
def main():
    op = 1
    DBCod = [100,250,785]
    DBInvest =[100,20,2000]

    while(op != 0):
        op = functions.menu()
        
        if op == 0:
            functions.copy()
        elif op == 1:
            print("\n\nINSERIR\n\n")
            # Chamar a função para Inserir os dados nos vetores
        elif op == 2:
            print("\n\nPESQUISAR\n\n")
            pos = functions.pesq(DBCod)
            print("Código do investimento: %d" %DBCod[pos])
            print("Valor do investimento: %d" %DBInvest[pos])
            # Imprimir os dados se encontrar
        elif op == 3:
            print("\n\nATUALIZAR\n\n")
            functions.atualizar()
            # Ler a informação para pesquisar
            # Chamar a função para pesquisar no vetor
            # Ler os novos dados
            # Se encontrar, então atualizar o vetor, na posição pesquisada,
            #    com os novos dados
        elif op == 4:
            print("\n\nMAIOR\n\n")
            # Chamar a função para pesquisar no vet or o maior elemento
        elif op == 5:
            print("\n\nEXCLUIR\n\n")
            functions.pesqEDel(DBCod,DBInvest)
        elif(op == 6):
            print("\n\nLISTAR\n\n")
            functions.listar(DBCod,DBInvest)
        else:
            print("Opção inválida!")
functions.login()
main()
