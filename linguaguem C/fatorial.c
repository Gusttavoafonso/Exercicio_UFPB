int fatorial(int num){
    int i , total = 0;
    total = num;

    for(i = num -1; i > 0; i --){
        total = total* i;
    }
    return total;
}

int main(){
    int m,n;

    scanf("%d %d", &m, &n);
    printf("%d", fatorial(m)+ fatorial(n));
}