#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* prox;
};

struct Pilha {
    struct No* topo;
};

struct Pilha* cria_pilha() {
    struct Pilha* p = (struct Pilha*) malloc(sizeof(struct Pilha));
    p->topo = NULL;
    return p;
}

int pilha_vazia(struct Pilha* p) {
    return (p->topo == NULL);
}

void empilhar(struct Pilha* p, int valor) {
    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    novo_no->dado = valor;
    novo_no->prox = p->topo;
    p->topo = novo_no;
}

int desempilhar(struct Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    int valor = p->topo->dado;
    struct No* temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
    return valor;
}

void imprime_pilha(struct Pilha* p) {
    struct No* aux = p->topo;
    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}


int remover_menor(struct Pilha* p) {
    struct Pilha* aux = cria_pilha();
    int menor = desempilhar(p);
    
    // Mover todos os elementos para a pilha auxiliar, encontrando o menor valor
    while (!pilha_vazia(p)) {
        int temp = desempilhar(p);
        if (temp < menor) {
            empilhar(aux, menor); // Colocar o antigo menor na pilha auxiliar
            menor = temp; // Atualizar o menor valor
        } else {
            empilhar(aux, temp);
        }
    }
    
    // Restaurar a pilha original sem o menor valor
    while (!pilha_vazia(aux)) {
        empilhar(p, desempilhar(aux));
    }
    
    free(aux); // Liberar a memória da pilha auxiliar
    return menor;
}



// Função para criar uma cópia da pilha original
Pilha* copyStack(Pilha *originalTop) {
    if (originalTop == NULL) {
        return NULL;
    }

    // Passo 1: Usamos uma pilha temporária para armazenar os elementos na ordem original
    Node *tempStack = NULL;
    Node *copyTop = NULL;
    Node *current = originalTop;

    // Desempilhamos a pilha original e empilhamos na pilha temporária
    while (current != NULL) {
        push(&tempStack, current->data);
        current = current->next;
    }

    // Passo 2: Agora empilhamos os elementos da pilha temporária na nova pilha
    while (!isEmpty(tempStack)) {
        push(&copyTop, pop(&tempStack));
    }

    return copyTop;
}

// Função para imprimir os elementos da pilha
void printStack(Node *top) {
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}


int main() {
    struct Pilha* p = cria_pilha();

    // Empilhando alguns valores
    empilhar(p, 5);
    empilhar(p, 2);
    empilhar(p, 9);
    empilhar(p, 1);
    empilhar(p, 3);

    printf("Pilha original: ");
    imprime_pilha(p);

    // Ordenando a pilha
    struct Pilha* pilha_ordenada = ordenar_pilha(p);

    printf("Pilha ordenada: ");
    imprime_pilha(pilha_ordenada);

    // Liberar memória
    free(p);
    free(pilha_ordenada);

    return 0;
}

