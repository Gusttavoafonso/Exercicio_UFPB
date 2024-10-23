#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

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

int altura_arv(Raiz* r){
    if(r){
       int a = 1 + altura_arv(r->esq);
       int b = 1+ altura_arv(r->dir);
       if(a>b){return a ;}

       else{return b ;}
    }
    else{return -1;}/// se liga
}


#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

// Função para criar um novo nó
No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para inserir um valor na árvore binária de busca
No* inserir_arvore(No* raiz, int valor) {
    if (raiz == NULL) {
        // Se a árvore está vazia, crie um novo nó com o valor
        return criar_no(valor);
    }

    // Se o valor for menor que o valor do nó atual, insira na subárvore esquerda
    if (valor < raiz->valor) {
        raiz->esq = inserir_arvore(raiz->esq, valor);
    }
    // Se o valor for maior que o valor do nó atual, insira na subárvore direita
    else if (valor > raiz->valor) {
        raiz->dir = inserir_arvore(raiz->dir, valor);
    }

    // Retorna a raiz (nenhuma mudança no nó atual)
    return raiz;
}

int altura_arvore( Raiz* r){
    if(!r){
        return -1; 
    }
    else{
       int  a =1 + altura_arvore(r->esq);
       int  b = 1 + altura_arvore(r->dir);
        if(a > b){return a;}
        else{return b;}
    }
}

bool e_binaria(Raiz* r) {
    // Se o nó for NULL, consideramos que é uma árvore válida (BST)
    if (r == NULL)
        
 
return true;

    // Verifica se a subárvore esquerda é maior que o nó atual
    if (r->esq != NULL && r->esq->num >= r->num)
        return false;

    // Verifica se a subárvore direita é menor que o nó atual
  
if (r->dir != NULL && r->dir->num <= r->num)   
    return false;

    

   
// Recursivamente verifica as subárvores esquerda e direita
    return e_binaria(r->esq) && e_binaria(r->dir);
}

void preOrdem(Raiz* raiz) {
    if (raiz != NULL) {
        printf("%d \n", raiz->num);  // Visita o nó
        preOrdem(raiz->esq);       // Visita a subárvore esquerda
        preOrdem(raiz->dir);       // Visita a subárvore direita
    }
}

void pos_fix(Raiz* r){
    if(r){
        pos_fix(r->esq);
        pos_fix(r->dir);
        printf("%d \n", r->num);
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

    printf("altura da arvore : %d\n", altura_arv(r));

    printf("altura da arvore : %d\n", altura_arvore(r));

    e_binaria(r);
    libera_arv(r);
    return 0;

}