#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct no {
    int dado;
    struct no* prox;
    struct no* ant;
    
};

struct lista{
    struct no* li;
    struct no* lf;
};




void criar_lista_dupla_encad_refe(struct lista*);

char esta_cheia_dupla_encad(struct lista*);
char esta_vazia(struct lista*);
void inserir_inicio(struct lista*, int );
char inserir_fim(struct lista*, int);
void limpar_lista_encad(struct lista*);

void imprimir_lista(struct lista*);
void remover_inicio_dupla_encad(struct lista*);
struct no* remover_inicio(struct lista*);




void criar_lista_dupla_encad_refe(struct lista *c){
    c->li = NULL;
    c->lf = NULL;


}




// Função para inserir um elemento no início da lista
void inserir_inicio(struct lista* l, int valor) {
    // Criando novo nó
    struct no* novo_no = (struct no*)malloc(sizeof(struct no));
    novo_no->dado = valor;
    novo_no->prox = NULL;
    novo_no->ant = NULL;

    // Se a lista estiver vazia
    if (l->li == NULL) {
        l->li = novo_no;
        l->lf = novo_no;
    } else {
        novo_no->prox = l->li; // O próximo do novo nó é o atual início
        l->li->ant = novo_no;  // O anterior do nó do início é o novo nó
        l->li = novo_no;       // Atualizando o ponteiro do início para o novo nó
    }
}

void remover_inicio_dupla_encad(struct lista* ll){
    struct no* aux;
    aux = ll->li;
    if(ll->li->prox == 0){
    ll->li =0;
    ll->lf = 0;
    }
    else{
        ll->li = aux ->prox;
        aux->prox->ant = 0;

    }
    free(aux);
}


// Função para imprimir a lista do início ao fim
void imprimir_lista(struct lista* l) {
    struct no* atual;

    atual = l->li;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int main(){
    struct lista l1;

    criar_lista_dupla_encad_refe(&l1);
    inserir_inicio(&l1, 5);
    inserir_inicio(&l1, 6);
    inserir_inicio(&l1, 7);
    imprimir_lista(&l1);
    remover_inicio_dupla_encad(&l1);
    imprimir_lista(&l1);
}