#include <stdio.h>
int soma(int *a, int *b){
*a =  *a + *b;
return *a;


}
int main(void) {
int x = 5, y = 3;
y = soma(&x, &y);
printf("%d", x+y);
return 0;
}