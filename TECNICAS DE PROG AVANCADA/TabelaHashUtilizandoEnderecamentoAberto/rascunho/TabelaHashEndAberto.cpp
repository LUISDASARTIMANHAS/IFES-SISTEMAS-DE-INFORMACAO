#include "TabelaHashEndAberto.h"

//Feito por: Lucas Garcia E Luis Augusto

void correct(){
    SetConsoleOutputCP(65001);
}

// inputs personalizados e modificados
int FileReadInt(FILE *arquivo){
    int value;
    fscanf(arquivo, "%d" , &value);
    return value;
}
long long int FileReadLongLongInt(FILE *arquivo){
    long long int value;
    fscanf(arquivo, "%lld" , &value);
    return value;
}
float input(){
    float value;
    scanf("%f", &value);
    return value;
}
float inputBoleano(){
	int value;
	do{
		fflush(stdin);
		scanf("%d", &value);
	}while(value != 1 && value != 0);
	return value;
}
void FileReadString(FILE *arquivo,char destino[]){
    int value;
    fscanf(arquivo, "%s" , &destino);
}
void inputS(char destino[]){
    scanf(" %100[^\n]s", destino);
}

// Gera um número aleatório entre 0 (inclusive) e 1 (exclusivo)
double aleatorio_quebrado() {
    // Inicializa a semente para gerar números aleatórios diferentes a cada execução
    srand(time(NULL));

    // RAND_MAX é o maior valor que rand() pode retornar
    return (double)rand() / RAND_MAX;
}

// Gera um número aleatório entre min (inclusive) e max (exclusivo)
double aleatorio_intervalo(double min, double max) {
    return min + (max - min) * aleatorio_quebrado();
}

int mod(int x, int y){
	return (x%y);
}

long long int hash(long long int k,int tamVetor){
    // Para o primeiro cálculo:
    // h(k) = k mod N
    // N eh o tamanho do vetor
    return mod(k,tamVetor);
}

long long int hash2(long long int k,int tamVetor){
    // N eh o tamanho do vetor
    // Caso haja colisão, inicialmente calculamos h2(K),
    // que pode ser definida como:
    // h2(k) = 1 + ( k mod (N-1) )
    int h1 = hash(k,tamVetor-1);
    return 1 + h1;
}

long long int reHash(long long int i,int k, int tamVetor){
    // N eh o tamanho do vetor
    // rh(i,k) = ( i + h2(k) ) mod N
    int h2 = hash2(k,tamVetor);
    return mod((i +  h2), tamVetor);
}

//=================================================
FILE * abrirArquivo(char * nomeArq, char * modo) {
    FILE * arq;
    arq = fopen(nomeArq, modo);
    if (arq == NULL) {
        printf("ERRO ao abrir o arquivo.\n");
        exit(-1);
    }
    printf("INFO: Arquivo Aberto! Bom uso.\n");
    return arq;
}

//=================================================

//=================================================
float aleatorio(int n){
    return (rand() % (n+1));
}
//=================================================
void lerArquivo(TLista *lista, FILE *arquivoLista) {
    char nome[100];
    char matriculaStr[20];  
    long long int matricula;

    while (fgets(nome, sizeof(nome), arquivoLista) != NULL) {
        nome[strcspn(nome, "\n")] = 0;  // Remover a quebra de linha do nome
        if (fgets(matriculaStr, sizeof(matriculaStr), arquivoLista) != NULL) {
            matricula = strtol(matriculaStr, NULL, 10);  // Converter string para long long int
            inserir(lista, matricula, nome);
        }
    }
}
//=================================================
void inicializa(TLista *lista, FILE *arquivoLista) {
    construirListaDoZero(lista);
    fseek(arquivoLista, 0, SEEK_END);
    long tamanho = ftell(arquivoLista);
    if (tamanho != 0) {
        fseek(arquivoLista, 0, SEEK_SET);  // Retorna ao início do arquivo
        lerArquivo(lista, arquivoLista);
    }
}

