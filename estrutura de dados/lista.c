#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
   int dados[N];
   int controle;
}lista;

// FUNCOES
void criar_lista(lista*);
char esta_cheia(lista*);
char esta_vazia(lista*);
char inserir_fim(lista*, int);
void limpar_lista(lista*);
int menu();
void mostrar_inf(lista*);
void remover_fim(lista*);

void criar_lista(lista* l){
    l->controle = -1;
}

char esta_cheia(lista* l) {
    if(l->controle == N - 1){
        puts("A lista está cheia");
        return 1;
    }
    return 0;
}

char esta_vazia(lista* l) {
    if(l->controle == -1){
        puts("A lista está vazia");
        return 1;
    }
    return 0;
}

char inserir_fim(lista* l, int n) {
    if(esta_cheia(l)) {
        return 0;
    } else {
        l->dados[(l->controle) + 1] = n;
        l->controle += 1;
        return 1;
    }
}

void limpar_lista(lista* l) {
    l->controle = -1;
}

int menu() {
    int num;
    puts("Digite a opcao que deseja realizar na lista");
    printf("1 para criar lista\n"
           "2 para inserir no fim\n"
           "3 para remover do fim\n"
           "4 para mostrar informacao da lista\n"
           "5 para ver se a lista esta cheia\n"
           "6 para ver se a lista esta vazia\n"
           "7 para limpar lista\n");
    scanf("%d", &num);
    return num;
}

void mostrar_inf(lista* l) {
    if(esta_vazia(l)){
        return;
    } else {
        for(int i = 0; i <= l->controle; i++ )
            printf("O %d item da lista é %d\n", i, l->dados[i]);
    }
}

void remover_fim(lista* l) {
    if(esta_vazia(l))
        return;

    l->controle -= 1; 
    l->dados[(l->controle) + 1] = 0;
}

int main() {
    lista minha_lista;
    int opcao, valor;

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
                remover_fim(&minha_lista);
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
