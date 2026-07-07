from dados import salvar_dados

def criar_conhecimento(base, titulo, conteudo):
    titulo = titulo.strip()
    conteudo = conteudo.strip()

    if not titulo or not conteudo:
        raise ValueError("Título e conteúdo são obrigatórios.")

    novo_id = max([item['id'] for item in base], default=0) + 1

    novo_item = {
        "id": novo_id,
        "titulo": titulo,
        "conteudo": conteudo,
        "acessos": 0
    }

    base.append(novo_item)
    return novo_item

def adicionar_conhecimento(base):
    print("\n--- NOVO CONHECIMENTO ---")

    titulo = input("Título: ")
    conteudo = input("Conteúdo: ")

    try:
        criar_conhecimento(base, titulo, conteudo)
    except ValueError as erro:
        print(f"Erro: {erro}")
        return

    salvar_dados(base)

    print("Conhecimento adicionado com sucesso!")
