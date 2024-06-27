#include <stdio.h>
#include <math.h>



// questão 1
void CalculaHexagono(float l, float *area, float *perimetro){

    *area =  3* (l*l) *(sqrt(3))/2;
    *perimetro = 6*l;
}


int main(){
    float l, *area, *perimetro;
    float a, p;

    area = &a;
    perimetro = &p;



    printf("digite o lado do hexagono: ");
    scanf("%f", &l);
    CalculaHexagono(l, area, perimetro);

    printf("lado do hexagono = %2.f, perimetro do hexagono = %2.f", a, p);



    return 0;

}



