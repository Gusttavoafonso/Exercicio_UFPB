//   pratica de alocaçao dinamica 
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

/* codigo um: armazenando 5 numeros inteiros e printando

int main(){
    int* n;
    int i;

    n = (int*) malloc(5 * sizeof(int));
    for ( i = 0; i < 5; i++)
    {
        printf("Digite o %d numero: ", (i +1));
        scanf("%d", &n[i]);
    }
    
    for ( i = 0; i < 5; i++)
    {
        printf("%d\n", n[i]);
    }
    


    free(n);
}  */


/*codigo 2: numero impar e par

int main(){

    int n,i, *vetn;

    printf("digite o tamanho do vetor: ");
    scanf("%d",&n);

    vetn = (int*)malloc(n* sizeof(int));

     for ( i = 0; i < n; i++)
    {
        printf("Digite o %d numero: ", (i +1));
        scanf("%d", &vetn[i]);
    }

    for ( i = 0; i < n; i++){
        if(vetn[i] % 2 == 0){
            printf("o numero %d e' par\n",vetn[i]);
        }
        else
            printf("o numero %d e' impar\n", vetn[i]);

    }
    
free(vetn);
}*/



int main(){
    char **pnomes, nome[100]; //pnomes tem ** pq ele vai apontar para um ARRAY DE PONTEIROS char
    int i;

    pnomes = (char**) malloc(3 * sizeof(char*)); // alocando memoria para o array de ponteiros 


    if (pnomes == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }

    for(i= 0; i < 3; i++){
        printf("digite um nome ");
        scanf("%s",nome);

        // Aloca memória suficiente para armazenar o nome e copia o nome para pnomes[i]
        pnomes[i] = (char*) malloc((strlen(nome) + 1) * sizeof(char));
        if (pnomes[i] == NULL) {
            printf("Erro na alocação de memória\n");
            return 1;
        }

        strcpy(pnomes[i], nome); // destino, origem
        
    }

     for(i= 0; i < 3; i++){
        printf("%s\n", pnomes[i]);
     }


        // Libera a memória alocada.   VOCE É ETERNAMENTE RESPONSAVEL PELA MEMORIA QUE ALOCASTE.
    for(i = 0; i < 3; i++) {
        free(pnomes[i]);
    }

   free(pnomes); 

}