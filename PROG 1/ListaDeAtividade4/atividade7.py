# Faça um programa, usando funções, para imprimir:
from typing import Concatenate
import presets

def main():
    presets.head()
    peso = presets.validPeso()
    altura = presets.validAltura()
    imc = (peso) / (altura * altura)
    categoria = presets.validImc(imc)
    print("-----------------------DADOS--------------------")
    print("\t Peso: %d" %peso)
    print("\t Altura: %0.2d" %altura)
    print("\t IMC: %d" %imc)
    print("\t Categoria: %s" %categoria)
    print("------------------------------------------------")
    presets.copy()

main()