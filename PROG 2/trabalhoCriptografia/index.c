#include  "functions.c"
#define maxTam 1024
// Terceira Etapa – Intercalar os elementos da string1 com os elementos da string2 para formar a mensagem criptografada. Primeiro pegue o primeiro elemento da string1 seguido do primeiro da string2, depois o segundo da string1 com o segundo da string2 e assim sucessivamente. Se uma das duas strings terminar, continue pegando apenas da outra string, até que todos os elementos tenham sido intercalados.

// Problemas Hiper-Interessantes com 0 (zero) e @.
// Pa0el)mrszH p r0l ternss@etesnc-meoi( e@0e b r.

int main(){
    correct();
    head();
    char dataString[maxTam];
    char string1[maxTam/2];
    char string2[maxTam/2];
    char cripto[maxTam];
    validString(dataString,maxTam);

    trocar(dataString);
    separador(dataString,string1,string2);
    intercalador(cripto,string1,string2);

    printf("\n----------------------------------------------------\n");
    printf("   \t STRING  - 1: %s", string1);
    printf("\n \t TAMANHO - 1: %d", strlen(string1));
    printf("\n \t STRING  - 2: %s", string2);
    printf("\n \t TAMANHO - 2: %d", strlen(string2));
    printf("\n \t CRIPTO: %s", cripto);
    printf("\n \t TAMANHO: %d", strlen(cripto));
    printf("\n----------------------------------------------------\n");
    copy();
    return 0;
}


// EXEMPLO: Considere a mensagem:
//Problemas Hiper-Interessantes com 0 (zero) e @.
// Primeira etapa: Pr0blem@s Hiper-Interess@ntes c0m o (zer0) e a.
// Após a segunda etapa:
// P0lmsHprItrs@tscmo(e0 . (posições ímpares – string1)
// ae)rz 0 enseen-ei @ebr (posições pares de forma inversa – string2)
// Após a terceira etapa, a frase resultante é:
// Pa0el)mrszH p r0l ternss@etesnc-meoi( e@0e b r. (mensagem criptografada)