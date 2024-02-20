#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

TLista lista; //variável global


int main(){
    head();
    inicializa(&lista);

    copy();
    return 0;
}