//=================================================
void salvarDadosNoArquivo(TabelaHash *tabela, FILE *arquivoLista) {
    // Abrir o arquivo no modo de escrita para sobrescrever os dados
    arquivoLista = fopen("../../data/nomes_matriculas.txt", "w");
    if (arquivoLista == NULL) {
        printf("ERRO ao abrir o arquivo para gravação.\n");
        return;
    }

    // Iterar sobre a tabela hash e escrever cada entrada no arquivo
    for (int i = 0; i < tabela->tamanho; i++) {
        TElemento *atual = tabela->vetorListas[i].inicio;
        while (atual != NULL) {
            // Gravar o nome e a matrícula no arquivo
            fprintf(arquivoLista, "%s\n%lld\n", atual->nome, atual->valor);
            atual = atual->prox;
        }
    }

    // Fechar o arquivo após a gravação
    fclose(arquivoLista);
    printf("INFO: Dados salvos com sucesso no arquivo.\n");
}
//=================================================
int pesquisarMatricula2(TLista *lista, long long int matriculaBusca) {
    TElemento *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == matriculaBusca) {
            printf("Matrícula %lld encontrada. Nome: %s\n", matriculaBusca, atual->nome);
            return 1;  // Encontrado
        }
        atual = atual->prox;
    }
    printf("Matrícula %lld não encontrada na lista.\n", matriculaBusca);
    return 0;  // Não encontrado
}
//=================================================
int pesquisarMatricula(TLista *lista) {
    int matriculaBusca;
    printf("Digite a matrícula que deseja buscar: ");
    scanf("%d", &matriculaBusca);
    TElemento *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == matriculaBusca) {
            return matriculaBusca;
        }
        atual = atual->prox;
    }
    printf("Matrícula %d não encontrada na lista.\n", matriculaBusca);
    return matriculaBusca;
}
//=================================================
void inserir(TLista *lista, long long int valor, char *nome) {
    TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
    novo->valor = valor;
    strcpy(novo->nome, nome); 
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;

    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->total++;
}
//=================================================
int pedirOpcao3() {
    int opcao;
    
    printf("Escolha o tamanho da tabela hash em relação ao número total de matrículas:\n");
    printf("1 - 120%% do número de matrículas\n");
    printf("2 - 150%% do número de matrículas\n");
    printf("3 - 180%% do número de matrículas\n");
    printf("Digite sua opção (1, 2 ou 3): ");
    scanf("%d", &opcao);
    return opcao;
    
}
//=================================================
void exibeLista(TLista lista) {
    TElemento *atual = lista.inicio;
    int cont = 0;
    while (atual != NULL) {
        printf("  Número %d da lista: Matrícula (%lld), Nome: %s\n", ++cont, atual->valor, atual->nome);
        atual = atual->prox;
    }
}
//=================================================
void excluirLista(TLista *lista, long long int valor){
    TElemento *atual = lista->inicio;
    TElemento *anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            // Encontra o elemento a ser excluído
            if (atual == lista->inicio) {
                // Exclusão do primeiro elemento da lista
                printf("\n\n\tExcluindo o ELEMENTO %lld ...\n", atual->valor);
                lista->inicio = atual->prox;
                if (lista->inicio == NULL) {
                    // A lista tinha apenas um elemento
                    lista->fim = NULL;
                }
            } else if (atual == lista->fim) {
                // Exclusão do último elemento da lista
                printf("\n\n\tExcluindo o ELEMENTO %lld ...\n", atual->valor);
                lista->fim = anterior;
                lista->fim->prox = NULL;
            } else {
                // Exclusão de um elemento do meio da lista
                printf("\n\n\tExcluindo o ELEMENTO %lld ...\n", atual->valor);
                anterior->prox = atual->prox;
            }
            free(atual);
            lista->total--;
            return; // Sai da função após excluir o elemento
        }
        anterior = atual;
        atual = atual->prox; // move para o próximo elemento
    }
    printf("Elemento %lld não encontrado na lista.\n", valor);
}
//=================================================
long long int pedirOpcao(){
    int op;
    printf("\n%s\n", INICIO);
    do {
        printf("1 - Inserir na Lista\n");
        printf("2 - Exibe Lista\n");
        printf("3 - Excluir da Lista\n");
        printf("4 - Pesquisar Matricula\n");
        printf("5 - Total de Matriculas\n");
        printf("6 - Imprimir toda a Tabela Hash\n");
        printf("7 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);
        printf("%s\n", CORTE);
    } while ((op < 1) || (op > 7));
    return op;
}
//=================================================
long long int pedirNum(int caminhoASerEscolhido) {
    long long int num;
    if (caminhoASerEscolhido == 0){
        printf("Digite um numero para ser inserido: ");
        scanf("%lld", &num);  // Usar %lld para long long int
    }else{
        printf("Digite um numero para ser excluido: ");
        scanf("%lld", &num);  // Usar %lld para long long int
    }
    return num;
}

//================================================
void imprimirTabelaHash(TabelaHash *tabela) {
    printf("\n\n===| Exibição Completa da Tabela Hash |===\n\n");    
    for (int i = 0; i < tabela->tamanho; i++) {
        printf("Índice %d:\n", i);
        
        TElemento *atual = tabela->vetorListas[i].inicio;
        
        if (atual == NULL) {
            printf("  (vazio)\n");
        } else {
            while (atual != NULL) {
                printf("  Matrícula: %lld, Nome: %s\n", atual->valor, atual->nome); // Adicione o nome aqui
                atual = atual->prox;
            }
        }
    }
    printf("\n========================================\n");
}

//================================================
void menuPrincipal(TabelaHash *tabelaHash, int funcaoHashEscolhida) {
    long long int op;
    long long int numInseri;
    char nomeInseri[100];
    int repete = 0;
    do {
        op = pedirOpcao();
        switch (op) {
            case 1:
                // Inserir na Tabela Hash
                numInseri = pedirNum(0);
                printf("Digite o nome associado à matrícula: ");
                getchar();  // Para evitar problemas com a leitura do '\n' residual
                fgets(nomeInseri, sizeof(nomeInseri), stdin);
                nomeInseri[strcspn(nomeInseri, "\n")] = 0;  // Remover a quebra de linha
                inserirTabelaHash(tabelaHash, numInseri, nomeInseri, funcaoHashEscolhida);
                break;
            case 2:
                // Exibir a Tabela Hash
                exibeTabelaHash(tabelaHash);
                break;
            case 3:
                // Excluir da Tabela Hash
                numInseri = pedirNum(1);
                excluirTabelaHash(tabelaHash, numInseri, funcaoHashEscolhida);
                break;
            case 4:
                // Pesquisar uma matrícula na Tabela Hash
                numInseri = pedirNum(0);
                pesquisarTabelaHash(tabelaHash, numInseri, funcaoHashEscolhida);
                break;
            case 5:
                // Exibir total de matrículas na Tabela Hash
                printf("O total de matrículas na tabela é: %d\n", contarTotalMatriculas(tabelaHash));
                break;
            case 6:
                // Imprimir toda a tabela hash
                imprimirTabelaHash(tabelaHash);
                break;
            case 7:
                // Sair
                repete = 1;
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (repete == 0);
}

//================================================
int funcaoHashMultiplicacao(long long int matricula, int tamanho) {
    double A = 0.6180339887 * 0.5;  // Usar double para maior precisão
    double hashValue = matricula * A;
    int indice = (int)(tamanho * (hashValue - (long long int)hashValue));
    printf("Depuração - Valor de A: %f, Matricula: %lld, Índice Calculado: %d\n", A, matricula, indice);
    // Garantir que o índice seja positivo e dentro dos limites da tabela
    if (indice < 0) {
        indice = -indice;
    }
    return indice % tamanho;  
}
//================================================
int funcaoHashRestoDivisao(long long int matricula, int tamanho) {
    return matricula % tamanho;
}
//================================================
int escolherFuncaoHash() {
    int opcao;
    printf("Escolha a função hash:\n");
    printf("1 - Resto da Divisão\n");
    printf("2 - Método da Multiplicação\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    return opcao;
}
//================================================
int contarMatriculas(FILE *arquivoLista) {
    char linha[100];
    int totalMatriculas = 0;
    while (fgets(linha, sizeof(linha), arquivoLista) != NULL) {
        totalMatriculas++;
    }
    // Como cada matrícula ocupa duas linhas (nome e matrícula), dividimos por 2
    return totalMatriculas / 2;
}
//================================================
int contarTotalMatriculas(TabelaHash *tabela) {
    int total = 0;
    for (int i = 0; i < tabela->tamanho; i++) {
        total += tabela->vetorListas[i].total;  // Somar o total de cada lista encadeada
    }
    return total;
}
//================================================
int ehPrimo(int num) {
    if (num <= 1) return 0; // Números menores ou iguais a 1 não são primos
    if (num == 2) return 1; // 2 é primo
    if (num % 2 == 0) return 0; // Números pares não são primos
    // Verificar divisibilidade por números ímpares até a raiz quadrada de num
    for (int i = 3; i <= num*0.5; i += 2) {
        if (num % i == 0) {
            return 0; // Não é primo
        }
    }
    return 1; // É primo
}
//================================================
int acharProximoPrimo(int num) {
    // Continuar incrementando até encontrar um número primo
    while (!ehPrimo(num)) {
        num++;
    }
    return num;
}
//================================================
void inicializarTabelaHash(TabelaHash *tabela, int tamanho) {
    tabela->tamanho = tamanho;
    tabela->vetorElementos = (TElemento *)malloc((size_t)tamanho * sizeof(TElemento));
    // Inicializar todas as listas encadeadas em cada posição do vetor
    for (int i = 0; i < tamanho; i++) {
        construirListaDoZero(&tabela->vetorElementos[i]);
    }
}
//================================================
void inicializarTabela(TabelaHash *tabelaHash, FILE *arquivoLista) {
    int totalMatriculas = contarMatriculas(arquivoLista);
    int opcaoPorcentagem = pedirOpcao3();
    int tamanhoTabela;
    
    switch (opcaoPorcentagem) {
        case 1:
            tamanhoTabela = acharProximoPrimo((int)(totalMatriculas * 1.2));
            break;
        case 2:
            tamanhoTabela = acharProximoPrimo((int)(totalMatriculas * 1.5));
            break;
        case 3:
            tamanhoTabela = acharProximoPrimo((int)(totalMatriculas * 1.8));
            break;
        default:
            printf("Opção inválida\n");
            exit(1);
    }

    inicializarTabelaHash(tabelaHash, tamanhoTabela);
}
//================================================
void lerEInserirMatriculas(TabelaHash *tabelaHash, FILE *arquivoLista, int funcaoHashEscolhida) {
    rewind(arquivoLista);  // Reposicionar para o início do arquivo
    long long int matricula;
    char nome[100];

    while (fgets(nome, sizeof(nome), arquivoLista) != NULL) {  // Ler o nome
        nome[strcspn(nome, "\n")] = 0;  // Remover o '\n' do nome
        if (fscanf(arquivoLista, "%lld\n", &matricula) != EOF) {  // Ler a matrícula como long long int
            inserirTabelaHash(tabelaHash, matricula, nome, funcaoHashEscolhida);  // Inserir na tabela hash
        }
    }
}

//================================================
void executarMenu(TabelaHash *tabelaHash, int funcaoHashEscolhida) {
    menuPrincipal(tabelaHash, funcaoHashEscolhida);
}
//================================================
int pesquisarTabelaHash(TabelaHash *tabela, long long int matricula, int funcaoHashEscolhida) {
    int indice;
    if (funcaoHashEscolhida == 1) {
        indice = funcaoHashRestoDivisao(matricula, tabela->tamanho);
    } else {
        indice = funcaoHashMultiplicacao(matricula, tabela->tamanho);
    }

    if (pesquisarMatricula2(&tabela->vetorListas[indice], matricula)) {
        printf("Matrícula %lld encontrada na tabela hash.\n", matricula);
        return 1;  // Encontrado
    } else {
        printf("Erro: A matrícula %lld não foi encontrada na tabela.\n", matricula);
        return 0;  // Não encontrado
    }
}

//================================================
void inserirTabelaHash(TabelaHash *tabela, long long int matricula, char *nome, int funcaoHashEscolhida) {
    int indice;
    if (funcaoHashEscolhida == 1) {
        indice = funcaoHashRestoDivisao(matricula, tabela->tamanho);
    } else {
        indice = funcaoHashMultiplicacao(matricula, tabela->tamanho);
    }
    if (pesquisarMatricula2(&tabela->vetorListas[indice], matricula)) {
        printf("Erro: A matrícula %lld já está presente na tabela.\n", matricula);
        return;
    }

    // Inserir a nova matrícula na lista correspondente no índice da tabela hash
    inserir(&tabela->vetorListas[indice], matricula, nome);
    printf("Matrícula %lld inserida com sucesso.\n", matricula);
}

//================================================
void excluirTabelaHash(TabelaHash *tabela, long long int matricula, int funcaoHashEscolhida) {
    int indice;
    if (funcaoHashEscolhida == 1) {
        indice = funcaoHashRestoDivisao(matricula, tabela->tamanho);
    } else {
        indice = funcaoHashMultiplicacao(matricula, tabela->tamanho);
    }
    printf("Tentando remover matrícula %lld no índice %d...\n", matricula, indice);
    if (pesquisarMatricula2(&tabela->vetorListas[indice], matricula)) {
        excluirLista(&tabela->vetorListas[indice], matricula);
        printf("Matrícula %lld removida com sucesso da tabela hash.\n", matricula);
    } else {
        printf("Erro: A matrícula %lld não foi encontrada para remoção.\n", matricula);
    }
}
//================================================
void exibeTabelaHash(TabelaHash *tabela) {
    printf("\n\n===| Exibição Completa da Tabela Hash |===\n\n");    
    for (int i = 0; i < tabela->tamanho; i++) {
        TElemento *atual = tabela->vetorListas[i].inicio;
        if (atual != NULL) {
            printf("Índice %d:\n", i);
            exibeLista(tabela->vetorListas[i]);
            printf("\n");
        }
    }
    printf("\n========================================\n");
}
//================================================
void liberarLista(TLista *lista) {
    TElemento *atual = lista->inicio;
    TElemento *prox;
    while (atual != NULL) {
        prox = atual->prox;  
        free(atual);         
        atual = prox;        
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->total = 0;
}
//================================================
void liberarTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        liberarLista(&tabela->vetorListas[i]); 
    }
    free(tabela->vetorListas);
}
//================================================
int main() {
    FILE *arquivoLista = abrirArquivo("../../data/nomes_matriculas.txt", "r");
    // Contar o número de matrículas no arquivo
    int totalMatriculas = contarMatriculas(arquivoLista);
    printf("Total de matrículas no arquivo: %d\n", totalMatriculas);
    // Reposicionar o ponteiro para o início do arquivo para leitura
    rewind(arquivoLista);

    TabelaHash tabelaHash;
    inicializarTabela(&tabelaHash, arquivoLista);

    int funcaoHashEscolhida = escolherFuncaoHash();
    printf("Função Hash escolhida: %d\n", funcaoHashEscolhida);  // Depuração

    lerEInserirMatriculas(&tabelaHash, arquivoLista, funcaoHashEscolhida);

    executarMenu(&tabelaHash, funcaoHashEscolhida);

    salvarDadosNoArquivo(&tabelaHash, arquivoLista);

    liberarTabelaHash(&tabelaHash);
    
    return 0;
}
