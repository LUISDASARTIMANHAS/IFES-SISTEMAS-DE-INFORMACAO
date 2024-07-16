// ============================= BASE ======================
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Defina constantes para as sequências de escape ANSI das cores
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define SEPARETOR BLUE "\n================================================\n"  RESET

typedef char string[101];

struct ClassDatabase {
    int codigo;
    char nome[101];
    float preco;
    int qtde;
};
typedef struct ClassDatabase Database;

FILE * abrirArquivo(char * nomeArq, char * modo) {
    // ABRIR o arquivo
    FILE * arq;
    arq = fopen( nomeArq, modo );
    if ( arq == NULL) {
        printf(RED "ERRO ao abrir o arquivo." RESET);
        exit(-1);
    }
    return arq;
}
void carregarArquivo(FILE * arquivo, Database * vetProd, int *qtde) {
    fread( qtde, sizeof(int), 1, arquivo  );
    fread( vetProd, sizeof(Database), *qtde, arquivo  );
}
void gravarArquivo(FILE * arquivo, Database * vetProd, int qtde) {
    fwrite( &qtde, sizeof(int), 1, arquivo  );
    fwrite( vetProd, sizeof(Database), qtde, arquivo  );
}

void correct(){
    SetConsoleOutputCP(65001);
}

// ============================= FIM DO BASE ======================

void head(){
    correct();
    FILE * logs;
    logs = abrirArquivo("../data/logs.txt","a+");
    printf(SEPARETOR);
    printf(BLUE"\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    printf("\n\t Iniciando o programa....." RESET);
    printf(SEPARETOR);
    // save in logs
    fprintf(logs,SEPARETOR);
    fprintf(logs,"\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    fprintf(logs,"\n\t Iniciando programa.....");
    fprintf(logs,SEPARETOR);
    fclose(logs);
}

void copy(){
    FILE * logs;
    logs = abrirArquivo("../data/logs.txt","a+");
    correct();
    printf(SEPARETOR);
    printf(BLUE "\n\t DEVS:");
    printf("\n\t LUIS_DAS_ARTIMANHAS.");
    printf("\n\t PINGOBRAS S.A" RESET);
    printf(SEPARETOR);
    // save in logs
    fprintf(logs,"\n----------------------------------------------------");
    fprintf(logs,"\n\t DEVS:");
    fprintf(logs,"\n\t LUIS_DAS_ARTIMANHAS.");
    fprintf(logs,"\n\t PINGOBRAS S.A");
    fprintf(logs,"\n----------------------------------------------------\n");
    fclose(logs);
}

// inputs personalizados e modificados
float input(){
    float value;
    scanf("%f", &value);
    return value;
}
void inputS(char destino[]){
    scanf(" %100[^\n]s", destino);
}


// validadores
void validNome(char destino[]){
    do{
        printf(YELLOW "\nInsira o nome do Produto: " RESET);
        inputS(destino);
    }while (strlen(destino) < 3);
}

int validCod(){
    int cod;
    do{
        printf(YELLOW "\nInsira o código do Produto: " RESET);
        cod = input();
    }while (cod < 1);
    return cod;
}

float validTaxa(){
    float porcent;
    printf(YELLOW "\nInsira a porcentagem de aumento ou desconto: " RESET);
    int tax = input();

    while((tax <= 0 ) || (tax > 100)){
        printf(RED "\nA taxa não pode ser menor do que 0 ou maior que 100!\n" RESET);
        printf(YELLOW "\nInsira a porcentagem de aumento ou desconto: " RESET);
        tax = input();
    }
    porcent = (tax/100);
    return porcent;
}

int validQuantidade(){
    int qtd;
    do{
        printf(YELLOW "\nInsira a quantidade do Produto: " RESET);
        qtd = input();
    }while (qtd < 0);
    return qtd;
}

int validDia(){
    int dia;
    do{
        printf(YELLOW "\nInsira o dia de validade: " RESET);
        dia = input();
    }while ((dia < 1) || (dia > 31));
    return dia;
}

int validMes(){
    int mes;
    do{
        printf(YELLOW "\nInsira o mês de validade: " RESET);
        mes = input();
    }while ((mes < 1)||(mes > 12));
    return mes;
}

int validAno(){
    int ano;
    do{
        printf(YELLOW "\nInsira o Ano de validade: " RESET);
        ano = input();
    }while ((ano < 1900)||(ano > 3050));
    return ano;
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
float validPreco(){
    float prise;
    do{
        printf(YELLOW "\nInsira o preço do Produto: " RESET);
        prise = input();
    }while (prise < 0);
    return prise;
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
int validAltura(){
    float alt;
    do{
        printf("Insira a altura: ");
        alt = input();
    }while (alt < 0);
    return alt;
}
int validBase(){
    float base;
    do{
        printf("Insira a base: ");
        base = input();
    }while (base < 0);
    return base;
}
int validRaio(){
    float raio;
    do{
        printf("Insira o raio: ");
        raio = input();
    }while (raio < 0);
    return (raio*raio);
}

int validQTD(){
    float qtd;
    do{
        printf("Insira a quantidade de produto: ");
        qtd = input();
    }while (qtd < 0);
    return qtd;
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

int calcArRetangulo(){
    float base = validBase();
    float altura = validAltura();
    float area = base * altura;
    return area;
}
int calcArCirculo(){
    float raio = validRaio();
    float area = M_PI * raio;
    return area;
}

// void saveArray(int *i,int *array,int data){
//     char continuar;
//     do{
//         array[*i] = data;
//         (*i)++;
//         printf("\nDeseja continuar? ");
//         scanf(" %c",&continuar);
//         continuar = toupper(continuar);
//     } while(continuar == "S");
// }

void removerArray(int *qtde, int *array, int pos){
    int i;
    for (i = pos; i < (*qtde)-1; i++){
        array[i] = array[i+1];
    }
    (*qtde)--;
}

void alocarMEM(int **database,int *maxSpace){
    printf("Entre com a quantidade de números: ");
    int quant_numeros = input();
    *database = (int *) malloc (quant_numeros * sizeof (int) );
    *maxSpace = quant_numeros;
}

void reAlocarMEM(int **database, int *maxSpace){
    printf("\nVoce tem alocado: %d \n",*maxSpace);
    printf("Entre com a quantidade a mais de elementos: ");
    int qtdeNova = input();
    *maxSpace = (qtdeNova+(*maxSpace));
    int tam = (*maxSpace) * sizeof (int);

    *database = (int *) realloc (*database , tam );
}