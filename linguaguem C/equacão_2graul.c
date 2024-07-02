#include <stdio.h>
#include <math.h>

int ResolveEquacao2Grau(float a, float b, float c, float *x1, float *x2){
    int delta;

    delta = (b*b) - 4 * a * c;

    if (delta < 0){
        return -2;
    }
    else if (a == 0){
         return -1;
    }
    else{

    *x1 = (-b + delta)/ (2*a);
    *x2 = (-b - delta)/ (2*a);

    }
 return 0;
}

