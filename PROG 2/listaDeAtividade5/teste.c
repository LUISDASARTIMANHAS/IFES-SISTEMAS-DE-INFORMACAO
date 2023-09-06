#include "functions.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    head();
    int *data;
    int elementos = 10;
    alocarMEM(&data);
    // printf("Entre com a quantidade de números: ");
    // int quant_numeros = input();
    // data = (int *) malloc (quant_numeros * sizeof (int) );

    saveArray(&elementos,data,12);
    saveArray(&elementos,data,15);
    saveArray(&elementos,data,5);
    // autoMEM(data,elementos);

    imprimirArray(data,elementos);
    copy();
    return 0;
}