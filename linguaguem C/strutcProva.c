#include <stdio.h>
#include <string.h>


typedef struct {

    long long int matricula;
    char nome[40];
    float nota1,nota2,nota3,recupecao;
    
}dadosAlunos;

void imprimeresul (dadosAlunos alunos,FILE *fpsaida){

    fprintf(fpsaida, "nome do aluno %s", alunos.nome);


}

int main(){

    FILE *fpsaida;
    dadosAlunos aluno[6];
    
    fpsaida = fopen("teste.txt", "w");

    printf("digite o nome do aluno: ");
    scanf("%s", &aluno[1].nome);

    fscanf(fpsaida,"%s",aluno[1].nome);


    fclose(fpsaida);
}