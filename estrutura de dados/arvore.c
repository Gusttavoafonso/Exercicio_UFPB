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

Raiz* criar_arvore( int v, Raiz* sae, Raiz* sad){
    Raiz* novo = (Raiz*)malloc(sizeof(Raiz));
    novo->num = v;
    novo->dir = sad;
    novo->esq = sae;
    return novo;
}

/*int arv_vazia(Raiz* r){
    if(r){
    return 1;
    }

}*/


void imprime_arv(Raiz * r){
    if(r){
        imprime_arv(r->esq);
        imprime_arv(r->dir);
        printf("valor = %d\n", r->num);

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
        encontrar_valor(r->dir, v);

    }
    return 0;
}

int contar_no(Raiz* r) {
    if (r == NULL) {
        return 0;
    }
    // O nó atual conta como 1, mais os nós à esquerda e à direita
    return 1 + contar_no(r->esq) + contar_no(r->dir);
}

int contar_naofolha(Raiz* r){
    if (r){
        if(r->esq || r->dir){
           return 1 + contar_naofolha(r->esq)+ contar_naofolha(r->dir);
            
        }
        else{return 0;}    
}
}


int main(){
    Raiz* r = criar_arvore(1, criar_arvore(2, criar_arvore(4, criar_arv_vazia(), criar_arv_vazia()), criar_arvore(5, criar_arv_vazia(), criar_arv_vazia())), criar_arvore(3, criar_arvore(6, criar_arv_vazia(), criar_arv_vazia()), criar_arvore(7, criar_arv_vazia(), criar_arv_vazia())));
    imprime_arv(r);
    printf("\n");
    printf("Quantidade de nos = %d", contar_no(r));
    printf("\n");
    printf("Valor encontrado = %d", encontrar_valor(r, 5));
    printf("\n");

    printf("quantidaddes de nao folha = %d\n", contar_naofolha(r));

    libera_arv(r);
    return 0;

}