#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

    //===| Programa Principal |===========================
int main(){
    int res;
	SetConsoleOutputCP(65001);
    res = fatorialAuto(5);
    printf("res: %d",res);
}