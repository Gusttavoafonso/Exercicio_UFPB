/*calculando n-esimo numero de fibonacci*/





int calcular_fibonacci(int *num){

    int num1, num2, resul, teste, i;
    num1 = num2 = 1;

    teste = *num;

    for ( i = 2; i < teste; i++)
    {
        resul = num1 + num2;
        num1 = num2;
        num2 = resul;
       
    }
    return resul;

}


void main(){
    int a, *pa;

    pa = &a;
    scanf("%d",&a);
    printf("%d e o %d de fibonacci", calcular_fibonacci(pa), *pa);




}