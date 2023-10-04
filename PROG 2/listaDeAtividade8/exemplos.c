#include <stdlib.h>
#include <stdio.h>
#include "functions.c"


int main(){
    BancoDeDados db;
    db.codigo = 100;
    lerData(&db);

    printf(db.date.dia);
    printf(db.date.mes);
    printf(db.date.ano);
}