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
void limparBuffer(){
    int ch;
    do{
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}


// inputs personalizados e modificados
float input(){
    float value;
    scanf("%f", &value);
    return value;
}

// validadores
void validString(char data[],int tam){
    printf("\n \t Espaço Maximo: %d", tam);
    printf("\n \t Insira um texto: ");
    fgets(data, tam, stdin);
    limparBuffer()
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
void inversor(char database[]){
    int fim = strlen(database)-1;
    int i;
    char e;

    for (i = 0; i < fim; i++,fim--){
        e = database[i];
        database[i] = database[fim];
        database[fim] = e;
    }
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

        if(e == '\n'){
            msm[i] = '\0';
        }
    }
}

void separador(char msm[],char pars[],char impars[]){
    int par = 0;
    int impar = 1;
    int i;
    char ePar,eImpar;
    int tam = strlen(msm);
    int tamSubsStrs = tam/2;

    for (i = 0; i < tam; i++,par=par+2,impar=impar+2){
        ePar = msm[par];
        eImpar= msm[impar];

        pars[i] = ePar;
        impars[i] = eImpar;
    }
    inversor(impars);
    pars[tamSubsStrs] = '\0';
    impars[tamSubsStrs] = '\0';
}

void intercalador(char cripto[],char pars[],char impars[]){
    int i;
    int tam = strlen(pars)+strlen(impars);
    char e1,e2;

    for (i = 0; i < tam; i++){
        e1 = pars[i];
        e2 = impars[i];
        cripto[i] = e1;
        cripto[i+1] = e2;
    }
    cripto[tam] = '\0';
}
// Terceira Etapa – Intercalar os elementos da string1 com os elementos da string2 para formar a mensagem criptografada. Primeiro pegue o primeiro elemento da string1 seguido do primeiro da string2, depois o segundo da string1 com o segundo da string2 e assim sucessivamente. Se uma das duas strings terminar, continue pegando apenas da outra string, até que todos os elementos tenham sido intercalados.