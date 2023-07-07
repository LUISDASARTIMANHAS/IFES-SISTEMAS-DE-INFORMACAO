import functions
functions.head()
###### PRINCIPAL ##########
def main():
    op = 1
    DBCod = []
    DBInvest =[]

    while op != 0:
        op = functions.menu()
        
        if op == 0:
            print("\n\nFim do programa!!!\n\n")
            
        elif op == 1:
            print("\n\nINSERIR\n\n")
            # Chamar a função para Inserir os dados nos vetores
        elif op == 2:
            print("\n\nPESQUISAR\n\n")
            pos = functions.pesq(DBCod)
            print(pos)
            # Imprimir os dados se encontrar
        elif op == 3:
            print("\n\nATUALIZAR\n\n")
            # Ler a informação para pesquisar
            # Chamar a função para pesquisar no vetor
            # Ler os novos dados
            # Se encontrar, então atualizar o vetor, na posição pesquisada,
            #    com os novos dados
        elif op == 4:
            print("\n\nMAIOR\n\n")
            # Chamar a função para pesquisar no vetor o maior elemento
        elif op == 5:
            print("\n\nEXCLUIR\n\n")
            functions.pesqEDel(DBCod)
        elif(op == 6):
            print("\n\nLISTAR\n\n")
            # Listar todos os dados dos vetores
        else:
            print("Opção inválida!")
main()
functions.copy()
