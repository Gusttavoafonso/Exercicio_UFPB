#include<stdlib.h>

int Finonace(int n){

  int  ele1 , ele2, elenovo;
    
    ele1 = 0;
    ele2 = 1;
    if (n != 0){
     for(; n >  0; n--){
       elenovo = ele1 + ele2;
       ele1 = ele2;
       ele2 = elenovo;
       
     }
        
  } else{
    elenovo = 0;
}

 return elenovo;

  }





int main(){
     unsigned int num;
     int resul, x;

     scanf("%d", &x);

    for(; x > 0; x--){
        scanf("%d",&num);
        resul = Finonace(num);
        printf("Fib(%d) = %d\n", num , resul);

    }



}