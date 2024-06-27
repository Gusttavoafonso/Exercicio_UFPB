typedef union
{   long long int cpfdestino,
    telefone, chavealea;

   
}tdadosDES;



typedef struct  
{   int long long cpfRemetente;
    tdadosDES destino;
    char  email[50];
    int valor;


} tdados;


void printTranfe(tdados dados ){

    printf("cpf do remetente: %d \n",dados.cpfRemetente);
    printf("cpf/telefone/email ou chave aleatoria do destinatario: %d\n",
                                        dados.email);
    printf("valor tranferido: %lld", dados.valor);
                            

}