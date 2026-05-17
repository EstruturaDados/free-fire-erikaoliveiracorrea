#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// STRUCT DO ITEM
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// STRUCT DO NÓ DA LISTA ENCADEADA
struct No {
    struct Item dados;
    struct No *proximo;
};

// CONTADORES DE COMPARAÇÕES
int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

// LIMPAR BUFFER
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//VETOR 
// LISTAR ITENS DO VETOR
void listarItensVetor(struct Item mochila[], int totalItens) {

    printf("\n========== MOCHILA VETOR ==========\n");

    if (totalItens == 0) {
        printf("Mochila vazia.\n");
    } else {

        for (int i = 0; i < totalItens; i++) {

            printf("\nItem %d\n", i + 1);
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
        }
    }

    printf("===================================\n");
}

// INSERIR ITEM NO VETOR
void inserirItemVetor(struct Item mochila[], int *totalItens) {

    if (*totalItens >= MAX_ITENS) {
        printf("\nMochila cheia!\n");
        return;
    }

    printf("\nDigite o nome do item: ");
    fgets(mochila[*totalItens].nome, 30, stdin);
    mochila[*totalItens].nome[strcspn(mochila[*totalItens].nome, "\n")] = '\0';

    printf("Digite o tipo do item: ");
    fgets(mochila[*totalItens].tipo, 20, stdin);
    mochila[*totalItens].tipo[strcspn(mochila[*totalItens].tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*totalItens].quantidade);

    limparBuffer();

    (*totalItens)++;

    printf("\nItem inserido com sucesso!\n");
}

