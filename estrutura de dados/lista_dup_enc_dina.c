#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista duplamente encadeada
struct no {
    int dado;
    struct no* prox;
    struct no* ant;
};

// Definição da estrutura da lista duplamente encadeada
struct lista {
    struct no *li; // ponteiro para o primeiro nó da lista
    struct no *lf; // ponteiro para o último nó da lista
};

// Função para criar uma lista duplamente encadeada vazia
void criar_lista_dupla_encad_refe(struct lista* c) {
    c->li = NULL; // define o ponteiro para o primeiro nó como NULL
    c->lf = NULL; // define o ponteiro para o último nó como NULL
}

// Função para inserir um elemento de forma ordenada na lista
void inserir_ordenada(struct lista* ll, int num) {
    // Aloca memória para um novo nó
    struct no* novo_no = (struct no*)malloc(sizeof(struct no));
    novo_no->dado = num; // atribui o valor ao novo nó
    novo_no->prox = NULL; // define o ponteiro para o próximo nó como NULL
    novo_no->ant = NULL; // define o ponteiro para o nó anterior como NULL
    
    // Verifica se a lista está vazia
    if (ll->li == NULL) {
        // Se estiver vazia, o novo nó se torna o primeiro e o último nó da lista
        ll->li = novo_no;
        ll->lf = novo_no;
    } else {
        struct no* aux = ll->li; // ponteiro auxiliar para percorrer a lista
        struct no* prev = NULL; // ponteiro para o nó anterior ao atual

        // Percorre a lista até encontrar a posição correta para inserir o novo nó
        while (aux != NULL && aux->dado < num) {
            prev = aux;
            aux = aux->prox;
        }

        // Verifica se o novo nó deve ser inserido no início da lista
        if (prev == NULL) {
            novo_no->prox = ll->li;
            ll->li->ant = novo_no;
            ll->li = novo_no;
        } 
        // Verifica se o novo nó deve ser inserido no final da lista
        else if (aux == NULL) {
            prev->prox = novo_no;
            novo_no->ant = prev;
            ll->lf = novo_no;
        } 
        // Caso contrário, o novo nó deve ser inserido no meio da lista
        else {
            prev->prox = novo_no;
            novo_no->ant = prev;
            novo_no->prox = aux;
            aux->ant = novo_no;
        }
    }
}

// Função para imprimir os elementos da lista
void imprimir_lista(struct lista* ll) {
    struct no* aux = ll->li; // ponteiro auxiliar para percorrer a lista
    while (aux != NULL) {
        printf("%d\n", aux->dado); // imprime o valor do nó atual
        aux = aux->prox; // avança para o próximo nó
    }
}

// Função para verificar se a lista está vazia
char estar_vazia(struct lista* ll) {
    return ll->li == NULL; // retorna 1 se a lista estiver vazia, 0 caso contrário
}

// Função para concatenar duas listas
struct lista* concatenar_listas(struct lista* ll1, struct lista* ll2) {
    struct no* aux = ll1->li; // ponteiro auxiliar para percorrer a primeira lista
    struct no* aux2 = ll2->li; // ponteiro auxiliar para percorrer a segunda lista
    struct lista* ll3 = (struct lista*)malloc(sizeof(struct lista)); // aloca memória para a nova lista
    criar_lista_dupla_encad_refe(ll3); // cria a nova lista vazia
    
    // Verifica qual lista tem o menor valor no primeiro nó
    if(ll1->li->dado < ll2->li->dado) {
        // Se o primeiro nó da primeira lista for menor, a nova lista começa com a primeira lista
        ll3->li = aux;
        
        // Percorre a primeira lista até encontrar o ponto de concatenação
        while(aux->dado < ll2->li->dado) {
            inserir_ordenada(ll3, aux->dado); // insere o valor na nova lista
            aux = aux->prox; // avança para o próximo nó
        }
        
        // Percorre a segunda lista e insere os valores na nova lista
        while(aux2->prox != NULL) {
            inserir_ordenada(ll3, aux2->dado); // insere o valor na nova lista
            aux2 = aux2->prox; // avança para o próximo nó
        }
        
        ll3->lf = aux2; // define o último nó da nova lista como o último nó da segunda lista
    } else {
        // Se o primeiro nó da segunda lista for menor, a nova lista começa com a segunda lista
        ll3->li = aux2;
        
        // Percorre a segunda lista até encontrar o ponto de concatenação
        while(aux2->dado < ll1->li->dado) {
            inserir_ordenada(ll3, aux2->dado); // insere o valor na nova lista
            aux2 = aux2->prox; // avança para o próximo nó
        }
        
        // Percorre a primeira lista e insere os valores na nova lista
        while(aux->prox != NULL) {
            inserir_ordenada(ll3, aux->dado); // insere o valor na nova lista
            aux = aux->prox; // avança para o próximo nó
        }
        
        ll3->lf = aux; // define o último nó da nova lista como o último nó da primeira lista
    }
    
    return ll3; // retorna a nova lista concatenada
}

int main() {
    struct lista ll, ll2; // declaração de duas listas
    struct lista* ll3; // ponteiro para a lista concatenada
    criar_lista_dupla_encad_refe(&ll); // cria a primeira lista vazia
    inserir_ordenada(&ll, 10); // insere elementos na primeira lista
    inserir_ordenada(&ll, 5);
    inserir_ordenada(&ll, 15);
    inserir_ordenada(&ll, 1);
    inserir_ordenada(&ll, 20);
    imprimir_lista(&ll); // imprime os elementos da primeira lista
    criar_lista_dupla_encad_refe(&ll2); // cria a segunda lista vazia
    inserir_ordenada(&ll2, 7); // insere elementos na segunda lista
    inserir_ordenada(&ll2, 3);
    inserir_ordenada(&ll2, 12);
    inserir_ordenada(&ll2, 8);
    imprimir_lista(&ll2); // imprime os elementos da segunda lista
    ll3 = concatenar_listas(&ll, &ll2); // concatena as duas listas
    imprimir_lista(ll3); // imprime os elementos da lista concatenada
    return 0;
}
