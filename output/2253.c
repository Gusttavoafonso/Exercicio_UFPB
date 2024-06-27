#include <stdio.h>

// Função para verificar se um caractere é uma letra maiúscula
int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

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

// Função para verificar se um caractere é uma letra minúscula
int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

// Função para verificar se um caractere é um dígito
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Função para verificar se um caractere é um espaço, pontuação ou acentuação
int is_invalid(char c) {
    return (c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126);
}

// Função para validar a senha
int validar_senha(char senha[]) {
    int i;
    int tem_maiuscula = 0;
    int tem_minuscula = 0;
    int tem_numero = 0;
    
    // Verifica se a senha tem de 6 a 32 caracteres
    if (senha[0] == '\0' || senha[32] != '\0') {
        return 0;
    }
    
    // Verifica se a senha contém pelo menos uma letra maiúscula, uma letra minúscula e um número
    for (i = 0; senha[i] != '\0'; i++) {
        if (is_upper(senha[i])) {
            tem_maiuscula = 1;
        } else if (is_lower(senha[i])) {
            tem_minuscula = 1;
        } else if (is_digit(senha[i])) {
            tem_numero = 1;
        }
    }
    
    if (!tem_maiuscula || !tem_minuscula || !tem_numero) {
        return 0;
    }
    
    // Verifica se a senha não contém caracteres de pontuação, acentuação ou espaço
    for (i = 0; senha[i] != '\0'; i++) {
        if (is_invalid(senha[i])) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char senha[33];
    
    // Processa as senhas
    while (scanf("%32s", senha) != EOF) {
        TiraBarraN(senha);
        if (validar_senha(senha)) {
            printf("Senha valida.\n");
        } else {
            printf("Senha invalida.\n");
        }
    }
    
    return 0;
}

