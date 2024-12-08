#include "fileSys.h"
//=================================================

void correct(){
    SetConsoleOutputCP(65001);
}
void head(){
    printf("\n ----------------------------------------------------");
    printf("\n\t LUIS_DAS_ARTIMANHAS & PINGOBRAS S.A");
    printf("\n\t Iniciando programa.....");
    printf("\n----------------------------------------------------\n");
}

void copy(){
    printf("\n----------------------------------------------------");
    printf("\n\t DEVS:");
    printf("\n\t LUIS_DAS_ARTIMANHAS.");
    printf("\n\t PINGOBRAS S.A");
    printf("\n----------------------------------------------------\n");
}


// Função para abrir um arquivo no modo especificado
FILE *abrirArquivo(char *nomeArq, char *modo) {
    FILE *arquivo;

    if (nomeArq == NULL){
        arquivo = fopen(DEFAULT_DATABASE, modo);
    }
    arquivo = fopen(nomeArq, modo);

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArq);
        exit(1);
    }
    printf("\n INFO: Arquivo %s Aberto! Bom uso.\n", nomeArq);
    return arquivo;
}

// Função para abrir um arquivo no modo leitura
FILE *lerArquivo(char *nomeArq) {
    FILE *arquivo;

    if (nomeArq == NULL){
        arquivo = fopen(DEFAULT_DATABASE, "r");
    }
    arquivo = fopen(nomeArq, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArq);
        exit(1);
    }
    printf("\n INFO: Arquivo %s Aberto! Bom uso.\n", nomeArq);
    return arquivo;
}

// Função para abrir um arquivo no modo escritura
FILE *escreverArquivo(char *nomeArq) {
    FILE *arquivo;

    if (nomeArq == NULL){
        arquivo = fopen(DEFAULT_DATABASE, "w");
    }
    arquivo = fopen(nomeArq, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArq);
        exit(1);
    }
    printf("\n INFO: Arquivo %s Aberto! Bom uso.\n", nomeArq);
    return arquivo;
}

/**
 * @brief Calcula e exibe o tempo de execução em segundos.
 * 
 * @param ini Tempo inicial.
 * @param fim Tempo final.
 */
double getTime() {
    double tempo = clock();
    return tempo;
}

/**
 * @brief Calcula e exibe o tempo de execução em segundos.
 * 
 * @param ini Tempo inicial.
 * @param fim Tempo final.
 */
void calcularTempo(double ini) {
    double fim = getTime();
    double tempoDecorrido = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempoDecorrido);
}

    // fprintf(arquivo, "\n%3d %-50s %5d %10.2f", cod, nome, qtde, preco  );

/**
 * @brief // Escreve valores inteiros no arquivo
 */
void fWiriteINT (FILE *arquivo, int value){
    fprintf(arquivo, "%d\n", value);
}
/**
 * @brief // Escreve valores string no arquivo
 */
void fWiriteSTRING (FILE *arquivo, char value[]){
    fprintf(arquivo, "%s\n", value);
}
/**
 * @brief // Escreve valores string no arquivo
 */
void fWiriteFLOAT (FILE *arquivo, float value){
    fprintf(arquivo, "%f\n", value);
}
/**
 * @brief // Escreve valores string no arquivo
 */
void fWiriteDOUBLE (FILE *arquivo, double value){
    fprintf(arquivo, "%lf\n", value);
}

/**
 * @brief // input para captar int do arquivo
 */
int freadINT (FILE *arquivo){
    int value;
    fscanf(arquivo, "%d" , &value);
    return value;
}

/**
 * @brief // string para captar  do arquivo
 */
void freadSTRING (FILE *arquivo, char destino[]){
    fscanf(arquivo, " %99[^\n]s" , destino);
}

/**
 * @brief // input para float Double do arquivo
 */
float freadFloat (FILE *arquivo){
    float value;
    fscanf(arquivo, "%f" , &value);
    return value;
}

/**
 * @brief // input para captar Double do arquivo
 */
double freadDouble (FILE *arquivo){
    double value;
    fscanf(arquivo, "%lf" , &value);
    return value;
}

float input(){
    float value;
    scanf("%f", &value);
    return value;
}
double inputDouble(){
    double value;
    scanf("%lf", &value);
    return value;
}

/**
 * @brief // input para captar long long int do teclado do usuario
 */
long long int inputDLLD(){
    long long int value;
    scanf("%lld", &value);
    return value;
}

/**
 * @brief // input para captar Verdadeiro ou falso (Bloeano) do teclado do usuario
 */
int inputBoleano(){
	int value;
	do{
		fflush(stdin);
		scanf("%d", &value);
	}while(value != 1 && value != 0);
	return value;
}

/**
 * @brief // input para captar Strings do teclado do usuario
 */
void inputS(char destino[]){
    scanf(" %100[^\n]s", destino);
}
