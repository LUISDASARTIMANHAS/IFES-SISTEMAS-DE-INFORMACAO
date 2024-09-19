//Feito por: Lucas Garcia E Luis Augusto
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define _USE_MATH_DEFINES

typedef char string[101];

void correct(){
    SetConsoleOutputCP(65001);
}

// inputs personalizados e modificados
int FileReadInt(FILE *arquivo){
    int value;
    fscanf(arquivo, "%d" , &value);
    return value;
}
long long int FileReadLongLongInt(FILE *arquivo){
    long long int value;
    fscanf(arquivo, "%lld" , &value);
    return value;
}
float input(){
    float value;
    scanf("%f", &value);
    return value;
}
float inputBoleano(){
	int value;
	do{
		fflush(stdin);
		scanf("%d", &value);
	}while(value != 1 && value != 0);
	return value;
}
void FileReadString(FILE *arquivo,char destino[]){
    int value;
    fscanf(arquivo, "%s" , &destino);
}
void inputS(char destino[]){
    scanf(" %100[^\n]s", destino);
}

// Gera um número aleatório entre 0 (inclusive) e 1 (exclusivo)
double aleatorio_quebrado() {
    // Inicializa a semente para gerar números aleatórios diferentes a cada execução
    srand(time(NULL));

    // RAND_MAX é o maior valor que rand() pode retornar
    return (double)rand() / RAND_MAX;
}

// Gera um número aleatório entre min (inclusive) e max (exclusivo)
double aleatorio_intervalo(double min, double max) {
    return min + (max - min) * aleatorio_quebrado();
}

int mod(int x, int y){
	return (x%y);
}

long long int hash(long long int k,int tamVetor){
    // Para o primeiro cálculo:
    // h(k) = k mod N
    // N eh o tamanho do vetor
    return mod(k,tamVetor);
}

long long int hash2(long long int k,int tamVetor){
    // N eh o tamanho do vetor
    // Caso haja colisão, inicialmente calculamos h2(K),
    // que pode ser definida como:
    // h2(k) = 1 + ( k mod (N-1) )
    int h1 = hash(k,tamVetor-1);
    return 1 + h1;
}

long long int reHash(long long int i,int k, int tamVetor){
    // N eh o tamanho do vetor
    // rh(i,k) = ( i + h2(k) ) mod N
    int h2 = hash2(k,tamVetor);
    return mod((i +  h2), tamVetor);
}

FILE * abrirArquivo(char * nomeArq, char * modo) {
    FILE * arq;
    arq = fopen(nomeArq, modo);
    if (arq == NULL) {
        printf("ERRO ao abrir o arquivo.\n");
        exit(-1);
    }
    printf("INFO: Arquivo Aberto! Bom uso.\n");
    return arq;
}