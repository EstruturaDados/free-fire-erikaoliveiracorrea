#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Struct que representa um item
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Função para limpar o buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para listar os itens
void listarItens(struct Item mochila[], int totalItens) {

    printf("\n========== ITENS DA MOCHILA ==========\n");

    if (totalItens == 0) {
        printf("A mochila esta vazia.\n");
    } else {

        for (int i = 0; i < totalItens; i++) {
            printf("\nItem %d\n", i + 1);
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
        }
    }

    printf("======================================\n");
}

// Função para inserir item
void inserirItem(struct Item mochila[], int *totalItens) {

    if (*totalItens >= MAX_ITENS) {
        printf("\nA mochila esta cheia!\n");
        return;
    }

    printf("\n===== CADASTRO DE ITEM =====\n");

    printf("Digite o nome do item: ");
    fgets(mochila[*totalItens].nome, 30, stdin);

    // Remove o \n do fgets
    mochila[*totalItens].nome[strcspn(mochila[*totalItens].nome, "\n")] = '\0';

    printf("Digite o tipo do item (arma, cura, municao...): ");
    fgets(mochila[*totalItens].tipo, 20, stdin);

    mochila[*totalItens].tipo[strcspn(mochila[*totalItens].tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*totalItens].quantidade);

    limparBuffer();

    (*totalItens)++;

    printf("\nItem cadastrado com sucesso!\n");

    listarItens(mochila, *totalItens);
}

// Função para remover item
void removerItem(struct Item mochila[], int *totalItens) {

    char nomeBusca[30];
    int encontrado = 0;

    if (*totalItens == 0) {
        printf("\nNao ha itens para remover.\n");
        return;
    }

    printf("\nDigite o nome do item que deseja remover: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < *totalItens; i++) {

        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            encontrado = 1;

            // Move os elementos para tras
            for (int j = i; j < *totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            (*totalItens)--;

            printf("\nItem removido com sucesso!\n");

            break;
        }
    }

    if (!encontrado) {
        printf("\nItem nao encontrado.\n");
    }

    listarItens(mochila, *totalItens);
}

// Função de busca sequencial
void buscarItem(struct Item mochila[], int totalItens) {

    char nomeBusca[30];
    int encontrado = 0;

    if (totalItens == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    printf("\nDigite o nome do item que deseja buscar: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < totalItens; i++) {

        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            printf("\n===== ITEM ENCONTRADO =====\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem nao encontrado.\n");
    }
}

// Função principal
int main() {

    struct Item mochila[MAX_ITENS];

    int totalItens = 0;
    int opcao;

    do {
        printf("======================================\n");
        printf("*BEM VINDO CÓDIGO DA ILHA - FREE FIRE*\n");
        printf("======================================\n");
        printf("\n=========== MENU ===========\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("============================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        limparBuffer();

        switch (opcao) {

            case 1:
                inserirItem(mochila, &totalItens);
                break;

            case 2:
                removerItem(mochila, &totalItens);
                break;

            case 3:
                listarItens(mochila, totalItens);
                break;

            case 4:
                buscarItem(mochila, totalItens);
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
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
