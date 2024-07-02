# include <stdio.h>

int main(){
    int ar[5] ={1,2,3,4,5};
    int *p, a,b,c,d;



    a = ar[0] + ar[4];
    p = &ar[2];
    b = *p * 2;
    c = p[1];
    d = 2[ar];

    printf("%d %d %d %d", a, b,c,d);
}