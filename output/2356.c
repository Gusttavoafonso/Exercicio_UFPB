#include <stdio.h>
#include <string.h>

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    getchar();

    while (casos_teste--) {
        char dna[101];
        char codigo_genetico[101];

        fgets(dna, sizeof(dna), stdin);

        if (dna[strlen(dna) - 1] == '\n') {
            dna[strlen(dna) - 1] = '\0';
        }

        fgets(codigo_genetico, sizeof(codigo_genetico), stdin);

        if (codigo_genetico[strlen(codigo_genetico) - 1] == '\n') {
            codigo_genetico[strlen(codigo_genetico) - 1] = '\0';
        }

        if (strstr(dna, codigo_genetico) != NULL) {
            printf("Resistente\n");
        } else {
            printf("Nao resistente\n");
        }
    }

    return 0;
}
