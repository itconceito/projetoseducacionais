#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("[ERRO] Falha ao alocar memória!\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        printf("-> Nó %d inserido com sucesso!\n", valor);
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    } else {
        printf("[AVISO] Valor %d já existe na árvore.\n", valor);
    }
    return raiz;
}

No* encontrarMinimo(No *raiz) {
    No *atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* remover(No *raiz, int valor) {
    if (raiz == NULL) {
        printf("[ERRO] Valor %d não encontrado.\n", valor);
        return NULL;
    }
    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No *temp = raiz->direita;
            free(raiz);
            printf("-> Nó %d removido com sucesso!\n", valor);
            return temp;
        } else if (raiz->direita == NULL) {
            No *temp = raiz->esquerda;
            free(raiz);
            printf("-> Nó %d removido com sucesso!\n", valor);
            return temp;
        }
        No *temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    No *raiz = NULL;
    int opcao, valor;

    do {
        printf("\n* * * RENALF S/A - MENU DE OPÇÕES * * *\n");
        printf("1. Incluir nó\n");
        printf("2. Remover nó\n");
        printf("3. Buscar pré-ordem\n");
        printf("4. Buscar em ordem\n");
        printf("5. Buscar pós-ordem\n");
        printf("0. Opção [0 para encerrar]\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n[INCLUSÃO]\nDigite o valor numérico: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("\n[REMOÇÃO]\nDigite o valor a remover: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;
            case 3:
                printf("\n[PRÉ-ORDEM (RED)]:\n");
                if (raiz == NULL) printf("Árvore vazia!");
                else preOrdem(raiz);
                printf("\n");
                break;
            case 4:
                printf("\n[EM ORDEM (ERD)]:\n");
                if (raiz == NULL) printf("Árvore vazia!");
                else emOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("\n[PÓS-ORDEM (EDR)]:\n");
                if (raiz == NULL) printf("Árvore vazia!");
                else posOrdem(raiz);
                printf("\n");
                break;
            case 0:
                printf("\nEncerrando e liberando memória...\n");
                liberarArvore(raiz);
                break;
            default:
                printf("\nOpção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
