#include <stdio.h>

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

int main(void){
    char frase[1002];
    int contaChar[26], t, i, contaLetras;

    scanf("%d%*c", &t);
    while(t--){
        fgets(frase, 1002, stdin);
        TiraBarraN(frase);

        for(i = 0; i < 26; i++)
            contaChar[i] = 0;

        for(i = 0; frase[i] != '\0'; i++){
            if (frase[i] >= 'a' && frase[i] <= 'z'){
                contaChar[frase[i] - 'a']++;
            }
        }

        contaLetras = 0;
        for(i = 0; i < 26; i++){
            if (contaChar[i] > 0){
                contaLetras++;
            }
        }

        if (contaLetras == 26){
            puts("frase completa");
        }else if (contaLetras >= 13){
            puts("frase quase completa");
        }else{
            puts("frase mal elaborada");
        }
    }




    return 0;
}