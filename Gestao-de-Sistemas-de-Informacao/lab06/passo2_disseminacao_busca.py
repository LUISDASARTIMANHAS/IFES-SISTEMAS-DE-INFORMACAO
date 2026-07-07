"""Parte 2 - Disseminacao do conhecimento via busca."""

from pprint import pprint

from sgc_empresa import buscar_conhecimento, montar_base_exemplo


print("LAB 6 - PARTE 2")
print("Disseminacao e recuperacao do conhecimento\n")

base = montar_base_exemplo()
termos = ["backup", "cabo", "temperatura"]

for termo in termos:
    print(f"Busca por: {termo}")
    resultados = buscar_conhecimento(base, termo)
    pprint(resultados, sort_dicts=False)
    print("-" * 70)
