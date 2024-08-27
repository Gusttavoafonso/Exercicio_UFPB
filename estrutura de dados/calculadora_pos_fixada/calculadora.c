#include "calculadora.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



// Função para criar uma nova pilha
Pilha* cria_pilha() {
    struct Pilha* p;
    p = (struct Pilha*)malloc(sizeof(struct Pilha));
    p->prim = NULL;
    return p;
}

// Função para adicionar um elemento no topo da pilha
void push(Pilha* p, int v) {
    struct Lista* novo;
    novo = (struct Lista*)malloc(sizeof(struct Lista));
    novo->info = v;
    novo->prox = p->prim;
    p->prim = novo;
}

// Função para remover e retornar o elemento do topo da pilha
int pop(Pilha* p) {
    if (vazia(p)) {
        printf("Pilha vazia\n");
        exit(1);
    }
    struct Lista* L_novo;
    int v;
    L_novo = p->prim;
    v = L_novo->info;
    p->prim = L_novo->prox;
    free(L_novo);
    return v;
}

// Função para verificar se a pilha está vazia
int vazia(Pilha* p) {
    return p->prim == NULL;
}

// Função para liberar a memória alocada para a pilha
void libera_pilha(Pilha* p) {
    Lista* q = p->prim;  // Inicializa q como o primeiro elemento da pilha
    while (q != NULL) {
        Lista* t = q;    // Armazena o nó atual em t para liberá-lo
        q = q->prox;     // Avança para o próximo nó
        free(t);         // Libera o nó atual
    }
    free(p);             // Finalmente, libera a estrutura da pilha
}

// Função para imprimir os elementos da pilha
void imprime_pilha(Pilha* p) {
    struct Lista* q;
    for (q = p->prim; q != NULL; q = q->prox) {
        printf("%d\n", q->info);
    }
}

// Função para criar uma nova calculadora
Cal* cria_calculadora(char* formato) {
    struct Cal* c;
    
    // Aloca memória para a calculadora
    c = (struct Cal*)malloc(sizeof(struct Cal));
    if (c == NULL) {  // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória para a calculadora.\n");
        exit(1);
    }
    
    // Copia o formato fornecido para a estrutura da calculadora
    strncpy(c->f, formato, sizeof(c->f) - 1);  // Usa strncpy para evitar buffer overflow
    c->f[sizeof(c->f) - 1] = '\0';  // Garante que a string está terminada em null
    
    // Cria uma nova pilha para a calculadora
    c->p = cria_pilha();
    if (c->p == NULL) {  // Verifica se a criação da pilha foi bem-sucedida
        printf("Erro ao criar a pilha.\n");
        free(c);  // Libera a memória alocada para a calculadora antes de sair
        exit(1);
    }
    
    return c;
}

// Função para adicionar um operando à calculadora
void calc_operando(Cal* c, float v) {
    push(c->p, v);
    imprime_pilha(c->p);
}

// Função para adicionar um operador à calculadora
void calc_operador(struct Cal* c, char op) {
    float v1, v2, r;
    if (vazia(c->p)) {
        v2 = 0;
    } else {
        v2 = pop(c->p);
    }

    if (vazia(c->p)) {
        v1 = 0;
    } else {
        v1 = pop(c->p);
    }

    switch(op) {
        case '+':
            r = v1 + v2;
            break;
        case '-':
            r = v1 - v2;
            break;
        case '*':
            r = v1 * v2;
            break;
        case '/':
            r = v1 / v2;
            break;
        default:
            printf("Operador inválido\n");
            exit(1);
    }
    push(c->p, r);
    printf("%f\n", r);  // Corrigir para usar o formato de ponto flutuante
}

// Função para liberar a memória alocada para a calculadora
void calc_libera(Cal* c) {
    libera_pilha(c->p);
    free(c);
}
