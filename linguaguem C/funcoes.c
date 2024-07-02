char Funcao(int x,int  y){
    int  funcao_a , funcao_b ,funcao_C;


    funcao_a = (3*x)*(3*x) + y*y;
    funcao_b = 2*(x*x) + (5*y)*(5*y),
    funcao_C = -100*x + (y*y*y);

    if (funcao_a> funcao_b && funcao_a > funcao_C){
              
            return ("Rafael ganhou");

            }else if(funcao_b> funcao_a && funcao_b >funcao_C){
              return ("Beto ganhou");
            }else if(funcao_C> funcao_a && funcao_C > funcao_b){
               return ("Carlos ganhou");
            }

}

int Main (){
    int n, i, x, y;

    scanf("%d", &n);
    for(i = 0;i < n; i++ ){
        scanf("%d %d", &x, &y);
        printf("%x", Funcao(x, y));
}
}