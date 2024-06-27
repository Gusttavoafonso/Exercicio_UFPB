#include <stdio.h>

int main()
{   unsigned long long int  X, P;
   
    


    
    while(1){
        
        scanf("%lld", &P);
        if(P == -1){
            puts("0");
            break;
        }
        else{
        X = P - 1;
        printf("%lld\n", X);
        }
    }

    

    return 0;
}
