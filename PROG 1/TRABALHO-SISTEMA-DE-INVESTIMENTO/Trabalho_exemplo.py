### EXEMPLO PARA O TRABALHO

def menu() :
    op = ""
    while op.isdigit() == False or int(op) < 0 or int(op) > 6:
        print("\n" * 130)
        print("NOME DO SEU SISTEMA:")
        print("1-Inserir")
        print("2-Pesquisar")
        print("3-Atualizar")
        print("4-Maior")
        print("5-Excluir")
        print("6-Listar")
        print("0-Sair")
        op = input("Escolha sua opção: ")
    return int(op)
###### PRINCIPAL ##########
def main():
    op = 1
    while op != 0:
        op = menu()
        if op == 0:
            print("\n\nFim do programa!!!\n\n")
        elif op == 1:
            print("\n\nINSERIR\n\n")
            # Chamar a função para Inserir os dados nos vetores
        elif op == 2:
            print("\n\nPESQUISAR\n\n")
            # Ler a informação para pesquisar
            # Chamar a função para pesquisar no vetor
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
            # Ler a informação para pesquisar
            # Chamar a função para pesquisar no vetor
            # Excluir a posição pesquisada, se encontrar
        elif op == 6:
            print("\n\nLISTAR\n\n")
            # Listar todos os dados dos vetores
        else:
            print("Opção inválida!")
        input("Pressione <enter> para continuar ...")
main()