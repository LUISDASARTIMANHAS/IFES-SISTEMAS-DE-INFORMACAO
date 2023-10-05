#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int correct(){
    SetConsoleOutputCP(65001);
    return 0;
}
void head(){
    correct();
    printf("\n ----------------------------------------------------");
    printf("\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    printf("\n\t Iniciando o programa.....");
    printf("\n----------------------------------------------------\n");
}

void copy(){
    correct();
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

void imprimirArray(int *array, int qtde){
    int i;

    for (i = 0; i < qtde; i++){
        printf("%d  ",array[i]);
    }
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


void saveArray(int *i,int *array,int data){
    char continuar;
    do{
        array[*i] = data;
        (*i)++;
        printf("\nDeseja continuar? ");
        scanf(" %c",&continuar);
    } while(toupper(continuar == 'S'));
}

void removerArray(int *qtde, int *array, int pos){
    int i;
    for (i = pos; i < (*qtde)-1; i++){
        array[i] = array[i+1];
    }
    (*qtde)--;
}

void trocar(char msm[]) {
    int i;
    char e;
    int tam = strlen(msm);

    for (i = 0; i < tam; i++){
        e = msm[i];

        if(e == 'o'){
            msm[i] = '0';
        }else if (e == '0'){
            msm[i] = 'o';
        }

        if(e == 'a'){
            msm[i] = '@';
        }else if (e == '@'){
            msm[i] = 'a';
        }
    }
}

void separador(char msm[],char impars[],char pars[]){
    int par,impar;
    int count1 = 0;
    int count2 = 0;
    char e;
    int tam = strlen(msm);
    // Segunda Etapa – Obter todos os caracteres da mensagem que estão em posições
// ímpares e colocar em uma string (string1). Obter todos os caracteres da mensagem que estão em posições pares, mas na ordem inversa, e colocar em outra string (string2). Considere todos os tipos de caracteres, como pontuação, espaços em branco e qualquer  símbolo que aparecer.
    for (par = 0; par < tam; par=par+2){
        e = msm[par];
        pars[count2] = e;

        printf("%c", e);
        count1 = count1+1;
    }
    for (impar = 1; impar < tam; impar=impar+2){
        e = msm[impar];
        impars[count2] = e;

        printf("%c", e);
        count2 = count2+1;
    }
}