#include <stdio.h>
#include <stdlib.h>

// Função para calcular o índice no array linear da matriz simétrica
int index(int i, int j) {
    if (i >= j) {
        return i * (i + 1) / 2 + j;  // metade inferior, incluindo a diagonal
    } else {
        return -1; // erro, fora da parte simétrica considerada
    }
}

int main() {
    int n = 4;  // tamanho da matriz
    int total_elements = (n * (n + 1)) / 2;  // elementos únicos
    double *matrix = (double *)malloc(total_elements * sizeof(double));  // alocação de memória

    if (matrix == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Exemplo de inicialização da matriz simétrica
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            matrix[index(i, j)] = i + j;  // Exemplo de valor
        }
    }

    // Exemplo de acesso a elementos (lembrar de acessar só a metade inferior ou diagonal)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                printf("%lf ", matrix[index(i, j)]);
            } else {
                printf("%lf ", matrix[index(j, i)]);  // refletir para a metade superior
            }
        }
        printf("\n");
    }

    free(matrix);  // liberar a memória
    return 0;

/*Nesse método, você aloca um bloco contínuo 
de memória para todos os elementos da matriz e depois usa aritmética 
de ponteiros para acessar os elementos*/

    int rows = 3, cols = 4;

    // Alocação de um único bloco contínuo de memória
    int *matrix = (int *)malloc(rows * cols * sizeof(int));

    if (matrix == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Acessando os elementos com aritmética de ponteiros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i * cols + j] = i + j;  // Exemplo de atribuição
        }
    }

    // Imprimindo a matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    // Liberar memória
    free(matrix);

    return 0;

/*Nesse método, você aloca memória
 para um array de ponteiros (um para cada linha), e 
 então aloca memória separadamente para cada linha da matriz.*/

    int rows = 3, cols = 4;

    // Alocação de memória para um array de ponteiros
    int **matrix = (int **)malloc(rows * sizeof(int *));
    
    if (matrix == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Alocação de memória para cada linha
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Erro na alocação de memória!\n");
            return 1;
        }
    }

    // Preenchendo a matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;  // Exemplo de atribuição
        }
    }

    // Imprimindo a matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar a memória
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;

/*Uma variação do método anterior, onde você aloca apenas a matriz de ponteiros, 
mas acessa os dados como se fosse uma matriz 2D.*/

    int rows = 3, cols = 4;

    // Alocação de um array de ponteiros para cada linha
    int **matrix = (int **)malloc(rows * sizeof(int *));
    
    if (matrix == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Alocação de um bloco único para todas as linhas
    matrix[0] = (int *)malloc(rows * cols * sizeof(int));

    if (matrix[0] == NULL) {
        printf("Erro na alocação de memória!\n");
        free(matrix);
        return 1;
    }

    // Definindo os ponteiros das linhas para apontar para o bloco único
    for (int i = 1; i < rows; i++) {
        matrix[i] = matrix[0] + i * cols;
    }

    // Preenchendo a matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;  // Exemplo de atribuição
        }
    }

    // Imprimindo a matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar a memória
    free(matrix[0]);
    free(matrix);

    return 0;
}






struct Pilha* push(struct Pilha * p,int num){
    struct No *novo = (no*)malloc(sizeof(no));
    novo->dado= num;
    if(p){
        no->prox = p->topo;
        p->topo = novo
    }
    else{
        novo->prox = NULL
        p->topo = novo
    }
}

struct Pilha* pop(struct Pilha* p){
    struct No* aux = p->topo;
    p->topo = p->topo->prox;
    free(aux)
    return p
}


fila * inserir(Fila* f, int valor){
    if(f){
        no* novo = (no*)malloc(sizeof(no));
        novo->num= valor;
        novo->prox = NULL;
        f->fim->prox = novo;
        f->fim = novo;
    
    }
    else{
        no* novo = (no*)malloc(sizeof(no));
        novo->num= valor;
        novo->prox = NULL;
        f->ini = novo;
        f->fim = novo

    }
}
