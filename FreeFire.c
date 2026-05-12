#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_ITENS 10

/* 
   Struct que representa um item da mochila.
   Cada item possui:
   - nome: nome do objeto
   - tipo: categoria do objeto (arma, munição, cura, etc.)
   - quantidade: quantidade disponível
*/
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};


void inserirItem(struct Item mochila[], int *totalItens) {
    if (*totalItens >= MAX_ITENS) {
        printf("\nA mochila esta cheia! Limite de %d itens.\n", MAX_ITENS);
        return;
    }

    printf("\n--- Cadastro de Item ---\n");

    printf("Nome do item: ");
    scanf(" %29[^\n]", mochila[*totalItens].nome);

    printf("Tipo do item: ");
    scanf(" %19[^\n]", mochila[*totalItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*totalItens].quantidade);

    (*totalItens)++;

    printf("\nItem cadastrado com sucesso!\n");
}



/*
    Função para remover um item pelo nome.
    A remoção é feita deslocando os elementos do vetor.
*/
void removerItem(struct Item mochila[], int *totalItens) {
    char nomeBusca[30];
    int i, j;
    int encontrado = 0;

    if (*totalItens == 0) {
        printf("\nA mochila esta vazia!\n");
        return;
    }

    printf("\n--- Remocao de Item ---\n");
    printf("Digite o nome do item a remover: ");
    scanf(" %29[^\n]", nomeBusca);

    for (i = 0; i < *totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;

            /* Desloca os itens para preencher o espaço removido */
            for (j = i; j < *totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            (*totalItens)--;

            printf("\nItem removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem nao encontrado!\n");
    }
}



/*
    Função para listar todos os itens da mochila.
*/
void listarItens(struct Item mochila[], int totalItens) {
    int i;

    printf("\n========================================\n");
    printf("           ITENS DA MOCHILA\n");
    printf("========================================\n");

    if (totalItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    for (i = 0; i < totalItens; i++) {
        printf("Item %d\n", i + 1);
        printf("Nome       : %s\n", mochila[i].nome);
        printf("Tipo       : %s\n", mochila[i].tipo);
        printf("Quantidade : %d\n", mochila[i].quantidade);
        printf("----------------------------------------\n");
    }
}




/*
    Função de busca sequencial.
    Procura um item pelo nome e exibe seus dados.
*/
void buscarItem(struct Item mochila[], int totalItens) {
    char nomeBusca[30];
    int i;
    int encontrado = 0;

    if (totalItens == 0) {
        printf("\nA mochila esta vazia!\n");
        return;
    }

    printf("\n--- Busca de Item ---\n");
    printf("Digite o nome do item a buscar: ");
    scanf(" %29[^\n]", nomeBusca);

    for (i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;

            printf("\nItem encontrado!\n");
            printf("Nome       : %s\n", mochila[i].nome);
            printf("Tipo       : %s\n", mochila[i].tipo);
            printf("Quantidade : %d\n", mochila[i].quantidade);

            break;
        }
    }

    if (!encontrado) {
        printf("\nItem nao encontrado!\n");
    }
}



int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n========================================\n");
        printf("      MOCHILA DE LOOT DO JOGADOR\n");
        printf("========================================\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &totalItens);
                listarItens(mochila, totalItens);
                break;

            case 2:
                removerItem(mochila, &totalItens);
                listarItens(mochila, totalItens);
                break;

            case 3:
                listarItens(mochila, totalItens);
                break;

            case 4:
                buscarItem(mochila, totalItens);
                listarItens(mochila, totalItens);
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}




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
