import presets

def main():
    nome = presets.validNome()
    idade = presets.validIdade()
    salario = presets.validSalario()
    sx = presets.validSexo()
    uf = presets.validUF()

    print("-----------------Dados------------")
    print("nome: %s" %nome)
    print("Idade: %d" %idade)
    print("Salário: %d" %salario)
    print("Sexo: %s" %sx)
    print("Estado Civil: %s" %uf)

main()