#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projetoTabela.h"
//Feito por: Lucas Garcia de Souza

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
void construirListaDoZero(TLista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->total = 0;
}

//=================================================
void lerArquivo(TLista *lista, FILE *arquivoLista) {
    char nome[100];
    char matriculaStr[20];  
    long int matricula;

    while (fgets(nome, sizeof(nome), arquivoLista) != NULL) {
        nome[strcspn(nome, "\n")] = 0;  // Remover a quebra de linha do nome
        if (fgets(matriculaStr, sizeof(matriculaStr), arquivoLista) != NULL) {
            matricula = strtol(matriculaStr, NULL, 10);  // Converter string para long int
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
void gravarListaEmArquivo(TLista *lista, FILE *arquivoLista) {
    arquivoLista = abrirArquivo("nomes_matriculas.txt", "w");
    TElemento *atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivoLista, "%ld\n%s\n", atual->valor, atual->nome);
        atual = atual->prox;
    }
    
    fclose(arquivoLista); 
    printf("INFO: Lista gravada com sucesso no arquivo!\n");
}

//=================================================
int pesquisarMatricula2(TLista *lista, long int matriculaBusca) {
    TElemento *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == matriculaBusca) {
            printf("Matrícula %ld encontrada. Nome: %s\n", matriculaBusca, atual->nome);
            return 1;  // Encontrado
        }
        atual = atual->prox;
    }
    printf("Matrícula %ld não encontrada na lista.\n", matriculaBusca);
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
void inserir(TLista *lista, long int valor, char *nome) {
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
    printf("1 - 100%% do número de matrículas\n");
    printf("2 - 120%% do número de matrículas\n");
    printf("3 - 150%% do número de matrículas\n");
    printf("Digite sua opção (1, 2 ou 3): ");
    scanf("%d", &opcao);
    return opcao;
    
}
//=================================================
void exibeLista(TLista lista) {
    TElemento *atual = lista.inicio;
    int cont = 0;
    while (atual != NULL) {
        printf("  Número %d da lista: Matrícula (%ld), Nome: %s\n", ++cont, atual->valor, atual->nome);
        atual = atual->prox;
    }
}
//=================================================
void excluirLista(TLista *lista, long int valor){
    TElemento *atual = lista->inicio;
    TElemento *anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            // Encontra o elemento a ser excluído
            if (atual == lista->inicio) {
                // Exclusão do primeiro elemento da lista
                printf("\n\n\tExcluindo o ELEMENTO %ld ...\n", atual->valor);
                lista->inicio = atual->prox;
                if (lista->inicio == NULL) {
                    // A lista tinha apenas um elemento
                    lista->fim = NULL;
                }
            } else if (atual == lista->fim) {
                // Exclusão do último elemento da lista
                printf("\n\n\tExcluindo o ELEMENTO %ld ...\n", atual->valor);
                lista->fim = anterior;
                lista->fim->prox = NULL;
            } else {
                // Exclusão de um elemento do meio da lista
                printf("\n\n\tExcluindo o ELEMENTO %ld ...\n", atual->valor);
                anterior->prox = atual->prox;
            }
            free(atual);
            lista->total--;
            return; // Sai da função após excluir o elemento
        }
        anterior = atual;
        atual = atual->prox; // move para o próximo elemento
    }
    printf("Elemento %ld não encontrado na lista.\n", valor);
}
//=================================================
long int pedirOpcao(){
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
long int pedirNum(int caminhoASerEscolhido) {
    long int num;
    if (caminhoASerEscolhido == 0){
        printf("Digite um numero para ser inserido: ");
        scanf("%ld", &num);  // Usar %ld para long int
    }else{
        printf("Digite um numero para ser excluido: ");
        scanf("%ld", &num);  // Usar %ld para long int
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
                printf("  Matrícula: %ld, Nome: %s\n", atual->valor, atual->nome); // Adicione o nome aqui
                atual = atual->prox;
            }
        }
    }
    printf("\n========================================\n");
}

