#ifndef CALCULADORA_H
#define CALCULADORA_H
#include<stdio.h>
#include<stdlib.h>

typedef struct Lista{
    int info;
    struct Lista *prox;
}Lista;


typedef struct Pilha{
    struct Lista *prim;
}Pilha;


// Definição da estrutura da calculadora
typedef struct Cal{
    char f[21]; //formato para impressão
    Pilha * p; //pilha de operandos
}Cal;

//funcões exportadas


Cal* cria_calculadora(char*);
void calc_operando(Cal*, float);
void calc_operador(Cal*, char);
void calc_libera(Cal*);

//funções de pilha

Pilha* cria_pilha();
void push(Pilha*, int);
int pop(Pilha*);
int vazia(Pilha*);
void libera_pilha(Pilha*);
void imprime_pilha(Pilha*);

#endif //CALCULADORA_H