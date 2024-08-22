#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{

    int dado;
    struct no *prox;

}lista_enca;


//funcoes
struct no* criar_lista_encad();

void criar_lista_encd_refe(struct no **);

char esta_cheia_encad(lista_enca*);
char esta_vazia(lista_enca*);
struct no* inserir_inicio(lista_enca*, int );
char inserir_fim(lista_enca*, int);
void limpar_lista_encad(lista_enca*);
int menu();
void mostrar_inf(lista_enca*);
void remover_inicio_encad(lista_enca*);
struct no* remover_inicio(lista_enca*);



struct no* criar_lista_encad(){
    return NULL;
}


void criar_lista_encd_refe(struct no **pl){

    *pl = 0;

};

void mostrar_inf(lista_enca* lista){
    struct no* aux;

    

    for(aux = lista; aux!= NULL; aux = aux->prox ){
        printf("%d", aux->dado);
    }

}

struct no* inserir_inicio(lista_enca* lista, int num){
    struct no* novo;

    novo = (struct no*)malloc(sizeof(struct no));
    if (novo)
    {
        novo->dado = num;
        novo->prox = lista;
        return novo;
    }
    else{
        puts("nao tem memoria");
        return 0;
    }

};


struct no* remover_inicio(lista_enca* lista ){
    struct no* aux;

    aux = lista->prox;
    lista = lista->prox;
    free(aux);
    return lista;


};