//================================================
void menuPrincipal(TabelaHash *tabelaHash) {
    long int op; 
    long int numInseri;
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
                exibeTabelaHash(tabelaHash);
                break;
            case 3:
                // Excluir da Tabela Hash
                numInseri = pedirNum(1);  
                excluirTabelaHash(tabelaHash, numInseri);
                break;
            case 4:
                // Pesquisar uma matrícula na Tabela Hash
                numInseri = pedirNum(0);  // Pedir matrícula para buscar
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
// 202312277890
//================================================
int funcaoHash(long int matricula, int tamanho) {
    return (int)(matricula % tamanho);  
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
    tabela->vetorListas = (TLista *)malloc((size_t)tamanho * sizeof(TLista));
    // Inicializar todas as listas encadeadas em cada posição do vetor
    for (int i = 0; i < tamanho; i++) {
        construirListaDoZero(&tabela->vetorListas[i]);
    }
}
//================================================
void inicializarTabela(TabelaHash *tabelaHash, FILE *arquivoLista) {
    int totalMatriculas = contarMatriculas(arquivoLista);
    int opcaoPorcentagem = pedirOpcao3();
    int tamanhoTabela;
    
    switch (opcaoPorcentagem) {
        case 1:
            tamanhoTabela = acharProximoPrimo((int)(totalMatriculas * 1.0));
            break;
        case 2:
            tamanhoTabela = acharProximoPrimo((int)(totalMatriculas * 1.2));
            break;
        case 3:
            tamanhoTabela = acharProximoPrimo((int)(totalMatriculas * 1.5));
            break;
        default:
            printf("Opção inválida\n");
            exit(1);
    }

    inicializarTabelaHash(tabelaHash, tamanhoTabela);
}
//================================================
void lerEInserirMatriculas(TabelaHash *tabelaHash, FILE *arquivoLista) {
    rewind(arquivoLista);  // Reposicionar para o início do arquivo
    long int matricula;
    char nome[100];

    while (fgets(nome, sizeof(nome), arquivoLista) != NULL) {  // Ler o nome
        nome[strcspn(nome, "\n")] = 0;  // Remover o '\n' do nome
        if (fscanf(arquivoLista, "%ld\n", &matricula) != EOF) {  // Ler a matrícula como long int
            inserirTabelaHash(tabelaHash, matricula, nome);  // Inserir na tabela hash
        }
    }
}

//================================================
void executarMenu(TabelaHash *tabelaHash) {
    menuPrincipal(tabelaHash);
}
//================================================
int pesquisarTabelaHash(TabelaHash *tabela, long int matricula) {
    int indice = funcaoHash(matricula, tabela->tamanho);
    if (pesquisarMatricula2(&tabela->vetorListas[indice], matricula)) {
        printf("Matrícula %ld encontrada na tabela hash.\n", matricula);
        return 1;  // Encontrado
    } else {
        printf("Erro: A matrícula %ld não foi encontrada na tabela.\n", matricula);
        return 0;  // Não encontrado
    }
}
//================================================
void inserirTabelaHash(TabelaHash *tabela, long int matricula, char *nome) {
    int indice = funcaoHash(matricula, tabela->tamanho);

    // Verificar se a matrícula já existe antes de inserir
    if (pesquisarMatricula2(&tabela->vetorListas[indice], matricula)) {
        printf("Erro: A matrícula %ld já está presente na tabela.\n", matricula);
        return;
    }

    // Inserir a nova matrícula na lista correspondente no índice da tabela hash
    inserir(&tabela->vetorListas[indice], matricula, nome);
    printf("Matrícula %ld inserida com sucesso.\n", matricula);

    // Adicione este printf para verificar se a inserção está sendo feita
    printf("Inserido: Nome = %s, Matrícula = %ld no índice %d\n", nome, matricula, indice);
}

//================================================
void excluirTabelaHash(TabelaHash *tabela, long int matricula) {
    int indice = funcaoHash(matricula, tabela->tamanho);
    printf("Tentando remover matrícula %ld no índice %d...\n", matricula, indice);

    // Verifica se a matrícula está na lista antes de tentar removê-la
    if (pesquisarMatricula2(&tabela->vetorListas[indice], matricula)) {
        excluirLista(&tabela->vetorListas[indice], matricula);
        printf("Matrícula %ld removida com sucesso da tabela hash.\n", matricula);
    } else {
        printf("Erro: A matrícula %ld não foi encontrada para remoção.\n", matricula);
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
        liberarLista(&tabela->vetorListas[i]);  // Função que libera cada lista
    }
    free(tabela->vetorListas);
}
//================================================
//=================================================
int main() {
    // Abrir o arquivo
    FILE *arquivoLista = abrirArquivo("nomes_matriculas.txt", "r");

    // Contar o número de matrículas no arquivo
    int totalMatriculas = contarMatriculas(arquivoLista);
    printf("Total de matrículas no arquivo: %d\n", totalMatriculas);

    // Reposicionar o ponteiro para o início do arquivo para leitura
    rewind(arquivoLista);

    // Inicializar a tabela de hash
    TabelaHash tabelaHash;
    inicializarTabela(&tabelaHash, arquivoLista);

    // Ler e inserir as matrículas na tabela hash
    lerEInserirMatriculas(&tabelaHash, arquivoLista);

    // Fechar o arquivo
    fclose(arquivoLista);

    // Executar o menu de opções
    executarMenu(&tabelaHash);

    liberarTabelaHash(&tabelaHash);
    return 0;
} 
