//Feito por: Lucas Garcia E Luis Augusto
#include "TabelaHashEndAberto.h"

// Funções hash e reHash necessárias
long long int hash(long long int k, int tamVetor) {
    return k % tamVetor;
}
// Função para calcular o incremento
long long int hash2(long long int k, int tamVetor) {
    return 1 + (k % (tamVetor - 1));
}
// Função re-hash
long long int reHash(long long int i,long long int k, int tamVetor) {
    return (i + hash2(k, tamVetor)) % tamVetor;
}

//=================================================
// Função para ler o arquivo
FILE *abrirArquivo(char *nomeArq, char *modo) {
    FILE *arq = fopen(nomeArq, modo);
    if (arq == NULL) {
        printf("ERRO ao abrir o arquivo.\n");
        exit(-1);
    }
    printf("INFO: Arquivo Aberto! Bom uso.\n");
    return arq;
}

//=================================================
// Função que calcula o tempo em segundos 
void calcularTempo(double ini, double fim) {
    double tempoDecorrido = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempoDecorrido);
}
//=================================================
// Função para salvar os dados no arquivo
void salvarDadosNoArquivo(TabelaHash *tabela, FILE *arquivoLista) {
    arquivoLista = fopen("nomes_matriculas.txt", "w");
    if (arquivoLista == NULL) {
        printf("ERRO ao abrir o arquivo para gravação.\n");
        return;
    }
    int i;
    // Percorre a tabela e pega os dados dentro dela e escreve os nomes e matriculas de volta no arquivo
    for (i = 0; i < tabela->tamanho; i++) {
        if (tabela->vetor[i].flag == 1) { // Apenas elementos ocupados
            fprintf(arquivoLista, "%s\n%lld\n", tabela->vetor[i].nome, tabela->vetor[i].valor);
        }
    }

    fclose(arquivoLista);
    printf("INFO: Dados salvos com sucesso no arquivo.\n");
}
//=================================================
// Função menu para perguntar o tamanho do vetor
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
// Menu de açoes para realizar com a tabela hash
long long int pedirOpcao() {
    int op;
    printf("\n--- Menu Principal ---\n");
    do {
        printf("1 - Inserir na Tabela Hash\n");
        printf("2 - Exibir a Tabela Hash\n");
        printf("3 - Excluir da Tabela Hash\n");
        printf("4 - Pesquisar Matricula\n");
        printf("5 - Total de Matriculas\n");
        printf("6 - Imprimir toda a Tabela Hash\n");
        printf("7 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);
    } while ((op < 1) || (op > 7));
    return op;
}
//=================================================
// Funçao para ler dados do usuario(teclado)
long long int pedirNum(int caminhoASerEscolhido) {
    long long int num;
    if (caminhoASerEscolhido == 0) {
        printf("Digite um numero para ser inserido: ");
        scanf("%lld", &num);
    } else {
        printf("Digite um numero para ser excluido: ");
        scanf("%lld", &num);
    }
    return num;
}

//================================================
// Função para exibir todos os elementos presentes na tabela
void imprimirTabelaHash(TabelaHash *tabela) {
    printf("\n\n===| Exibição Completa da Tabela Hash |===\n\n");
    for (int i = 0; i < tabela->tamanho; i++) {
        if (tabela->vetor[i].flag == 1) { // Apenas elementos ocupados
            printf("Índice %d: Matrícula: %lld, Nome: %s\n", i, tabela->vetor[i].valor, tabela->vetor[i].nome);
        } else {
            printf("Índice %d: (vazio)\n", i);
        }
    }
    printf("\n========================================\n");
}
//================================================
// Funçao para sustentar o menu de ações do programa
void menuPrincipal(TabelaHash *tabelaHash) {
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
                inserirTabelaHash(tabelaHash, numInseri, nomeInseri);
                break;
            case 2:
                // Exibir a Tabela Hash
                imprimirTabelaHash(tabelaHash);
                break;
            case 3:
                // Excluir da Tabela Hash
                numInseri = pedirNum(1);
                excluirTabelaHash(tabelaHash, numInseri);
                break;
            case 4:
                // Pesquisar uma matrícula na Tabela Hash
                numInseri = pedirNum(0);
                pesquisarTabelaHash(tabelaHash, numInseri);
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
// Função para contar as matriculas enquanto ainda estao no arquivo
int contarMatriculas(FILE *arquivoLista) {
    char linha[100];
    int totalMatriculas = 0;
    // Loop para ler as linhas das do arquivo e contabilidar o numero de linhas
    while (fgets(linha, sizeof(linha), arquivoLista) != NULL) {
        totalMatriculas++;
    }
    // Como cada matrícula ocupa duas linhas (nome e matrícula), dividimos por 2
    return totalMatriculas / 2;
}
//================================================
// Função para contar as matriculas quando elas ja estao na tabela
int contarTotalMatriculas(TabelaHash *tabela) {
    int total = 0;
    for (int i = 0; i < tabela->tamanho; i++) {
        if (tabela->vetor[i].flag == 1) {
            total++;
        }
    }
    return total;
}
//================================================
// Função para veridicar se o numero e primo
int ehPrimo(int num) {
    if (num <= 1) return 0; // Números menores ou iguais a 1 não são primos
    if (num == 2) return 1; // 2 é primo
    if (num % 2 == 0) return 0; // Números pares não são primos
    for (int i = 3; i <= (num*0.5); i += 2) {
        if (num % i == 0) {
            return 0; // Não é primo
        }
    }
    return 1; // É primo
}
//================================================
// Função para encontrar um numero primo
int acharProximoPrimo(int num) {
    // Continuar incrementando até encontrar um número primo
    while (!ehPrimo(num)) {
        num++;
    }
    return num;
}
//================================================
// Função que inicia a tabela hash com pelo menos um elemento
void inicializarTabelaHash(TabelaHash *tabela, int tamanho) {
    tabela->tamanho = tamanho;
    tabela->vetor = (TElemento *)malloc(tamanho * sizeof(TElemento));
    for (int i = 0; i < tamanho; i++) {
        tabela->vetor[i].valor = 0;  // Valor zero indica posição vazia
        tabela->vetor[i].flag = 0;   // 0 para vazio, 1 para ocupado, 2 para removido
        strcpy(tabela->vetor[i].nome, "");
    }
}
//================================================
// Funçao para a criação da tabela hash
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
    // Chamada da funçao que ira iniciar a tabela de fato
    inicializarTabelaHash(tabelaHash, tamanhoTabela);
}
//================================================
// Função que le as matriculas do arquivo e coloca na tabela
void lerEInserirMatriculas(TabelaHash *tabelaHash, FILE *arquivoLista) {
    rewind(arquivoLista);  // Reposicionar para o início do arquivo
    long long int matricula;
    char nome[100];

    // Loop que passa pelo arquivo, ele interrompe o loop quando o conteudo da leitura for NULL
    while (fgets(nome, sizeof(nome), arquivoLista) != NULL) {  // Ler o nome
        nome[strcspn(nome, "\n")] = 0;  // Remover o '\n' do nome
        if (fscanf(arquivoLista, "%lld\n", &matricula) != EOF) {  // Ler a matrícula como long long int
            inserirTabelaHash(tabelaHash, matricula, nome);  // Inserir na tabela hash
        }
    }
}
//================================================
// Função que serve para pesquisar matriculas na tabela hash
int pesquisarTabelaHash(TabelaHash *tabela, long long int matricula) {
    long long int i = hash(matricula, tabela->tamanho);
    int tentativas = 0; // contador que servira para identificar se ainda existe espaço na tabela

    // Loop que enquanto o indice gerado na função hash e se as tentativas ja ultrapasaram o tamanho da tabela
    while ((tabela->vetor[i].flag != 0) && (tentativas < tabela->tamanho)) {
        // Verifica se a matricula foi encontrada e se ali e um espaço ocupado
        if ((tabela->vetor[i].valor == matricula) && (tabela->vetor[i].flag == 1)) {
            printf("Matrícula %lld encontrada. Nome: %s\n", matricula, tabela->vetor[i].nome);
            return 1; // Encontrado
        }
        // nao encontrou roda o hash novamente para achar os passos feitos na hora da inserção
        i = reHash(i, matricula, tabela->tamanho);
        tentativas++;
    }

    printf("Matrícula %lld não encontrada na tabela.\n", matricula);
    return 0; // Não encontrado
}

//================================================
// Função para inserir elementos na tabela hash
void inserirTabelaHash(TabelaHash *tabela, long long int matricula, char *nome) {
    long long int i = hash(matricula, tabela->tamanho);
    int tentativas = 0;

    // Loop para verificar se aquela matricula ja existe dentro da tabela
    while ((tabela->vetor[i].flag == 1) && (tentativas < tabela->tamanho)) {
        if (tabela->vetor[i].valor == matricula) {
            printf("Erro: A matrícula %lld já está presente na tabela.\n", matricula);
            return;
        }
        i = reHash(i, matricula, tabela->tamanho);
        tentativas++;
    }

    // Prepara para a inserção considerando que ainda exista expaço dentro da tabela
    if (tentativas < tabela->tamanho) {
        tabela->vetor[i].valor = matricula;
        strcpy(tabela->vetor[i].nome, nome);
        tabela->vetor[i].flag = 1; // Marca como ocupado
        printf("Matrícula %lld inserida com sucesso.\n", matricula);
    } else {
        printf("Erro: Tabela cheia, não foi possível inserir.\n");
    }
}
//================================================
void excluirTabelaHash(TabelaHash *tabela, long long int matricula) {
    long long int i = hash(matricula, tabela->tamanho);
    int tentativas = 0;

    // Loop que verifica o mesmo processo de pesquisa
    while ((tabela->vetor[i].flag != 0) && (tentativas < tabela->tamanho)) {
        if ((tabela->vetor[i].valor == matricula) && (tabela->vetor[i].flag == 1)) {
            tabela->vetor[i].flag = 2; // Marca como removido
            printf("Matrícula %lld removida com sucesso.\n", matricula);
            return;
        }
        i = reHash(i, matricula, tabela->tamanho);
        tentativas++;
    }

    printf("Erro: A matrícula %lld não foi encontrada para remoção.\n", matricula);
}
//================================================
// Libera a instancia do vetor
void liberarTabelaHash(TabelaHash *tabela) {
    free(tabela->vetor);
}
//================================================
int main() {
    FILE *arquivoLista = abrirArquivo("nomes_matriculas.txt", "r");
    int totalMatriculas = contarMatriculas(arquivoLista);
    printf("Total de matrículas no arquivo: %d\n", totalMatriculas);
    rewind(arquivoLista); // organiza o cursor do arquivo

    TabelaHash tabelaHash;
    inicializarTabela(&tabelaHash, arquivoLista);

    double inicio = clock();
    lerEInserirMatriculas(&tabelaHash, arquivoLista);
    double fim = clock();
    calcularTempo(inicio, fim);

    menuPrincipal(&tabelaHash);
    salvarDadosNoArquivo(&tabelaHash, arquivoLista);
    liberarTabelaHash(&tabelaHash);

    return 0;
}