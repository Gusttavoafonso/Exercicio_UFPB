#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*questao 1:servem para organizar
 manipular e acessar dados em
 diversos formatos de acordo com os objetivos do projeto.
*/


/*questao 3: A principal vantagem da alocação dinâmica é 
trabalhar apenas com a quantidade 
necessária de memória, evitando assim o desperdício da mesma

Na alocação estática, o tamanho e o tipo das variáveis são
 conhecidos em tempo de compilação, 
 e a memória é alocada durante a compilação

Na alocação dinâmica, a memória é alocada 
durante a execução do programa, geralmente na "heap" (montão).
vantagens:
Permite alocar a quantidade exata de memória necessária em tempo
 de execução, o que é útil para estruturas de dados dinâmicas.
 Pode ser mais eficiente no uso 
 da memória, pois só a quantidade necessária é alocada.
*/


/*int main(){

int a,*p,**k,b,teste;

teste =10;

a = 7;
b = 12;
k = teste;
p = &teste;

printf("%d\n", (*p)+1);// valor de p + 1
//printf("%d\n", &p);// endereço de p
//printf("%d\n", b); //valoe de b

//printf("%d\n", &k); // endereço de onde k aponta
//printf("%d\n", *b);erro
//*k == valor de k
}*/


//questao 4

typedef struct lista{

        int dados[11];
        tamanho = -1;

}

char inserir_ordenado(lista_ordenada* l, int n) {
    if (esta_cheia(l)) {
        puts("A lista está cheia.");
        return 0;
    }
    int i = l->tamanho - 1;

    // Encontra a posição correta para o novo elemento
    while (i >= 0 && l->dados[i] > n) {
        l->dados[i + 1] = l->dados[i];
        i--;
    }

    l->dados[i + 1] = n;
    l->tamanho++;
    return 1;
}

//questão 5

int **pv, *vetor[9], numeros[10];


//questao 7;

typedef struct medicamentos{
    infos
}

typedef struct no{
    struct medicamentos *dados;
    struct no *prox

}l;

//questão 8

typedef struct lista{

    vetor[100];
    controle;

}l; 

int maior(struct lista l*){
    int m = 0,i = 0;

    while(i<= l->controle){
        if(l->vetor[i]> m){
            m = l->vetor[i];
            i += 1
        }
    }
    return m;
}

//questao 8.2

int soma_vetor(struct *lista l){
    int soma = 0,int i= 1;

    

    while(i<= l->controle){
        soma += l->controle[i - 1];
    }

    return soma;
}