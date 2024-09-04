#include<stdio.h>
#include<stdlib.h>


typedef struct no{
    int valor;
    struct no* prox;
    struct no* ant;
}No;

typedef struct fila{
    struct no* inicio;
    struct no* fim;


}Fila;

//função para inserir

static No* inserir_ini(No* i, int v){
    No* novo =(No*)malloc(sizeof(No));
    if(novo){
        novo->valor = v;
        novo->ant = NULL;
        novo->prox = i;
        if(i != NULL){
            i->ant = novo;
        }
    }
    return novo;
}

static No* inserir_fim(No* f, int v){
    No* novo = (No*)malloc(sizeof(No));
    if (novo){
        novo->valor = v;
        novo->prox = NULL;
        novo->ant = f;
        if(f != NULL){
            f->prox = novo;

        }
    }
    return novo;
}

void fila_insere_ini(Fila* f,int v){
    f->inicio = inserir_ini(f->inicio, v);
    if(f->fim == NULL)
        f->fim = f->inicio;
}