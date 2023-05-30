nome = input("Insira seu nome: ");
nTam = len(nome)

while(nTam <= 3 ):
    print("O nome não pode ser menor do que 3 caracteres");
    nome = input("Insira seu nome: ");
    nTam = len(nome)

idade = int(input("Insira sua idade: "));
while(idade <= 0) or (idade >= 50):
    print("Idade invalida.");
    idade = int(input("Insira sua idade: "));

salario = int(input("Insira seu salario: "));
while(salario < 0):
    print("Salario invalido.")
    salario = input("Insira Seu salario: ");

sx = input("Insira seu sexo(F/M): ").upper();
while (sx != "F") and (sx != "M"):
    print("Sexo invalido.")
    sx = input("Insira seu sexo(F/M): ").upper();

uf = input("Insira seu Estado Civil: ").upper();
while (uf != "S") and (uf != "C") and (uf != "V") and (uf != "D"):
    print("Sexo invalido.")
    uf = input("Insira seu Estado Civil: ").upper();

print("-----------------Dados------------")
print("nome: %s" %nome)
print("Idade: %d" %idade)
print("Salário: %d" %salario)
print("Sexo: %s" %sx)
print("Estado Civil: %s" %uf)