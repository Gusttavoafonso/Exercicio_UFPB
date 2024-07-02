#include <stdio.h>

int main(){

int N,X;

   unsigned long long int mult, resultado;

    scanf("%d", &N);

    while (N> 0){
        scanf ("%d", &X);
        mult = 2;
        X = X - 1;

        for (; X > 0; X--){
            mult *= 2;
        }

        resultado = (mult - 1)/12000;

        printf("%lld kg\n", resultado);

        N--;}
}