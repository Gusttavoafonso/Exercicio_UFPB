#include <stdio.h>

int main()
{   int A, B;
    unsigned long long int soma;

    soma = 0;
    scanf("%d %d", &A, &B);
    
    while(A <= B){
        soma += A;
        A += 1;
    }
    printf("%lld",soma);

    return 0;
}
