def buscar_conhecimento(base, termo):
    termo = termo.strip().lower()
    return [
        item for item in base
        if termo in item.get('titulo', '').lower()
        or termo in item.get('conteudo', '').lower()
    ]
