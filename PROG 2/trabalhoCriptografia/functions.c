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
    int tamPars = strlen(pars);
    int tamImpars = strlen(impars);
    int tam = (tamPars + tamImpars);
    int i;
    int iPar=0;
    int iImpar=0;
    char ePar,eImpar;

    printf("\ntamanhos %d", tam);
    for (i = 0; i < tam; i++){
        ePar = pars[iPar];
        eImpar = impars[iImpar];

        if (i % 2 == 0){
            cripto[i] = ePar;
            iPar++;
        }else{
            cripto[i] = eImpar;
            iImpar++;
        }
    }
    cripto[tam] = '\0';
}