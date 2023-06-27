import presets

# Utilize a função criada nos exercícios anteriores para gerar agora um vetor com 100 números aleatórios. Faça uma função que receba como parâmetro esse vetor e dois índices (início e fim) e retorne a soma dos números apenas do intervalo entre os índices [início, fim]. 


# Lembre-se de fazer a validação: início >= 0, fim < 100 e início <= fim.
def sumItervalVetor(data,ini,fim):
    i = 0
    soma = 0
    if(ini >= 0) and (fim < 100) and (ini <= fim):
        while(i < fim):
            soma = soma + data[i]
            i = i + 1
    return soma

def main():
    presets.head()
    vetorNum = []
    inicio = presets.validNum()
    fim = presets.validNum()

    presets.gerarNumQtd(100,1,100,vetorNum)
    total = sumItervalVetor(vetorNum,inicio,fim)

    presets.imprimirArray("Esse e o vetorNum na linha ",vetorNum)
    print("A soma total foi: %d" %total)
    presets.copy()

main()