#include<stdio.h>
#include<stdlib.h>

typedef struct raiz{
    int num;
    struct raiz* dir;
    struct raiz* esq;
}Raiz;

//FUNÇÔES PARA ARVORE

Raiz* criar_arv_vazia(){
    return NULL;
}

Raiz* criar_arvore( int v, Raiz* sae, Raiz sad){
    Raiz* novo = (Raiz*)malloc(sizeof(Raiz));
    novo->num = v;
    novo->dir = sad;
    novo->esq = sae;
    return novo
}

int arv_vazia(Raiz* r){
    if(r)
    return;
}

void imprime_arv(Raiz * r){
    if(r){
        imprime_arv(r->esq);
        imprime_arv(r->dir);
        printf("valor = %d", r->num);

    }
    return;
}

Raiz* libera_arv(Raiz* r){
    if(r){
        libera_arv(r->esq);
        libera_arv(r->dir);
        free(r);
    }
    return NULL;
}

int encontrar_valor(Raiz* r, int v){
    if(r){
        return r->num == v || encontrar_valor(r->esq, v) || 
        encontrar_valor(r->dir);

    }
    return 0;
}