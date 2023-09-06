#include "functions.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    head();
    int *data,space;
    int elementos = 10;
    alocarMEM(&data,&space);

    saveArray(&elementos,data,12);
    saveArray(&elementos,data,15);
    saveArray(&elementos,data,5);
    reAlocarMEM(&data,&space);

    imprimirArray(data,elementos);
    copy();
    return 0;
}