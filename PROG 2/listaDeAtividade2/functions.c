#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

// SetConsoleOutputCP(65001);

int head(){
    printf("\n ----------------------------------------------------");
    printf("\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    printf("\n\t Iniciando programa.....");
    printf("\n----------------------------------------------------");
    return 0;
}

int copy(){
    printf("\n----------------------------------------------------");
    printf("\n\t DEVS:");
    printf("\n\t LUIS_DAS_ARTIMANHAS.");
    printf("\n\t PINGOBRAS S.A");
    printf("\n----------------------------------------------------");
    return 0;
}

int input(){
    int value = scanf("%d", &value);
    return value;
}

int validNota(){
    printf("Insira uma Nota: ");
    int nota = input();
    
    while((nota < 0) || ( nota > 10)){
        printf("Nota Invalida!\n");
        printf("Insira uma Nota: ");
        nota = input();
        }
    return nota;
}

int validNome(){
    printf("Insira seu nome: ");
    int nome = input();
    int nTam = len(nome);

    while(nTam <= 3 ){
        printf("O nome não pode ser menor do que 3 caracteres");
        printf("Insira seu nome: ");
        nome = input();
        nTam = len(nome);
    }
    return nome;
}

int validUser(){
    printf("Insira seu usuario: ");
    int user = input();
    int nTam = len(user);
    
    while(nTam <= 3 ){
        printf("O nome não pode ser menor do que 6 caracteres");
        printf("Insira seu usuario: ");
        user = input();
        nTam = len(user);
    }
    return user;
}

int validIdade(){
    printf("Insira sua idade: ");
    int idade = input();
    while((idade <= 0) || (idade >= 50)){
        printf("Idade invalida.");
        printf("Insira sua idade: ");
        idade = input();
        
    }
    return idade;
}

int validSalario(){
    printf("Insira seu salario: ");
    int salario = input();
    
    while(salario < 0){
        printf("Salario invalido.");
        printf("Insira Seu salario: ");
        salario = input();
    }
    return salario;
}

// int validSexo(){
//     int sx = input();
//     printf("Insira seu sexo(F/M): ").upper();
//     while( (sx != "F") && (sx != "M")){
//         printf("Sexo invalido.");
//         sx = input();
//         printf("Insira seu sexo(F/M): ").upper();
//     }
//     return sx;
// }

// int validUF(){
//     int uf = input();
//     ("Insira seu Estado Civil: ")
//     while((uf != "S") && (uf != "C") && (uf != "V") && (uf != "D")){
//         printf("Sexo invalido.");
//         uf = input();
//         ("Insira seu Estado Civil: ").upper();
//     }
//     return uf;
// }

int validSenha(){
    printf("Insira Sua senha: ");
    int senha = input();
    while (len(senha) < 6){
        printf("A senha não pode ser men|| do que 6 caracteres");
        printf("Insira Sua senha: ");
        senha = input();
        
    }
    return senha;
}

int fatorial(int num){
    int fat = 1;

    while( num > 1){
        fat = fat * num;
        num = num - 1;
    }
    return fat;
}