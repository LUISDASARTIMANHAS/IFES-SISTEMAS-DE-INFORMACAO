# A senha não pode ser igual ao nome do usuário, 
# nem menor que 6 caracteres.
#  Caso ocorra o erro, mostre a mensagem de erro e volte a pedir as informações. 
# No final imprima o nome e a senha.
# DICA: Use a função “len” para pegar a quantidade de caracteres de uma string.

# Faça um programa que leia um nome de usuário e a sua senha. 
nome = input("Insira seu nome de usuario: ");
senha = input("Insira Sua senha: ");

while (len(nome) < 6):
    print("")