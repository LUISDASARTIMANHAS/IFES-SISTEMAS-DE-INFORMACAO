nome = input("Insira seu nome de usuario: ");
senha = input("Insira Sua senha: ");

while (len(nome) < 6):
    print("O nome não pode ser menor do que 6 caracteres");
    nome = input("Insira seu nome de usuario: ");

while (len(senha) < 6):
    print("A senha não pode ser menor do que 6 caracteres");
    senha = input("Insira Sua senha: ");

while (senha == nome):
    print("Senha invalida! A Senha não pode ser igual ao nome.");
    senha = input("Insira Sua senha: ");

print("Seu Usuário foi definido como: %s" %nome);
print("Sua senha foi definido como: %s" %senha);