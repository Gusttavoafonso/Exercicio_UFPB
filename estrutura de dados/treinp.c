#include<stdio.h>
#include<stdlib.h>

// Pilha

typedef struct no {
    int dado;
    struct no* prox;

}No;

typedef struct Pilha{
    struct no* topo;
}Pilha;

Pilha* criar_pilha(){
    Pilha* p= (Pilha*)malloc(sizeof(Pilha));

    p->topo = NULL;
    return p;
}

void push_pilha(Pilha * p,int i){
   No* novo = ( No*)malloc(sizeof(No));
    novo->dado = i;
    if(novo){
        if(p->topo == NULL){//verificar se esta vazia
            novo->prox = NULL;
            p->topo = novo;
        }else{
            novo->prox = p->topo;
            p->topo = novo;
        }
    }
}

int pop_pilha(Pilha* p){
    if(p->topo == NULL){
        puts("pilha vazia");
        return 0;
    }
    No* aux = p->topo;
    int v = aux->dado;
    p->topo =aux->prox;
    free(aux);
    return v;
}

//fila

typedef struct no2 {
    int dado;
    struct no2* prox;

}No2;

typedef struct fila{
    struct no2* ini;
    struct no2* fim;
}Fila;


Fila* criar_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->fim = NULL;
    f->ini = NULL;
    return f;
}

void inserir_fila(Fila* f , int i){
    No2* novo = (No2*)malloc(sizeof(No2));
    novo->dado = i;
    if (f->ini == NULL){
        f-> ini = novo;
        novo->prox =NULL;
        f->fim = novo;
    }
    else{
        novo->prox =NULL;
        f->fim = novo;
    }
}

int remover_fila(Fila* f){
    if(f->ini != NULL){
    No2* aux = f->ini;
    int v = aux->dado;
    f->ini = aux->prox;
    free(aux);
    return v;
    }else
    return 0;
}
