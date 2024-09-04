//implementação com vetor

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*#define MAX 50

struct fila {
    int num ;
    int inicio;
    int vet[MAX];
};

typedef struct fila Fila;

Fila* criar_fila(){
    Fila * f = (Fila*)malloc(sizeof(Fila));
    if(f){
        f->inicio = 0;
        f->num = 0;
    }
    return f;
}

//insere no inicio
void fila_insere(Fila* f, int i){
    int fim;
    if (f->num == MAX){
        printf("capacidade cheia"); // imprime mensagem de erro se a fila estiver cheia
        exit(1);
    }
    else{
        fim =(f->inicio + f->num) % MAX;
        f->vet[fim] = i; // insere o elemento no final da fila
        f->num++;
    }
}


int fila_retira(Fila* f){
    int v;
    if(f->num == 0){
        printf("a fila esta vazia"); // imprime mensagem de erro se a fila estiver vazia
        exit(1);

    }else{
        v =  f->vet[f->inicio]; // obtém o elemento no início da fila
        f->inicio = (f->inicio +1) % MAX; // atualiza o início da fila
        f->num--;
    }
    return v;
}*/


//implementação com lista

typedef struct no{
    int valor;
    struct no* prox;

}no;

typedef struct fila
{
    struct no* ini;
    struct no* fim;
}fila;


fila* criar_fila(){
    fila* f =(fila*)malloc(sizeof(fila));
    if(f){
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}


//inserir no fim
void inserir_fila(fila* f,int v){
  //  printf("coloquei\n");
    no* novo = (no*)malloc(sizeof(no));
    if(novo == NULL){
        printf("falhou");
        return;
    }


    novo->valor = v;
    novo->prox = NULL;

    if (f->ini != 0){
        f->fim->prox = novo;
        f->fim = novo;


    }else{
            f->fim = novo;
            f->ini = novo;
        }
    
}

//retira do inicio
int fila_retira(fila* f){
 //   printf("retirei\n");
    no* aux;

    if(f->ini != 0){
    aux = f->ini;
    int v = f->ini->valor;
    f->ini = f->ini->prox;
    return v;
    free(aux);
    }
    else{
        printf("fila vazia");
        return 0;
    }

}

void libera_fila(fila* f){
 //   printf("liberei\n");
    no* aux;
    aux = f->ini;
    while(aux != 0){
        no* aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(f);
}

void imprime_fila(fila* f){
//    printf("imprimir\n");
    no* aux;
    aux = f->ini;
    while(aux != 0){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

int main(){
    fila* f = criar_fila();
    inserir_fila(f, 10);
    inserir_fila(f, 20);
    inserir_fila(f, 30);
    imprime_fila(f);
    fila_retira(f);
    fila_retira(f);
    imprime_fila(f);
    inserir_fila(f, 40);
    inserir_fila(f, 50);
    libera_fila(f);

return 0;

}