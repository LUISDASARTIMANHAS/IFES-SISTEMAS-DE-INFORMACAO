#include <windows.h>
#include <math.h>
#define _USE_MATH_DEFINES

// SetConsoleOutputCP();

void head(){
    printf("\n ----------------------------------------------------");
    printf("\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    printf("\n\t Iniciando programa.....");
    printf("\n----------------------------------------------------\n");
}

void copy(){
    printf("\n----------------------------------------------------");
    printf("\n\t DEVS:");
    printf("\n\t LUIS_DAS_ARTIMANHAS.");
    printf("\n\t PINGOBRAS S.A");
    printf("\n----------------------------------------------------\n");
}

float input(){
    float value;
    scanf("%f", &value);
    return value;
}

int validNum(){
    printf("Insira um numero: ");
    int num = input();

    while(num < 0){
        printf("Salario invalido.");
        printf("Insira Seu salario: ");
        num = input();
    }
    return num;
}

int validNota(){
    float nota;
    do{
        printf("Insira uma Nota: ");
        nota = input();
    }while ((nota < 0) || ( nota > 10));
    return nota;
}
int validMatricula(){
    float matricula;
    do{
        printf("Insira sua matricula: ");
        matricula = input();
    }while (matricula < 0);
    return matricula;
}

// int validNome(){
//     printf("Insira seu nome: ");
//     int nome = inputS();
//     int nTam = strlen(nome);

//     while(nTam <= 3 ){
//         printf("O nome não pode ser menor do que 3 caracteres");
//         printf("Insira seu nome: ");
//         nome = inputS();
//         nTam = strlen(nome);
//     }
//     return nome;
// }

// int validUser(){
//     printf("Insira seu usuario: ");
//     int user = input();
//     int nTam = len(user);
    
//     while(nTam <= 3 ){
//         printf("O nome não pode ser menor do que 6 caracteres");
//         printf("Insira seu usuario: ");
//         user = input();
//         nTam = len(user);
//     }
//     return user;
// }

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

// int validSenha(){
//     printf("Insira Sua senha: ");
//     int senha = input();
//     while (len(senha) < 6){
//         printf("A senha não pode ser men|| do que 6 caracteres");
//         printf("Insira Sua senha: ");
//         senha = input();
//     }
//     return senha;
// }

int validPreco(){
    float prc;
    do{
        printf("Insira o preco do produto: ");
        prc = input();
    }while (prc < 1);
    return prc;
}

int fatorial(){
    int i,num, fat;
    printf("Informe o número: ");
    scanf("%d", &num);
    fat = 1;
    for(i=num; i > 1 ; i--) {
        fat = fat * i;
    }
    return fat;
}
int lerOpcaoCalc() {
    int op;
    printf("\n\nCALCULAR A ÁREA:\n");
    printf("1-Retângulo\n");
    printf("2-Círculo\n");
    printf("0-Sair\n");
    printf("Informe sua opção: ");
    scanf("%d", &op);
    // VALIDAR a opção entre 0, 1 e 2
    return op;
}

int somar(int num1, int num2){
    int total = num1 + num2;
    printf("\nSomando os numeros: %d + %d\n", num1,num2);
    return total;
}
int diminuir(int num1, int num2){
    int total = num1 - num2;
    printf("\n Subtraindo os numeros: %d - %d\n", num1,num2);
    return total;
}
float calcMedia3(float n1,float n2,float n3){
    float media = (n1 + n2 + n3 )/3;
    return media;
}
int menuPay(){
    printf("\n=======SELECIONAR FORMA DE PAGAMENTO=======\n");
    printf("1-A vista\n");
    printf("2-A prazo\n");
    printf("=====================\n");
    printf("Forma: ");
    int opc = input();

    return opc;
}