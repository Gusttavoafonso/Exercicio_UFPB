/*CRIAR UMA FUNÇÃO PARA INDICAR SE UM 
PONTO X ESTA DENTRO OU NAO DE UMRETANGULO*/


int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){

    if((x >= x0 && x <= x1) && (y >= y0 && y <= y1)){
        return 1;
    }
    else
        return 0;

} 

int main(){

    printf("%d",dentro_ret(0,2,5,7,1,4));


}