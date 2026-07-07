from dados import carregar_dados, salvar_dados
from logica import buscar_conhecimento
from apresentacao import exibir_dashboard
from colaboracao import adicionar_conhecimento

def menu():
    base = carregar_dados()

    while True:
        print("\nSGC - MENU")
        print("1. Dashboard")
        print("2. Buscar")
        print("3. Adicionar")
        print("4. Sair")

        opcao = input("Escolha: ")

        if opcao == '1':
            exibir_dashboard(base)

        elif opcao == '2':
            termo = input("Busca: ")
            resultados = buscar_conhecimento(base, termo)

            print(f"\nResultados: {len(resultados)}")
            for r in resultados:
                print(f"{r['titulo']} -> {r['conteudo']}")
                r['acessos'] += 1

            salvar_dados(base)

        elif opcao == '3':
            adicionar_conhecimento(base)

        elif opcao == '4':
            salvar_dados(base)
            print("Encerrado.")
            break

if __name__ == "__main__":
    menu()
