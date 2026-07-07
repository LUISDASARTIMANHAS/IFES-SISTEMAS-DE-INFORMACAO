"""Parte 1 - Producao e Armazenamento do conhecimento."""

from pprint import pprint

from sgc_empresa import (
    converter_tacito_para_explicito,
    montar_base_exemplo,
    salvar_base_json,
)


print("LAB 6 - PARTE 1")
print("Producao e armazenamento do conhecimento\n")

print("1. Conversao do conhecimento tacito em explicito (POP):")
pprint(converter_tacito_para_explicito(), sort_dicts=False)

print("\n2. Base de conhecimento apos inclusao de novos registros:")
base = montar_base_exemplo()
pprint(base, sort_dicts=False)

arquivo = salvar_base_json(base)
print(f"\n3. Persistencia concluida em: {arquivo.name}")
