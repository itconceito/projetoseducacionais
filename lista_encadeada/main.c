#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do Nó (Node) da Lista Simplesmente Encadeada
typedef struct No {
    int id;                 // Campo identificador/chave
    char nome[50];          // Exemplo de dado armazenado
    struct No *proximo;     // Ponteiro para o próximo nó da lista
} No;

// Função para criar um novo nó com alocação dinâmica
No* criarNo(int id, const char *nome) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("[ERRO] Falha ao alocar memória!\n");
        exit(1);
    }
    novoNo->id = id;
    strncpy(novoNo->nome, nome, sizeof(novoNo->nome) - 1);
    novoNo->nome[sizeof(novoNo->nome) - 1] = '\0';
    novoNo->proximo = NULL;
    return novoNo;
}

// 1. INCLUSÃO: Insere um novo elemento no final da lista
void inserir(No **inicio, int id, const char *nome) {
    No *novo = criarNo(id, nome);
    
    // Se a lista estiver vazia, o novo nó torna-se o início
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *atual = *inicio;
        // Percorre a lista até encontrar o último nó
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    printf("-> Registro ID %d ('%s') incluído com sucesso!\n", id, nome);
}

// 2. CONSULTA / LISTAGEM:
// 2.1 Listar todos os elementos armazenados
void listarTodos(No *inicio) {
    if (inicio == NULL) {
        printf("\n[AVISO] A lista está vazia!\n");
        return;
    }
    
    printf("\n=================== LISTA DE DADOS ===================\n");
    No *atual = inicio;
    while (atual != NULL) {
        printf("ID: %-5d | Nome: %-30s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
    printf("======================================================\n");
}

// 2.2 Consultar um registro específico pelo ID
No* buscarPorId(No *inicio, int id) {
    No *atual = inicio;
    while (atual != NULL) {
        if (atual->id == id) {
            return atual; // Retorna o nó se encontrado
        }
        atual = atual->proximo;
    }
    return NULL; // Retorna NULL se não for encontrado
}

// 3. ALTERAÇÃO: Atualiza os dados de um elemento existente
void alterar(No *inicio, int id) {
    No *noEncontrado = buscarPorId(inicio, id);
    if (noEncontrado == NULL) {
        printf("[ERRO] Registro com ID %d não foi encontrado.\n", id);
        return;
    }
    
    char novoNome[50];
    printf("Registro encontrado: ID %d | Nome Atual: %s\n", noEncontrado->id, noEncontrado->nome);
    printf("Digite o novo nome: ");
    getchar(); // Limpa o buffer do teclado
    fgets(novoNome, sizeof(novoNome), stdin);
    novoNome[strcspn(novoNome, "\n")] = '\0'; // Remove a quebra de linha '\n'
    
    strcpy(noEncontrado->nome, novoNome);
    printf("-> Registro ID %d alterado com sucesso!\n", id);
}

// 4. REMOÇÃO: Remove um nó da lista pelo seu ID
void remover(No **inicio, int id) {
    if (*inicio == NULL) {
        printf("[AVISO] A lista está vazia, nada para remover.\n");
        return;
    }

    No *atual = *inicio;
    No *anterior = NULL;

    // Se o elemento a ser removido for o primeiro nó
    if (atual != NULL && atual->id == id) {
        *inicio = atual->proximo; // O início passa a ser o segundo elemento
        free(atual);              // Libera a memória alocada
        printf("-> Registro ID %d removido com sucesso!\n", id);
        return;
    }

    // Busca o nó a ser removido mantendo a referência do nó anterior
    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se o ID não for encontrado
    if (atual == NULL) {
        printf("[ERRO] Registro com ID %d não encontrado.\n", id);
        return;
    }

    // Desvincula o nó da lista e libera a memória
    anterior->proximo = atual->proximo;
    free(atual);
    printf("-> Registro ID %d removido com sucesso!\n", id);
}

// Função para liberar toda a memória alocada ao encerrar o programa
void liberarLista(No **inicio) {
    No *atual = *inicio;
    No *proximoNo;

    while (atual != NULL) {
        proximoNo = atual->proximo;
        free(atual);
        atual = proximoNo;
    }
    *inicio = NULL;
}

// Função principal com menu de interação
int main() {
    No *lista = NULL; // Inicializa a lista vazia
    int opcao, id;
    char nome[50];

    do {
        printf("\n--- RENALF MEGA DATA - SISTEMA DE GERENCIAMENTO DE LISTA ---\n");
        printf("1. Incluir registro\n");
        printf("2. Listar todos os registros\n");
        printf("3. Consultar por ID\n");
        printf("4. Alterar registro\n");
        printf("5. Remover registro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n[INCLUSÃO]\n");
                printf("Digite o ID: ");
                scanf("%d", &id);
                printf("Digite o Nome: ");
                getchar(); // Limpa o buffer do teclado
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove o \n
                inserir(&lista, id, nome);
                break;

            case 2:
                listarTodos(lista);
                break;

            case 3:
                printf("\n[CONSULTA]\n");
                printf("Digite o ID a consultar: ");
                scanf("%d", &id);
                No *encontrado = buscarPorId(lista, id);
                if (encontrado != NULL) {
                    printf("-> Registro Encontrado: ID = %d | Nome = %s\n", encontrado->id, encontrado->nome);
                } else {
                    printf("-> Registro com ID %d não foi encontrado.\n", id);
                }
                break;

            case 4:
                printf("\n[ALTERAÇÃO]\n");
                printf("Digite o ID do registro a ser alterado: ");
                scanf("%d", &id);
                alterar(lista, id);
                break;

            case 5:
                printf("\n[REMOÇÃO]\n");
                printf("Digite o ID do registro a ser removido: ");
                scanf("%d", &id);
                remover(&lista, id);
                break;

            case 0:
                printf("\nEncerrando o programa e liberando memória...\n");
                liberarLista(&lista);
                printf("Programa finalizado com sucesso!\n");
                break;

            default:
                printf("\n[OPÇÃO INVÁLIDA] Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
