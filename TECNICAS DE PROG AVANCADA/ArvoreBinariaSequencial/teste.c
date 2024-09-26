#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar(int vet[],int i,int f){
    int aux;
    aux = vet[i];
    vet[i] = vet[f];
    vet[f] = aux;
}

void insereArvBin(long long int R[], int i, long long int valor){
    printf("\n\n Executando inserção %lld, no indice %d",valor, i);
    
    if (i >= R[i]){
        // inserção a direita
        if (R[i+2] == NULL){
            printf("\n\n Inserção a direita.");
            R[i+2] = valor;
        }else{
            printf("\n\n Descendo a Direita.");
            insereArvBin(R,i+2,valor);
        }
    }else{
        // inserção a esquerda
        if (R[i+1] == NULL){
            printf("\n\n Inserção a esquerda.");
            R[i+1] = valor;
        }else{
            printf("\n\n Descendo a esquerda.");
            insereArvBin(R,i+1,valor);
        }

    }
}

// long long int buscaArvBin(long long int R[],long long int args){
// 	if(R == NULL){
// 		return NULL;
// 	} else if(args == R[args]){
// 		//No Encontrado.
// 		return R;
// 	} else if(args > R[args]){
// 		//Desce pela Direita.
// 		printf("\n Visitando %lld e DESCENDO pela DIREITA...", R[args]);
// 		return buscaArvBin(&R[args+1], args);
// 	} else {
// 		//Desce pela Esquerda.
// 		printf("\n Visitando %lld e DESCENDO pela ESQUERDA...", R[args]);
// 		return buscaArvBin(&R[args-1], args);
//     }
// }

int main(){
    long long int raiz[100];
    int i;
    
    insereArvBin(raiz,0,2023122760328);
    insereArvBin(raiz,0,2023122760329);
    insereArvBin(raiz,0,2023122760325);
    return 0;
}