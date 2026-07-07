"""Parte 3 - Aplicacao do conhecimento por meio de regras."""

from sgc_empresa import diagnostico_servidor


print("LAB 6 - PARTE 3")
print("Motor de regras para temperatura do servidor\n")

for temperatura in [34.2, 35.7, 37.4]:
    status = diagnostico_servidor(temperatura)
    print(f"Temperatura: {temperatura:.1f}C -> {status}")
