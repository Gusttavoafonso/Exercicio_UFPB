#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int dados[N]; // Array para armazenar os elementos
    int frente;   // Índice do primeiro elemento
    int tras;     // Índice do último elemento
    int tamanho;  // Número atual de elementos na lista
} lista_circular;

// FUNCOES
void criar_lista(lista_circular*);
char esta_cheia(lista_circular*);
char esta_vazia(lista_circular*);
char inserir_fim(lista_circular*, int);
void limpar_lista(lista_circular*);
void mostrar_inf(lista_circular*);
void remover_inicio(lista_circular*);
void remover_fim(lista_circular*);

void criar_lista(lista_circular* l) {
    l->frente = 0;
    l->tras = -1;
    l->tamanho = 0;
}

char esta_cheia(lista_circular* l) {
    return l->tamanho == N;
}

char esta_vazia(lista_circular* l) {
    return l->tamanho == 0;
}

char inserir_fim(lista_circular* l, int n) {
    if (esta_cheia(l)) {
        puts("A lista está cheia.");
        return 0;
    }
    l->tras = (l->tras + 1) % N;
    l->dados[l->tras] = n;
    l->tamanho++;
    return 1;
}

void remover_inicio(lista_circular* l) {
    if (esta_vazia(l)) {
        puts("A lista está vazia.");
        return;
    }
    l->frente = (l->frente + 1) % N;
    l->tamanho--;
}

void remover_fim(lista_circular* l) {
    if (esta_vazia(l)) {
        puts("A lista está vazia.");
        return;
    }
    l->tras = (l->tras - 1 + N) % N;
    l->tamanho--;
}

void limpar_lista(lista_circular* l) {
    l->frente = 0;
    l->tras = -1;
    l->tamanho = 0;
}

void mostrar_inf(lista_circular* l) {
    if (esta_vazia(l)) {
        puts("A lista está vazia.");
        return;
    }
    for (int i = 0; i < l->tamanho; i++) {
        int idx = (l->frente + i) % N;
        printf("O %d item da lista é %d\n", i, l->dados[idx]);
    }
}

int menu() {
    int num;
    puts("Digite a opcao que deseja realizar na lista");
    printf("1 para criar lista\n"
           "2 para inserir no fim\n"
           "3 para remover do inicio\n"
           "4 para remover do fim\n"
           "5 para mostrar informacao da lista\n"
           "6 para ver se a lista esta cheia\n"
           "7 para ver se a lista esta vazia\n"
           "8 para limpar lista\n");
    scanf("%d", &num);
    return num;
}

int main() {
    lista_circular minha_lista;
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
                inserir_fim(&minha_lista, valor);
                break;
            case 3:
                remover_inicio(&minha_lista);
                break;
            case 4:
                remover_fim(&minha_lista);
                break;
            case 5:
                mostrar_inf(&minha_lista);
                break;
            case 6:
                esta_cheia(&minha_lista);
                break;
            case 7:
                esta_vazia(&minha_lista);
                break;
            case 8:
                limpar_lista(&minha_lista);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
