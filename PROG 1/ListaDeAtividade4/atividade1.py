import presets

def main():
    presets.head()
    nome = presets.validUser()
    senha = presets.validSenha()

    while (senha == nome):
        print("Senha invalida! A Senha não pode ser igual ao nome.");
        senha = input("Insira Sua senha: ");
    
    print("Seu Usuário foi definido como: %s" %nome);
    print("Sua senha foi definido como: %s" %senha);
    presets.copy()

main()
