#include <stdio.h>
#include <string.h>
#include <ctype.h>

int TamanhoStr(const char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++)
        ;
    
    return i;
}

void TiraBarraN(char *str){
    if (str[TamanhoStr(str) - 1] == '\n'){
        str[TamanhoStr(str) - 1] = '\0';
    }
}


int main(){
    int N, cont;
    char pokemons[20], controle[20];

    scanf("%d", &N);
    cont = 0;

    if (N != 0){

    
    while(N--){
       
        scanf("%s", pokemons);
        TiraBarraN(pokemons);
            for(int i = 0; pokemons[i]; i++) {
                pokemons[i] = toupper(pokemons[i]);
            }

            if(!(strcmp(pokemons, controle))){
                continue;
            }
            else
                cont++;
            strcpy(controle, pokemons);

    }
    

    printf("Falta(m) %d pomekon(s).\n",151-cont);
    }
    else
        printf("Falta(m) 151 pomekon(s).\n");

}