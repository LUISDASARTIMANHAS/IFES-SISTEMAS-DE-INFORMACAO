"""Respostas comentadas para os exercicios de avaliacao tecnica."""

from sgc_empresa import montar_base_exemplo, salvar_base_json


print("LAB 6 - EXERCICIOS DE AVALIACAO TECNICA\n")

base = montar_base_exemplo()
arquivo = salvar_base_json(base)

print("1. Persistencia de dados")
print(
    f"A base foi salva em '{arquivo.name}' usando a biblioteca json, "
    "atendendo ao requisito do roteiro."
)

print("\n2. Conversao de conhecimento")
print(
    "A conversao de conhecimento tacito para explicito ocorre quando o relato do "
    "Sr. Carlos e estruturado em campos formais do POP e em registros da base."
)

print("\n3. Analise de caso")
print(
    "Sem o sistema, a fase interrompida seria principalmente a de armazenamento, "
    "pois o conhecimento do especialista nao seria codificado nem preservado."
)

print("\n4. Evolucao com NLP")
print(
    "NLP pode melhorar a disseminacao com busca semantica, expansao de sinonimos, "
    "resumo automatico de incidentes e classificacao inteligente por contexto."
)
