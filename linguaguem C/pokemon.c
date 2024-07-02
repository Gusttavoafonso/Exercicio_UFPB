int Valor_do_golpe(int bonus, int ataque, int defesa, int level){
    int valorGolpe = 0;
    if (level % 2 == 0){

        valorGolpe = (ataque + defesa) /2 + bonus;
    }else{

        valorGolpe = (ataque + defesa) /2; 
    }

    return valorGolpe;
}



int main(){
   int  t , i, b, a, d, l;
   int gu, dabri;

    scanf("%d", &t);

   for(i = 0 ; i< t;i++ ){

     scanf("%d", &b);

     scanf("%d %d %d", &a, &d, &l);
    
     gu = Valor_do_golpe(b, a, d, l);

     scanf("%d %d %d", &a, &d, &l);

     dabri = Valor_do_golpe(b, a, d, l);

    
    

    if (gu != dabri){
        if(gu > dabri){
            puts("Dabriel");
        
        }
        else{
            puts("Guarte");
        }
    }
        else{
        puts("Empate");
    }
    } 

}