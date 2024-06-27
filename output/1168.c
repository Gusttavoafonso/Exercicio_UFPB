
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, cont;
    char led[101];

    scanf("%d", &n);

    while (n--) {
        cont = 0;
        scanf("%s", led);

        for (i = 0; i < strlen(led); i++) {

            switch (led[i]) {
                case '0':
                    cont += 6;
                    break;
                case '1':
                    cont += 2;
                    break;
                case '2':
                case '3':
                case '5':
                    cont += 5;
                    break;
                case '4':
                    cont += 4;
                    break;
                case '6':
                case '9':
                    cont += 6;
                    break;
                case '7':
                    cont += 3;
                    break;
                case '8':
                    cont += 7;
                    break;
                default:
                    break;
            }
        }
        printf("%d leds\n", cont);
    }
    return 0;
}
