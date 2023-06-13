# Faça um programa, usando funções, para imprimir:
import presets

def main():
    peso = presets.validPeso()
    altura = presets.validAltura()
    imc = (peso) / (altura * altura)

main()