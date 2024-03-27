#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

TLista listas;

void inicializa(TLista *DB){
    menu();
    copy();
}

int main(){
    inicializa(&listas);
    return 0;
}

