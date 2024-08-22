#include <stdio.h>
#include <stdlib.h>

// Estrutura para o nó da lista
struct No {
    int dado;
    struct No* prox;
    struct No* ant;
};

// Estrutura para a lista duplamente encadeada
struct Lista {
    struct No* li; // Aponta para o início (cabeça)
    struct No* lf; // Aponta para o fim (cauda)
};

// Função para inicializar a lista
void criar_lista_duplamente_encadeada(struct Lista* lista) {
    lista->li = NULL; // Início da lista como NULL (lista vazia)
    lista->lf = NULL; // Fim da lista como NULL (lista vazia)
}

// Função para inserir um elemento no final da lista
void inserir_final(struct Lista* lista, int valor) {
    // Criando novo nó
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no->dado = valor;
    novo_no->prox = NULL;
    novo_no->ant = NULL;

    // Se a lista estiver vazia
    if (lista->li == NULL) {
        lista->li = novo_no;
        lista->lf = novo_no;
    } else {
        novo_no->ant = lista->lf; // O anterior do novo nó é o nó do fim
        lista->lf->prox = novo_no; // O próximo do nó do fim é o novo nó
        lista->lf = novo_no; // Atualizando o ponteiro do fim para o novo nó
    }
}

// Função para imprimir a lista do início ao fim
void imprimir_lista(struct Lista* lista) {
    struct No* atual = lista->li;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para liberar a memória da lista
void liberar_lista(struct Lista* lista) {
    struct No* atual = lista->li;
    struct No* prox_no;
    while (atual != NULL) {
        prox_no = atual->prox;
        free(atual);
        atual = prox_no;
    }
    lista->li = NULL;
    lista->lf = NULL;
}

int main() {
    struct Lista lista;

    criar_lista_duplamente_encadeada(&lista);

    // Inserindo elementos
    inserir_final(&lista, 10);
    inserir_final(&lista, 20);
    inserir_final(&lista, 30);

    // Imprimindo lista
    imprimir_lista(&lista);

    // Liberando memória
    liberar_lista(&lista);

    return 0;
}
