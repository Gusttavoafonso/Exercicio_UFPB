#include <stdio.h>
#include <string.h>

struct Dados_Alunos{
    long long int matricula;
    char nome[40], situacao[10];
    float nota1,nota2,nota3, mediaarit, mediaFinal;
    float recuperacao ;
   
};

int main()
{   char disciplina[51];
    int quant_alunos, i;
   
   
    //primeira etapa
    printf("Boas vindas\n");
   
    printf("Digite o nome da disciplina: ");
    fgets(disciplina, sizeof(disciplina), stdin);
   
    printf("digite a quantidade de alunos: ");
    scanf("%d", &quant_alunos);
   


    //segunda etapa
   
    struct Dados_Alunos alunos[quant_alunos];
   
    for(i=0; i< quant_alunos; i++){
        printf("Matricula do %d  aluno: ", i+1);
        scanf("%lld", &alunos[i].matricula);
       
        while (getchar() != '\n');
       
        printf("Nome do aluno: ");
        fgets(alunos[i].nome,sizeof(alunos[i].nome), stdin);
   
   
   
    }

 //terceira etapa
 
    for(i=0; i< quant_alunos; i++){
        printf("Digite as notas de %s(separado por espaco)", alunos[i].nome) ;
        scanf("%f %f %f",&alunos[i].nota1,&alunos[i].nota2,&alunos[i].nota3);
       
    }




// quarta etapa
    puts("ALUNOS EM RECUPERACAO\n");
    for(i = 0; i<quant_alunos; i++){
       alunos[i].mediaarit = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3;
       if(alunos[i].mediaarit < 7 && alunos[i].mediaarit >= 4){
        

        printf("Nome do aluno: %s\n", alunos[i].nome);
        printf("Media : %.2f\n", alunos[i].mediaarit);
        printf("Digite a nota da recuperacao: ");
        while (getchar() != '\n');
        scanf("%f", &alunos[i].recuperacao);
        printf("\n");


        alunos[i].mediaFinal = (alunos[i].mediaarit*6 + alunos[i].recuperacao* 4)/10;
        if( alunos[i].mediaFinal >= 5)
            strcpy(alunos[i].situacao, "Aprovado");
        else
            strcpy(alunos[i].situacao, "Reprovado");

       }


    }

// quinta etapa

    for(i = 0; i<quant_alunos; i++){
         if(alunos[i].mediaarit < 4){
         alunos[i].mediaFinal = alunos[i].mediaarit;
            strcpy(alunos[i].situacao, "Reprovado");

         }
        else if(alunos[i].mediaarit > 7){
            alunos[i].mediaFinal = alunos[i].mediaarit;
            strcpy(alunos[i].situacao, "Aprovado");
            
        }


    }
puts("-------------------------------------");
printf("NOME DA DISCIPLINA : %s",disciplina);
puts("-------------------------------------");

for(i = 0; i<quant_alunos; i++){
    printf("MAtricula: %lld \n", alunos[i].matricula);
    printf("Nome: %s \n", alunos[i].nome);
    printf("Nota1 : %.2f ; Nota2 : %.2f ; nota3 : %.2f \n", alunos[i].nota1,alunos[i].nota2,alunos[i].nota3);
    printf("Media : %.2f \n", alunos[i].mediaFinal);
    printf("Situacao: %s\n", alunos[i].situacao);
    printf("\n");

    puts("-------------------------------------");
}



}