// REMOVER ITEM DO VETOR
void removerItemVetor(struct Item mochila[], int *totalItens) {

    char nomeBusca[30];
    int encontrado = 0;

    printf("\nDigite o nome do item para remover: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < *totalItens; i++) {

        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            encontrado = 1;

            for (int j = i; j < *totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            (*totalItens)--;

            printf("\nItem removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem não encontrado.\n");
    }
}

// BUSCA SEQUENCIAL NO VETOR
void buscarSequencialVetor(struct Item mochila[], int totalItens) {

    char nomeBusca[30];
    int encontrado = 0;

    comparacoesSequencial = 0;

    printf("\nDigite o nome do item: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < totalItens; i++) {

        comparacoesSequencial++;

        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            printf("\nITEM ENCONTRADO!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem não encontrado.\n");
    }

    printf("Comparações realizadas: %d\n", comparacoesSequencial);
}

// ORDENAR VETOR (BUBBLE SORT)
void ordenarVetor(struct Item mochila[], int totalItens) {

    struct Item temp;

    for (int i = 0; i < totalItens - 1; i++) {

        for (int j = 0; j < totalItens - 1 - i; j++) {

            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {

                temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }

    printf("\nItens ordenados com sucesso!\n");
}

// BUSCA BINÁRIA
void buscarBinariaVetor(struct Item mochila[], int totalItens) {

    char nomeBusca[30];

    int inicio = 0;
    int fim = totalItens - 1;
    int meio;
    int resultado;

    comparacoesBinaria = 0;

    printf("\nDigite o nome do item: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    while (inicio <= fim) {

        comparacoesBinaria++;

        meio = (inicio + fim) / 2;

        resultado = strcmp(mochila[meio].nome, nomeBusca);

        if (resultado == 0) {

            printf("\nITEM ENCONTRADO!\n");
            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);

            printf("Comparacoes realizadas: %d\n", comparacoesBinaria);

            return;
        }

        if (resultado < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("\nItem nao encontrado.\n");
    printf("Comparacoes realizadas: %d\n", comparacoesBinaria);
}

//LISTA ENCADEADA 
// INSERIR ITEM NA LISTA
void inserirItemLista(struct No **lista) {

    struct No *novo = malloc(sizeof(struct No));

    if (novo == NULL) {
        printf("\nErro de memoria.\n");
        return;
    }

    printf("\nDigite o nome do item: ");
    fgets(novo->dados.nome, 30, stdin);
    novo->dados.nome[strcspn(novo->dados.nome, "\n")] = '\0';

    printf("Digite o tipo do item: ");
    fgets(novo->dados.tipo, 20, stdin);
    novo->dados.tipo[strcspn(novo->dados.tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    limparBuffer();

    novo->proximo = *lista;
    *lista = novo;

    printf("\nItem inserido na lista!\n");
}

// LISTAR ITENS DA LISTA
void listarItensLista(struct No *lista) {

    int contador = 1;

    printf("\n========== LISTA ENCADEADA ==========\n");

    if (lista == NULL) {
        printf("Lista vazia.\n");
    }

    while (lista != NULL) {

        printf("\nItem %d\n", contador);

        printf("Nome: %s\n", lista->dados.nome);
        printf("Tipo: %s\n", lista->dados.tipo);
        printf("Quantidade: %d\n", lista->dados.quantidade);

        lista = lista->proximo;
        contador++;
    }

    printf("=====================================\n");
}

// REMOVER ITEM DA LISTA
void removerItemLista(struct No **lista) {

    char nomeBusca[30];

    struct No *atual = *lista;
    struct No *anterior = NULL;

    printf("\nDigite o nome do item para remover: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    while (atual != NULL &&
           strcmp(atual->dados.nome, nomeBusca) != 0) {

        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nItem não encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);

    printf("\nItem removido da lista!\n");
}

// BUSCA SEQUENCIAL NA LISTA
void buscarSequencialLista(struct No *lista) {

    char nomeBusca[30];

    comparacoesSequencial = 0;

    printf("\nDigite o nome do item: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    while (lista != NULL) {

        comparacoesSequencial++;

        if (strcmp(lista->dados.nome, nomeBusca) == 0) {

            printf("\nITEM ENCONTRADO!\n");

            printf("Nome: %s\n", lista->dados.nome);
            printf("Tipo: %s\n", lista->dados.tipo);
            printf("Quantidade: %d\n", lista->dados.quantidade);

            printf("Comparacoes realizadas: %d\n",
                   comparacoesSequencial);

            return;
        }

        lista = lista->proximo;
    }

    printf("\nItem nao encontrado.\n");

    printf("Comparacoes realizadas: %d\n",
           comparacoesSequencial);
}


// FUNÇÃO PRINCIPAL
int main() {

    struct Item mochila[MAX_ITENS];
    int totalItens = 0;

    struct No *lista = NULL;

    int opcao;
    int estrutura;

    do {

        printf("\n======================================\n");
        printf("* BEM VINDO CODIGO DA ILHA FREE FIRE *\n");
        printf("======================================\n");

        printf("\nEscolha a estrutura:\n");
        printf("1 - Vetor\n");
        printf("2 - Lista Encadeada\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &estrutura);

        limparBuffer();

        if (estrutura == 1) {

            do {

                printf("\n========= MENU VETOR =========\n");

                printf("1 - Inserir item\n");
                printf("2 - Remover item\n");
                printf("3 - Listar itens\n");
                printf("4 - Busca Sequencial\n");
                printf("5 - Ordenar vetor\n");
                printf("6 - Busca Binaria\n");
                printf("0 - Voltar\n");

                printf("Opcao: ");
                scanf("%d", &opcao);

                limparBuffer();

                switch (opcao) {

                    case 1:
                        inserirItemVetor(mochila, &totalItens);
                        break;

                    case 2:
                        removerItemVetor(mochila, &totalItens);
                        break;

                    case 3:
                        listarItensVetor(mochila, totalItens);
                        break;

                    case 4:
                        buscarSequencialVetor(mochila, totalItens);
                        break;

                    case 5:
                        ordenarVetor(mochila, totalItens);
                        break;

                    case 6:
                        buscarBinariaVetor(mochila, totalItens);
                        break;

                    case 0:
                        break;

                    default:
                        printf("\nOpcao invalida.\n");
                }

            } while (opcao != 0);
        }

        else if (estrutura == 2) {

            do {

                printf("\n====== MENU LISTA ENCADEADA ======\n");

                printf("1 - Inserir item\n");
                printf("2 - Remover item\n");
                printf("3 - Listar itens\n");
                printf("4 - Busca Sequencial\n");
                printf("0 - Voltar\n");

                printf("Opcao: ");
                scanf("%d", &opcao);

                limparBuffer();

                switch (opcao) {

                    case 1:
                        inserirItemLista(&lista);
                        break;

                    case 2:
                        removerItemLista(&lista);
                        break;

                    case 3:
                        listarItensLista(lista);
                        break;

                    case 4:
                        buscarSequencialLista(lista);
                        break;

                    case 0:
                        break;

                    default:
                        printf("\nOpcao invalida.\n");
                }

            } while (opcao != 0);
        }

    } while (estrutura != 0);

    printf("\nEncerrando sistema...\n");

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
