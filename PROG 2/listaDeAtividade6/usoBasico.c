// Podemos alterar valores de posições da string. Exemplo:
int main() {
char str[10] = "Joao";
printf("\n\nString: %s", str);
printf("\nSegunda letra: %c", str[1] );
str[1] = 'U';
printf("\nAgora a segunda letra eh: %c", str[1] );
printf("\n\nString resultante: %s", str);
return(0);
}

// Funções para manipulação
// ► fgets   ler uma string do teclado.
// ► strcpy  copia uma string para outra
// ► strcat  concatena duas strings
// ► strlen  retorna o tamanho de uma string
// ► strcmp  compara duas strings
// ► strchr  procura um caracter em uma string
// ► strstr  procura uma string em outra string
// ► strupr  converte para maiúsculas
// ► strlwr  converte para minúsculas
