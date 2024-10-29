#include<stdio.h>

int main(){

int a,*p,**k,b,teste;

teste =10;

a = 7;
b = 12;
p = &b;
k = &p;


printf("%d\n", (*p)+1);// valor de p + 1
printf("endereco de b : %p\n", &b);
printf("endereco de p %p\n", &p);// endereço de p
//printf("%d\n", b); //valoe de b
printf("endereco de p recebe %p\n", p); // endereço de onde k aponta
printf("para onde K aponta : %p", *k);
//printf("%d\n", *b);erro
//*k == valor de k
}