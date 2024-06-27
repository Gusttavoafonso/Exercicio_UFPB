#include <stdio.h>
#include <string.h>

struct Dados_Alunos {
    long long int matricula;
    char nome[40], situacao[10];
    float nota1, nota2, nota3, mediaarit, mediaFinal;
    float recuperacao;
};

// Função para calcular a média 
float calcularMedia(float nota1, float nota2, float nota3) {
    return (nota1 + nota2 + nota3) / 3;
}

// Função para determinar a situação 
void determinarSituacao(struct Dados_Alunos *aluno) {
    if (aluno->mediaFinal >= 7.0)
        strcpy(aluno->situacao, "Aprovado");
    else if (aluno->mediaFinal >= 4.0)
        strcpy(aluno->situacao, "Recuperacao");
    else
        strcpy(aluno->situacao, "Reprovado");
}

int main() {
    FILE *fdiscentes, *fpSaida;

    char disciplina[51];
    int quant_alunos, i;

    fdiscentes = fopen("teste.txt", "r");
    if (fdiscentes == NULL) {
        puts("Nao foi possivel abrir arquivo de entrada");
        return 1;
    }

    fpSaida = fopen("saida", "w");
    if (fpSaida == NULL) {
        puts("Nao foi possivel abrir arquivo de saida");
        return 1;
    }

    printf("Boas vindas\n");
    printf("Digite o nome da disciplina: ");
    fgets(disciplina, sizeof(disciplina), stdin);
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quant_alunos);

    struct Dados_Alunos alunos[quant_alunos];

    for (i = 0; i < quant_alunos; i++) {
        fscanf(fdiscentes, "%lld %s %f %f %f",
               &alunos[i].matricula, alunos[i].nome,
               &alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3);

        alunos[i].mediaarit = calcularMedia(alunos[i].nota1, alunos[i].nota2, alunos[i].nota3);

        determinarSituacao(&alunos[i]);

        fprintf(fpSaida, "Matrícula: %lld\n", alunos[i].matricula);
        fprintf(fpSaida, "Nome: %s\n", alunos[i].nome);
        fprintf(fpSaida, "Nota1: %.2f ; Nota2: %.2f ; Nota3: %.2f\n",
                alunos[i].nota1, alunos[i].nota2, alunos[i].nota3);
        fprintf(fpSaida, "Média: %.2f\n", alunos[i].mediaarit);
        fprintf(fpSaida, "Situação: %s\n\n", alunos[i].situacao);
    }


    fclose(fpSaida);
    fclose(fdiscentes);

    return 0;
}
