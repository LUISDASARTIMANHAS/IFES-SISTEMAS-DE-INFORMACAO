#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

void insertionSort(int vet[], int tam){
    int i,j;
    int valor;

    for (i = 0; i < tam; i++){
        valor = vet[i];
        j = i - 1;

        while ((j >= 0) && (valor < vet[j])){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = valor;
    }
}

void buscaBinaria(int vetor[],int pesq, int tam){
        int meio;
        int fim = tam-1;
        int ini = 0;
        int count = 0;

        while(ini<=fim){
            meio = (ini+fim)/2;

            if(pesq == vetor[meio]){
                printf("Executado: %d",count);
                return meio;
            }else if(pesq > vetor[meio]){
                ini=meio+1;
            }else{
                fim = meio-1;
            }
            count++;
        }
        printf("Executado: %d", count);
        return -1;
    }

int main(){
    head();
    int tam = 10;
    int data[10] = {10, 20, 30,40, 50, 60, 70, 80, 90, 100};

    insertionSort(data,tam);

    copy();
    return 0;
}
