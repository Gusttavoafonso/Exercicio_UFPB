#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int dados[N]; // Array para armazenar os elementos
    int tamanho;  // Número atual de elementos na lista
} lista_ordenada;

// FUNCOES
void criar_lista(lista_ordenada*);
char esta_cheia(lista_ordenada*);
char esta_vazia(lista_ordenada*);
char inserir_ordenado(lista_ordenada*, int);
void limpar_lista(lista_ordenada*);
void mostrar_inf(lista_ordenada*);
void remover_elemento(lista_ordenada*, int);

void criar_lista(lista_ordenada* l) {
    l->tamanho = 0;
}

char esta_cheia(lista_ordenada* l) {
    return l->tamanho == N;
}

char esta_vazia(lista_ordenada* l) {
    return l->tamanho == 0;
}

char inserir_ordenado(lista_ordenada* l, int n) {
    if (esta_cheia(l)) {
        puts("A lista está cheia.");
        return 0;
    }
    int i = l->tamanho - 1;

    // Encontra a posição correta para o novo elemento
    while (i >= 0 && l->dados[i] > n) {
        l->dados[i + 1] = l->dados[i];
        i--;
    }

    l->dados[i + 1] = n;
    l->tamanho++;
    return 1;
}

void remover_elemento(lista_ordenada* l, int n) {
    if (esta_vazia(l)) {
        puts("A lista está vazia.");
        return;
    }
    
    int i;
    // Encontra o elemento a ser removido
    for (i = 0; i < l->tamanho; i++) {
        if (l->dados[i] == n) {
            break;
        }
    }
    
    if (i == l->tamanho) {
        puts("Elemento não encontrado.");
        return;
    }

    // Move os elementos seguintes para preencher o espaço
    for (; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->tamanho--;
}

void limpar_lista(lista_ordenada* l) {
    l->tamanho = 0;
}

void mostrar_inf(lista_ordenada* l) {
    if (esta_vazia(l)) {
        puts("A lista está vazia.");
        return;
    }
    for (int i = 0; i < l->tamanho; i++) {
        printf("O %d item da lista e %d\n", i, l->dados[i]);
    }
}

int menu() {
    int num;
    puts("Digite a opcao que deseja realizar na lista");
    printf("1 para criar lista\n"
           "2 para inserir ordenado\n"
           "3 para remover elemento\n"
           "4 para mostrar informacao da lista\n"
           "5 para ver se a lista esta cheia\n"
           "6 para ver se a lista esta vazia\n"
           "7 para limpar lista\n");
    scanf("%d", &num);
    return num;
}

int main() {
    lista_ordenada minha_lista;
    int opcao, valor;

    criar_lista(&minha_lista);

    do {
        opcao = menu();
        switch(opcao) {
            case 1:
                criar_lista(&minha_lista);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir_ordenado(&minha_lista, valor);
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remover_elemento(&minha_lista, valor);
                break;
            case 4:
                mostrar_inf(&minha_lista);
                break;
            case 5:
                esta_cheia(&minha_lista);
                break;
            case 6:
                esta_vazia(&minha_lista);
                break;
            case 7:
                limpar_lista(&minha_lista);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
