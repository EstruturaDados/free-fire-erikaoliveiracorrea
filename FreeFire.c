#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COMPONENTES 20

// STRUCT DO COMPONENTE
struct Componente {
    char nome[30];
    char tipo[20];
    int prioridade;
};

// CONTADORES
int comparacoes = 0;

// LIMPAR BUFFER
void limparBuffer() {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

// CADASTRAR COMPONENTES
void cadastrarComponentes(struct Componente torre[],
                          int *total) {

    if (*total >= MAX_COMPONENTES) {

        printf("\nLimite de componentes atingido!\n");
        return;
    }

    printf("\nDigite o nome do componente: ");
    fgets(torre[*total].nome, 30, stdin);

    torre[*total].nome[strcspn(torre[*total].nome,
                               "\n")] = '\0';

    printf("Digite o tipo do componente: ");
    fgets(torre[*total].tipo, 20, stdin);

    torre[*total].tipo[strcspn(torre[*total].tipo,
                               "\n")] = '\0';

    printf("Digite a prioridade (1 a 10): ");
    scanf("%d", &torre[*total].prioridade);

    limparBuffer();

    (*total)++;

    printf("\nComponente cadastrado!\n");
}

// MOSTRAR COMPONENTES
void mostrarComponentes(struct Componente torre[],
                        int total) {

    printf("\n======= COMPONENTES =======\n");

    if (total == 0) {

        printf("Nenhum componente cadastrado.\n");
    }

    for (int i = 0; i < total; i++) {

        printf("\nComponente %d\n", i + 1);

        printf("Nome: %s\n", torre[i].nome);
        printf("Tipo: %s\n", torre[i].tipo);
        printf("Prioridade: %d\n",
               torre[i].prioridade);
    }

    printf("===========================\n");
}

// BUBBLE SORT POR NOME
void bubbleSortNome(struct Componente torre[],
                    int total) {

    struct Componente temp;

    comparacoes = 0;

    for (int i = 0; i < total - 1; i++) {

        for (int j = 0;
             j < total - 1 - i;
             j++) {

            comparacoes++;

            if (strcmp(torre[j].nome,
                       torre[j + 1].nome) > 0) {

                temp = torre[j];
                torre[j] = torre[j + 1];
                torre[j + 1] = temp;
            }
        }
    }

    printf("\nOrdenado por NOME.\n");
    printf("Comparacoes: %d\n",
           comparacoes);
}

// INSERTION SORT POR TIPO
void insertionSortTipo(struct Componente torre[],
                       int total) {

    struct Componente chave;

    comparacoes = 0;

    for (int i = 1; i < total; i++) {

        chave = torre[i];

        int j = i - 1;

        while (j >= 0 &&
               strcmp(torre[j].tipo,
                      chave.tipo) > 0) {

            comparacoes++;

            torre[j + 1] = torre[j];

            j--;
        }

        torre[j + 1] = chave;
    }

    printf("\nOrdenado por TIPO.\n");

    printf("Comparacoes: %d\n",
           comparacoes);
}

// SELECTION SORT POR PRIORIDADE
void selectionSortPrioridade(struct Componente torre[],
                             int total) {

    struct Componente temp;

    comparacoes = 0;

    for (int i = 0; i < total - 1; i++) {

        int menor = i;

        for (int j = i + 1;
             j < total;
             j++) {

            comparacoes++;

            if (torre[j].prioridade <
                torre[menor].prioridade) {

                menor = j;
            }
        }

        temp = torre[i];
        torre[i] = torre[menor];
        torre[menor] = temp;
    }

    printf("\nOrdenado por PRIORIDADE.\n");

    printf("Comparacoes: %d\n",
           comparacoes);
}

// BUSCA BINARIA POR NOME
void buscaBinariaPorNome(struct Componente torre[],
                         int total,
                         char nomeBusca[]) {

    int inicio = 0;
    int fim = total - 1;
    int meio;
    int resultado;

    comparacoes = 0;

    while (inicio <= fim) {

        comparacoes++;

        meio = (inicio + fim) / 2;

        resultado = strcmp(torre[meio].nome,
                           nomeBusca);

        if (resultado == 0) {

            printf("\nCOMPONENTE ENCONTRADO!\n");

            printf("Nome: %s\n",
                   torre[meio].nome);

            printf("Tipo: %s\n",
                   torre[meio].tipo);

            printf("Prioridade: %d\n",
                   torre[meio].prioridade);

            printf("Comparacoes: %d\n",
                   comparacoes);

            return;
        }

        if (resultado < 0) {

            inicio = meio + 1;

        } else {

            fim = meio - 1;
        }
    }

    printf("\nComponente nao encontrado.\n");

    printf("Comparacoes: %d\n",
           comparacoes);
}

// MEDIR TEMPO DOS ALGORITMOS
void medirTempo(void (*algoritmo)
               (struct Componente[], int),

               struct Componente vetor[],
               int tamanho) {

    clock_t inicio, fim;

    double tempo;

    inicio = clock();

    algoritmo(vetor, tamanho);

    fim = clock();

    tempo = ((double)(fim - inicio))
            / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %.6f segundos\n",
           tempo);
}

// FUNÇÃO PRINCIPAL
int main() {

    struct Componente torre[MAX_COMPONENTES];

    int total = 0;

    int opcao;

    char nomeBusca[30];

    do {

        printf("\n====================================\n");
        printf("* DESAFIO MESTRE - FREE FIRE *\n");
        printf("====================================\n");

        printf("\n1 - Cadastrar componente\n");
        printf("2 - Mostrar componentes\n");
        printf("3 - Bubble Sort por nome\n");
        printf("4 - Insertion Sort por tipo\n");
        printf("5 - Selection Sort prioridade\n");
        printf("6 - Busca Binaria por nome\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        limparBuffer();

        switch (opcao) {

            case 1:

                cadastrarComponentes(torre,
                                     &total);

                break;

            case 2:

                mostrarComponentes(torre,
                                   total);

                break;

            case 3:

                medirTempo(bubbleSortNome,
                           torre,
                           total);

                mostrarComponentes(torre,
                                   total);

                break;

            case 4:

                medirTempo(insertionSortTipo,
                           torre,
                           total);

                mostrarComponentes(torre,
                                   total);

                break;

            case 5:

                medirTempo(selectionSortPrioridade,
                           torre,
                           total);

                mostrarComponentes(torre,
                                   total);

                break;

            case 6:

                printf("\nDigite o nome do componente: ");

                fgets(nomeBusca, 30, stdin);

                nomeBusca[strcspn(nomeBusca,
                                  "\n")] = '\0';

                buscaBinariaPorNome(torre,
                                    total,
                                    nomeBusca);

                break;

            case 0:

                printf("\nEncerrando sistema...\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
//COMENTÁRIO DA PROFESSORA
//------------------------------------
// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.
 // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
