// Produzido por LUCAS GARCIA & LUIS AUGUSTO DE SOUZA
#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

TLista listas;

void inicializa(TLista *DB){
    head();

    menu();

    copy();
}

int main(){
    inicializa(&listas);
    return 0;
}

